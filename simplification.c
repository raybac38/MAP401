#include "simplification.h"

void Recursif_Douglas_Peucker(Tableau * contour, Tableau * contour_simplifier, unsigned index_a, unsigned index_b, double distance_seuil);

Tableau * Simplification_Segment(Tableau * liste_contours, double distance_seuil)
{
    Tableau * liste_contours_simplifier = InitTableau(TYPE_TABLEAU, 0);
    unsigned nombre_contour = TableauGetSize(liste_contours);

    for (unsigned index_contour = 0; index_contour < nombre_contour; index_contour++)
    {

        Tableau * contour_simplifiers = InitTableau(TYPE_POINT2, 0); // Initialisation a une taille standard
        Tableau * contour =  TableauGetTableau(liste_contours, index_contour);
        
        unsigned last_element_index = TableauGetSize(contour) - 1;


        Recursif_Douglas_Peucker(contour, contour_simplifiers, 0, last_element_index, distance_seuil);

        if(TableauGetSize(contour_simplifiers) == 1)
        { 
            TableauFree(&contour_simplifiers);
            continue;    
        }
        
        Point2 point = TableauGetPoint2(contour_simplifiers, 0);
        TableauAppend(contour_simplifiers, &point);


        TableauAppend(liste_contours_simplifier , contour_simplifiers);   


    }
    return liste_contours_simplifier;
}



//// Amélioration possible dans l'algorythme de Douglas Peucker pour enviter une redondance des appelles RAM 
////    Faire en sorte que les valeurs n'ayant pas de changement ne soit pas réappelé

void Recursif_Douglas_Peucker(Tableau * contour, Tableau * contour_simplifier, unsigned index_a, unsigned index_b, double distance_seuil)
{
    Point2 point_a = TableauGetPoint2(contour ,index_a);
    Point2 point_b = TableauGetPoint2(contour ,index_b);
    Point2 point_c;
    unsigned index_distance_max;

    double distance_max = 0;

    unsigned index_point_c = index_a;

    while(index_point_c != index_b)
    {
        index_point_c ++;
        point_c = TableauGetPoint2(contour, index_point_c);

        double distance = DistanceSegmentPoint(point_a, point_b, point_c);
        if(distance > distance_max)
        {
            distance_max = distance;
            index_distance_max = index_point_c;
        }
    }

    if(distance_max <= distance_seuil)
    {
        // Dépassement de la distance seuil
        TableauAppend(contour_simplifier, &point_a);

    }
    else
    {
        Recursif_Douglas_Peucker(contour, contour_simplifier, index_a, index_distance_max, distance_seuil);
        Recursif_Douglas_Peucker(contour, contour_simplifier, index_distance_max, index_b, distance_seuil);
    }
}

void Recursif_Douglas_Peucker_bezier2(Tableau * contour, Tableau * contour_simplifier, unsigned index_c0, unsigned index_c2, double distance_seuil);
void Recursif_Douglas_Peucker_bezier3(Tableau * contour, Tableau * contour_simplifier, unsigned index_c0, unsigned index_c3, double distance_seuil);



Tableau * Simplification_Bezier2(Tableau * liste_contours, double distance_seuil)
{
    Tableau * liste_contours_simplifier = InitTableau(TYPE_TABLEAU, 0);
    unsigned nombre_contour = TableauGetSize(liste_contours);

    for (unsigned index_contour = 0; index_contour < nombre_contour; index_contour++)
    {

        Tableau * contour_simplifiers = InitTableau(TYPE_POINT2, 0); // Initialisation a une taille standard
        Tableau * contour =  TableauGetTableau(liste_contours, index_contour);
        
        unsigned last_element_index = TableauGetSize(contour) - 1;


        Recursif_Douglas_Peucker_bezier2(contour, contour_simplifiers, 0, last_element_index, distance_seuil);
        
        if(TableauGetSize(contour_simplifiers) == 2)
        { 
            TableauFree(&contour_simplifiers);
            continue;    
        }

        Point2 point = TableauGetPoint2(contour_simplifiers, 0);

        
        TableauAppend(contour_simplifiers, &point);

        TableauAppend(liste_contours_simplifier , contour_simplifiers);   

    }
    return liste_contours_simplifier;
}

void Recursif_Douglas_Peucker_bezier3(Tableau * contour, Tableau * contour_simplifier, unsigned index_c0, unsigned index_c3, double distance_seuil)
{
    unsigned delta = index_c3 - index_c0;

    Point2 c0 = TableauGetPoint2(contour ,index_c0);
    Point2 c3 = TableauGetPoint2(contour ,index_c3);
    Point2 c1, c2 = SetPoint2(0, 0);
    ApproxBezier3(contour, index_c0, index_c3, &c1, &c2);

    unsigned index_distance_max;
    double distance_max = 0;

    for (unsigned j = index_c0 + 1; j < index_c3; j++)
    {
        unsigned i = j - index_c0;
        double ti = (double)i / (double)delta;
        double distance = Point2DistanceBezier3(c0, c1, c2, c3, TableauGetPoint2(contour, j), ti);

        if(distance > distance_max)
        {
            distance_max = distance;
            index_distance_max = j;
        }
    }

    if(distance_max <= distance_seuil)
    {
        // Dépassement de la distance seuil

        TableauAppend(contour_simplifier, &c0);
        TableauAppend(contour_simplifier, &c1);
        TableauAppend(contour_simplifier, &c2);

    }
    else
    {
        Recursif_Douglas_Peucker_bezier3(contour, contour_simplifier, index_c0, index_distance_max, distance_seuil);
        Recursif_Douglas_Peucker_bezier3(contour, contour_simplifier, index_distance_max, index_c3, distance_seuil);
    }
}




void Recursif_Douglas_Peucker_bezier2(Tableau * contour, Tableau * contour_simplifier, unsigned index_c0, unsigned index_c2, double distance_seuil)
{
    unsigned delta = index_c2 - index_c0;

    Point2 c0 = TableauGetPoint2(contour ,index_c0);
    Point2 c2 = TableauGetPoint2(contour ,index_c2);
    Point2 c1 = ApproxBezier2(contour, index_c0, index_c2);

    unsigned index_distance_max;
    double distance_max = 0;

    for (unsigned j = index_c0 + 1; j < index_c2; j++)
    {
        unsigned i = j - index_c0;
        double ti = (double)i / (double)(delta);
        double distance = Point2DistanceBezier2(c0, c1, c2, TableauGetPoint2(contour, j), ti);

        if(distance > distance_max)
        {
            distance_max = distance;
            index_distance_max = j;
        }
    }

    if(distance_max <= distance_seuil)
    {
        // Dépassement de la distance seuil

        TableauAppend(contour_simplifier, &c0);
        TableauAppend(contour_simplifier, &c1);

    }
    else
    {
        Recursif_Douglas_Peucker_bezier2(contour, contour_simplifier, index_c0, index_distance_max, distance_seuil);
        Recursif_Douglas_Peucker_bezier2(contour, contour_simplifier, index_distance_max, index_c2, distance_seuil);
    }
}






Tableau * Simplification_Bezier3(Tableau * liste_contours, double distance_seuil)
{
    Tableau * liste_contours_simplifier = InitTableau(TYPE_TABLEAU, 0);
    unsigned nombre_contour = TableauGetSize(liste_contours);

    for (unsigned index_contour = 0; index_contour < nombre_contour; index_contour++)
    {

        Tableau * contour_simplifiers = InitTableau(TYPE_POINT2, 0); // Initialisation a une taille standard
        Tableau * contour =  TableauGetTableau(liste_contours, index_contour);
        
        unsigned last_element_index = TableauGetSize(contour) - 1;


        Recursif_Douglas_Peucker_bezier3(contour, contour_simplifiers, 0, last_element_index, distance_seuil);
        
        if(TableauGetSize(contour_simplifiers) == 2 || TableauGetSize(contour_simplifiers) == 3)
        { 
            TableauFree(&contour_simplifiers);
            continue;    
        }

        Point2 point = TableauGetPoint2(contour_simplifiers, 0);

        
        TableauAppend(contour_simplifiers, &point);

        TableauAppend(liste_contours_simplifier , contour_simplifiers);   

    }
    return liste_contours_simplifier;
}







