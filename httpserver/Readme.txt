Compile the boost and then link the httpserver to use libboost_system

fernando@hendrix-3570R-370R-470R-450R-510R-4450RV:~/ligadesligaledcpp/httpserver$ g++ -pthread -std=c++11 -o httpserver.o -I ../ligadesligaled/boost mime_types.cpp reply.cpp request_handler.cpp request_parser.cpp connection.cpp connection_manager.cpp server.cpp main.cpp -L../ligadesligaled/boost/bin.v2/libs/system/build/gcc-4.8/release/link-static/threading-multi/ -lboost_system
