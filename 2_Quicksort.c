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

int particion(int arr[], const int linf, const int lsup) {
	const int a = arr[linf];
	int arriba = lsup;
	int abajo = linf;

	while(abajo < arriba) {
		while(arr[abajo] <= a && abajo < lsup) {
			abajo++;
		}
		while(arr[arriba] > a) {
			arriba--;
		}
		if(abajo < arriba) {
			const int temp = arr[abajo];
			arr[abajo] = arr[arriba];
			arr[arriba] = temp;
		}
	}

	arr[linf] = arr[arriba];
	arr[arriba] = a;

	return arriba;
}

void quick(int arr[], const int linf, const int lsup) {
	if(linf >= lsup) {
		return;
	}
	const int j = particion(arr, linf, lsup);
	quick(arr, linf, j - 1);
	quick(arr, j + 1, lsup);
}

int main() {
	int arreglo[SIZE];

	srand(time(NULL));

	for(int i = 0; i < SIZE; i++) {
		arreglo[i] = rand() % MAXRAND;
	}

	printf("Arreglo desordenado\n");
	imprime_arreglo(arreglo);

	quick(arreglo, 0, SIZE - 1);

	printf("\nArreglo ordenado\n");
	imprime_arreglo(arreglo);

	return 0;
}