CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(ContentMatch)

SET(CMAKE_INSTALL_PREFIX ".")

SET(CMAKE_SOURCE_DIR ".")

SET(CMAKE_BUILD_TYPE "Release")

add_definitions("-g")

IF(UNIX)
  INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/include/
  )
ELSE(WIN32)
  INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/src/
  )
  ADD_DEFINITIONS (/D _CRT_SECURE_NO_WARNINGS /D _CRT_SECURE_NO_DEPRECATE /D STDC_HEADERS)
ENDIF(UNIX)

SET(LIBRARY_OUTPUT_PATH .)

SET(SRC_LIST   src/ContentMatchTest.cpp src/ArticleAnalyze.cpp src/CompareArticles.cpp src/ModifyResult.cpp src/SentAndPosition.cpp src/SentenceSplit.cpp)

IF(UNIX)
  #static set
  SET(EXTRA_LIBS libICTTextMining.a -pthread)

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
ADD_EXECUTABLE(contentmatch ${SRC_LIST})
IF(UNIX)
	TARGET_LINK_LIBRARIES(contentmatch ${EXTRA_LIBS} )
ELSE(WIN32)
	TARGET_LINK_LIBRARIES(contentmatch ${EXTRA_LIBS})
ENDIF(UNIX)


INSTALL(FILES contentmatch DESTINATION ./bin)

