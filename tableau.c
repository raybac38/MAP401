#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tableau.h"

void TableauIncreaseSize(Tableau *tab);

/* Initialise un tableau*/
Tableau *InitTableau(Type type, unsigned size)
{
    unsigned standard_size = pow(2, DEFAULT_MAX_SIZE);

    if (size < standard_size)
    {
        size = standard_size;
    }
    Tableau *tab = (Tableau *)malloc(sizeof(Tableau));
    tab->power = (unsigned char)DEFAULT_MAX_SIZE;
    tab->max = size;
    tab->size = 0;
    tab->type = type;

    switch (type)
    {
    case TYPE_INT:
        tab->array = (int *)malloc(sizeof(int) * size);
        break;
    case TYPE_POINT2:
        tab->array = (Point2 *)malloc(sizeof(Point2) * size);
        break;
    case TYPE_TABLEAU:
        tab->array = (Tableau *)malloc(sizeof(Tableau) * size);

    default:
        break;
    }

    //////////
    return tab;
}

/*
Ajout d'une valeur a la fin d'un tableau avec detection de débordement
*/
void TableauAppend(Tableau *tab, void *a)
{
    if (tab->size == tab->max)
    {
        // FULL, RANGER NEED BACK-UP
        TableauIncreaseSize(tab);
    }

    Type type = tab->type;

    switch (type)
    {
    case TYPE_INT:
        *((int *)tab->array + tab->size) = *((int *)a);
        break;
    case TYPE_POINT2:
        *((Point2 *)tab->array + tab->size) = *((Point2 *)a);
        break;
    case TYPE_TABLEAU:
        *((Tableau *)tab->array + tab->size) = *((Tableau *)a);
        break;

    default:
        printf("Type unknow\n");
        break;
    }
    tab->size++;
}

/*
Ajout d'une valeur a la fin du tableau sans detection de débordement
Utilisation non recommander
*/
void TableauAppendUnsafe(Tableau *tab, void *a)
{
    Type type = tab->type;

    switch (type)
    {
    case TYPE_INT:
        *((int *)tab->array + tab->size) = *((int *)a);
        break;
    case TYPE_POINT2:
        *((Point2 *)tab->array + tab->size) = *((Point2 *)a);
        break;
    case TYPE_TABLEAU:
        *((Tableau *)tab->array + tab->size) = *((Tableau *)a);
        break;

    default:
        printf("Type unknow\n");
        break;
    }
    tab->size++;
}

/* Avoir la taille du tableau*/
unsigned TableauGetSize(Tableau *tab)
{
    return tab->size;
};

Type TableauGetType(Tableau *tab)
{
    return tab->type;
}

/* Lièbre la mémoire du tableau*/
void TableauFree(Tableau **tab)
{
    switch ((*tab)->type)
    {
    case TYPE_INT:
        free((*tab)->array);
        free(*tab);
        *tab = NULL;
        break;
    case TYPE_POINT2:
        free((*tab)->array);
        free(*tab);
        *tab = NULL;
        break;
    case TYPE_TABLEAU:
        unsigned size = (*tab)->size;

        for (size_t index = 0; index < size - 1; index++)
        {
            TableauFree((Tableau **)&(*((Tableau **)(*tab)->array + index)));
        }
        free((*tab)->array);
        free(*tab);
        *tab = NULL;
        break;

    default:
        break;
    }
}

/* Get point2 element from tab*/
Point2 TableauGetPoint2(Tableau *tab, unsigned index)
{
    if (tab == NULL)
    {
        printf("Pointeur de structure tableau vide\n");
        exit(EXIT_FAILURE);
    }
    if (tab->array == NULL)
    {
        printf("pointeur d'array vide");
        exit(EXIT_FAILURE);
    }
    if (index >= tab->size || index < (unsigned int)0)
    {
        printf("ERROR TAB OUT OF INDEX");
        exit(EXIT_FAILURE);
    }

    return *((Point2 *)tab->array + index);
}

/* Get int element from tab*/
int TableauGetInt(Tableau *tab, unsigned index)
{
    if (index >= tab->size || index < (unsigned int)0)
    {
        printf("ERROR TAB OUT OF INDEX");
        exit(EXIT_FAILURE);
    }
    return *((int *)tab->array + index);
}

/* Get point2 element from tab*/
Tableau *TableauGetTableau(Tableau *tab, unsigned index)
{
    if (index >= tab->size || index < (unsigned int)0)
    {
        printf("ERROR TAB OUT OF INDEX");
        exit(EXIT_FAILURE);
    }
    return ((Tableau *)tab->array + index);
}

/* Fonction privé automatiquement appeler pour agrandir le tableau au besion*/
void TableauIncreaseSize(Tableau *tab)
{
    tab->power++;
    unsigned int newsize = (unsigned int)pow(2, tab->power);
    tab->max = newsize - 1;

    switch (tab->type)
    {
    case TYPE_INT:
        tab->array = realloc(tab->array, sizeof(int) * newsize);
        break;
    case TYPE_POINT2:
        tab->array = realloc(tab->array, sizeof(Point2) * newsize);
        break;
    case TYPE_TABLEAU:
        tab->array = realloc(tab->array, sizeof(Tableau) * newsize);
        break;
    default:
        break;
    }
}

void TableauRemove(Tableau *tab)
{
    tab->size--;
    if (tab->type == TYPE_TABLEAU && tab->size > 0)
    {
        Tableau *subArray = (Tableau *)tab->array + (tab->size - 1);
        TableauFree(&subArray);
    }
}

Point2 TableauSumPoint2(Tableau *tab, unsigned a, unsigned b)
{
    Point2 somme = SetPoint2(0, 0);

    for (unsigned i = a + 1; i < b; i++)
    {
        somme = SumPoint2(somme, TableauGetPoint2(tab, i));
    };
    return somme;
}

Point2 ApproxBezier2(Tableau *tab, unsigned a, unsigned b)
{
    unsigned delta = b - a;

    if (delta == 1)
    {
        return Point2MiddlePoint2(TableauGetPoint2(tab, a), TableauGetPoint2(tab, b));
    }

    double alpha = (3 * delta) / ((delta * delta) - 1);
    double beta = (1 - 2 * delta) / (2 * (delta - 1));

    Point2 sum = TableauSumPoint2(tab, a, b);
    Point2 a_plus_b = SumPoint2(TableauGetPoint2(tab, a), TableauGetPoint2(tab, b));

    return SumPoint2(ScalePoint2(sum, alpha), ScalePoint2(a_plus_b, beta));
}