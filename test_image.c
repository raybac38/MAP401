#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"

void main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("Argument invalide, soyez plus persuasif !");
    }
    Image img = lire_fichier_image(argv[1]);
    ecrire_image(img);
    img = negatif_image(img);
    ecrire_image(img);
}