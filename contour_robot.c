#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometrie2d.h"
#include "image.h"
#include "tableau.h"
#include "types_marcos.h"

/* Implementation d'un robot qui s'interesse aux contours d'une image */


Tableau images_en_tableau(Image image1) {
    int larg, haut;
    int i, j;
    Tableau tab_im;
    larg = image1.la_largeur_de_l_image;    
    haut = image1.la_hauteur_de_l_image;
    *tab_im = InitTableau();
    for(i=0; i < larg, i++) {
        for(j=0; j < haut, j++){
            TableauAppend(tab_im, (i,j));
        }

    }
    return tab_im;
}

Tableau contour(Image image1) {
    Tableau tbl;
    int i;
    Point2 depart_point, new_point;
    Orientation robot;
    tbl = images_en_tableau(image1);
    while (get_pixel_image(image1, tableau.i[0], tableau.i[1]) != NOIR);
        i = i + 1; 
    depart_point = get_pixel_image(image1, tableau.i[0], tableau.i[1]);
    new_point = depart_point

    

    while (new_point != depart_point) { 
        switch (expression)
        {
        case Nord:
             
            pixel_gauche
            break;
        case Sud:
            break;
        case Ouest:
            break;
        case Est:
            break;    
        default:
            break;
        
        } 
        }
}

/*
Si Nord : G x-1 y-1 D x+0 y-1
Si Sud : G x+1 y+1 D x+0 y+1
Si Ouest (W) : G x+1 y-1 D x+1 y+0
Si Est : G x+1 y-1 D x+1 y+0
*/
