//
//  host.cpp
//  libmoai
//
//  Created by cao xu on 14-4-9.
//
//

#include "host.h"
#include <emp-html/headers.h>
#include <moai-core/headers.h>
#include <emp-iphone/EMPHtmlIOS.h>

static bool sIsInitialized = false;

//----------------------------------------------------------------//
void AKUFinalizeEMPHtml () {
	
	if ( !sIsInitialized ) return;
	//TODO destruction
	// add this function call to MoaiView
	sIsInitialized = false;
}

//----------------------------------------------------------------//
void AKUInitializeEMPHtml () {
	
	if ( !sIsInitialized ) {
		sIsInitialized = true;
	}
	
	
	
	EMPHtmlIOS::Affirm();
	EMPDocument::Affirm().SetFactory(EMPHtmlIOS::Get().GetFactory());
	
	REGISTER_LUA_CLASS ( EMPHtmlIOS )
    REGISTER_LUA_CLASS ( EMPDocument )
}