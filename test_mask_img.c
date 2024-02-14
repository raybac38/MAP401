#include "multi_contour.h"

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("pas assez convainquant, donnez moi de meilleur argument ! \n");
        printf("./this <fichier img>\n");
        exit(EXIT_FAILURE);
    }

    Image img = lire_fichier_image(argv[1]);

    ecrire_image(img);

    img = CreateMaskPicture(img);

    ecrire_image(img);
    return 0;
}