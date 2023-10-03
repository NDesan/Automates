#ifndef PILE_H
#define PILE_H
#define SIZE 256

//fichier automate passé en paramètre de l'executable 

typedef int etat;

struct pile{
    etat top;
    etat pile[SIZE];
};

typedef struct pile pile;


/*  @requires nothing
    @assigns nothing
    @ensures empty stack
*/

pile* empty();

/*  @requires nothing
    @assigns nothing
    @ensures une pile avec l'état initial
*/

pile initial();

/*  @requires une pile et un état
    @assigns la pile
    @ensures l'empilement de l'état à la pile
*/

void empilement(pile *p, etat e);

/*  @requires une pile 
    @assigns la pile
    @ensures enlève le top de la pile et le renvoie 
*/

etat pop(pile *p);

#endif