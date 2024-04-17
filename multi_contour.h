#include "tableau.h"
#include "image.h"
#include "contour.h"

/*
Extraction de tout les contours d'une image
*/
Tableau * ExtractAllOutline(Image img);

/*
Création d'une image mask
*/
Image CreateMaskPicture(Image ref);