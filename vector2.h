

typedef struct Vector2
{
    double x;
    double y;
} Vector2;

typedef struct Point2
{
    double x;
    double y;
} Point2;

double Dotproduct(Vector2 * a, Vector2 * b);

Vector2 * ScaleVector2(Vector2 * a, double b);
Point2 * ScalePoint2(Point2 * a, double b);


Vector2 * SumVector2(Vector2 * a, Vector2 * b);
Point2 * SumPoint2(Point2 *a, Point2 *b);

/*Malloc un Vector2*/
Vector2 * InitVector2(void);

/*Malloc un Point2*/
Point2 * InitPoint2(void);

/*Calculate euclidien norme*/
double Norme(Vector2 * a);

double Distance(Point2 *a, Point2 *b);

/*Create a vector of norm 1*/
Vector2 * Normalize(Vector2 * a);

/*Free struc and set it to NULL*/
void FreeVector2(Vector2 ** a);
/*Free struc and set it to NULL*/
void FreePoint2(Point2 ** a);

/*Create a Vector2 from 2 Point2*/
Vector2 * Vector2FromPoint2(Point2 * a, Point2*  b);

/*Create a vector from 2 double*/
Vector2 * SetVector2(double x, double y);

/*Create a point from 2 double*/
Point2 * SetPoint2(double x, double y);

