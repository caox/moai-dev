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
#include <list>
#include <moai-core/headers.h>
#include "util.h"
#include "EMPViewFactory.h"
class EMPViewImpl;


/*@定义宏,类通过包含该宏,实现动态创建*/
#define DECLARE_RUNTIME(class_name)\
string class_name##Name;\
static GenDynamic* class_name##gd; \
static EMPView* CreateInstance(){return new class_name();}

/*@宏实现,类通过实现该宏,实现动态创建*/
#define IMPLEMENT_RUNTIME(name, class_name)\
GenDynamic* class_name::class_name##gd\
= new GenDynamic(#name,class_name::CreateInstance);

typedef struct Layout {
	float x;
	float y;
	float width;
	float higth;
} layout;

class EMPView: public MOAIGlobalClass < EMPView, MOAILuaObject > {
	
public:
	
	enum ViewType {
		Container,
		Leaf
	};
	
	
	EMPView(){printf("new emp view\n");}
	EMPView(ViewType t);
	~EMPView(){printf("release emp view\n");}
	void addSubView(EMPView *);
	void * getRealView();
	void setViewType(ViewType);
	void setParent(EMPView *);
	void setLayout(layout);
	void setAttributeMap(attribute_map* m) {map = m;}
	std::list<EMPView *> getChild() const;
	EMPView* getParent() const ;
	EMPView* getFirstChild() const;
	ViewType getViewType() const {return type;}
	layout getLayout() const {return mLayout;}
	void layoutSubView(); // layout subviews
	bool isContainer(){return type == Container;}
	
	DECL_LUA_FACTORY ( EMPView )
	GET(EMPViewImpl*, ViewImpl, mViewImpl)
	SET(EMPViewImpl*, ViewImpl, mViewImpl)
	GET(attribute_map*, AttrMap, map)
	void			RegisterLuaFuncs	( MOAILuaState& state );

	
private:
	
	float x;
	float y;
	float width;
	float higth;
	ViewType type;
	Layout mLayout;
	attribute_map* map;
	std::list<EMPView *> child;
	EMPViewImpl * mViewImpl = NULL;
	
	static int		_getCssStyles		( lua_State* L );
	static int      _getCssStyleByName  ( lua_State* L );
	
};


#endif /* defined(__libmoai__EMPView__) */
