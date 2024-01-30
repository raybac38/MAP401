

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

/*Copy Point 2*/
Point2 * CopyPoint2(Point2 a);

/*Copy Vector 2*/
Vector2 * CopyVector2(Vector2 a);

/*Create a scaled Vector2*/
Vector2 * ScaleVector2(Vector2 * a, double b);

/*Create a scaled Point2*/
Point2 * ScalePoint2(Point2 * a, double b);

/*creates a vector2 sum of two vector2*/
Vector2 * SumVector2(Vector2 * a, Vector2 * b);

/*creates a Point2 sum of two Point2*/
Point2 * SumPoint2(Point2 *a, Point2 *b);

/*Malloc un Vector2*/
Vector2 * InitVector2(void);

/*Malloc un Point2*/
Point2 * InitPoint2(void);

/*Calculate euclidien norme*/
double Norme(Vector2 * a);

/*Calculate distance between two point*/
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

/*Get value of a Vector2*/
double GetValueVector2(Vector2 * a, char coord);

/*Get value of a Pointr2*/
double GetValuePoint2(Point2 * a, char coord);

/*Print Vector2 in the console*/
void ShowVector2(Vector2 *a);

/*Print Point2 in the console*/
void ShowPoint2(Point2 * a);

