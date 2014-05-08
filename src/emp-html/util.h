//
//  util.h
//  libmoai
//
//  Created by cao xu on 14-5-7.
//
//

#ifndef libmoai_util_h
#define libmoai_util_h
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

typedef hash_map<string, string> attribute_map;

#endif
