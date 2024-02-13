#include "multi_contour.h"

/*
But de ce script :

Crée une image masque de l'image pixelisé contenant tout les points de départ potentiel

Requeillir tout les contours detecté par nuttynoodler (module contour)

Sortir une liste de points, ainsi qu'un tableau de début de polygone
*/


void ExtractAllOutline(Tableau * outlines, Tableau * start, Image img)
{
    
    if(outlines != NULL)
    {
        TableauRemove(outlines);
    }
    if(start != NULL)
    {
        TableauRemove(start);
    }

    unsigned outlineNumber = 0;

    Image mask = CreateMaskPicture(img);

    unsigned i = 0;
    unsigned j = 0;

    unsigned largeur = largeur_image(img);
    unsigned hauteur = hauteur_image(img);

    Pixel p;

    for (i = 0; i < largeur; i++)
    {
        for (j = 0; j < hauteur; j++)
        {
            p = get_pixel_image(mask, i, j);
            if(p == NOIR)
            {
                GetOutline(outlines, i, j, mask);

            }
        }
        
    }
    

    
}







Image CreateMaskPicture(Image ref)
{
    unsigned largeur = largeur_image(ref);
    unsigned hauteur = hauteur_image(ref);

    Image img = creer_image(largeur, hauteur);

    unsigned i = 0;
    unsigned j = 0;

    Pixel p;
    Pixel pup;
    for (i = 0; i < largeur; i++)
    {
        for (j = 0; j < hauteur; j++)
        {
            p = get_pixel_image(ref, i, j);
            pup = get_pixel_image(ref, i, j-1);
            if(p == NOIR && pup == BLANC)
            {
                set_pixel_image(img, i, j, NOIR);
            }
            else
            {
                set_pixel_image(img, i, j, BLANC);
            }
        }
        
    }
    return img;
    
}