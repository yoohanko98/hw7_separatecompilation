
OBJ := main.o Cube.o Cylinder.o Drawing.o

draw3D: $(OBJ)
	g++ -g $(OBJ) -o draw3D

main.o: main.cc Cube.h Cylinder.h Shape3D.h Drawing.h
	g++ -g -c main.cc

Cube.o: Cube.cc Cube.h Shape3D.h
	g++ -g -c Cube.cc

Cylinder.o: Cylinder.cc Cylinder.h Shape3D.h
	g++ -g -c Cylinder.cc

Drawing.o: Drawing.cpp Drawing.h Shape3D.h
	g++ -g -c Drawing.cpp

clean:
	rm *.o draw3D