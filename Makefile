#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2020/2021
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = gcc

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_image test_contour test_mask_img test_module_ps


#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

geometrie2d.o : geometrie2d.c geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geometrie2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

test_image.o: test_image.c image.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

#test_geometrie2d.o : test_geometrie2d.c geometrie2d.h 
#	@echo ""
#	@echo "---------------------------------------------"
#	@echo "Compilation du module test_geometrie2d"
#	@echo "---------------------------------------------"
#	$(CC) -c $(COMPILOPTS) $< -o $@

contour.o : contour.c contour.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

multi_contour.o : multi_contour.c multi_contour.h contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module multi_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

test_mask_img.o: test_mask_img.c multi_contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_mask_img"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@
		
tableau.o : tableau.c tableau.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module tableau"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@		

test_contour.o : test_contour.c contour.h geometrie2d.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@			

module_ps.o : module_ps.c module_ps.h tableau.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module module_ps"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@			
	
test_module_ps.o : test_module_ps.c module_ps.h tableau.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_module_ps"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@	
########################################################
# regles explicites de creation des executables

test_image : test_image.o image.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

#test_geometrie2d : test_geometrie2d.o geometrie2d.o 
#	@echo ""
#	@echo "---------------------------------------------"
#	@echo "Creation de l'executable "$@
#	@echo "---------------------------------------------"
#	$(CC) $^ $(LDOPTS) -o $@

test_contour : test_contour.o contour.o geometrie2d.o tableau.o image.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_mask_img : test_mask_img.o multi_contour.o contour.o geometrie2d.o tableau.o image.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_module_ps : test_module_ps.o module_ps.o multi_contour.o contour.o geometrie2d.o tableau.o image.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
