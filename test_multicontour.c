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

    unsigned somme_segment = 0;
    unsigned somme_point = 0;
    Image image = lire_fichier_image(argv[1]);

    Point2 dimention = SetPoint2(largeur_image(image), hauteur_image(image));

    Liste * contours = ExtractAllOutline(image);

    printf("Information : \n");

    printf("Image de taille : %d x %d \n", largeur_image(image), hauteur_image(image));


    unsigned nombreContours =  ListeSize(contours);

    printf("Nombre de contours detecter : %d\n", nombreContours);

    for (unsigned i = 0; i < nombreContours; i++)
    {
        Tableau * t = ListeGet(contours, i);
        unsigned tabnbpoints = TableauGetSize(t);
        somme_segment += (unsigned)tabnbpoints - 1;
        somme_point += (unsigned)tabnbpoints;
    }

    printf("Total nombre point : %d\n", somme_point);
    printf("Total nombre segment : %d\n", somme_segment);

    printf("Fin du teste\n");
    
    if(argc == 3)
        {

            printf("Impression de l'image de contours \n");
            PsSimpleSegment(contours, dimention, argv[2]);
        }
    return 0;
    

}
