//
//  EMPHtmlIOS.cpp
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#include "EMPHtmlIOS.h"


int EMPHtmlIOS::test(lua_State* L ){
	UNUSED ( L );
	UIWindow* window = [[ UIApplication sharedApplication ] keyWindow ];
	UIViewController* rootVC = [ window rootViewController ];
	
	UIView* doc = [[UIView alloc] init];
	
	printf ( "EMP factory singleton foo!\n" );
	string xml = "<div><button> this is a test</button></div><div>ppp</div>";
	EMPDocument::Get().render(xml, (void*)doc);
	[rootVC.view addSubview: doc];
	
	return 0;
}


//================================================================//
// EMPHtmlIOS
//================================================================//

//----------------------------------------------------------------//
EMPHtmlIOS::EMPHtmlIOS () {
	
	// register all classes EMPHtmlIOS derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
	RTTI_EXTEND ( MOAILuaObject )
	
	factory = new EMPViewFactoryIOS();
	
	// and any other objects from multiple inheritance...
	// RTTI_EXTEND ( EMPHtmlIOSBase )
	RTTI_END
}

//----------------------------------------------------------------//
EMPHtmlIOS::~EMPHtmlIOS () {
	delete factory;
}

//----------------------------------------------------------------//
void EMPHtmlIOS::RegisterLuaClass ( MOAILuaState& state ) {
	
	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );
	
	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );
	
	// here are the class methods:
	luaL_Reg regTable [] = {
		{ "render",		test },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}