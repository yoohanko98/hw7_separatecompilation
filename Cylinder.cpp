//
// Created by Peera on 22/4/2021 AD.
//
#include "Cylinder.h"
#include "cmath"
using namespace std;
Cylinder::Cylinder(double x, double y, double z, double r, double h, int f): Shape3D(x,y,z), radius(r), height(h), facets(f) {}
Cylinder::~Cylinder() {}
void Cylinder::createVertices(vector<vertex> &vertices) {

    float incre = (2*M_PI) / facets;

    //construct top and bottom coordinates
    for(float i = 0; i <= 2*M_PI; i+= incre){
        tops.push_back({radius*cos(i), radius*sin(i), height});
        bottoms.push_back({radius*cos(i), radius*sin(i), 0});
    }
    //put together coordinates to form shape
    for(int i = 0; i < facets; i++){
        //top + 2 triangles/side + bottom
        vertices.push_back(tops[i], tops[i+1], {0,0,height},
                           tops[i], bottoms[i], bottoms[i+1],
                           tops[i], bottoms[i+1], top[i+1],
                           bottoms[i], bottoms[i+1], {0,0,0});
    }
    for(vector<vertex>::iterator v = vertices.begin(); v != vertices.end(); ++v){
        v->x += getX();
        v->y += getY();
        v->z += getZ();
    }

}

void Cylinder::print(string filename) {
    //print stl format
    f(filename.c_str());
    createVertices(vertices);
    Shape3D::stlCombineFacets(f,vertices);
}


