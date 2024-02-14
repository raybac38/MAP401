#include "multi_contour.h"
#include "module_ps.h"

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("pas assez convainquant, donnez de bon argument !\n ./this <fichier image> <out file>\n");
        exit(EXIT_FAILURE);
    }
    

    /// Teste de la sortie ps

    Image img = lire_fichier_image(argv[1]);

    Tableau * outline = InitTableau();
    Tableau * start = InitTableau();

    ExtractAllOutline(outline, start, img);

    sortie_fichier(*outline, argv[2]);

   

}
