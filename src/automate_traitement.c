#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "automate_traitement.h"

/*  @requires une chaine de caractères
    @assigns nothing
    @ensures le nombre d'éléments de la première ligne de la chaîne de caractères
*/

int nombre_etats(char* aut){
    return atoi(&aut[1]);
}

/*  @requires un etat s, un tableau act des actions de l'automate et une lettre e
    @assigns nothing
    @ensures un entier associé à Rejette, Accepte, Decale, Réduit qui correspond à la case (s,c) du tableau
*/

int action(etat s, lettre e, int* act){
    int val = act[s*128+atoi(&e)];
    return val;
}

/*  @requires la ligne dec sous forme d'un tableau d'entiers, une pile p, un état et une lettre 
    @assigns la pile
    @ensures un état
*/

etat decale(int* dec, pile *p, etat e, lettre l){
    empilement(p,e);
    int i=0;
    int j=1;
    while((((dec[i])!=e)&&(dec[j]!=l))||((dec[i]!='\255')&&(dec[j]!='\255'))){ //à partir d'un certain rang on atteint soit les '/255' de l'automate soit l'état ou la lettre que l'on recherche
        i=i+3;
        j=j+3;
    }
    return (dec[j+1]);
}

/*  @requires une pile, un etat et un tableau d'entier red1 
    @assigns la pile 
    @ensures un etat 
*/

etat reduit_entier(pile *p, etat e, int* red1){
    int n = (red1[e]);
    int j;
    for(j=0;j<n-1;j++){
        pop(p);
    }
    etat a=pop(p);      
    return a;
}

/*  @requires un etat et une chaine de caractères aut 
    @assigns nothing
    @ensures un symbole non-terminal
*/

int reduit_sym_non_term(etat e, int* red2){
    symbole m =  red2[e];      
    return m;
}

/*  @requires un tableau d'entier, un état et un symbole non-terminal
    @assigns nothing
    @ensures un état
*/

etat branchement(int* branch, etat s, symbole sym){
    int i=0;
    int j=1;
    while((((branch[i])!=s)&&(branch[j]!=sym))||((branch[j]!='\255')&&(branch[j]!='\255'))){ //la chaîne de caractères branchement fini avec '/255' donc la boucle s'arrêtera à ce moment là
        i=i+3;
        j=j+3;
    }
    return (branch[j+1]);    
}


/*  @requires une pile, un etat s, une lettre c et la partie de l'automate qui contient action, réduit et branchement
    @assigns la pile
    @ensures l'entier correspondant au comportement de l'automate en renvoyant l'entier correspondant à accepter ou refuser
*/

int comportement(pile *p, etat s, lettre c, int* act, int* red1, int * red2, int * branch){
    int a = action(s,c, act);
    int valeur;
    if(a==0){ // action Rejette
        valeur = 0;
    }
    else if(a==1){ //action Accepte
        valeur = 1;
    }
    else if(a==2){ //action Décale
        comportement(p, decale(act,p,s,c), c, act, red1, red2, branch); //l'automate renvoie vers un état "Accepte" ou "Rejette" à partir d'un certain nombre d'étapes
    }
    else if(a==3){ //action Réduit
        int n = reduit_entier(p,s,red1); 
        char c = reduit_sym_non_term(s, red2);
        int i;
        for(i=0; i<n-1 ; i++){
            pop(p);
        }
        etat s_bis = pop(p);
        etat s_tris=branchement(branch,s_bis,c);

        empilement(p,s_tris);
        comportement(p, s_tris, c, act, red1, red2, branch); //l'automate renvoie vers un état "Accepte" ou "Rejette" à partir d'un certain nombre d'étapes 
    }
    else{
        valeur = 2;
    }
    return valeur;
}

/*  @requires un entier
    @assigns nothing
    @renvoie Accepter ou rejeter en fonction de la valeur de l'entier
*/

void print(int a){
    if(a==0){
        printf("Accepté");
    }
    else if(a==1){
        printf("Rejeté");
    }
    else{
        printf("Erreur");
    }
}