#include "multi_contour.h"
#include "ps.h"


/* Donne les contours d'une image ainsi que les informations*/
int main(int argc, char * argv[])
{
    if(argc != 2 && argc != 3)
    {
        printf("Argument invalide \n ./this <file> || <file.out>\n");
        exit(EXIT_SUCCESS);
    }

    Image image = lire_fichier_image(argv[1]);

    Point2 dimention = SetPoint2(largeur_image(image), hauteur_image(image));

    Tableau * contours = ExtractAllOutline(image);

    printf("Information : \n");

    printf("Image de taille : %d x %d \n", largeur_image(image), hauteur_image(image));


    unsigned nombreContours =  TableauGetSize(contours);

    printf("Nombre de contours detecter : %d\n", nombreContours);

    printf("Fin du teste\n");
    
    if(argc == 3)
        {

            printf("Impression de l'image de contours \n");
            PsSimpleSegment(contours, dimention, argv[2]);
        }
    return 0;
    

}
