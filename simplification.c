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









