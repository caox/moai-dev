//
//  EMPView.h
//  libmoai
//
//  Created by cao xu on 14-3-30.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <moai-core/headers.h>


class EMPViewFactoryIOS :public MOAIGlobalClass < EMPViewFactoryIOS, MOAILuaObject > {
private:
	
	//----------------------------------------------------------------//
	static int test(lua_State* L );
public:
	
	DECL_LUA_SINGLETON ( EMPViewFactoryIOS )
	
	//----------------------------------------------------------------//
	EMPViewFactoryIOS			();
	~EMPViewFactoryIOS			();
	void			RegisterLuaClass	( MOAILuaState& state );
	static void renderView(const EMPView&);
	
};


