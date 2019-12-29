#ifndef FONCTIONS
#define FONCTIONS

#include <stdio.h>
#include <stdlib.h>

int** init_mat_A(int taille);//pour initialiser la matrice A par l'utilisateur
void affiche_mat_A(int taille,int** mat_A); //affichage de la matrice A
int* init_vect_b(int taille); //initialisation du vecteur b par l'utilisateur
void affiche_vect_b(int taille,int* vect_b); //affichage du vecteur b

#endif
