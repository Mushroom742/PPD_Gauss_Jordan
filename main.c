#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main(void){
	int taille;
	int** mat_A = NULL;
	int* vect_b = NULL;
	
	do {
		printf("Entrez la taille n de la matrice\n");
		scanf(" %d",&taille);
	} while (taille<=0);
	
	mat_A = init_mat_A(taille);
	affiche_mat_A(taille,mat_A);
	
	vect_b = init_vect_b(taille);
	affiche_vect_b(taille,vect_b);
	
	return 0;
}
