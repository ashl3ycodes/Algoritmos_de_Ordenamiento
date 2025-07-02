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

void insert(int arr[], const int n) {
	for(int k = 1; k < n; k++) {
		const int y = arr[k];
		int i = k - 1;
		while(i >= 0 && y < arr[i]) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = y;
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

	insert(arreglo, SIZE);

	printf("\nArreglo ordenado\n");
	imprime_arreglo(arreglo);

	return 0;
}