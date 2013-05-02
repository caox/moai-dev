cmake_minimum_required ( VERSION 2.8.5 )

project ( third-party )

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -DNDEBUG -DHAVE_MEMMOVE -DFT2_BUILD_LIBRARY" )

set ( CMAKE_CURRENT_SOURCE_DIR "${ROOT_DIR}../../../3rdparty" )

add_subdirectory ( box2d )
add_subdirectory ( chipmunk )
add_subdirectory ( contrib )
add_subdirectory ( crypto )
add_subdirectory ( curl )
add_subdirectory ( expat )
add_subdirectory ( freetype )
add_subdirectory ( jansson )
add_subdirectory ( jpg )
add_subdirectory ( lua )
add_subdirectory ( luaext )
add_subdirectory ( mongoose )
add_subdirectory ( ogg )
add_subdirectory ( png )
add_subdirectory ( sfmt )
add_subdirectory ( sqlite3 )
add_subdirectory ( ssl )
add_subdirectory ( tinyxml )
add_subdirectory ( tlsf )
add_subdirectory ( vorbis )
add_subdirectory ( zlib )
add_subdirectory ( glew )

set ( THIRD_PARTY_INCLUDES 
  
  ${BOX2D_INCLUDES}
  ${CHIPMUNK_INCLUDES}
  ${CRYPTO_INCLUDES}
  ${CURL_INCLUDES}
  ${EXPAT_INCLUDES}
  ${FREETYPE_INCLUDES}
  ${JANSSON_INCLUDES}
  ${LUAEXT_INCLUDES}
  ${MONGOOSE_INCLUDES}
  ${OGG_INCLUDES}
  ${SQLITE3_INCLUDES}
  ${TINYXML_INCLUDES}
  ${VORBIS_INCLUDES}
  ${ZLIB_INCLUDES}
  ${GLEW_INCLUDES}
  
CACHE INTERNAL "doc string" )

include_directories ( 
  ${THIRD_PARTY_INCLUDES}
)

add_library ( third-party STATIC 
  ${BOX2D_SOURCES}
  ${CHIPMUNK_SOURCES}
  ${CONTRIB_SOURCES}
  ${CRYPTO_SOURCES}
  ${CURL_SOURCES}
  ${EXPAT_SOURCES}
  ${FREETYPE_SOURCES}
  ${JANSSON_SOURCES}
  ${JPG_SOURCES}
  ${LUA_SOURCES} 
  ${LUAEXT_SOURCES}
  ${MONGOOSE_SOURCES} 
  ${OGG_SOURCES} 
  ${PNG_SOURCES} 
  ${SFMT_SOURCES}
  ${SQLITE3_SOURCES} 
  ${TINYXML_SOURCES}
  ${TLSF_SOURCES}
  ${VORBIS_SOURCES}
  ${ZLIB_SOURCES}
  ${GLEW_SOURCES}
)