#include "liste.h"


/*Initialise une liste de longueur 0 avec une tete/queue*/
Liste * ListeInit()
{
    Liste * l = (Liste *)malloc(sizeof(Liste));
    l->cul = NULL;
    l->size = 0;
    l->tete = NULL;
    return l;
}

/*Detruit une liste et libere la memoire*/
void ListeDestroy(Liste ** l)
{
    if(*l == NULL) return;

    Node * pointeur;
    Node * traineur;

    pointeur = (*l)->tete;
    while(pointeur != NULL)
    {
        traineur = pointeur;
        pointeur = pointeur->next;

        TableauFree(&traineur->contours);
        free(traineur);
    }
    free(*l);
    *l = NULL;
    return;
}

/*Ajoute un element à la liste*/
void ListeAppend(Liste * l, Tableau * contour)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->contours = contour;
    newNode->next = NULL;
 
    if(l->size == 0)
    {
        l->cul = newNode;
        l->tete = newNode;
        l->size = 1;
    }
    else
    {
        l->cul->next = newNode;
        l->cul = newNode;
        l->size ++;
    }
    return;
}

/*Insère un element dans la liste chaînee à l'index specifie
(traite les différents cas de figure avec si l'indice est en milieu de chaine, une insertion de noeud)*/
void ListeInsert(Liste * l, Tableau * contour, unsigned index)
{
    if(index > l->size)
    {
        printf("ERROR : Liste index invalide \n");
        return;
    }

    if(index == l->size)
    {
        ListeAppend(l, contour);
        return;
    }

    Node * newNode = malloc(sizeof(Node));
    newNode->contours = contour;

    if(index == 0)
    {
        l->size ++;
        newNode->next = l->tete;
        l->tete = newNode;
    }
    else
    {
        unsigned i = 0;
        
        Node * pointeur = l->tete;
        for (size_t val = 0; val < index - 1; val++)
        {
            pointeur = pointeur->next;
        }
        newNode->next = pointeur->next;
        pointeur->next =newNode;
        l->size++;
    }
}

/*Obtenir un element avec un index */
Tableau * ListeGet(Liste * l, unsigned index)
{
    printf("accessing element %d\n", index);
    Node * pointeur = l->tete;

    if(index >= l->size)
    {
        printf("Error : Out of index\n");
        return;
    }
    for (size_t i = 0; i < index; i++)
    {
        pointeur = pointeur->next;
    }
    return pointeur->contours;
}

/*retourne la taille de la liste*/
unsigned ListeSize(Liste * l)
{
    return l->size;
}
