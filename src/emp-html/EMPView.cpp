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
	if(NULL!= view)
	child.push_back(view);
}

void EMPView::layoutSubView(){
	list<EMPView*>::iterator iter;
	layout init = {80, 80, 50, 30};
	for(iter=child.begin(); iter!= child.end(); ++iter){
		EMPView* view = (*iter);
		view->setLayout(init);
	}
}

void EMPView::setLayout(layout l) {
	mLayout = l;
	mViewImpl->draw(this);
}

EMPView*  EMPView::getFirstChild() const{
	return child.front();
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