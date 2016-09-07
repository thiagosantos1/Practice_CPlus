# All of the extra flags we give to the compiler for SFML programs
SFML = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

# build a list of all the cpp files in this directory
SRCS = $(wildcard *.cpp)

# build a list of all the header files in this directory
HDRS = $(wildcard *.h)

# if any of the cpp or h files changes, recompile the program
main : $(SRCS) $(HDRS)
	clang++ -o main $(SRCS) $(SFML)

run : 
	./main

clean :
	rm -f main
