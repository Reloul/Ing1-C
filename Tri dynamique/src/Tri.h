#ifndef __TRI_H_
#define __TRI_H_

 /*!
 *  \file Tri.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief déclaration des fonctions
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>

int* copierSousTableau(int* tableauSource, int int_debut, int int_fin);

void fusion(int* ptint_tab1, int int_taille1, int* ptint_tab2, int int_taille2, int* ptint_tabRes);
void triFusion(int *tintp_tableau, int int_taille);
void affichage(int* ptint_tab, int int_taille);
int saisieEntier();

#endif