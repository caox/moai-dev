//
//  EMPViewFactory.cpp
//  libmoai
//
//  Created by cao xu on 14-5-6.
//
//

#include "EMPViewFactory.h"
#include "EMPDiv.h"

#include "EMPButton.h"
#include <strings.h>
#include <string>
#include <emp-html/EMPView.h>
#include <emp-html/EMPViewImpl.h>
#include <emp-html/EMPDocument.h>
using namespace std;

classMap EMPViewFactory::mClassMap;


// XXX: The including of init.h must be placed after mClassMap's initialization,
//      otherwise the registeration will be discarded.
#include "init.h"

// ----------------------------------------------------------------------
// STDOUT dump and indenting utility functions
// ----------------------------------------------------------------------
const unsigned int NUM_INDENTS_PER_SPACE=2;

const char * getIndent( unsigned int numIndents )
{
	static const char * pINDENT="                                      + ";
	static const unsigned int LENGTH=strlen( pINDENT );
	unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH ) n = LENGTH;
	
	return &pINDENT[ LENGTH-n ];
}

// same as getIndent but no "+" at the end
const char * getIndentAlt( unsigned int numIndents )
{
	static const char * pINDENT="                                        ";
	static const unsigned int LENGTH=strlen( pINDENT );
	unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH ) n = LENGTH;
	
	return &pINDENT[ LENGTH-n ];
}

int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent)
{
	if ( !pElement ) return 0;
	
	TiXmlAttribute* pAttrib=pElement->FirstAttribute();
	int i=0;
	int ival;
	double dval;
	const char* pIndent=getIndent(indent);
	printf("\n");
	while (pAttrib)
	{
		printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());
		
		if (pAttrib->QueryIntValue(&ival)==TIXML_SUCCESS)    printf( " int=%d", ival);
		if (pAttrib->QueryDoubleValue(&dval)==TIXML_SUCCESS) printf( " d=%1.1f", dval);
		printf( "\n" );
		i++;
		pAttrib=pAttrib->Next();
	}
	return i;
}

void dump_to_stdout( TiXmlNode* node, unsigned int indent = 0 )
{
	if ( !node ) return;
	
	TiXmlNode* pChild;
	TiXmlText* pText;
	int t = node->Type();
	printf( "%s", getIndent(indent));
	int num;
	
	switch ( t )
	{
		case TiXmlNode::DOCUMENT:
			printf( "Document" );
			break;
			
		case TiXmlNode::ELEMENT:
			printf( "Element [%s]", node->Value() );
			num=dump_attribs_to_stdout(node->ToElement(), indent+1);
			switch(num)
		{
			case 0:  printf( " (No attributes)"); break;
			case 1:  printf( "%s1 attribute", getIndentAlt(indent)); break;
			default: printf( "%s%d attributes", getIndentAlt(indent), num); break;
		}
			break;
			
		case TiXmlNode::COMMENT:
			printf( "Comment: [%s]", node->Value());
			break;
			
		case TiXmlNode::UNKNOWN:
			printf( "Unknown" );
			break;
			
		case TiXmlNode::TEXT:
			pText = node->ToText();
			printf( "Text: [%s]", pText->Value() );
			break;
			
		case TiXmlNode::DECLARATION:
			printf( "Declaration" );
			break;
		default:
			break;
	}
	printf( "\n" );
	for ( pChild = node->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
	{
		dump_to_stdout( pChild, indent+1 );
	}
}


void EMPViewFactory::createViewElement(TiXmlNode* node, EMPView* parentView, void* host_arg){
	
	if ( !node ) return;
	
	if (TiXmlNode::ELEMENT == node->Type()){
		const char* name = node->Value();
		printf("element : %s \n", name);
		EMPView* viewElement = initView(name, node->ToElement(), host_arg);
		if (NULL != viewElement){
			parentView->addSubView(viewElement);
			if (viewElement->isContainer()) {
				/* TODO We need change the host_arg of the container.
				 As for iOS, it could be the pointer of UIView of
				 the container.
				 */
				createViewElement(node->FirstChild(), parentView, host_arg);
			}
		}
	}
	createViewElement(node->NextSibling(), parentView, host_arg);
	
}

EMPView* EMPViewFactory::createViewHierarchy(const char* xml, void* host_arg){
	TiXmlDocument* doc = new TiXmlDocument();
	doc->Parse(xml);
	if (doc->Error()){
		printf("xml error");
		
	}
	dump_to_stdout(doc);
	
	
	EMPView* docView = new EMPView();
	createViewElement(doc->FirstChild(), docView, host_arg);
	delete doc;
	return docView;
}

attribute_map* EMPViewFactory::dumpAttributeToMap(TiXmlElement* node){
	if (!node) return NULL;
	
	attribute_map * map= new attribute_map();
	TiXmlAttribute* nodeAttr=node->FirstAttribute();
	while (nodeAttr)
	{
		map->insert(make_pair(nodeAttr->Name(), nodeAttr->Value()));
		nodeAttr=nodeAttr->Next();
	}
	return map;
}

EMPView* EMPViewFactory::initView(const char* name, TiXmlElement* node, void* host_arg){
	EMPView* view = EMPViewFactory::GetClassByName(name);
	if (NULL!= view) {
		attribute_map* map = dumpAttributeToMap(node);
		EMPViewImpl* impl = createViewImpl(name, host_arg);
		view->setAttributeMap(map);
		view->SetViewImpl(impl);
	}
	return view;
}

GenDynamic::GenDynamic(string name,CreateEMPView method){
	EMPViewFactory::RegistClass(name,method);
}
