//
// Created by Peera on 29/4/2021 AD.
//
#include "Drawing.h"
using namespace std;

Drawing::Drawing() {}
Drawing::~Drawing() {
    for(int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
}
void Drawing::add(Shape3D *s) {
    shapes.push_back(s);
}
void Drawing::print(string filename) {
    for(int i = 0; i < shapes.size(); i++){
        shapes[i]->print(filename);
    }
}
