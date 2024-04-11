#include "uintArray.h"
#include "stdlib.h"
#include "math.h"


#define STANDARD_SIZE 8

void UIntArrayRealloc(UIntArray * tab);


/// @brief Allocation d'un tableau de unsigned d'une taille d'une puissance de 2 suppérieur
/// @param size 
/// @return 
UIntArray * UIntArrayInitPresized(unsigned initial_size)
{
    unsigned size = ceil(log2(initial_size));

    if(size < STANDARD_SIZE)
    {
        size = STANDARD_SIZE;
    }

    UIntArray * uintArray = malloc(sizeof(IntArray));
    uintArray->size = 0;
    uintArray->array = malloc(sizeof(unsigned) * pow(2, size));
    uintArray->max_size = pow(2, STANDARD_SIZE);
    uintArray->pow = STANDARD_SIZE;
    return uintArray;
}

/// @brief Allocation d'un tableau de unsigned de taille 2 ^ 8
/// @return 
UIntArray * UIntArrayInitStandard()
{
    UIntArray * uintArray = malloc(sizeof(IntArray));
    uintArray->size = 0;
    uintArray->array = malloc(sizeof(unsigned) * pow(2, STANDARD_SIZE));
    uintArray->max_size = pow(2, STANDARD_SIZE);
    uintArray->pow = STANDARD_SIZE;
    return uintArray;
}

void UIntArrayAdd(UIntArray tab, unsigned valeur)
{
    tab.size++;
    tab.array[tab.size] = valeur;
}

void UIntArrayAddSafe(UIntArray tab, unsigned valeur)
{
    if(tab.size == tab.max_size)
    {
        //Trop plein de unsigned :s
        // ==> brigade de la realloc en marche ! 
        UIntArrayRealloc(tab);
    }
    tab.size++;
    tab.array[tab.size] = valeur;
}

void UIntArrayRealloc(UIntArray * tab)
{
    tab->pow ++;
    tab->max_size = pow(2, tab->pow);
    realloc(tab->array, tab->max_size * sizeof(unsigned));
}


void UIntArrayGet( UIntArray tab,unsigned index)
{
    return tab.array[index];
}