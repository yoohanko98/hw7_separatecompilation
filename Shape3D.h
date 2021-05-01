//
// Created by Peera on 22/4/2021 AD.
//

#ifndef MYHOMEWORK_SHAPE3D_H
#define MYHOMEWORK_SHAPE3D_H
#include "string"
#include "vector"
#include "fstream"
using namespace std;

class Shape3D {
private:
    double x_t, y_t, z_t;
public:
    //ofstream f;
    struct vertex {
        double x; double y; double z;
        vertex(double x, double y, double z): x(x), y(y), z(z){}
        vertex() {}
    };
    vector<vertex> vertices;
    Shape3D(double x, double y, double z);
    virtual ~Shape3D();
    virtual void print(string filename) = 0;
    virtual void createVertices(vector<vertex>& vertices) = 0;
    friend vertex operator ^(const vertex& a,const vertex& b); //cross product
    friend vertex operator -(const vertex& a, const vertex& b); //minus vector
    void unit(vertex& v); //make unit vector
    void stlFacetOut(ofstream& file,vector<vertex>::const_iterator i, vertex normal); //print each facet
    void stlCombineFacets(ofstream& file, const vector<vertex>& vertices); //combine all facets
    double getX(); double getY(); double getZ();


};
#endif //MYHOMEWORK_SHAPE3D_H
