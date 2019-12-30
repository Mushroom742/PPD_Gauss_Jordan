#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

int main(void){
	int taille,i,choix,nb_thread;
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

	do{
		printf("Sequentiel(1) ou Parallèle(2)\n");
		scanf(" %d", &choix);
	}while((choix!=1) && (choix!=2));

	if(choix==1){
		elimin_gauss_jordan(taille,mat_A,vect_b);

		resol_systeme(taille,mat_A,vect_b);
		printf("Solution : \n");
		affiche_vect_b(taille,vect_b);
	}

	if(choix==2){

		do {
			printf("Nombre de threads ?\n");
			scanf(" %d",&nb_thread);
		} while (nb_thread<=0);


		elimin_gauss_jordan_parallel(taille,mat_A,vect_b,nb_thread);

		resol_systeme_parallel(taille,mat_A,vect_b,nb_thread);
		printf("Solution : \n");
		affiche_vect_b(taille,vect_b);
	}

	free(vect_b);
	for(i=0;i<taille;i++){
		free(mat_A[i]);
	}
	free(mat_A);

	return 0;
}
