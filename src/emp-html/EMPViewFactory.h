//
//  EMPViewFactory.h
//  libmoai
//
//  Created by cao xu on 14-4-2.
//
//

#ifndef libmoai_EMPViewFactory_h
#define libmoai_EMPViewFactory_h


#include <emp-html/EMPView.h>
#include <emp-html/EMPViewImpl.h>

class EMPViewFactory{
public:
	virtual EMPViewImpl* createViewImpl(EMPView* )=0;
	
	//----------------------------------------------------------------//
	virtual ~EMPViewFactory(){};

};

#endif
