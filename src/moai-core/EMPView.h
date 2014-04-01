//
//  EMPView.h
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#ifndef __libmoai__EMPView__
#define __libmoai__EMPView__

#include <iostream>
#include <vector>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx {
	template<>
	struct hash<string> {
		size_t operator()(const string& s) const {
			return hash<const char*> ()(s.c_str());
		}
	};
}

typedef hash_map<string, string> css_map;

class EMPView{
	
public:
	
	enum ViewType {
		DIV,
		FORM,
		BUTTON,
		LABEL
	};
	
	struct Layout {
		float x;
		float y;
		float width;
		float higth;
	} ;
	
	void addSubView(EMPView *);
	void setLayout(Layout);
	void setViewType(ViewType);
	void setParent(EMPView *);
	std::vector<EMPView *> getChild() const;
	EMPView * getParent() const ;
	ViewType getViewType() const {return type;}
	Layout getLayout() const {return layout;}
	
private:
	float x;
	float y;
	float width;
	float higth;
	ViewType type;
	Layout layout;
	std::vector<EMPView *> child;
	
};

#endif /* defined(__libmoai__EMPView__) */
