#ifndef __PUISSANCE4_H_
#define __PUISSANCE4_H_


 /*!
 *  \file puissance4.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier de déclaration de nos fonctions
*/ 

//On defini les tailles utiles pour nos tableaux
#define LARGEUR 6
#define LONGUEUR 7
//On défini un cas où il y aurait une erreur de case
#define ERREUR_CASE -2

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>

void initialisation(int ttint_plateau[LARGEUR][LONGUEUR]);

void affichage(int ttint_plateau[LARGEUR][LONGUEUR]);

int jouer (int ttint_plateau[LARGEUR][LONGUEUR], int int_x);

int verifLigne(int ttint_plateau[LARGEUR][LONGUEUR]);
int verifColonne(int ttint_plateau[LARGEUR][LONGUEUR]);
int verifDiag(int ttint_plateau[LARGEUR][LONGUEUR]);
int verifDiagInv(int ttint_plateau[LARGEUR][LONGUEUR]);

void tourDeJeu(int ttint_plateau[LARGEUR][LONGUEUR]);
#endif