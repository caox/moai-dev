//
//  EMPView.mm
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#import "EMPViewFactoryIOS.h"
#import "EMPButtonImpl.h"

EMPViewImpl * EMPViewFactoryIOS::createViewImpl(const char* tag, void* host_arg) {
		
	EMPButtonImpl * buttonImpl = new EMPButtonImpl(host_arg);
	return buttonImpl;
}

