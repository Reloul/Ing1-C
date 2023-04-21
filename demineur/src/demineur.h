#ifndef __DEMINEUR_H_
#define __DEMINEUR_H_

/*!
 *  \file demineur.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier de déclaration des fonction pour notre démineur
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>
/*Inclusion de la librairie time.h pour pouvoir se servir de la fonction rand()*/
#include <time.h>

/*!
 *  \struct cases
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 22 2022 - 11:54:32
 *  \brief structure permettant de représenter les cases de notre grille de jeu
 *  \param int_etat entier qui représente l'état de nos cases, si elles sont cachées ou dévoilées
 *  \param int_type entier qui représente le type de nos cases, permet de savoir si il s'agit d'une bombe, une case voisine d'une bombe ou une case "vide"
 *  \param int_drapeau entier permettant de savoir si l'utilisateur a posé un drapeau sur une case
 *  \param int_lien entie permettant de faire le lien entre les cases vides voisines afin d'afficher toutes les cases vides côte à côte si l'utilisateur tombe sur une case vide
*/

typedef struct cases
{
    int int_etat;
    int int_type;
    int int_drapeau;
    int int_lien;
}cases;


void initialisation(cases** ppcases_grille, int int_taille);

void affichage(cases** ppcases_grille,int int_taille);

int verifBombe(cases** ppcases_grille, int int_x, int int_y);

int nbBombe(cases** ppcases_grille, int int_x, int int_y, int int_taille);

void attributionType(cases** ppcases_grille, int int_taille, int int_x, int int_y, int int_compteBombe);

void premierCoup(cases** ppcases_grille, int int_taille, int int_compteBombe);

void lien(cases** ppcases_grille, int int_taille);

int saisieEntier(int int_taille);

void tourJeu(cases** ppcases_grille, int int_taille, int int_compteBombe);

void drapeau(cases** ppcases_grille, int int_taille);

void supprDrapeau(cases** ppcases_grille, int int_taille);

int verifGagne(cases** ppcases_grille, int int_taille, int int_compteBombe, int int_compteDrapeau);

void gainPerte(cases** ppcases_grille, int int_taille, int int_gagne, int int_perd);

void reveleLien(cases** ppcases_grille, int int_taille);

#endif