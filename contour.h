#include <stdio.h>
#include <image.h>
#include "tableau.h"
#include "types_macros.h"


/* Humans' Best Friends and Image Outlines

In her life, Nutty Noodle has only two goal, to find an outline and to be happy :)
Her little name is Nuttnutt ^^
*/

typedef struct NuttyNoodler
{
    unsigned int x;
    unsigned int y;
    Orientation orientation;
    Image * img;
    Image * mask;
}NuttyNoodler;

/* Calculate a outline from a correct strating point*/
Tableau GetOutline(unsigned int stratingx, unsigned int startingy, Image * img);


