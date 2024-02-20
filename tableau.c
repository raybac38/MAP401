#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tableau.h"


void TableauIncreaseSize(Tableau * tab);

/* Initialise un tableau*/
Tableau * InitTableau()
{
    Tableau * tab = (Tableau *)malloc(sizeof(Tableau));
    unsigned int size = (unsigned int)pow(2, DEFAULT_MAX_SIZE);
    tab->power = (unsigned char)DEFAULT_MAX_SIZE;
    tab->max = size - 1;
    tab->size = 0;
    tab->array = (Point2 *)malloc(sizeof(Point2) * size);
    return tab;
}

/* Ajout d'un point a la fin du tableau*/
void TableauAppend(Tableau * tab, Point2 a)
{
    if(tab->size == tab->max)
    {
        //FULL, RANGER NEED BACK-UP
        TableauIncreaseSize(tab);
    }

    tab->array[tab->size] = a;
    tab->size ++;
}

/* Avoir la taille du tableau*/
unsigned TableauGetSize(Tableau * tab)
{
    return tab->size;
};

/* Lièbre la mamoire du tableau*/
void TableauFree(Tableau ** tab)
{
    free((*tab)->array);
    free(*tab);
    *tab = NULL;
}

/* Get point2 element from tab*/
Point2 TableauGetPoint2(Tableau * tab, unsigned index)
{
    if(index >= tab->size || index < (unsigned int) 0)
    {
        printf("ERROR TAB OUT OF INDEX");
        exit(EXIT_FAILURE);
    }
    return tab->array[index];

}

/* Fonction privé automatiquement appeler pour agrandir le tableau au besion*/
void TableauIncreaseSize(Tableau * tab)
{
    tab->power ++;
    unsigned int newsize = (unsigned int)pow(2, tab->power);
    tab->max = newsize - 1;
    tab->array = (Point2 *)realloc(tab->array, sizeof(Point2) * newsize);
}

void TableauRemove(Tableau * tab)
{
    tab->size --;
}