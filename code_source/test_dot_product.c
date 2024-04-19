#include "geometrie2d.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int main()
{

    printf("Bienvenu au testeur de fonction bugger ! \n");
    printf("Pas de temps a perdre : calculons une distance Segement - Point ! \n");

    printf("Mesure de la distance du segment AB au point C\n");

    double valeurs[6];

    double *pointeur = valeurs;

    printf("Ax = ");
    scanf("%lf", pointeur++);

    printf("Ay = ");
    scanf("%lf", pointeur++);

    printf("Bx = ");
    scanf("%lf", pointeur++);

    printf("By = ");
    scanf("%lf", pointeur++);

    printf("Cx = ");
    scanf("%lf", pointeur++);

    printf("Cy = ");
    scanf("%lf", pointeur++);

    printf("\n Récapitulatif : \nA : %lf, %lf\nB :%lf, %lf\nC :%lf, %lf\n", valeurs[0], valeurs[1], valeurs[2], valeurs[3], valeurs[4], valeurs[5]);

    Point2 a = SetPoint2(valeurs[0], valeurs[1]);
    Point2 b = SetPoint2(valeurs[2], valeurs[3]);
    Point2 c = SetPoint2(valeurs[4], valeurs[5]);

    printf("La distance tant attendu : %lf\n", DistanceSegmentPoint(a, b, c));

    printf("Bonne chance pour le debuggage ^^ \n");
    return 1;
}
