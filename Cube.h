//
// Created by Peera on 22/4/2021 AD.
//

#ifndef MYHOMEWORK_CUBE_H
#define MYHOMEWORK_CUBE_H
#include "Shape3D.h"
#include "string"
#include "fstream"
#include "vector"

class Cube : public Shape3D {
private:
    double length;
    //ofstream f;
public:
    Cube(double x, double y, double z, double l);
    ~Cube();
    void print(string filename) override;
    //determine the location of each vertex
    void createVertices(vector<vertex>& vertices) override;
};
#endif //MYHOMEWORK_CUBE_H
