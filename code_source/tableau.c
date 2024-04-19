#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tableau.h"

void TableauIncreaseSize(Tableau *tab);
void ElevationDegres(Point2 C0, Point2 C1, Point2 C2, Point2 *pointer_D1, Point2 *pointer_D2);
double GetGamma(double k, double n);

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

    if (*tab == NULL) // Vérifie si le tableau est déjà NULL
        return;
    unsigned size = 0;

    switch ((*tab)->type)
    {
    case TYPE_INT:
    printf("Libere INT\n");
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
    {
        for (unsigned i = 0; i < (*tab)->size; i++) {

            // Appel récursif pour désallouer chaque élément du tableau
            Tableau *tableau = (Tableau *)(*tab)->array + i;

            if(tableau == NULL) continue;

            TableauFree(&tableau);
        }
    
        free(*tab);
        *tab = NULL;
        break;
    }

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

Point2 TableauSumPoint2WithGama(Tableau *tab, unsigned a, unsigned b, double coef_a, double coef_b)
{
    Point2 somme = SetPoint2(0, 0);
    unsigned delta = b - a;

    for (unsigned i = a + 1; i < b; i++)
    {
        Point2 temporaire = TableauGetPoint2(tab, i);
        double gamma = GetGamma(coef_a * (double)(i - a) + coef_b, (double)delta);
        temporaire = ScalePoint2(temporaire, gamma);
        somme = SumPoint2(somme, temporaire);
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

    double alpha = (3.0 * (double)delta) / (((double)delta * (double)delta) - 1.0);
    double beta = (1.0 - 2.0 * (double)delta) / (2.0 * ((double)delta + 1.0));

    Point2 sum = TableauSumPoint2(tab, a, b);
    Point2 a_plus_b = SumPoint2(TableauGetPoint2(tab, a), TableauGetPoint2(tab, b));

    // ShowPoint2(sum);

    Point2 c = SumPoint2(ScalePoint2(sum, alpha), ScalePoint2(a_plus_b, beta));

    return c;
}

double GetAlpha(double n)
{
    return (-15.0 * n * n * n + 5.0 * n * n + 2.0 * n + 4.0) / (3.0 * (n + 2.0) * (3.0 * n * n + 1.0));
}

double GetBeta(double n)
{
    return (10.0 * n * n * n - 15.0 * n * n + n + 2.0) / (3.0 * (n + 2.0) * (3.0 * n * n + 1.0));
}

double GetLambda(double n)
{
    return (70.0 * n) / (3.0 * (n * n - 1.0) * (n * n - 4.0) * (3.0 * n * n + 1.0));
}

double GetGamma(double k, double n)
{
    return 6.0 * k * k * k * k - 8.0 * n * k * k * k + 6.0 * k * k - 4.0 * n * k + n * n * n * n - n * n;
}

void ApproxBezier3(Tableau *tab, unsigned a, unsigned b, Point2 *pointer_C1, Point2 *pointer_C2)
{
    unsigned delta = b - a;

    Point2 C1, C2 = SetPoint2(0, 0);
    Point2 C0 = TableauGetPoint2(tab, a);
    Point2 C3 = TableauGetPoint2(tab, b);

    if (delta == 1 || delta == 2)
    {
        Point2 T0 = ApproxBezier2(tab, a, b);
        ElevationDegres(C0, T0, C3, &C1, &C2);
    }
    else
    {
        double alpha = GetAlpha(delta);
        double beta = GetBeta(delta);
        double lambda = GetLambda(delta);

        Point2 sum_1 = TableauSumPoint2WithGama(tab, a, b, 1, 0);
        Point2 sum_2 = TableauSumPoint2WithGama(tab, a, b, -1, delta);

        C1 = SumPoint2(ScalePoint2(C0, alpha), SumPoint2(ScalePoint2(sum_1, lambda), ScalePoint2(C3, beta)));
        C2 = SumPoint2(ScalePoint2(C0, beta), SumPoint2(ScalePoint2(sum_2, lambda), ScalePoint2(C3, alpha)));
    }
    (*pointer_C1) = C1;
    (*pointer_C2) = C2;

    return;
}

void ElevationDegres(Point2 C0, Point2 C1, Point2 C2, Point2 *pointer_D1, Point2 *pointer_D2)
{
    Point2 D1 = ScalePoint2(SumPoint2(ScalePoint2(C1, 2.0), C0), 1.0 / 3.0);
    Point2 D2 = ScalePoint2(SumPoint2(ScalePoint2(C1, 2.0), C2), 1.0 / 3.0);

    (*pointer_D1) = D1;
    (*pointer_D2) = D2;

    return;
}
