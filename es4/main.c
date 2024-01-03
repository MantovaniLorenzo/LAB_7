#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 30
#define N 100
int main(void) {
	
	FILE* fp;
	char nome[M], nome_at[N][M], tmp[M];
	int i= 0, j= 0, count = 0, punteggio[N], tmp_p;

	printf("Inserisci il nome del file di input:");
	scanf("%s", nome);

	// APERTURA FILE
	fp = fopen(nome, "r");
	if (fp == NULL) {
		printf("ERRORE in apertura file.\n");
		exit(EXIT_FAILURE);
	}

	// LETTURA FILE 
	count = 0;
	while(count < 100 || !feof(fp)){
		fscanf(fp, "%s%d", nome_at[i], &punteggio[i]);
		count++;
	}
	int dim = count;
	fclose(fp);

	// INSERIMENTO ORDINATO NEL FILE

	for (i = 0; i < dim; i++) {
		for (j = i; j < dim - 1 - i; j++) {
			if (strcmp(nome_at[j], nome_at[j + 1]) > 0) {
				strcpy(tmp, nome_at[j]);
				strcpy(nome_at[j], nome_at[j + 1]);
				strcpy(nome_at[j + 1], tmp);
				tmp_p = punteggio[j];
				punteggio[j] = punteggio[j + 1];
				punteggio[j + 1] = tmp_p;
			}
		}
	}

	// STAMPA IN ORDINE ALFABETICO 

	int max1 = 0, max2 = 0, max3 = 0;
	char primo[M], secondo[M], terzo[M];
	printf("L'elenco in ordine alfabetico e': \n");
	fp = fopen("garaord.txt", "w");
	for (i = 0; i < dim; i++) {
		fprintf(fp, "%s %d\n", nome_at[i], punteggio[i]);
		printf("%s %d\n", nome_at[i], punteggio[i]);
		if (punteggio[i] > max1) {
			max3 = max2;
			strcpy(terzo, secondo);
			max2 = max1;
			strcpy(secondo, primo);
			max1 = punteggio[i];
			strcpy(primo, nome_at[i]);
		}
		else if (punteggio[i] > max2) {
			max3 = max2;
			strcpy(terzo, secondo);
			max2 = punteggio[i];
			strcpy(secondo, nome_at[i]);
		}
		else if (punteggio[i] > max3) {
			max3 = punteggio[i];
			strcpy(terzo, nome_at[i]);
		}
	}
	fclose(fp);

	printf("\n Il primo arrivato e' %s con %d punti.\n", primo, max1);
	printf("\n Il primo arrivato e' %s con %d punti.\n", secondo, max2);
	printf("\n Il primo arrivato e' %s con %d punti.\n", terzo, max3);

	return 0;
}