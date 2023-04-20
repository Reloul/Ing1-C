#ifndef __TD_H_
#define __TD_H_


 /*!
 *  \file td.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief déclaration des fonctions que l'on utilisera
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>
/*Inclusion de la librairie string.h qui permet d'obtenir des fonctions utiles pour les chaînes de caractère : connaitre la taille d'une chaine, comparaison de pointeur de chaine...*/
#include <string.h>
/*Inclusion de la librairie math.h afin d'obtenir des fonctions mathématiques utiles au code : comme l'utilisation de sqrt pour avoir la racine carrée d'un nombre*/
#include <math.h>

void cesar(char* pchar_chaine, int int_decalage);

void vigenere(char* pchar_chaine, char* pchar_cle);

void scytale(char* pchar_chaine);

void help();

void methode(char** pchar_chaine, int int_nbArgument);

#endif