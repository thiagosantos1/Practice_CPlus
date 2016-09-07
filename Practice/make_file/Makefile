all : practice1 practice2 


practice1 : practice1.cpp globals.h
	clang++ practice1.cpp -o practice1

practice1.1 : practice1.o Foo.o
	clang++ practice1.o Foo.o -o practice1.1

practice1.o : practice1.cpp globals.h Foo.h
	clang++ -c practice1.cpp

Foo.o : Foo.cpp Fooh.h
	clang++ -c Foo.cpp

practice2 : practice2.cpp globals.h
	clang++ practice2.cpp -o practice2


clean :  // if you type make clean, it's gonna clean everything
	rm -f practice1 practice2 *.o
