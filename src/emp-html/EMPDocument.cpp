//
//  EMPDocument.cpp
//  libmoai
//
//  Created by cao xu on 14-4-1.
//
//

#include "EMPDocument.h"
#include <emp-html/EMPButton.h>
#include <emp-html/EMPDiv.h>
#include <emp-html/EMPViewFactory.h>


void EMPDocument::render(const string& xml, void* host_arg){
	printf("the xml: %s", xml.c_str());
	// TODO: parse the xml
	//		 traverse the DOM
	//		 generate the view hierarchy
	
	// sample code for div and label
	

	// if current_doc != NULL release current_doc
	EMPView * docView = factory-> createViewHierarchy(xml.c_str(), host_arg);
	
	current_doc =  docView;
	
};


void EMPDocument::RegisterLuaClass ( MOAILuaState& state ) {
	
	luaL_Reg regTable [] = {
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}