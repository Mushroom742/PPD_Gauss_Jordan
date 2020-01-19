#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

int main(void){

	//Initialisation
	int taille,i,choix,nb_thread = 1;
	double** mat_A = NULL;
	double* vect_b = NULL;
	double temps_debut, temps_final;
	srand(time(NULL));

	//Definition de la taille de la matrice
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

	//Choix entre les deux versions de l'algorithme
	do{
		printf("Sequentiel(1) ou Parallèle(2)\n");
		scanf(" %d", &choix);
	}while((choix!=1) && (choix!=2));

	if(choix==1){

		temps_debut = omp_get_wtime();

		elimin_gauss_jordan(taille,mat_A,vect_b);
		resol_systeme(taille,mat_A,vect_b);

		printf("Solution : \n");
		affiche_vect_b(taille,vect_b);

	}

	if(choix==2){

		//Definition du nombre de threads utilisé
		do {
			printf("Nombre de threads ?\n");
			scanf(" %d",&nb_thread);
		} while (nb_thread<=0);

		temps_debut = omp_get_wtime();

		elimin_gauss_jordan_parallel(taille,mat_A,vect_b,nb_thread);
		resol_systeme_parallel(taille,mat_A,vect_b,nb_thread);

		printf("Solution : \n");
		affiche_vect_b(taille,vect_b);
	}

	//Affichage du temps et des charges
	temps_final = omp_get_wtime() -temps_debut;
	printf("Temps pris: %f\n",temps_final);

	free(vect_b);
	for(i=0;i<taille;i++){
		free(mat_A[i]);
	}
	free(mat_A);

	return 0;
}
