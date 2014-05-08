//
//  EMPViewFactory.h
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#ifndef libmoai_EMPViewFactory_h
#define libmoai_EMPViewFactory_h


#include "util.h"
#include <tinyxml.h>

class EMPView;
class EMPViewImpl;

typedef EMPView* (*CreateEMPView)(void);

typedef hash_map<string, CreateEMPView> classMap ;

class EMPViewFactory{
private:
	static classMap mClassMap;
public:
	EMPView* initView(const char* tag, TiXmlElement* node, void* host_arg);
	void createViewElement(TiXmlNode* doc, EMPView *docView, void* host_arg);
	EMPView* createViewHierarchy(const char* xml, void* host_arg);
	attribute_map* dumpAttributeToMap(TiXmlElement* node);
	virtual EMPViewImpl* createViewImpl(const char* tag, void* host_arg)=0;
	
	
	//----------------------------------------------------------------//
	virtual ~EMPViewFactory(){};
	
	static EMPView* GetClassByName(string name) /*遍历工厂类，根据类名返回类对象*/
	{
		classMap::const_iterator iter;
		iter = mClassMap.find(name);
		if(iter==mClassMap.end())
			return NULL;
		else
			return iter->second();
	}
	
	static void RegistClass(string name,CreateEMPView method)  /*向工厂类注册createClass方法*/
	{
		mClassMap.insert(pair<string,CreateEMPView>(name,method));
	}


};


/*@动态创建类,动态创建的类通过包含该类的一个静态对象
 *向类工厂里注册自己的创建对象函数
 */
class GenDynamic
{
public:
	GenDynamic(string name,CreateEMPView method);
};


#endif
