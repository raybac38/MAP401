#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"module_ps.h"


// Le but de cette fonction recuperer un tableau de coordonnées puis d'ecrire un fichier .ps
// qui dessine une image de ses coordonnées relier par un segment

void sortie_fichier(Tableau  xy_image, char* name) {
    Point2 c;
    int i,cx,cy; 
    FILE *fichier;

    name = strcat(name, ".ps\0");

    fichier = fopen(name, "w"); // Ouvre le fichier en écriture
    
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
        return;
    }

    fprintf(fichier, "%%!PS-Adobe-3.0 EPSF-3.0");
    fprintf(fichier, "%%!PS-Adobe-3.0 EPSF-3.0");
    
    for(i=0; i < TableauGetSize(&xy_image); i++) {
        c = TableauGetPoint2(&xy_image, i);
        cx = c.x;
        cy = c.y;
   
        if (i == 0) {
            fprintf(fichier, "%d %d moveto", cx, cy);
            //moveto sur le fichier avec coord
        }
        else{
            fprintf(fichier, "%d %d lineto", cx, cy);
            if (((i+1)%3)==0) {
                fprintf(fichier, "\n");
            }
            // lineto sur fichier avec coord
        }      
    }

    fprintf(fichier, "showpage \n");
    fclose(fichier); // Ferme le fichier
}

