//
// Created by Peera on 29/4/2021 AD.
//
#ifndef MYHOMEWORK_DRAW_H
#define MYHOMEWORK_DRAW_H

#include "Shape3D.h"
#include "fstream"
#include "vector"
using namespace std;

class Drawing {
private:
    //ofstream f;
    vector<Shape3D*> shapes;
public:
    Drawing();
    ~Drawing();
    void add(Shape3D* s);
    void print(string filename);
};
#endif //MYHOMEWORK_DRAW_H
