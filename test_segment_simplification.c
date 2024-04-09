#include "simplification_segment.h"
#include "ps.h"


/* Donne les contours d'une image ainsi que les informations*/
int main(int argc, char * argv[])
{

    if(argc != 4)
    {
        printf("Argument invalide, try \n ./this <input_file> <output_file> <distance>\n");
        exit(EXIT_FAILURE);
    }

    unsigned somme_segment = 0;
    unsigned somme_point = 0;
    Image image = lire_fichier_image(argv[1]);

    Point2 dimention = SetPoint2(largeur_image(image), hauteur_image(image));

    Liste * contours = ExtractAllOutline(image);


    Liste * contours_simplifier = Simplification_Segment(contours, atof(argv[3]));

    printf("Information : \n");

    printf("Image de taille : %d x %d \n", largeur_image(image), hauteur_image(image));


    unsigned nombreContours =  ListeSize(contours_simplifier);

    printf("Nombre de contours detecter : %d\n", nombreContours);

    for (unsigned i = 0; i < nombreContours; i++)
    {
        Tableau * t = ListeGet(contours_simplifier, i);
        unsigned tabnbpoints = TableauGetSize(t);
        somme_segment += (unsigned)tabnbpoints - 1;
        somme_point += (unsigned)tabnbpoints;
    }

    printf("Total nombre point : %d\n", somme_point);
    printf("Total nombre segment : %d\n", somme_segment);

    printf("Fin du teste\n");
    
    

            printf("Impression de l'image de contours \n");
            PsSimpleSegment(contours_simplifier, dimention, argv[2]);
        
    return 0;
    

}
