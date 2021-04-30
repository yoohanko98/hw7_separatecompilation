//
// Created by Peera on 22/4/2021 AD.
//
#include "Cylinder.h"
#include "cmath"
using namespace std;
Cylinder::Cylinder(double x, double y, double z, double r, double h, int f): Shape3D(x,y,z), radius(r), height(h), facets(f) {}
Cylinder::~Cylinder() {}
void Cylinder::createVertices(vector<Shape3D::vertex> &vertices) {

    float incre = (2*M_PI) / facets;

    //construct top and bottom coordinates
    for(float i = 0; i <= 2*M_PI; i+= incre){
        tops.push_back(vertex(radius*cos(i), radius*sin(i), height));
        bottoms.push_back(vertex(radius*cos(i), radius*sin(i), 0));
    }
    //put together coordinates to form shape
    for(int i = 0; i < facets; i++){
        //top + 2 triangles/side + bottom
        vertices.push_back(tops[i]);
        vertices.push_back(tops[i+1]);
        vertices.push_back(vertex(0,0,height));

        vertices.push_back(tops[i]);
        vertices.push_back(bottoms[i]);
        vertices.push_back(bottoms[i+1]);

        vertices.push_back(tops[i]);
        vertices.push_back(bottoms[i+1]);
        vertices.push_back(tops[i+1]);

        vertices.push_back(bottoms[i]);
        vertices.push_back(bottoms[i+1]);
        vertices.push_back(vertex(0,0,0));
    }
    for(vector<Shape3D::vertex>::iterator v = vertices.begin(); v != vertices.end(); ++v){
        v->x += getX();
        v->y += getY();
        v->z += getZ();
    }

}

void Cylinder::print(string filename) {
    //print stl format
    ofstream f(filename.c_str());
    createVertices(vertices);
    Shape3D::stlCombineFacets(f,vertices);
}


