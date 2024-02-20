#include "contour.h"

typedef struct liste
{
    Node * tete;
    Node * cul;
    unsigned size;
}Liste;

typedef struct node
{
    Tableau * contours;
    Node * next;
}Node;

Liste * ListeInit(void);

void ListeDestroy(Liste ** l);

void ListeAppend(Liste * l, Tableau * contour);

void ListeInsert(Liste * l, Tableau * contour, unsigned index);

void ListeRemove(Liste * l, unsigned index);

bool ListeIsEmpty(Liste * l);

Tableau * ListeGet(Liste * l, unsigned index);

unsigned ListeSize(Liste * l);




