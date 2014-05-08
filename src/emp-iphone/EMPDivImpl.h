//
//  EMPDivImpl.h
//  libmoai
//
//  Created by cao xu on 14-4-9.
//
//

#include <iostream>
#include <emp-html/EMPViewImpl.h>
#include <emp-html/EMPView.h>
#import <UIKit/UIKit.h>

class EMPDivImpl:public EMPViewImpl{
public:
	void draw(EMPView*, void *);
	~EMPDivImpl(){};
private:
	UIView * mIOSView;
};
