#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tren {
	char part[20];
	char arr[20];
}treni;

int main(void) {

	FILE* fp;
	char nome[20];
	treni* v;
	int dim, count_arr = 0, count_part = 0;

	printf("Inserire il numero di dati da voler analizzare: ");
	scanf("%d", &dim);

	printf("Inserisci il nome del file di input: ");
	scanf_s("%s", nome, 20);

	// APERTURA FILE

	fp = fopen(nome, "r");
	if (fp == NULL) {
		printf("ERRORE in apertura del file.\n");
		exit(EXIT_FAILURE);
	}

	// ALLOCAZIONE VETTORE

	v = (treni*)malloc(dim * sizeof(treni));
	if (v == NULL) {
		printf("ERRORE di allocazione.\n");
		exit(EXIT_FAILURE);
	}
	//LETTURA FILE
	int i = 0;
	while (i < dim && fscanf(fp, "%s%*d%s%*d", v[i].part, v[i].arr)) {
		i++;
	}
	dim = i;
	fclose(fp);

	// RICHIESTA STAZIONE DA TASTIERA

	printf("\nInserire il nome di una citta': ");
	scanf("%s", nome);

	for (i = 0; i < dim; i++) {
		if (strcmp(nome, v[i].part) == 0) {
			count_part++;
		}
		else if (strcmp(nome, v[i].arr) == 0) {
			count_arr++;
		}
	}
	if (count_part == 0 && count_arr == 0) {
		printf("Non ci sono treni ne in partenza ne in arrivo nella citta' indicata.\n");
	}
	else {
		printf("\nI treni in partenza da '%s' sono %d.\n", nome, count_part);
		printf("\nI treni in arrivo da '%s' sono %d.\n", nome, count_arr);
	}



	return 0;
}