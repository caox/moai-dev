//
//  MOAIHtmlMgr.h
//  libmoai
//
//  Created by cao xu on 14-3-26.
//
//

#ifndef __libmoai__MOAIHtmlMgr__
#define __libmoai__MOAIHtmlMgr__

#include <moai-core/MOAILua.h>


//================================================================//
// MOAIHtmlMgr
//================================================================//
/**	@name	MOAIHtmlMgr
 @text	Example singleton for extending Moai using MOAILuaObject.
 Copy this object, rename it and add your own stuff.
 Just don't forget to register it with the runtime
 using the REGISTER_LUA_CLASS macro (see moaicore.cpp).
 */
class MOAIHtmlMgr :
public MOAIGlobalClass < MOAIHtmlMgr, MOAILuaObject > {
private:
	
	//----------------------------------------------------------------//
	static int		_singletonHello		( lua_State* L );
	
public:
	
	DECL_LUA_SINGLETON ( MOAIHtmlMgr )
	
	//----------------------------------------------------------------//
	MOAIHtmlMgr			();
	~MOAIHtmlMgr			();
	void			RegisterLuaClass	( MOAILuaState& state );
};

#endif /* defined(__libmoai__MOAIHtmlMgr__) */
