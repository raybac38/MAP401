#include "multi_contour.h"

/*
Simplification d'un coutour pas une Serie de segment en fonction d'une distance seuil
*/
Tableau * Simplification_Segment(Tableau * liste_contours, double distance_seuil);

/*
Simplification d'un coutour par une Serie de Courbe de bezier de degres 2 en fonction d'une distance seuil
*/
Tableau * Simplification_Bezier2(Tableau * liste_contours, double distance_seuil);