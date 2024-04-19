#include "multi_contour.h"

/*
But de ce script :

Crée une image masque de l'image pixelisé contenant tout les points de départ potentiel

Requeillir tout les contours detecté par nuttynoodler (module contour)

Sortir une liste de points, ainsi qu'un tableau de début de polygone
*/


Tableau * ExtractAllOutline(Image img)
{

    Image mask = CreateMaskPicture(img);

    unsigned i = 0;
    unsigned j = 0;

    unsigned largeur = largeur_image(img);
    unsigned hauteur = hauteur_image(img);

    Pixel p;

    Tableau * contours = InitTableau(TYPE_TABLEAU, 0);



    for (i = 1; i <= largeur; i++)
    {
        for (j = 1; j <= hauteur; j++)
        {
            p = get_pixel_image(mask, i, j);
            if(p == NOIR)
            {
                Tableau * contour = InitTableau(TYPE_POINT2, 0);
                GetOutline(contour, i - 1, j - 1, &img, &mask);
                TableauAppend(contours, contour);
            }
            
        }
    }
    supprimer_image(&mask);

    return contours;
}







Image CreateMaskPicture(Image ref)
{
    unsigned largeur = largeur_image(ref);
    unsigned hauteur = hauteur_image(ref);

    Image img = creer_image(largeur, hauteur);

    unsigned i = 0;
    unsigned j = 1;

    Pixel pixel;
    Pixel pixel_up;
    for (i = 1; i <= largeur; i++)
    {
        pixel_up = BLANC; 
        for (j = 1; j <= hauteur; j++)
        {
            pixel = get_pixel_image(ref, i, j);

            if(pixel == NOIR && pixel_up == BLANC)
            {
                set_pixel_image(img, i, j, NOIR);
                set_pixel_image(img, i, j + 1, BLANC);
                j++;
                pixel = pixel_up = get_pixel_image(ref, i, j);
            }
            else if(pixel == NOIR && pixel_up == NOIR)
            {
                set_pixel_image(img, i, j, BLANC);
                set_pixel_image(img, i, j + 1, BLANC);
                j++;
                pixel = pixel_up = get_pixel_image(ref, i, j);
            }
            else
            {
                set_pixel_image(img, i, j, BLANC);
            }
            
            pixel_up = pixel; 
        }
        
    }
    return img;
}
