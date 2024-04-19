#include "tableau.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    Tableau * tab = InitTableau(TYPE_TABLEAU, 0);



    TableauAppend(tab, InitTableau(TYPE_INT, 0));
    TableauAppend(tab, InitTableau(TYPE_INT, 0));
    TableauAppend(tab, InitTableau(TYPE_INT, 0));

    TableauFree(&tab);

}