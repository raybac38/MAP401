#include "contour.h"

typedef struct node Node;

struct node
{
    Tableau * contours;
    Node * next;
};

typedef struct liste
{
    Node * tete;
    Node * cul;
    unsigned size;
}Liste;



Liste * ListeInit(void);

void ListeDestroy(Liste ** l);

void ListeAppend(Liste * l, Tableau * contour);

void ListeInsert(Liste * l, Tableau * contour, unsigned index);

Tableau * ListeGet(Liste * l, unsigned index);

unsigned ListeSize(Liste * l);




