#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector2.h"

double Dotproduct(Vector2 * a, Vector2 * b)
{
    return (a->x * b->x) + (a->y * b->y);
}

Vector2 * ScaleVector2(Vector2 * a, double b)
{
    Vector2 * vect =  InitVector2();
    vect->x = a->x *b;
    vect->y = a->y * b;
    return vect;
}

Point2 * ScalePoint2(Point2 * a, double b)
{
    Point2 * pt =  InitPoint2();
    pt->x = a->x *b;
    pt->y = a->y * b;
    return pt;
}

Point2 * SumPoint2(Point2 *a, Point2 *b)
{
    Point2 *pt = InitPoint2();
    pt->x = a->x + b->x;
    pt->y = a->y + b->y;
    return pt;
}

Vector2 * SumVector2(Vector2 *a, Vector2 *b)
{
    Vector2 *vect = InitVector2();
    vect->x = a->x + b->x;
    vect->y = a->y + b->y;
    return vect;
}
Vector2 * InitVector2()
{
    return malloc(sizeof(Vector2));
}

double Distance(Point2 *a, Point2 *b)
{
    return sqrt(pow(b->x - a->x, 2) + pow(b->y -a->y, 2));
}

Vector2 * Vector2FromPoint2(Point2 * a, Point2*  b)
{
    Vector2 * vect = InitVector2();
    vect->x = b->x - a->x;
    vect->y = b->y - a->y;
    return vect;
}



/*Create a vector from 2 double*/
Vector2 * SetVector2(double x, double y)
{
    Vector2 * vect = InitVector2();
    vect->x = x;
    vect->y = y;
    return vect;
}

/*Create a point from 2 double*/
Point2 * SetPoint2(double x, double y)
{
    Point2 * pt = InitPoint2();
    pt->x = x;
    pt->y = y;
    return pt;
}




Point2 * InitPoint2()
{
    return malloc(sizeof(Point2));
}

double Norme(Vector2 * a)
{
    return sqrt(pow(a->x, 2) + pow(a->y, 2));
}

Vector2 * Normalize(Vector2 *a)
{
    Vector2 * vect = InitVector2();
    double norme = Norme(a);
    vect->x = a->x / norme;
    vect->y = a->y / norme;
    return vect;
}


void FreeVector2(Vector2 ** a)
{
    free(*a);
    *a = NULL;
}
void FreePoint2(Point2 ** a)
{
    free(*a);
    *a = NULL;
}