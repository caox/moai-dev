//
//  EMPButtonImpl.cpp
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#include "EMPButtonImpl.h"


void EMPButtonImpl::draw(EMPView* button, void* parentView){
	mButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    mButton.frame = CGRectMake(221, 81, 54, 30);
    [mButton setTitle:@"前往" forState:UIControlStateNormal];
    [(UIView*) parentView addSubview:mButton];
	button->SetViewImpl(this);
}
