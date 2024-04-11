#include "simplification_segment.h"

void Recursif_Douglas_Peucker(Tableau * contour, UIntArray * index_contour_simplifier, unsigned index_a, unsigned index_b, double distance_seuil);

Liste * Simplification_Segment(Liste * liste_contours, double distance_seuil)
{
    Liste * liste_contours_simplifier = ListeInit();
    unsigned nombre_contour = ListeSize(liste_contours);

    for (unsigned index_contour = 0; index_contour < nombre_contour; index_contour++)
    {

        UIntArray * index_contour_simplifier = UIntArrayInitStandard(); // Initialisation a une taille standard

        Tableau * contour =  ListeGet(liste_contours, index_contour);
        
        unsigned last_element_index = TableauGetSize(contour) - 1;


        Recursif_Douglas_Peucker(contour, index_contour_simplifier, 0, last_element_index, distance_seuil);
        UIntArrayAddSafe(index_contour_simplifier, 0);

        ListeAppend(liste_contours_simplifier ,contour_simplifier);   


    }
    return liste_contours_simplifier;
}



//// Amélioration possible dans l'algorythme de Douglas Peucker pour enviter une redondance des appelles RAM 
////    Faire en sorte que les valeurs n'ayant pas de changement ne soit pas réappelé

void Recursif_Douglas_Peucker(Tableau * contour, UIntArray * index_contour_simplifier, unsigned index_a, unsigned index_b, double distance_seuil)
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
        ShowPoint2(point_a);
        UIntArrayAddSafe(index_contour_simplifier, index_a);

    }
    else
    {
        Recursif_Douglas_Peucker(contour, index_contour_simplifier, index_a, index_distance_max, distance_seuil);
        Recursif_Douglas_Peucker(contour, index_contour_simplifier, index_distance_max, index_b, distance_seuil);
    }
}









