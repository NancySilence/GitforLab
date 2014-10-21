CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(WebSearch)

SET(CMAKE_INSTALL_PREFIX ".")

SET(CMAKE_SOURCE_DIR ".")

SET(CMAKE_BUILD_TYPE "Release")

add_definitions("-g")

IF(UNIX)
  INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/include/  
	${CMAKE_SOURCE_DIR}/include/json/
  )
ELSE(WIN32)
  INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/src/
  )
  ADD_DEFINITIONS (/D _CRT_SECURE_NO_WARNINGS /D _CRT_SECURE_NO_DEPRECATE /D STDC_HEADERS)
ENDIF(UNIX)

SET(LIBRARY_OUTPUT_PATH .)

SET(SRC_LIST  src/WebSearchTest.cpp src/GetMeta.cpp src/SimiCompare.cpp )

IF(UNIX)
  #static set
  SET(EXTRA_LIBS libgetmeta.a libICTTextMining.a libjson.a -pthread -lgetmeta -lpthread -lidn -lldap -lrt -ljson)

ELSE(WIN32)
	IF(CMAKE_BUILD_TYPE MATCHES "Release")
		MESSAGE(STATUS "Release...")
	  SET(EXTRA_LIBS libmysql )
	ELSE()
		MESSAGE(STATUS "Debug...")
	  SET(EXTRA_LIBS libmysql )
	ENDIF()
ENDIF(UNIX)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/ /usr/local/lib)
ADD_EXECUTABLE(websearch ${SRC_LIST})
IF(UNIX)
	TARGET_LINK_LIBRARIES(websearch ${EXTRA_LIBS} )
ELSE(WIN32)
	TARGET_LINK_LIBRARIES(websearch ${EXTRA_LIBS})
ENDIF(UNIX)


INSTALL(FILES websearch DESTINATION ./bin)

