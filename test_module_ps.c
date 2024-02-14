#include "contour.h"
#include "module_ps.h"

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("pas assez convainquant, donnez de bon argument !\n ./this <fichier image>\n");
        exit(EXIT_FAILURE);
    }
    

    /// Teste de la sortie ps

    Image img = lire_fichier_image(argv[1]);

    Tableau * tab = InitTableau();

   

}
