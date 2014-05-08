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

	DECLARE_RUNTIME(EMPButton)
};

//IMPLEMENT_RUNTIME(button, EMPButton)

#endif /* defined(__libmoai__EMPButton__) */
