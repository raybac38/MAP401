
typedef struct uintArray
{
    unsigned pow;
    unsigned max_size;
    unsigned size;
    unsigned * array;
} UIntArray;


void UIntArrayGet( UIntArray tab,unsigned index);
UIntArray * UIntArrayInitPresized(unsigned initial_size);
UIntArray * UIntArrayInitStandard();
void UIntArrayAdd(UIntArray tab, unsigned valeur);
void UIntArrayAddSafe(UIntArray tab, unsigned valeur);
