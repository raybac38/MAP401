

IMAGES="Asterix3.pbm lettre-L-cursive.pbm ColombesDeLaPaix.pbm"

METHODES="Segment Bezier2 Bezier3"

DISTANCES="0 0.5 1 2 4 8 16"

declare -A methodes_commandes=(    ["Segment"]="./test_segment_simplification"    ["Bezier2"]="./test_bezier2_simplification"    ["Bezier3"]="./test_bezier3_simplification")


    echo "Image | Méthode | Distance-seuil | Résultat"
    echo "------|---------|----------------|---------"


for METHODE in ${METHODES}
do
    for IMAGE in ${IMAGES}
    do
        for DISTANCE in ${DISTANCES}
        do
        
            ${methodes_commandes["${METHODE}"]} ./IMAGES_TESTS/${IMAGE} zzz ${DISTANCE} > "./output.txt"
            pid=$!
            wait $pid


            if [ "Segment" == "${METHODE}" ]; then
                nombre=$(grep "Apres traitement" -A 2 output.txt | awk '/Total nombre segment/{print $5}')
            else
                nombre=$(grep "Apres traitement" -A 2 output.txt | awk '/Total nombre point/{print $5}')
            fi

            echo "${IMAGE} | ${METHODE} | ${DISTANCE} | ${nombre}"

        done


    done


done