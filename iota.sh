#!/bin/bash

METHODES=("Segment" "Bezier2" "Bezier3")

declare -A listes_commandes

listes_commandes["Segment"]="./test_segment_simplification"
listes_commandes["Bezier2"]="./test_bezier2_simplification"
listes_commandes["Bezier3"]="./test_bezier3_simplification"


CONF_INIT="./conf_init.txt"
CONF="./conf.txt"
if [ ! -e "$CONF" ]; then
    echo "Fichier conf.txt introuvable, initialisation de conf.txt"
    cp "$CONF_INIT" "$CONF"
    echo "Fichier conf.txt initialiser"

fi
    










