#Meu primeiro Makefile
 
alvoprincipal: createTmpObj createLib createObj
	echo "Compilando objeto"

createTmpObj:
	[ -d tmpObj ] || mkdir tmpObj
	g++-4.8 -pthread -std=c++11 -c -I ../boost/boost_1_61_0 mime_types.cpp reply.cpp request_handler.cpp request_parser.cpp connection.cpp connection_manager.cpp server.cpp -L../boost/boost_1_61_0/bin.v2/libs/system/build/gcc-4.6/release/link-static/threading-multi -lboost_system
 
createLib:
	mv *.o tmpObj
	ar rcs tmpObj/libhttpserver.a tmpObj/*.o
 
createObj:
	g++-4.8 -pthread -std=c++11 -o httpserver -I ../boost/boost_1_61_0  main.cpp -LtmpObj -L../boost/boost_1_61_0/bin.v2/libs/system/build/gcc-4.6/release/link-static/threading-multi -lboost_system -lhttpserver

clean:
	rm -rf tmpObj 
	rm *.o
