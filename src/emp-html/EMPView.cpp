//
//  EMPView.cpp
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//


#include <emp-html/EMPView.h>
#include <emp-html/EMPViewImpl.h>

EMPView::EMPView(ViewType t){
	type = t;
}

void EMPView::setViewType(ViewType t){
	this->type = t;
};

void EMPView::addSubView(EMPView* view){
	child.push_back(view);
}

int EMPView::_getCssStyles ( lua_State* L ) {
	UNUSED ( L );
	
	printf ( "MOAIHtmlMgr singleton foo!\n" );
	
	return 0;
}

int EMPView::_getCssStyleByName ( lua_State* L ) {
	UNUSED ( L );
	
	printf ( "MOAIHtmlMgr singleton foo!\n" );
	
	return 0;
}

void * EMPView::getRealView(){
	return mViewImpl->getRealView();
}


void EMPView::RegisterLuaFuncs ( MOAILuaState& state ) {
	
	luaL_Reg regTable [] = {
		{ "getCssStyles",		_getCssStyles },
		{ "getStyleByName",	    _getCssStyleByName },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}