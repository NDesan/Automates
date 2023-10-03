#ifndef AUTOMATE_H
#define AUTOMATE_H
#include "pile.h"

//fichier automate passé en paramètre de l'executable 

typedef int etat;
typedef char alphabet; 
typedef char lettre;
typedef int symbole;

/*  @requires une chaine de caractères
    @assigns nothing
    @ensures le nombre d'éléments de la première ligne de la chaîne de caractères
*/

int nombre_etats(char* aut);

/*  @requires un etat s, un tableau act des actions de l'automate et une lettre e
    @assigns nothing
    @ensures un entier associé à Rejette, Accepte, Decale, Réduit qui correspond à la case (s,c) du tableau
*/

int action(etat s, lettre e, int* act);

/*  @requires la ligne dec sous forme d'un tableau d'entiers, une pile p, un état et une lettre 
    @assigns la pile
    @ensures un état
*/

etat decale(int* dec, pile *p, etat e, lettre l);

/*  @requires une pile, un état et un tableau d'entier red1 
    @assigns la pile 
    @ensures un entier 
*/

etat reduit_entier(pile *p, etat e, int* red1);

/*  @requires un état et une chaine de caractères aut 
    @assigns nothing
    @ensures un symbole non-terminal
*/

int reduit_sym_non_term(etat e, int* red2);

/*  @requires un tableau d'entier, un état et un symbole non-terminal
    @assigns nothing
    @ensures un état
*/

etat branchement(int* branch, etat e, symbole sym);

/*  @requires une pile, un etat s, une lettre c et la partie de l'automate qui contient action, réduit et branchement
    @assigns la pile
    @ensures l'entier correspondant au comportement de l'automate en renvoyant l'entier correspondant à accepter ou refuser
*/

int comportement(pile *p, etat s, lettre c, int* act, int* red1, int * red2, int * branch);

/*  @requires un entier
    @assigns nothing
    @renvoie Accepter ou rejeter en fonction de la valeur de l'entier
*/

void print(int a);

#endif