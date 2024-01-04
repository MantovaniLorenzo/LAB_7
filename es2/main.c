#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 80
#define MAX 20

typedef struct sc {
	char materia[MAX];
	char nome[MAX];
	char cognome[MAX];
	int periodo;
	int crediti;
	float psup;
}libretto;


int main (void) {

	FILE* fp;
	char nome_file[MAX];
	libretto* v;
	int i, dim, max_crediti = 0, max_pos, sum_cred = 0, sum_sup = 0, sup1 = 100, sup2 = 100, sup3 = 100, sup4 = 100, flag = 0;
	char mat1[MAX], mat2[MAX], mat3[MAX], mat4[MAX];
	float media = 0;

	printf("Inserisci il nome del file di input: ");
	scanf("%s", nome_file);

	//ALLOCAZIONE VETTORE
	v = (libretto*)malloc(N * sizeof(libretto));
	if (v == NULL) {
		printf("ERRORE di allocazione.\n");
		exit(EXIT_FAILURE);
	}

	//APERTURA FILE

	fp = fopen(nome_file, "r");
	if (fp == NULL) {
		printf("ERRORE di apertura file di input.\n");
		exit(EXIT_FAILURE);
	}

	// LETTURA FILE
	i = 0;
	while (i < N && !feof(fp)) {
		fscanf(fp, "%s%s%s%d%d%f", v[i].materia, v[i].nome, v[i].cognome, &v[i].periodo, &v[i].crediti, &v[i].psup);
		i++;
	}
	dim = i;  // dimensione effettiva dei dati
	fclose(fp);


	// RICERCA MATERIA CON PIù CREDITI 
	max_pos = 0;
	for (i = 0; i < dim; i++) {
		if (v[i].crediti > max_crediti) {
			max_crediti = v[i].crediti;
			max_pos = i;
		}
	}

	printf("\nLa materia con il massimo numero di crediti e' '%s' con %d crediti.\n", v[max_pos].materia, max_crediti);


	// RICERCA MATERIA PIù DIFFICILE PER PERIODO DIDATTICO
	// POTEVA ESSERE FATTO CON UNO SWITCH CASE VOLENDO

	for (i = 0; i < dim; i++) {
	
		if (v[i].periodo == 1) {
			if (v[i].psup < sup1) {
				sup1 = v[i].psup;
				strcpy(mat1, v[i].materia);
			}
		}
		else if (v[i].periodo == 2) {
			if (v[i].psup < sup2) {
				sup2 = v[i].psup;
				strcpy(mat2, v[i].materia);
			}
		}
		else if (v[i].periodo == 3) {
			if (v[i].psup < sup3) {
				sup3 = v[i].psup;
				strcpy(mat3, v[i].materia);
			}
		}
		else if (v[i].periodo == 4) {
			if (v[i].psup < sup4) {
				sup4 = v[i].psup;
				strcpy(mat4, v[i].materia);
			}
		}
		else {
			printf("\nIl file contiene periodi non validi, controllare il file.\n");
			exit(EXIT_FAILURE);
		}
		
	}

	if(sup1 != 100) // servono da controlli se rimane a 100 vuol dire che non sono presenti materie di quel periodo e quindi non stampa
		printf("\nLa materia piu' difficile del periodo 1 e' stata:  %s.\n", mat1);
	if(sup2 != 100)
		printf("La materia piu' difficile del periodo 2 e' stata:  %s.\n", mat2);
	if(sup3 != 100)
		printf("La materia piu' difficile del periodo 3 e' stata:  %s.\n", mat3);
	if(sup4 != 100)
		printf("La materia piu' difficile del periodo 4 e' stata:  %s.\n", mat4);


	//DATI PROFESSORE INSERITO DA TASTIERA

	
		printf("\nInserire il cognome di un professore: ");
		scanf("%s", nome_file);  // riciclato variabile

		for (int i = 0; i < dim; i++) {
			if (strcmp(v[i].cognome, nome_file) == 0) {
				flag++;
				sum_cred += v[i].crediti;
				sum_sup += v[i].psup;
			}
		}

		

		if (flag == 0) {
			printf("\nIl professore cercato non risulta in elenco.\n");
		}
		else {

			printf("\nLa somma dei crediti delle materie sostenute dal professore '%s' e' di %d crediti.\n", nome_file, sum_cred);
			printf("La media di superamento degli esami tenuti dal professore '%s' e' %.2f", nome_file, (float)sum_sup / flag);
		}
	
	return 0;
}