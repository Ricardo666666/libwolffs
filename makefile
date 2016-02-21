flags = -std=c++11 -Os -Wall -lboost_system -lboost_filesystem

all:
	g++ wolffs.cpp $(flags) -c -fpic
	g++ -shared -o libwolffs.so wolffs.o

install:
	#You'll probably want to run this as root.
	#Tested to work for Arch Linux
	install -m 755 -s libwolffs.so /usr/lib/libwolffs.so
	install -m 755 wolffs.hpp /usr/include/Pr0Wolf29/wolffs.hpp

uninstall:
	rm /usr/lib/libwolffs.so /usr/include/Pr0Wolf29/wolffs.hpp

clean:
	rm *.o *.so

