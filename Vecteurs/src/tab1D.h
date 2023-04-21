#ifndef __TAB1D_H_
#define __TAB1D_H_

 /*!
 *  \file tab1D.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief déclaration des fonctions pour les tableaux 1 dimension
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>
/*Inclusion de la librairie time.h pour utiliser la fonction rand()*/
#include <time.h>
#define DIMENSION 10



void initInvers();
void inversion(int tint_tab[], int int_taille);
void initSomme();
void somme(int tint_tabP[], int tint_tabD[], int int_taille, int tint_tabT[]);
void initTraver();
int traversable(int tint_tab[], int int_taille);
void initPalindrome();
int palindrome(char tchar_tab[], int int_taille);

#endif