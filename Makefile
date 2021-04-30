
OBJ := main.o Cube.o Cylinder.o Shape3D.o Drawing.o

draw3D: $(OBJ)
	g++ -g $(OBJ) -o draw3D

main.o: main.cc Cube.h Cylinder.h Shape3D.h Drawing.h
	g++ -g -c main.cc

Cube.o: Cube.cpp Cube.h Shape3D.h
	g++ -g -c Cube.cpp

Cylinder.o: Cylinder.cpp Cylinder.h Shape3D.h
	g++ -g -c Cylinder.cpp

Drawing.o: Drawing.cpp Drawing.h Shape3D.h
	g++ -g -c Drawing.cpp

Shape3D.o: Shape3D.cpp Shape3D.h
	g++ -g -c Shape3D.cpp
clean:
	rm *.o draw3D