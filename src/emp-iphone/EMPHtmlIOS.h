//
//  EMPHtmlIOS.h
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#ifndef __libmoai__EMPHtmlIOS__
#define __libmoai__EMPHtmlIOS__

#include <iostream>
#include <moai-core/headers.h>
#include <EMPViewFactoryIOS.h>
#import <emp-html/headers.h>
#import <UIKit/UIKit.h>
#endif /* defined(__libmoai__EMPHtmlIOS__) */


class EMPHtmlIOS:public MOAIGlobalClass < EMPHtmlIOS, MOAILuaObject > {
private:
	EMPViewFactoryIOS * factory;
	//----------------------------------------------------------------//
	static int test(lua_State* L );
public:
	
	DECL_LUA_SINGLETON ( EMPHtmlIOS )
	
	GET(EMPViewFactoryIOS*, Factory, factory)
	//----------------------------------------------------------------//
	EMPHtmlIOS			();
	~EMPHtmlIOS			();
	void			RegisterLuaClass	( MOAILuaState& state );
	
};