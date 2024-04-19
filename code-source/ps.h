#include "tableau.h"

/*
Sortie PS permettant d'écrire une image sous format segment
*/
void PsSimpleSegment(Tableau * contours, Point2 dimention, char * name);

/*
Sortie PS permettant d'écrire une image sous format segment de bezier 2
Convertie automatiquement en degres 3 pour l'écriture fichier
*/
void PsCourbeBezier3(Tableau * contours, Point2 dimention, char * name);

/*
Sortie PS permettant d'écrire une image sous format courbe de bezier de degres 3
*/
void PsCourbeBezier2(Tableau * contours, Point2 dimention, char * name);