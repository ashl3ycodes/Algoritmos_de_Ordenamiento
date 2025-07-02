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

void burbuja(int arr[], const int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) {
				const int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
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

	burbuja(arreglo, SIZE);

	printf("\nArreglo ordenado\n");
	imprime_arreglo(arreglo);

	return 0;
}