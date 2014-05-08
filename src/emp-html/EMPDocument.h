//
//  EMPDocument.h
//  libmoai
//
//  Created by cao xu on 14-4-1.
//
//

#ifndef __libmoai__EMPDocument__
#define __libmoai__EMPDocument__

#include <iostream>
#include <moai-core/headers.h>
#include <string>
#include <emp-html/EMPView.h>


class EMPViewFactory;
using namespace std;

class EMPDocument:public MOAIGlobalClass < EMPDocument, MOAILuaObject >{
public:
	void render(const string&, void *);
	
	DECL_LUA_SINGLETON ( EMPDocument )
	SET ( EMPViewFactory*, Factory, factory )
	SET ( EMPView*, Document, current_doc )
	GET ( EMPViewFactory*, Factory, factory )
	void			RegisterLuaClass	( MOAILuaState& state );
private:

	
	EMPView * current_doc;
	EMPViewFactory * factory;
	static int		_getElementByName		( lua_State* L );
};

#endif /* defined(__libmoai__EMPDocument__) */
