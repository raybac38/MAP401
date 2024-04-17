#include "geometrie2d.h"
#include "tableau.h"
#include <stdio.h>
#include<stdlib.h>


int main(int argc, char * argv[])
{
    Tableau * tab = InitTableau(TYPE_POINT2, 0);

    Point2 a = SetPoint2(0, 0);
    Point2 b = SetPoint2(1, 0);
    Point2 c = SetPoint2(1, 1);
    Point2 d = SetPoint2(1, 2);
    Point2 e = SetPoint2(2, 2);
    Point2 f = SetPoint2(3, 2);
    Point2 g = SetPoint2(3, 3);
    Point2 h = SetPoint2(4, 3);
    Point2 i = SetPoint2(5, 3);

    TableauAppend(tab, &a);
    TableauAppend(tab, &b);
    TableauAppend(tab, &c);
    TableauAppend(tab, &d);
    TableauAppend(tab, &e);
    TableauAppend(tab, &f);
    TableauAppend(tab, &g);
    TableauAppend(tab, &h);
    TableauAppend(tab, &i);

    Point2 C0 = a;
    Point2 C2 = i;
    Point2 C1 = ApproxBezier2(tab, 0, TableauGetSize(tab) - 1);

    ShowPoint2(C1);

    for (unsigned i = 1; i < TableauGetSize(tab) - 1; i++)
    {
        double distance = Point2DistanceBezier2(C0, C1, C2, TableauGetPoint2(tab, i), (double)i/8.0);
        printf("Distance %lf \n", distance);
    }

}