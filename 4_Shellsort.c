#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAXRAND 5000

void imprime_arreglo(int arreglo[]) {
	for(int i = 0; i < SIZE; i++)
		printf("%d,", arreglo[i]);
	putchar('\n');
}

void shellsort(int arr[], const int n, int incr[], const int numinc) {
	int k;
	for(int i = 0; i < numinc; i++) {
		const int span = incr[i];
		for(int j = span; j < n; j++) {
			const int y = arr[j];
			for(k = j - span; k >= 0 && y < arr[k]; k -= span) {
				arr[k + span] = arr[k];
			}
			arr[k + span] = y;
		}
	}
}

int main() {
	int arreglo[SIZE];

	srand(time(NULL));

	for(int i = 0; i < SIZE; i++) {
		arreglo[i] = rand() % MAXRAND;
	}

	printf("Arreglo desordenado\n");
	imprime_arreglo(arreglo);

	shellsort(arreglo, SIZE, (int[]){5, 3, 1}, 3);

	printf("\nArreglo ordenado\n");
	imprime_arreglo(arreglo);

	return 0;
}