#include "multi_contour.h"

/*
But de ce script :

Crée une image masque de l'image pixelisé contenant tout les points de départ potentiel

Requeillir tout les contours detecté par nuttynoodler (module contour)

Sortir une liste de points, ainsi qu'un tableau de début de polygone
*/


Liste * ExtractAllOutline(Image img)
{

    Image mask = CreateMaskPicture(img);

    unsigned i = 0;
    unsigned j = 0;

    unsigned largeur = largeur_image(img);
    unsigned hauteur = hauteur_image(img);

    Pixel p;

    Liste * contours = ListeInit();



    for (i = 1; i <= largeur; i++)
    {
        for (j = 1; j <= hauteur; j++)
        {
            p = get_pixel_image(mask, i, j);
            if(p == NOIR)
            {
                Tableau * contour = InitTableau();
                GetOutline(contour, i - 1, j - 1, &img, &mask);
                ListeAppend(contours, contour);
            }
            
        }
    }

    return contours;
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
    for (i = 1; i <= largeur; i++)
    {
        for (j = 1; j <= hauteur; j++)
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
