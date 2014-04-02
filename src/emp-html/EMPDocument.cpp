//
//  EMPDocument.cpp
//  libmoai
//
//  Created by cao xu on 14-4-1.
//
//

#include "EMPDocument.h"
#include <emp-html/EMPButton.h>


void EMPDocument::render(const string& xml, void * rootView){
	printf("the xml: %s", xml.c_str());
	// TODO: parse the xml
	//		 traverse the DOM
	//		 generate the view hierarchy
	
	// sample code for div and label
	EMPView * button = new EMPButton();
	EMPViewImpl * buttonImpl = factory->createViewImpl(button);
	buttonImpl->draw(button, rootView);
	
};


void EMPDocument::RegisterLuaClass ( MOAILuaState& state ) {
	
	luaL_Reg regTable [] = {
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}