//
// Created by Peera on 22/4/2021 AD.
//
#include "Shape3D.h"
#include "cmath"
#include "fstream"
Shape3D::Shape3D(double x, double y, double z): x_t(x), y_t(y), z_t(z) {}
Shape3D::~Shape3D() {}
double Shape3D::getX() {return x_t;}
double Shape3D::getY() {return y_t;}
double Shape3D::getZ() {return z_t;}
Shape3D::vertex operator ^(const Shape3D::vertex& a,const Shape3D::vertex& b){
    Shape3D::vertex result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;

}
Shape3D::vertex operator -(const Shape3D::vertex& a, const Shape3D::vertex& b){
    // Subtraction.
    Shape3D::vertex result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}
void Shape3D::unit(Shape3D::vertex &v) {
    // Normalize a vector.
    float vmod = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
    vmod = sqrt(vmod);

    if (vmod > (float)1.0e-9) {
        v.x /= vmod;
        v.y /= vmod;
        v.z /= vmod;
    }
}

void Shape3D::stlFacetOut(ofstream &file, vector<vertex>::const_iterator i, Shape3D::vertex normal) {
    file << "  facet normal " << normal.x << " " << normal.y << " " << normal.z << '\n';
    file << "     outer loop" << '\n';
    file << "         vertex " << i->x << " " << i->y << " " << i->z << '\n';
    file << "         vertex " << (i+1)->x << " " << (i+1)->y << " " << (i+1)->z << '\n';
    file << "         vertex " << (i+2)->x << " " << (i+2)->y << " " << (i+2)->z << '\n';
    file << "     endloop" << '\n';
    file << "  endfacet" << '\n';
}

void Shape3D::stlCombineFacets(ofstream& file, const vector<vertex>& vertices) {
    //compute normal vector for each iteration
    vertex normal;
    file << "solid OpenSCAD_Model" << '\n';
    for(vector<vertex>::const_iterator v = vertices.begin(); v != vertices.end(); v+=3){
        normal = (*(v+1) - *v) ^ (*(v+2) - *v);
        unit(normal);

        stlFacetOut(file,v,normal);
    }
    file << "endsolid OpenSCAD_Model";
}
