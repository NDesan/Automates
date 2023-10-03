#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "pile.h"
#include "automate_traitement.h"

#define SIZE 256

int main(int argc, char* argv[]){
    if (argc!=2){
        fprintf(stderr,"%s : trop ou pas d'arguments", argv[0]);
    }

    if (argv[1] == NULL){
        printf("Erreur fopen\n");
        return 1;
    }

    FILE* fp;
    fp = fopen(argv[1],"r");

    if (fp == NULL) {
        printf("Erreur fopen\n");
        return 1;
    }

    char etat[256];
    fgets(etat, 256, fp);
    int n=nombre_etats(etat); //nombre états de l'automate

    int *action=malloc(n*128*sizeof(int)); //valeur de action dans le tableau action
    int i;
    for(i=0; i<(n*128); i++){
        action[i]= fgetc(fp);
    }

    int *red1=malloc(n*sizeof(int)); //valeur de la première composante de réduit dans le tableau red1
    for(i=0; i<n; i++){
        red1[i]= fgetc(fp);
    }

    int *red2=malloc(n*sizeof(int)); //valeur de la deuxième composante de réduit dans le tableau red2
    for(i=0; i<n; i++){
        red2[i]= fgetc(fp);
    }

    int *dec=malloc(n*256*sizeof(int)); //valeur de decale dans le tableau dec
    for(i=0; i<n*256; i++){
        dec[i]= fgetc(fp);
    }
    
    int *branch=malloc(n*256*sizeof(int)); //valeur de branchement dans le tableau branch
    for(i=0; i<n*256; i++){
        branch[i]= fgetc(fp);
    }

    char* ch= (char *) malloc(sizeof(char)); //ch chaine de caractère dans l'entrée standard
    scanf("%s", ch);
    pile p =initial();
    
    i=0;
    int a = comportement(&p, 0, *ch,action,red1,red2,branch);
    print(a);
    printf("\n");

    return 0;
}
