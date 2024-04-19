#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include <stdio.h>
#include <image.h>
#include "tableau.h"
#include "types_macros.h"


/* Humans' Best Friends and Image Outlines

In her life, Nutty Noodle has only two goal, to find an outline and to be happy :)
Her little name is Nuttnutt ^^
*/

typedef struct
{
    unsigned int x;
    unsigned int y;
    Orientation orientation;
    Image * img;
    Image * mask;
} NuttyNoodler;

/* Calculate a outline from a correct strating point*/
void GetOutline(Tableau * outline, unsigned int stratingx, unsigned int startingy, Image * img, Image * mask);


#endif