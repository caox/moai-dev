//
//  EMPButtonImpl.h
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#ifndef __libmoai__EMPButtonImpl__
#define __libmoai__EMPButtonImpl__

#include <iostream>
#include <emp-html/EMPViewImpl.h>
#include <emp-html/EMPView.h>
#import <UIKit/UIKit.h>

class EMPButtonImpl:public EMPViewImpl{
public:
	void draw(EMPView*, void *);
	~EMPButtonImpl(){};
private:
	UIButton * mButton;
};

#endif /* defined(__libmoai__EMPButtonImpl__) */
