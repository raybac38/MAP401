#include <stdio.h>
#include <stdlib.h>
#include "geometrie2d.h"

int main(int argc, char *argv[])
{
    printf("\n---Launch of the geometrie2d test program---\n\n");

    if (argc != 5)
    {
        printf("invalid argument format, try :\n ./test_geometrie2d Ax Ay Bx By\n");
    }
    printf("test vector : \n\n");

    Vector2 *temp = NULL;

    Vector2 *a = SetVector2(atof(argv[1]), atof(argv[2]));

    printf("Create a vector A \n");
    ShowVector2(a);
    printf("\n\n");
    

    Vector2 *b = SetVector2(atof(argv[3]), atof(argv[4]));

    printf("Create a vector B \n");
    ShowVector2(b);
    printf("\n\n");

    printf("Dotproduct of A and B is : \n%f \n\n", Dotproduct(a, b));

    /////////////

    printf("Scale 10 time vector A : \n");
    temp = ScaleVector2(a, 10);
    ShowVector2(a);
    printf("\n\n");

    FreeVector2(&temp);

    ///////////

    printf("Sum of A and B :\n");
    temp = SumVector2(a, b);
    ShowVector2(temp);
    printf("\n\n");

    FreeVector2(&temp);

    ///////////

    printf("Norme of A : \n");
    printf("%f \n\n", Norme(a));

    ///////////

    printf("Normalized A : \n");
    temp = Normalize(a);
    ShowVector2(temp);
    printf("\n\n");

    FreeVector2(&temp);

    ///////////

    printf("X value of vector A : \n");
    printf("%f \n\n", GetValueVector2(a, 'x'));
    printf("Y value of vector A : \n");
    printf("%f \n", GetValueVector2(a, 'y'));

    printf("\n\n");

    FreeVector2(&a);
    FreeVector2(&b);

    printf("test point : \n\n");

    Point2 * ap = SetPoint2(atof(argv[1]), atof(argv[2]));
    Point2 * bp = SetPoint2(atof(argv[3]), atof(argv[4]));
    Point2 * temp2 = NULL;

    printf("create 2 point, A and B \n");
    ShowPoint2(ap);
    printf("\n");
    ShowPoint2(bp);
    printf("\n\n");

    //////////

    printf("A scale 10 time : \n");

    temp2 = ScalePoint2(ap, 10);
    ShowPoint2(temp2);
    printf("\n\n");

    FreePoint2(&temp2);

    ////////////
    
    printf("Sum of A and B : \n");

    temp2 = SumPoint2(ap, bp);
    ShowPoint2(temp2);
    printf("\n\n");

    FreePoint2(&temp2);
    
    /////////

    printf("Distance between A and B :\n%f \n\n", Distance(ap,bp));

    /////////

    printf("Vector AB : \n");
    temp = Vector2FromPoint2(ap,bp);
    ShowVector2(temp);
    printf("\n\n");

    FreeVector2(&temp);

    printf("Vector BA : \n");
    temp = Vector2FromPoint2(bp,ap);
    ShowVector2(temp);
    printf("\n\n");

    FreeVector2(&temp);

    ///////////////

    
    printf("X value of point A : \n");
    printf("%f \n\n", GetValuePoint2(ap, 'x'));
    printf("Y value of point A : \n");
    printf("%f \n", GetValuePoint2(ap, 'y'));

    printf("\n---End---\n");

    FreePoint2(&ap);
    FreePoint2(&bp);


}