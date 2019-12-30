#ifndef FONCTIONS
#define FONCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** init_mat_A(int taille);//pour initialiser la matrice A par l'utilisateur
double** init_mat_A_alea(int taille); //initialisation de la matrice A aléatoirement
void affiche_mat_A(int taille,double** mat_A); //affichage de la matrice A
double* init_vect_b(int taille); //initialisation du vecteur b par l'utilisateur
double* init_vect_b_alea(int taille); //initialisation du vecteur b aléatoirement
void affiche_vect_b(int taille,double* vect_b); //affichage du vecteur b
void elimin_gauss_jordan(int taille,double** mat_A,double* vect_b); //diagonalisation de la matrice
void resol_systeme(int taille,double** mat_A, double* vect_b); //résoud le système linéaire

#endif
