//
//  MOAIHtmlMgr.cpp
//  libmoai
//
//  Created by cao xu on 14-3-26.
//
//

#include "pch.h"
#include <moai-core/MOAIHtmlMgr.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
/**	@name	singletonHello
 @text	Prints the string 'MOAIHtmlMgr singleton foo!' to the console.
 
 @out	nil
 */
int MOAIHtmlMgr::_singletonHello ( lua_State* L ) {
	UNUSED ( L );
	
	printf ( "MOAIHtmlMgr singleton foo!\n" );
	
	return 0;
}

//================================================================//
// MOAIHtmlMgr
//================================================================//

//----------------------------------------------------------------//
MOAIHtmlMgr::MOAIHtmlMgr () {
	
	// register all classes MOAIHtmlMgr derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
	RTTI_EXTEND ( MOAILuaObject )
	
	// and any other objects from multiple inheritance...
	// RTTI_EXTEND ( MOAIHtmlMgrBase )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIHtmlMgr::~MOAIHtmlMgr () {
}

//----------------------------------------------------------------//
void MOAIHtmlMgr::RegisterLuaClass ( MOAILuaState& state ) {
	
	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );
	
	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );
	
	// here are the class methods:
	luaL_Reg regTable [] = {
		{ "singletonHello",		_singletonHello },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
