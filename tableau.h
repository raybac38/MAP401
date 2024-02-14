#ifndef TABLEAU_H
#define TABLEAU_H

#include "geometrie2d.h"

#define DEFAULT_MAX_SIZE 8

typedef struct Tableau
{
    Point2 * array;
    unsigned size;
    unsigned max;
    unsigned char power;
} Tableau;


/* Initialise un tableau*/
Tableau * InitTableau(void);

/* Ajout d'un point a la fin du tableau*/
void TableauAppend(Tableau * tab, Point2 a);

/* Avoir la taille du tableau*/
unsigned TableauGetSize(Tableau * tab);

/* Lièbre la mamoire du tableau*/
void TableauFree(Tableau ** tab);

/* Get point2 element from tab*/
Point2 TableauGetPoint2(Tableau * tab, unsigned index);

/* Remove last element of tab*/
void TableauRemove(Tableau * tab);

#endif


