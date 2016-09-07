practice1.1 : practice1.o Foo.o
	clang++ practice1.o Foo.o -o practice1.1

practice1.o : practice1.cpp globals.h Foo.h
	clang++ -c practice1.cpp

Foo.o : Foo.cpp Fooh.h
	clang++ -c Foo.cpp

It's means, when you have multiple class, that you have to compile all .cpp to then make the final execute, we have to run 1 by one, but now with clang++ -c, that create the computer language code. Then, we have to linking them, that is making in the first line


all : practice1 practice2 

This line have to be the first, because always when we type just make, it takes the first target in the make file, so then we create a false target to make all the files then