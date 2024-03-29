#include "contour.h"

/* 
Declaration des fonction ici pour ne pas noyer les script 
et le header qui n'ont de porter que local
*/

void NuttNuttNextStep(NuttyNoodler * nuttnutt);
Point2 NuttNuttDoReport(NuttyNoodler * nuttnutt);
void TurnNuttyNoodler(NuttyNoodler * nuttnutt, unsigned angle);
Pixel GetNuttNuttLeftPixelValue(NuttyNoodler * nuttnutt);
Pixel GetNuttNuttRightPixelValue(NuttyNoodler * nuttnutt);
NuttyNoodler * InitNuttyNoodler(unsigned int stratingx, unsigned int stratingy);
void NuttNuttGoForward(NuttyNoodler * nuttnutt);


/*  Add outline point at the end of points*/
void GetOutline(Tableau * outline, unsigned int stratingx, unsigned int startingy, Image * img, Image * mask)
{
    NuttyNoodler nuttnutt;
    nuttnutt.orientation = Est;
    nuttnutt.x = stratingx;
    nuttnutt.y = startingy;
    nuttnutt.img = img;

    double dimentionY = (double)hauteur_image(*img);

    Point2 StartingPoint2 = SetPoint2(stratingx, startingy);
    Point2 reverseY = SetPoint2(0, 0);

    Point2 lastPosition = StartingPoint2;
    do
    {
        if(nuttnutt.orientation == Est)
        {
            set_pixel_image(*mask,(unsigned int) GetValuePoint2(lastPosition, 'x') + 1, (unsigned int) GetValuePoint2(lastPosition, 'y') +1 , BLANC);
        }
        reverseY = SetPoint2(GetValuePoint2(lastPosition, 'x'), dimentionY - GetValuePoint2(lastPosition, 'y'));

        NuttNuttGoForward(&nuttnutt);

        TableauAppend(outline, reverseY);

	    NuttNuttNextStep(&nuttnutt);
        lastPosition = NuttNuttDoReport(&nuttnutt);
        
    } while (1 != IsPoint2Equal(lastPosition, StartingPoint2) || nuttnutt.orientation != Est);
    reverseY = SetPoint2(stratingx, dimentionY - startingy);
    
    TableauAppend(outline, reverseY);
}



/* NuttNutt is very calm, she only walk step by step*/
void NuttNuttNextStep(NuttyNoodler * nuttnutt)
{
    Pixel left = GetNuttNuttLeftPixelValue(nuttnutt);
    Pixel right = GetNuttNuttRightPixelValue(nuttnutt);

    if(left == NOIR)
    {
        TurnNuttyNoodler(nuttnutt, 270);
    }
    else if(right == BLANC)
    {
        TurnNuttyNoodler(nuttnutt, 90);
    }
    
}

/* NuttNutt say where she is*/
Point2 NuttNuttDoReport(NuttyNoodler * nuttnutt)
{
    /// Where are you my sweet nuttnutt ? You miss me !
    return SetPoint2(nuttnutt->x, nuttnutt->y);
}

/* Permet a NuttyNoodler de tourne dans le sens ANTI TRIGONOMETRIQUE*/
void TurnNuttyNoodler(NuttyNoodler * nuttnutt, unsigned angle)
{
    Orientation orient = nuttnutt->orientation;
    unsigned orientationNumber = (unsigned)orient;

    orientationNumber = (orientationNumber + (unsigned)(angle/ 90)) % 4;

    nuttnutt->orientation = (Orientation)orientationNumber;
}

/* Get NuttNutt relative forward left pixel value*/
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

/* Get NuttNutt relative forward right pixel value*/
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

/* Make nuttnutt go forward*/
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

/* Make a new nuttnutt ^^
 She like stalin, so she always start forwarding Est*/
NuttyNoodler * InitNuttyNoodler(unsigned int stratingx, unsigned int stratingy)
{
    NuttyNoodler * nuttnutt = (NuttyNoodler *)malloc(sizeof(NuttyNoodler));
    nuttnutt->x = stratingx;
    nuttnutt->y = stratingy;
    nuttnutt->orientation = Est;
    return nuttnutt;
}



