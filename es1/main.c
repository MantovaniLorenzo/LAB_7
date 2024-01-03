#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 3

int main(void) {

	int mat[N][N], find, n, count = 0;

	printf("Inserisci i valori della matrice '%d x %d':\n", N, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);
	}

	printf("\nLa matrice appena creata e' la seguente:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
		
	printf("\nInserire l'elemento da cercare all'interno della matrice: ");
	scanf("%d", &find);

	do {
		printf("\nInserire quanto deve essere (almeno) lunga la sequenza da ricercare (ricorda la matrice e' %d x %d): ", N, N);
		scanf("%d", &n);
		if (count > N) {
			printf("Sequenza troppo lunga, RIPROVARE.\n");
		}
	} while(count > N);

	// ricerca sulle righe 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - n +1 ; j++) {
				count = 0;
				for (int r = 0; r < n; r++) {
					if (mat[i][j+r] == find)
						count++;
				} if (count == n)
					printf("La sequenza e' stata trovata alla %d-esima riga.\n", i+1);
		}
	}


	// ricerca sulle colonne 

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - n + 1 ; i++) {
			count = 0;
			for (int r = 0; r < n; r++) {
				if (mat[i + r][j] == find)
					count++;
			} if (count == n)
				printf("La sequenza e' stata trovata alla %d-esima colonna.\n", j + 1);
		}

	}
	
	return 0;
}