//
//  EMPViewImpl.h
//  libmoai
//
//  Created by cao xu on 14-4-1.
//
//

#ifndef __libmoai__EMPViewImpl__
#define __libmoai__EMPViewImpl__

#include <iostream>
#include <emp-html/EMPView.h>


class EMPViewImpl {
public:
	virtual void draw(EMPView *, void *){};
	virtual void * getRealView(){};
	virtual ~EMPViewImpl(){};
};
#endif /* defined(__libmoai__EMPViewImpl__) */
