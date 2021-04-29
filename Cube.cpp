//
// Created by Peera on 22/4/2021 AD.
//
#include "Cube.h"
using namespace std;
//initiate constructor assigned origin point and side length
//Cube has 12 facets and each facet uses 3 vertices, so then the number of vertices is 3*facetNum
Cube::Cube(double x, double y, double z, double l) : Shape3D(x,y,z), length(l){}
Cube::~Cube() noexcept {}
void Cube::createVertices(vector <vertex> &vertices) {
    //determine the 12 vertices' location
    vertices = {
            //upper face
            {0,length,length},
            {length,0,length},
            {length,length,length}
            ,
            {length,0,length},
            {0,length,length},
            {0,0,length},

            //bottom face
            {0,0,0},
            {length,length,0},
            {length,0,0}
            ,
            {length,length,0},
            {0,0,0},
            {0,length,0},

            //front
            {0,0,0},
            {length,0,length},
            {0,0,length}
            ,
            {length,0,length},
            {0,0,0},
            {length,0,0},

            //right
            {length,0,length},
            {length,length,0},
            {length,length,length}
            ,
            {length,length,0},
            {length,0,length},
            {length,0,0},

            //rear
            {length,length,0},
            {0,length,length},
            {length,length,length}
            ,
            {0,length,length},
            {length,length,0},
            {0,length,0},

            //left
            {0,0,0},
            {0,length,length},
            {0,length,0}
            ,
            {0,length,length},
            {0,0,0},
            {0,0,length}

    };
    for(vector<vertex>::iterator v = vertices.begin(); v != vertices.end(); ++v){
        v->x = v->x + x_t;
        v->y = v->y + y_t;
        v->z = v->z + z_t;
    }
}

void Cube::print(string filename) {
    //print stl format
    f(filename.c_str());
    createVertices(vertices);
    Shape3D::stlCombineFacets(f,vertices);
}




