 # Traitement des automates LR(1)

Ce projet implémente un programme permettant de traiter des automates LR(1) afin de reconnaître des langages spécifiques à partir d'une description fournie dans un fichier.

---

## Sommaire
1. [Introduction](#introduction)
2. [Piles](#piles)
3. [Automate - Traitement](#automate---traitement)
4. [Main](#main)
5. [Conclusion](#conclusion)

---

## Introduction

L'objectif de ce projet est de concevoir un programme capable d'exécuter un automate LR(1) pour analyser et reconnaître des langages formels. Le fonctionnement principal est détaillé comme suit :

- Le programme prend en entrée un fichier décrivant un automate LR(1).
- Il analyse des lignes données sur l'entrée standard et détermine si elles sont reconnues par l'automate.
- Pour chaque ligne, le programme retourne :
  - **Accepted** si la ligne est reconnue.
  - **Rejected** sinon.

Pour exécuter correctement les transitions de l'automate, une pile est utilisée. Elle commence avec un unique état initial, décrit dans `pile.h`.

---

## Piles

Les piles sont essentielles pour gérer les transitions et les réductions des automates LR(1). Par exemple, lors d'une opération `réduit(s) = (n, A)`, il est nécessaire de dépiler la pile `n` fois pour récupérer l'état souhaité `s'`.

### Détails techniques :
- **Structure** : 
  - Les piles stockent des états sous forme d'entiers.
  - Elles possèdent un état `top` pour le sommet de la pile.
  - Les états sont sauvegardés dans un tableau de taille maximale `SIZE = 256`.
- **Dépendance** :
  - Le module `automate_traitement.h` dépend directement de `pile.h` (cf. `Makefile`).

---

## Automate - Traitement

La partie "traitement des automates" repose sur les opérations effectuées sur les piles. Cette composante du projet permet :
- De lire la description d'un automate LR(1) à partir d'un fichier d'entrée.
- D'exécuter les transitions définies dans l'automate pour vérifier la validité des lignes d'entrée.

Les principaux fichiers impliqués sont :
- **automate_traitement.h** : Contient les définitions des fonctions principales pour le traitement.
- **automate_traitement.c** : Implémente la logique de l'automate.

---

## Main

Le fichier principal, `main.c`, coordonne l'exécution du programme. Il réalise les étapes suivantes :
1. Lecture du fichier contenant la description de l'automate LR(1).
2. Lecture des lignes depuis l'entrée standard.
3. Appel des fonctions du module `automate_traitement` pour vérifier si chaque ligne est reconnue.
4. Affichage des résultats (**Accepted** ou **Rejected**) pour chaque ligne.

---

## Conclusion

Ce projet démontre l'implémentation pratique d'un automate LR(1) et l'importance des structures de données comme les piles dans le traitement des langages formels. Il met en évidence les interactions entre différentes parties du code (par exemple, entre `pile.h` et `automate_traitement.h`) pour offrir une solution modulaire et extensible.

---

## Compilation et Exécution

### Compilation
Utilisez le fichier `Makefile` fourni pour compiler le projet :
```bash
make

