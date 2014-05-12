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
#include <moai-core/host.h>


@interface EMPIOSButton:UIResponder{
	UIButton* button;
	NSString* onClick;
}

//- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
//- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
//- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
//- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

@property (nonatomic, retain) UIButton *button;
@property (nonatomic, copy) NSString *onClick;
@end

class EMPButtonImpl:public EMPViewImpl{
public:
	
	EMPButtonImpl();
	EMPButtonImpl(void* parent);
	void draw(EMPView*);
	void* getRealView(){return (void*) mButton;}
	~EMPButtonImpl(){};
private:
	EMPIOSButton * mButton;
};



#endif /* defined(__libmoai__EMPButtonImpl__) */
