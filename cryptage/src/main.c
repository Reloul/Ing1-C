/*!
 *  \mainpage Programme pour chiffrer un message selon une méthode voulue
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \section INFO
 *     Voici le code fais par Valentin Serres qui permet de chiffrer un message donné par l'utilisateur de trois manières différentes: le code César, le code Vigenère ou le code Scytale
*/


 /*!
 *  \file main.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief programme principale servant à utiliser les différentes fonctions pour chiffre un message
*/ 

//On inclus le fichier servant à déclarer nos fonctions et utiliser les bibliothèques utiles
#include "td.h"

/*!
 *  \fn int main(int argc, char** argv)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 13 2022 - 14:04:01
 *  \brief fonction main qui permettra d'exécuter toutes nos fonctions
 *  \param argv nombre d'argument passé en paramètre
 *  \param argv tableau des différents arguments passés en paramètre
 *  \return 0 si tout se passe bien
*/

int main(int argc, char** argv){
    //entier qui servira à vérifier si les paramètres passés en argument par l'utilisateur sont bons ou non
    int int_verif;
    //On l'initialise à "bon" de base
    int_verif=1;
    //Si le nombre d'argument dépasse 1, permet d'éviter une erreur de mémoire lors de la première comparaison
    if (argc > 1){
        //on vérifie si l'utilisateur demande l'aide
        if (strcmp(argv[1], "--help") == 0){
            //Si l'utilisateur demande l'aide alors on affiche l'aide
            help();
        //Sinon on vérifie si l'utilisateur demande de chiffrer un message
        }else if (strcmp(argv[1], "-c") == 0){
            //Si oui alors on va vérifier ses arguments et on exécute le code adapté
            methode(argv, argc);
        }else{
            //Si l'utilisateur demande autre chose alors il s'est trompé dans les arguments 
            int_verif = 0;
        }   
    }else{
        //Si il n'y a pas d'argument alors l'utilisateur c'est trompé
        int_verif = 0;
    }
    //Si il y a une erreur alors on le signal à l'utilisateur
    if(int_verif == 0){
        printf("Erreur dans les arguments.\n");
    }
    //On retourne 0 si tout c'est bien passé
    return(0);
    
}
