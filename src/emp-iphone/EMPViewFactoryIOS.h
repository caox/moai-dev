//
//  EMPView.h
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#import <Foundation/Foundation.h>

#import <emp-html/headers.h>


class EMPViewFactoryIOS:public EMPViewFactory {
private:
	
public:
	
	//----------------------------------------------------------------//
	EMPViewFactoryIOS			(){};
	~EMPViewFactoryIOS			(){};
	EMPViewImpl* createViewImpl(EMPView*);
	
};


