//
//  EMPButton.h
//  libmoai
//
//  Created by cao xu on 14-4-1.
//
//

#ifndef __libmoai__EMPButton__
#define __libmoai__EMPButton__

#include <iostream>
#include <emp-html/EMPView.h>


class EMPButton:public EMPView{
public:
	EMPButton(){printf("init button\n");}
	~EMPButton(){printf("release button\n");}
	static EMPView* CreateInstance(){
		return new EMPButton();
	}
	
private:
	DECLARE_RUNTIME(EMPButton)
};

#endif /* defined(__libmoai__EMPButton__) */
