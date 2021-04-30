//
// Created by Peera on 22/4/2021 AD.
//

#ifndef MYHOMEWORK_CYLINDER_H
#define MYHOMEWORK_CYLINDER_H
#include "Shape3D.h"
#include "fstream"
#include "string"
#include "vector"

class Cylinder : public Shape3D {
private:
    double radius;
    double height;
    int facets;
    vector<vertex> tops;
    vector<vertex> bottoms;
    //ofstream f;
public:
    Cylinder(double x, double y, double z, double r, double h, int f);
    ~Cylinder();
    void print(string filename) override;
    void createVertices(vector<vertex>& vertices) override;
};
#endif //MYHOMEWORK_CYLINDER_H
