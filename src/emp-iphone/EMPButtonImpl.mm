//
//  EMPButtonImpl.cpp
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#include "EMPButtonImpl.h"

EMPButtonImpl::EMPButtonImpl(){
};

EMPButtonImpl::EMPButtonImpl(void* parent){
	mIOSButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    mIOSButton.frame = CGRectMake(221, 81, 54, 30);
    [mIOSButton setTitle:@"前往" forState:UIControlStateNormal];
    [(UIView*) parent addSubview:mIOSButton];
};

void EMPButtonImpl::draw(EMPView* button, void* parentView){
	

}
