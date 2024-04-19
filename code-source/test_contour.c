#include <stdio.h>
#include <stdlib.h>
#include "contour.h"

#include "image.h"



int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("pas assez d'argument, pas assez convainquant !\n");
        exit(EXIT_FAILURE);
    }

    Image img = lire_fichier_image(argv[1]);
    Tableau * outline = InitTableau(TYPE_POINT2, 0);

    unsigned largeur = largeur_image(img);
    unsigned hauteur = hauteur_image(img);

    unsigned i;
    unsigned j;

    bool outlineDetected = false;

    Pixel p;
    Pixel pup;
    
    printf("lecture du fichier %s\n", argv[1]);

    for (j = 1; j <= hauteur; j++)
    {
        for (i = 1; i <=largeur ; i++)
        {
            p = get_pixel_image(img, i, j);
            pup = get_pixel_image(img, i, j -1);
            if(p == NOIR && pup == BLANC)
            {
                outlineDetected = true;
                GetOutline(outline, i - 1, j - 1, &img, NULL);
            }
            if(outlineDetected) break;
        }
        if(outlineDetected) break;
    }
    if(!outlineDetected)
    {
        printf("pas de contours detecter\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("contour detecter ! \n");
        unsigned nombre_point = TableauGetSize(outline);
        printf("nombre de points : %d\n", nombre_point);
        printf("nombre de segment : %d\n", nombre_point - 1);
        unsigned i;
        for (i = 0; i < nombre_point; i++)
        {
            ShowPoint2(TableauGetPoint2(outline, i));
            printf("\n");
        }

        printf("\nfin des points du contours \n");

        
        
    }
    exit(EXIT_SUCCESS);
}

