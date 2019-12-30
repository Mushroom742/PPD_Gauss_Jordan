#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

int main(void){
	int taille,i;
	double** mat_A = NULL;
	double* vect_b = NULL;
	
	srand(time(NULL));
	
	do {
		printf("Entrez la taille n de la matrice\n");
		scanf(" %d",&taille);
	} while (taille<=0);
	
	//mat_A = init_mat_A(taille);
	mat_A = init_mat_A_alea(taille);
	affiche_mat_A(taille,mat_A);
	
	//vect_b = init_vect_b(taille);
	vect_b = init_vect_b_alea(taille);
	affiche_vect_b(taille,vect_b);
	
	elimin_gauss_jordan(taille,mat_A,vect_b);
	
	resol_systeme(taille,mat_A,vect_b);
	printf("Solution : \n");
	affiche_vect_b(taille,vect_b);
	
	free(vect_b);
	for(i=0;i<taille;i++){
		free(mat_A[i]);
	}
	free(mat_A);
	
	return 0;
}
