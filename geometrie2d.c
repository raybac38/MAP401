#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometrie2d.h"

double Dotproduct(Vector2 a, Vector2 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

Vector2 ScaleVector2(Vector2 a, double b)
{
    Vector2 vect;
    vect.x = a.x *b;
    vect.y = a.y * b;
    return vect;
}

Point2 ScalePoint2(Point2 a, double b)
{
    Point2 pt;
    pt.x = a.x *b;
    pt.y = a.y * b;
    return pt;
}

Point2 SumPoint2(Point2 a, Point2 b)
{
    Point2 pt;
    pt.x = a.x + b.x;
    pt.y = a.y + b.y;
    return pt;
}

Vector2 SumVector2(Vector2 a, Vector2 b)
{
    Vector2 vect;
    vect.x = a.x + b.x;
    vect.y = a.y + b.y;
    return vect;
}

Point2 SubPoint2(Point2 a, Point2 b)
{
    Point2 pt;
    pt.x = a.x - b.x;
    pt.y = a.y - b.y;
    return pt;
}

Vector2 SubVector2(Vector2 a, Vector2 b)
{
    Vector2 vect;
    vect.x = a.x - b.x;
    vect.y = a.y - b.y;
    return vect;
}


Vector2 * InitVector2()
{
    return (Vector2 *)malloc(sizeof(Vector2));
}

double Distance(Point2 a, Point2 b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y -a.y, 2));
}

Vector2 Vector2FromPoint2(Point2 a, Point2 b)
{
    Vector2 vect;
    vect.x = b.x - a.x;
    vect.y = b.y - a.y;
    return vect;
}



/*Create a vector from 2 double*/
Vector2 SetVector2(double x, double y)
{
    Vector2 vect;
    vect.x = x;
    vect.y = y;
    return vect;
}

/*Create a point from 2 double*/
Point2 SetPoint2(double x, double y)
{
    Point2 pt;
    pt.x = x;
    pt.y = y;
    return pt;
}




Point2 * InitPoint2()
{
    return malloc(sizeof(Point2));
}

double Norme(Vector2 a)
{
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

Vector2 Normalize(Vector2 a)
{
    Vector2 vect;
    double norme = Norme(a);
    vect.x = a.x / norme;
    vect.y = a.y / norme;
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

Point2 * MallocPoint2(Point2 a)
{
    Point2 * newpoint = InitPoint2();
    newpoint->x = a.x;
    newpoint->y = a.y;
    return newpoint;
}

Vector2 * MallocVector2(Vector2 a)
{
    Vector2 * newvector = InitVector2();
    newvector->x = a.x;
    newvector->y = a.y;
    return newvector;
}
/*Get value of a Vector2*/
double GetValueVector2(Vector2 a, char coord)
{
    if(coord == 'x')
    {
        return a.x;
    }
    if(coord == 'y')
    {
        return a.y;
    }
    printf(" ...What exactly do you want? There are only two dimensions");
    return 0;
}

/*Get value of a Pointr2*/
double GetValuePoint2(Point2 a, char coord)
{
    if(coord == 'x')
    {
        return a.x;
    }
    if(coord == 'y')
    {
        return a.y;
    }
    printf(" ...What exactly do you want? There are only two dimensions");
    return 0;
}


/*Print Vector2 in the console*/
void ShowVector2(Vector2 a)
{
    printf("Vector (%f, %f)", a.x, a.y);
}

/*Print Point2 in the console*/
void ShowPoint2(Point2  a)
{
    printf("Point (%f, %f)", a.x, a.y);
}


/*is two Point2 equal ?*/
unsigned IsPoint2Equal(Point2 a, Point2 b)
{
    return (a.x == b.x) && (a.y == b.y);
}

/*is two Vector2 equal ?*/
unsigned IsVector2Equal(Vector2 a, Vector2 b)
{
    return (a.x == b.x) && (a.y == b.y);
}

double DistanceSegmentPoint(Point2 a, Point2 b, Point2 c)
{
    Vector2 ab = Vector2FromPoint2(a,b);
    Vector2 ac = Vector2FromPoint2(a,c);

    double distance_ab = Distance(a,b);
    double distance_ac = Distance(a,c);

    if(distance_ab == 0) 
    {
        return distance_ac;
    }

    double dot_product = Dotproduct(ab, ac);

    if(dot_product <= 0)
    {
        /// C' est sur A
        return distance_ac;
    }

    if(dot_product >= distance_ab * distance_ab)
    {
        return Distance(b,c);
    }

    double valeur = dot_product/ (distance_ab * distance_ab);

    Point2 c_prime = SumPoint2(a, Vector2toPoint2(ScaleVector2(ab, valeur)));


    return Distance(c_prime, c); 


        
}

Point2 Point2MiddlePoint2(Point2 a, Point2 b)
{
    return SetPoint2(a.x + b.x / 2 ,  a.y + b.y / 2);
}

Point2 Vector2toPoint2(Vector2 a)
{
    Point2 b;
    b.x = a.x;
    b.y = a.y;
    return b;
}
Vector2 Point2toVector2(Point2 a)
{
    Vector2 b;
    b.x = a.x;
    b.y = a.y;
    return b;
}

double Point2DistanceBezier2(Point2 c0, Point2 c1, Point2 c2, Point2 a, double ti)
{
    /// Calcule du point sur la courbe de bezier

    double alpha = (1 - ti) * (1 - ti);
    double beta = 2 * ti * (1 - ti);
    double gamma = ti * ti;

    Point2 khi = ScalePoint2(c0, alpha);
    Point2 psi = ScalePoint2(c1, beta);
    Point2 omega = ScalePoint2(c2, gamma);

    Point2 point = SumPoint2(khi, psi);
    point = SumPoint2(point, omega);

    return Distance(point, a);
}
