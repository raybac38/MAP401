
typedef struct Point_ 
{
    double x, y;
} Point;

typedef struct Vecteur_ 
{
    double x, y;
} Vecteur;

/* Creer et ajouter le point */
Point set_point(double x, double y);

/*Somme de deux points: V3 = (x1+x2,y1+y2), puis insertion du point en question*/
Point add_point(Point P1, Point P2);

/*vecteur correspondant au bipoint*/
Vecteur vect_bipoint(Point A, Point B);

