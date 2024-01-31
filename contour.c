#include "contour.h"
#include "types_macros.h"
#include <stdio.h>
#include <stdlib.h>


Tableau GetOutline(unsigned int stratingx, unsigned int startingy, Image * img)
{
    NuttyNoodler nuttnutt;
    nuttnutt.orientation = Est;
    nuttnutt.x = stratingx;
    nuttnutt.y = startingy;
    nuttnutt.img = img;
    do
    {
        
    } while (/* condition */);
    
    
}

void NuttNuttNextStep(NuttyNoodler * nuttnutt)
{
    Pixel left = GetNuttNuttLeftPixelValue(nuttnutt);
    Pixel right = GetNuttNuttRightPixelValue(nuttnutt);

}

Pixel GetNuttNuttLeftPixelValue(NuttyNoodler * nuttnutt)
{
    unsigned int x= nuttnutt->x;
    unsigned int y= nuttnutt->y;
    switch (nuttnutt->orientation)
    {
    case Est:
        x++;
        break;
    case Sud:
        x++;
        y++;
        break;
    case Ouest:
        y++;
        break;
    default:
        break;
    }
    return get_pixel_image(*(nuttnutt->img), x, y);
}

Pixel GetNuttNuttRightPixelValue(NuttyNoodler * nuttnutt)
{
    unsigned int x= nuttnutt->x;
    unsigned int y= nuttnutt->y;
    switch (nuttnutt->orientation)
    {
    case Nord:
        x++;
        break;
    case Est:
        x++;
        y++;
        break;
    case Sud:
        y++;
        break;
    default:
        break;
    }
    return get_pixel_image(*(nuttnutt->img), x, y);
}

void NuttNuttGoForward(NuttyNoodler * nuttnutt)
{
    switch (nuttnutt->orientation)
    {
    case Nord:
        nuttnutt->y--;
        break;
    case Est:
        nuttnutt->x++;
        break;
    case Sud:
        nuttnutt->y++;
        break;
    case Ouest:
        nuttnutt->x--;
        break;
    
    default:
        break;
    }
}

NuttyNoodler * InitNuttyNoodler(unsigned int stratingx, unsigned int stratingy)
{
    NuttyNoodler * nuttnutt = (NuttyNoodler *)malloc(sizeof(NuttyNoodler));
    nuttnutt->x = stratingx;
    nuttnutt->y = stratingy;
    nuttnutt->orientation;
    return nuttnutt;
}

