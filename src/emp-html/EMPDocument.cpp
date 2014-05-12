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

EMPView* EMPDocument::currentDoc = NULL;

void EMPDocument::render(const string& xml, void* host_arg){
	printf("the xml: %s", xml.c_str());
	// TODO:
	// if current_doc != NULL release current_doc
	EMPView * docView = factory-> createViewHierarchy(xml.c_str(), host_arg);
	docView->layoutSubView();
	currentDoc =  docView;
	
};


int EMPDocument::_setElementLayout(lua_State* L ){
	MOAILuaState state ( L );
	
	float x = state.GetValue < float >( 2, 100.0f );
	float y = state.GetValue < float >( 3, 100.0f );
	float width = state.GetValue < float >( 4, 30.0f );
	float higth = state.GetValue < float >( 5, 30.0f );
	
	layout l = {x,y,width,higth};
	EMPView* view = currentDoc->getFirstChild();
	view->setLayout(l);
	return 0;
}

void EMPDocument::RegisterLuaClass ( MOAILuaState& state ) {
	
	luaL_Reg regTable [] = {
		{ "reset",		_setElementLayout },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}