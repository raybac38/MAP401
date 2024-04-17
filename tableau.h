#ifndef TABLEAU_H
#define TABLEAU_H

#include "geometrie2d.h"

#define DEFAULT_MAX_SIZE 8

typedef enum
{
    TYPE_INT, TYPE_POINT2, TYPE_TABLEAU
} Type;

typedef struct
{
    void * array;
    Type type;
    unsigned size;
    unsigned max;
    unsigned char power;
} Tableau;


/* Initialise un tableau*/
Tableau * InitTableau(Type type, unsigned size);

/*
Ajout d'une valeur a la fin d'un tableau avec detection de débordement
*/
void TableauAppend(Tableau * tab, void * a);

/*
Ajout d'une valeur a la fin du tableau sans detection de débordement
Utilisation non recommander
*/
void TableauAppendUnsafe(Tableau * tab, void * a);

/* Avoir la taille du tableau*/
unsigned TableauGetSize(Tableau * tab);

/* Avoir le type du tableau*/
Type TableauGetType(Tableau * tab);

/* 
Lièbre la mamoire du tableau
*/
void TableauFree(Tableau ** tab);

/* Get point2 element from tab*/
Point2 TableauGetPoint2(Tableau * tab, unsigned index);

/* Get Int element from tab*/
int TableauGetInt(Tableau * tab, unsigned index);

/* Get tableau element from tab*/
Tableau * TableauGetTableau(Tableau * tab, unsigned index);

/* Remove last element of tab*/
void TableauRemove(Tableau * tab);

/* Ecrire le tableau de points dans un fichier .txt*/
void TableauWrite(Tableau * tab,Tableau * start, char * name);


/*
    Approximation d'une serie de point par une courbe de bezier
    Renvoie le point de controle intérmediaire
*/
Point2 ApproxBezier2(Tableau *, unsigned a, unsigned b);

/*
    Somme des points entre A et B exclus
    Renvoie le point de la sommation
*/
Point2 TableauSumPoint2(Tableau *, unsigned a, unsigned b);


#endif


