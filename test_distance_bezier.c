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

    double a = 0.0 , b = 0.0;

    do
    {
        printf("Point numero %u \n", TableauGetSize(tab));
        scanf("%lf %lf", &a, &b);
        Point2 p = SetPoint2(a, b);
        TableauAppend(tab, &p);
        taille--;

    } while (taille != 0);

    taille = TableauGetSize(tab);

    Point2 C0 = TableauGetPoint2(tab, 0);
    Point2 C2 = TableauGetPoint2(tab, TableauGetSize(tab) - 1);
    Point2 C1 = ApproxBezier2(tab, 0, TableauGetSize(tab) - 1);

    printf("Point de controle :");    ShowPoint2(C1);    printf("\n");

    for (unsigned i = 1; i < taille - 1; i++)
    {
        double distance = Point2DistanceBezier2(C0, C1, C2, TableauGetPoint2(tab, i), (double)i / (double)taille);
        printf("Distance %lf \n", distance);
    }
}