all:
	g++ wolffs.cpp -std=c++11 -Os -Wall -c -fpic
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

