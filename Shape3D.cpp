//
// Created by Peera on 22/4/2021 AD.
//
#include "Shape3D.h"

Shape3D::Shape3D(double x, double y, double z): x_t(x), y_t(y), z_t(z) {}
Shape3D::~Shape3D() {}
friend vertex operator ^(const vertex& a,const vertex& b){
    vertex result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;

}
friend vertex operator -(const vertex& a, const vertex& b){
    // Subtraction.
    vertex result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}
void Shape3D::unit(vertex &v) {
    // Normalize a vector.
    float vmod = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
    vmod = sqrt(vmod);

    if (vmod > (float)1.0e-9) {
        v.x /= vmod;
        v.y /= vmod;
        v.z /= vmod;
    }
}

void Shape3D::stlFacetOut(ofstream &file, vector<vertex>::const_iterator v, vertex normal) {
    file << "facet normal " << normal.x << " " << normal.y << " " << normal.z << '\n';
    file << "   outer loop" << '\n';
    file << "       vertex " << v[0].x << " " << v[0].y << " " << v[0].z << '\n';
    file << "       vertex " << v[1].x << " " << v[1].y << " " << v[1].z << '\n';
    file << "       vertex " << v[2].x << " " << v[2].y << " " << v[2].z << '\n';
    file << "   end loop" << '\n';
    file << "endfacet" << '\n';
}

void Shape3D::stlCombineFacets(ofstream& file, const vector<vertex>& vertices) {
    //compute normal vector for each iteration
    vertex normal;
    file << "solid OpenSCAD_Model" << '\n';
    for(vector<vertex>::iterator i = vertices.begin(); i != vertices.end(); i+=3){
        normal = (i[1] - i[0]) ^ (i[2] - i[0]);
        unit(normal);

        stlFacetOut(file,i,normal);
    }
    file << "endsolid OpenSCAD_Model";
}
