//
//  EMPView.mm
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#import "EMPViewFactoryIOS.h"


void  EMPViewFactoryIOS::renderView(const EMPView& rootView) {
	UIWindow* window = [[ UIApplication sharedApplication ] keyWindow ];
	UIViewController* rootVC = [ window rootViewController ];
	
	if(rootView.getViewType() == EMPView::BUTTON){
		printf ( "A single button!\n" );
		UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
		button.frame = CGRectMake(221, 81, 54, 30);
		[button setTitle:@"前往" forState:UIControlStateNormal];
		[rootVC.view addSubview:button ];
	}
}
int EMPViewFactoryIOS::test(lua_State* L ){
	UNUSED ( L );
	
	printf ( "EMP factory singleton foo!\n" );
	EMPView * view = new EMPView();
	view->setViewType(EMPView::BUTTON);
	renderView(*view);
	return 0;
}


//================================================================//
// EMPViewFactoryIOS
//================================================================//

//----------------------------------------------------------------//
EMPViewFactoryIOS::EMPViewFactoryIOS () {
	
	// register all classes EMPViewFactoryIOS derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
	RTTI_EXTEND ( MOAILuaObject )
	
	// and any other objects from multiple inheritance...
	// RTTI_EXTEND ( EMPViewFactoryIOSBase )
	RTTI_END
}

//----------------------------------------------------------------//
EMPViewFactoryIOS::~EMPViewFactoryIOS () {
}

//----------------------------------------------------------------//
void EMPViewFactoryIOS::RegisterLuaClass ( MOAILuaState& state ) {
	
	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );
	
	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );
	
	// here are the class methods:
	luaL_Reg regTable [] = {
		{ "renderHtml",		test },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}