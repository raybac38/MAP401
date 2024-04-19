#include "geometrie2d.h"
#include "tableau.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Bienvenu dans le programme de test ^^\n");
    unsigned taille = 0;
    do
    {
        printf("Quelle taille voulez vous travailler ? \n");
        scanf("%u", &taille);
        if (taille < 2)
        {
            printf(" trop petit, min : 2\n");
        };

    } while (taille < 2);
    Tableau *tab = InitTableau(TYPE_POINT2, 0);
    double a = 0.0, b = 0.0;
    do
    {
        printf("Point numero %u \n", TableauGetSize(tab));
        scanf("%lf %lf", &a, &b);
        Point2 p = SetPoint2(a, b);
        TableauAppend(tab, &p);
        taille--;

    } while (taille != 0);

    taille = TableauGetSize(tab);
    printf("%u\n", taille);
    Point2 C0 = TableauGetPoint2(tab, 0), C3 = TableauGetPoint2(tab, TableauGetSize(tab) - 1);
    Point2 C1, C2 = SetPoint2(0, 0);

    ApproxBezier3(tab, 0, TableauGetSize(tab) - 1, &C1, &C2);

    printf("Point de controle :");    ShowPoint2(C1);   printf("\n");    ShowPoint2(C2);    printf("\n");

    for (unsigned i = 1; i < taille - 1; i++)
    {
        printf("%lf\n", (double)i / (double)(taille - 1));
        Point2 a = TableauGetPoint2(tab, i);
        double distance = Point2DistanceBezier3(C0, C1, C2, C3, a, (double)i / (double)(taille - 1));
        printf("Distance : %lf\n", distance);
    }
}