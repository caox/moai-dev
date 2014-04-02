//
//  EMPView.mm
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#import "EMPViewFactoryIOS.h"
#import "EMPButtonImpl.h"

EMPViewImpl * EMPViewFactoryIOS::createViewImpl(EMPView * view) {
		
	EMPButtonImpl * buttonImpl = new EMPButtonImpl();
	return buttonImpl;
}

