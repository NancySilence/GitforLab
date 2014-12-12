all:	./src/ICTContentMatch_server.skeleton.cpp
	 g++ -o ContentMatchServer ./src/SentenceSplit.cpp  ./src/SentAndPosition.cpp ./src/ModifyResult.cpp ./src/CompareArticles.cpp ./src/ArticleAnalyze.cpp  ./src/ICTContentMatch.cpp ./src/ict_content_match_server_types.cpp ./src/ict_content_match_server_constants.cpp ./src/Logger.cpp ./src/ICTContentMatch_server.skeleton.cpp -I./include -I./include/thrift -L./lib -lICTTextMining -lthrift -lpthread -pthread -lrt -L./usr/local/lib
clean:
	rm -f *.o 