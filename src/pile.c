#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

#define SIZE 256

//fichier automate passé en paramètre de l'executable 

typedef int etat;

/*  @requires nothing
    @assigns nothing
    @ensures empty stack
*/

pile* empty(){
    pile* p = malloc(sizeof(pile));
    p->top=-1;
    return p;
}

/*  @requires nothing
    @assigns nothing
    @ensures une pile avec l'état initial
*/

pile initial(){
    pile p;
    p.top = 0;
    return p; 
}

/*  @requires une pile et un état
    @assigns la pile
    @ensures l'empilement de l'état à la pile
*/

void empilement(pile *p, etat e){
    p->top += 1;
    p->pile[p->top] = e;
}

/*  @requires une pile 
    @assigns la pile
    @ensures enlève le top de la pile et le renvoie 
*/

etat pop(pile *p){
    int n = p->top;
    etat e = p->pile[n];
    
    pile *pile_bis = empty();
    
    int i;
    for(i=0; i<n-1; i++){
        pile_bis->pile[i] = p->pile[i];
    }
    p=pile_bis;
    p->top = p->top - 1;

    return e;
}
