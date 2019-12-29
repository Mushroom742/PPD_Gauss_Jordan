#include "fonctions.h"

int** init_mat_A(int taille){
	int** mat_A = NULL;
	int i,j;
	
	mat_A = malloc(taille*sizeof(int*));
	for(i=0;i<taille;i++){
		mat_A[i]=malloc(taille*sizeof(int));
	}
	
	printf("Entrez les valeurs de la matrice A\n");
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("Entrez le coefficient %d %d\n",i,j);
			scanf(" %d",&(mat_A[i][j]));
		}
	}
	
	return mat_A;
}

void affiche_mat_A(int taille,int** mat_A){
	int i,j;
	printf("Matrice A : \n");
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf(" %d ",mat_A[i][j]);
		}
		printf("\n");
	}
}


int* init_vect_b(int taille){
	int* vect_b = NULL;
	int i;
	
	vect_b = malloc(taille*sizeof(int));
	
	printf("Entrez les valeurs du vecteur b \n");
	for(i=0;i<taille;i++){
		printf("Entrez le coefficient %d\n",i);
		scanf(" %d",&(vect_b[i]));
	}
	
	return vect_b;
	
}

void affiche_vect_b(int taille,int* vect_b){
	int i;
	
	printf("Vecteur b : \n");
	for(i=0;i<taille;i++){
		printf(" %d ",vect_b[i]);
	}
	printf("\n");
	
}
