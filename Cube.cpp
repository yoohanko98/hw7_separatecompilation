//
// Created by Peera on 22/4/2021 AD.
//
#include "Cube.h"
#include "Shape3D.h"
#include "fstream"
using namespace std;
//initiate constructor assigned origin point and side length
//Cube has 12 facets and each facet uses 3 vertices, so then the number of vertices is 3*facetNum
Cube::Cube(double x, double y, double z, float l) : Shape3D(x,y,z), length(l){}
Cube::~Cube(){}
void Cube::createVertices(vector<Shape3D::vertex>& vertices) {
    //determine the 12 vertices' location
    //top
    vertices.push_back(vertex(0, length, length));
    vertices.push_back(vertex(length, 0, length));
    vertices.push_back(vertex(length, length, length));
    vertices.push_back(vertex(length, 0, length));
    vertices.push_back(vertex(0, length, length));
    vertices.push_back(vertex(0, 0, length));

    //bottom
    vertices.push_back(vertex(0, 0, 0));
    vertices.push_back(vertex(length, length, 0));
    vertices.push_back(vertex(length, 0, 0));
    vertices.push_back(vertex(length, length, 0));
    vertices.push_back(vertex(0, 0, 0));
    vertices.push_back(vertex(0, length, 0));

    //front
    vertices.push_back(vertex(0, 0, 0));
    vertices.push_back(vertex(length, 0, length));
    vertices.push_back(vertex(0, 0, length));
    vertices.push_back(vertex(length, 0, length));
    vertices.push_back(vertex(0, 0, 0));
    vertices.push_back(vertex(length, 0, 0));

    //right
    vertices.push_back(vertex(length, 0, length));
    vertices.push_back(vertex(length, length, 0));
    vertices.push_back(vertex(length, length, length));
    vertices.push_back(vertex(length, length, 0));
    vertices.push_back(vertex(length, 0, length));
    vertices.push_back(vertex(length, 0, 0));

            //rear
    vertices.push_back(vertex(length, length, 0));
    vertices.push_back(vertex(0, length, length));
    vertices.push_back(vertex(length, length, length));
    vertices.push_back(vertex(0, length, length));
    vertices.push_back(vertex(length, length, 0));
    vertices.push_back(vertex(0, length, 0));

            //left
    vertices.push_back(vertex(0, 0, 0));
    vertices.push_back(vertex(0, length, length));
    vertices.push_back(vertex(0, length, 0));
    vertices.push_back(vertex(0, length, length));
    vertices.push_back(vertex(0, 0, 0));
    vertices.push_back(vertex(0, 0, length));

    for(vector<Shape3D::vertex>::iterator v = vertices.begin(); v != vertices.end(); ++v){
        v->x = v->x + getX();
        v->y = v->y + getY();
        v->z = v->z + getZ();
    }
}

void Cube::print(string filename) {
    //print stl format
    ofstream f(filename.c_str());
    createVertices(vertices);
    stlCombineFacets(f,vertices);
}




