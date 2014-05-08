//
//  EMPView.h
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#import <Foundation/Foundation.h>

#import <emp-html/headers.h>


class EMPViewFactoryIOS:public virtual EMPViewFactory {
private:
	
public:
	
	//----------------------------------------------------------------//
	EMPViewFactoryIOS			(){};
	~EMPViewFactoryIOS			(){};
	EMPViewImpl* createViewImpl(const char* tag, void* host_arg);
	
};


