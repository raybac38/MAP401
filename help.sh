#!/bin/bash

IMAGES="Asterix3.pbm lettre-L-cursive.pbm ColombesDeLaPaix.pbm"

methodes="Segment Bezier2 Bezier3"

commandes="./test_segment_simplification ./test_bezier2_simplification ./test_bezier3_simplification"

distances="0 0.5 1 2 4 8 16"


for image in ${IMAGES}
do
    for methode in ${methodes}
    do
        for distance in ${distances}
        do
            echo ${image} ${methode} ${distance}
        done
    done
done