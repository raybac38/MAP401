#!/bin/bash

set -x

# Définition du tableau de noms
NAMES=("image poly tache6.pbm" "elephant-gotlib.pbm" "goudyini-A.pbm" "JoaquimHock-LesArbres.pbm" "cheval.pbm" "papillon2.pbm")

# Boucle pour itérer sur chaque élément du tableau NAMES
for NAME in "${NAMES[@]}"
do
    ./test_segment_simplification "./IMAGES_TESTS/${NAME}" "./Tache6-P2-Image/${NAME}_1" 1 >> ./Tache6-P2-Image/resultats-tache6-2.txt
done

for NAME in "${NAMES[@]}"
do
    ./test_segment_simplification "./IMAGES_TESTS/${NAME}" "./Tache6-P2-Image/${NAME}_2" 2 >> ./Tache6-P2-Image/resultats-tache6-2.txt
done