SFML = -lsfml-graphics -lsfml-window -lsfml-system

main: main.o Shape.o ShapeManager.o
	clang++ main.o Shape.o ShapeManager.o -o main $(SFML)

main.o: main.cpp Shape.h ShapeManager.h
	clang++ -c main.cpp

Shape.o: Shape.cpp Shape.h
	clang++ -c Shape.cpp

ShapeManager.o: ShapeManager.cpp ShapeManager.h
	clang++ -c ShapeManager.cpp

clean:
	rm -f main *.o
