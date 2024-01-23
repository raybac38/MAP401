#include <stdio.h>
#include <stdlib.h>
#include "geometrie2d.h"

int main(int argc, char * argv[])
{
    printf("\n---Launch of the geometrie2d test program---\n\n");

    if(argc != 5)
    {
        printf("invalid argument format, try :\n ./test_geometrie2d Ax Ay Bx By\n");

        printf("test vector : \n");

        Vector2 * a = SetVector2(atof(argv[1]), atof(argv[2]));

        printf("creating a vector : A (%d, %d) \n", GetValueVector2(a, 'x'), GetValueVector2(a, 'y'));

        Vector2 * b = SetVector2(atof(argv[3]), atof(argv[4]));

        printf("creating a vector : A (%d, %d) \n", GetValueVector2(b, 'x'), GetValueVector2(b, 'y'));

        printf("Dotproduct of A and B is : %d\n", Dotproduct(a, b));

        printf("Scale vector A by 10 is : ")

    }

}