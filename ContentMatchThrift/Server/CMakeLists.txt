cmake_minimum_required(VERSION 0.1)
set(CMAKE_INSTALL_PREFIX ".")
# 设置项目名
PROJECT(ICT_CONTENT_MATCH_SERVER)

# 设置编译器
SET(CMAKE_C_COMPILER g++)

SET(CMAKE_SOURCE_DIR ".")

# 添加头文件包含路径
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include/thrift
                    ${CMAKE_SOURCE_DIR}/include)
# 添加子路径src
ADD_SUBDIRECTORY(src)
SET(SRC_LIST  src/SentenceSplit.cpp src/SentAndPosition.cpp src/ModifyResult.cpp src/ICTContentMatch_server.skeleton.cpp src/ICTContentMatch.cpp src/ict_content_match_server_types.cpp src/ict_content_match_server_constants.cpp src/CompareArticles.cpp src/ArticleAnalyze.cpp )
					
SET(EXTRA_LIBS libICTTextMining.a libthrift.a -pthread -lpthread )
	
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/ /usr/local/lib)
ADD_EXECUTABLE(ContentMatchServer ${SRC_LIST})	
					
TARGET_LINK_LIBRARIES(ContentMatchServer ${EXTRA_LIBS} )

INSTALL(FILES ContentMatchServer DESTINATION ./bin)
