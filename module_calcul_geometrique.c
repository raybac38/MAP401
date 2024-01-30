#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "module_calcul_geometrique.h"

Point set_point(double x, double y) {
    Point P = {x, y};
    return P;
}

Point add_point(Point P1, Point P2) {
    return set_point(P1.x+P2.x,P1.y+P2.y);
};

Vecteur vect_bipoint(Point A, Point B) {
    Vecteur V = {B.x-A.x,B.y-A.x};
    return V;
}


