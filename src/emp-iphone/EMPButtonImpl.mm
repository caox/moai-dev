//
//  EMPButtonImpl.cpp
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#include "EMPButtonImpl.h"



@implementation EMPIOSButton
@synthesize button;
@synthesize onClick;

- (id) init{
	button = [UIButton buttonWithType:UIButtonTypeCustom];
	button.frame = CGRectMake(221, 81, 54, 30);
	button.showsTouchWhenHighlighted=YES;
    [button setTitle:@"测试" forState:UIControlStateNormal];
	return self;
}

//- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
//	
//};
//- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event{
//	
//};
//- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event{
//	
//};
//- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event{
//	
//};

- (void)submitAction:(id)sender {
	printf("test action\n");
	if(![self.onClick isEqualToString:(@"")]){
		AKURunString([self.onClick UTF8String]);
	}
}

@end


EMPButtonImpl::EMPButtonImpl(){
};

EMPButtonImpl::EMPButtonImpl(void* parent){
	mButton = [[EMPIOSButton alloc] init];
	mButton.onClick=@"";
    [(UIView*)parent addSubview:mButton.button];
//	BOOL f = [mButton becomeFirstResponder];
};


void EMPButtonImpl::draw(EMPView* button){
	layout l = button->getLayout();
	attribute_map* map =button->GetAttrMap();
	mButton.button.frame = CGRectMake(l.x,l.y,l.width,l.higth);
	attribute_map::iterator pos = map->find("onclick");
	if(pos != map->end()){
		mButton.onClick = [NSString stringWithUTF8String:(pos->second).c_str()];
		[mButton.button addTarget:(mButton) action:@selector(submitAction:) forControlEvents:UIControlEventTouchUpInside];
	}
}

