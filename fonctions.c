#include "fonctions.h"

double** init_mat_A(int taille){
	double** mat_A = NULL;
	int i,j;

	mat_A = malloc(taille*sizeof(double*));
	for(i=0;i<taille;i++){
		mat_A[i]=malloc(taille*sizeof(double));
	}

	printf("Entrez les valeurs de la matrice A\n");
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("Entrez le coefficient %d %d\n",i,j);
			scanf(" %lf",&(mat_A[i][j]));
		}
	}

	return mat_A;
}

double** init_mat_A_alea(int taille){
	double** mat_A = NULL;
	int i,j;

	mat_A = malloc(taille*sizeof(double*));
	for(i=0;i<taille;i++){
		mat_A[i]=malloc(taille*sizeof(double));

		for(j=0;j<taille;j++){
			if((j>0 && j==i-1) || (j<taille && j==i+1) || j==i){
				mat_A[i][j] = rand()%100;
			}
			else {
				mat_A[i][j] = 0;
			}
		}
	}

	return mat_A;

}

void affiche_mat_A(int taille,double** mat_A){
	int i,j;
	printf("Matrice A : \n");
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf(" %lf ",mat_A[i][j]);
		}
		printf("\n");
	}
}


double* init_vect_b(int taille){
	double* vect_b = NULL;
	int i;

	vect_b = malloc(taille*sizeof(double));

	printf("Entrez les valeurs du vecteur b \n");
	for(i=0;i<taille;i++){
		printf("Entrez le coefficient %d\n",i);
		scanf(" %lf",&(vect_b[i]));
	}

	return vect_b;

}

double* init_vect_b_alea(int taille){
	double* vect_b = NULL;
	int i;

	vect_b = malloc(taille*sizeof(double));

	for(i=0;i<taille;i++){
		vect_b[i] = rand()%100;
	}

	return vect_b;
}

void affiche_vect_b(int taille,double* vect_b){
	int i;

	printf("Vecteur b : \n");
	for(i=0;i<taille;i++){
		printf(" %lf ",vect_b[i]);
	}
	printf("\n");

}


void elimin_gauss_jordan(int taille,double** mat_A,double* vect_b){
	int i,j,k,lignePivot;
	double tmp;

	for(k=0;k<taille;k++){
		if(mat_A[k][k]==0){
			lignePivot=k+1;
			while(mat_A[lignePivot][k]==0){
				lignePivot++;
			}
			//permutation
			for(j=k;j<taille;j++){
				tmp = mat_A[k][j];
				mat_A[k][j] = mat_A[lignePivot][j];
				mat_A[lignePivot][j] = tmp;
			}
			tmp = vect_b[k];
			vect_b[k] = vect_b[lignePivot];
			vect_b[lignePivot] = tmp;
		}

		//diagonalisation

		for(i=0;i<taille;i++){
			if(i!=k){
				for(j=k+1;j<taille;j++){
					mat_A[i][j] = mat_A[i][j]-(mat_A[k][j]/mat_A[k][k])*mat_A[i][k];
				}
			}
			tmp = vect_b[k];
			vect_b[i] = vect_b[i]-(mat_A[i][k]/mat_A[k][k])*vect_b[k];
			vect_b[k] = tmp;
		}
	}
}

void resol_systeme(int taille,double** mat_A, double* vect_b){
	int i;

	for(i=0;i<taille;i++){
		vect_b[i] = vect_b[i]/mat_A[i][i];
	}
}

void elimin_gauss_jordan_parallel(int taille,double** mat_A,double* vect_b, int nb_thread){
	int i,j,k,lignePivot;
	double tmp;
	omp_set_num_threads(nb_thread);

	#pragma omp parallel for private(i,j)
	//SCHEDULE ?
	for(k=0;k<taille;k++){
		if(mat_A[k][k]==0){
			lignePivot=k+1;
			while(mat_A[lignePivot][k]==0){
				lignePivot++;
			}
			//permutation
			#pragma omp parallel for
			for(j=k;j<taille;j++){
				tmp = mat_A[k][j];
				mat_A[k][j] = mat_A[lignePivot][j];
				mat_A[lignePivot][j] = tmp;
			}
			tmp = vect_b[k];
			vect_b[k] = vect_b[lignePivot];
			vect_b[lignePivot] = tmp;
		}

		//diagonalisation

		for(i=0;i<taille;i++){
			if(i!=k){
				for(j=k+1;j<taille;j++){
					mat_A[i][j] = mat_A[i][j]-(mat_A[k][j]/mat_A[k][k])*mat_A[i][k];
				}
			}
			tmp = vect_b[k];
			vect_b[i] = vect_b[i]-(mat_A[i][k]/mat_A[k][k])*vect_b[k];
			vect_b[k] = tmp;
		}
	}
}

void resol_systeme_parallel(int taille,double** mat_A, double* vect_b, int nb_thread){
	int i;
	omp_set_num_threads(nb_thread);

	#pragma omp parallel for
	for(i=0;i<taille;i++){
		vect_b[i] = vect_b[i]/mat_A[i][i];
	}
}
