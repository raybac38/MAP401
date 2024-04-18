#include "simplification.h"
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

    Tableau * contours = ExtractAllOutline(image);


    Tableau * contours_simplifier = Simplification_Bezier2(contours, atof(argv[3]));

    printf("Information :\n");

    printf("Image : %s\n", argv[1]);
    printf("Distante seuil : %lf\n", atof(argv[3]));

    printf("Image de taille : %d x %d \n", largeur_image(image), hauteur_image(image));



    unsigned nombreContours =  TableauGetSize(contours_simplifier);

    printf("Nombre de contours detecter : %d\n", nombreContours);

    for (unsigned i = 0; i < nombreContours; i++)
    {
        Tableau * t = TableauGetTableau(contours, i);
        unsigned tabnbpoints = TableauGetSize(t);
        somme_segment += (unsigned)tabnbpoints - 1;
        somme_point += (unsigned)tabnbpoints;
    }
    printf("Avant traitement : \n");
    printf("Total nombre point : %d\n", somme_point);
    printf("Total nombre segment : %d\n", somme_segment);

    somme_point = 0;
    somme_segment = 0;


    for (unsigned i = 0; i < nombreContours; i++)
    {
        Tableau * t = TableauGetTableau(contours_simplifier, i);
        unsigned tabnbpoints = TableauGetSize(t);
        somme_segment += (unsigned)tabnbpoints - 1;
        somme_point += (unsigned)tabnbpoints;
    }
    printf("Apres traitement : \n");
    printf("Total nombre point : %d\n", somme_point);
    printf("Total nombre courbe : %d\n", (somme_point - 1) / 2);

    printf("Fin du teste\n");
            printf("Impression de l'image de contours \n");
            PsCourbeBezier2(contours_simplifier, dimention, argv[2]);
        
    exit(EXIT_SUCCESS);
    

}
