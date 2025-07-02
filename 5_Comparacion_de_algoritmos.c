#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 99999
#define MAXRAND 10000

void imprime_arreglo(int arreglo[]) {
	for(int i = 0; i < SIZE; i++)
		printf("%d,", arreglo[i]);
	putchar('\n');
}

// Bubble Sort
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

// Quick Sort
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

// Insertion Sort
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

// Shell Sort
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

void fillArray(int arreglo[], const int size, const int maxrand) {
	for(int i = 0; i < size; i++) {
		arreglo[i] = rand() % maxrand;
	}
}

void cloneArray(int origen[], int destino[], const int n) {
	for(int i = 0; i < n; i++) {
		destino[i] = origen[i];
	}
}

void timedBurbuja(int arr[], const int n) {
	const time_t inicio = time(NULL);
	burbuja(arr, n);
	const time_t fin = time(NULL);
	printf("Tiempo total: %ld segundos\n", fin - inicio);
}

void timedQuick(int arr[], const int n) {
	const time_t inicio = time(NULL);
	quick(arr, 0, n - 1);
	const time_t fin = time(NULL);
	printf("Tiempo total: %ld segundos\n", fin - inicio);
}

void timedInsert(int arr[], const int n) {
	const time_t inicio = time(NULL);
	insert(arr, n);
	const time_t fin = time(NULL);
	printf("Tiempo total: %ld segundos\n", fin - inicio);
}

void timedShellsort(int arr[], const int n, int incr[], const int numinc) {
	const time_t inicio = time(NULL);
	shellsort(arr, n, incr, numinc);
	const time_t fin = time(NULL);
	printf("Tiempo total: %ld segundos\n", fin - inicio);
}

int main() {
	int arreglo[SIZE];
	int testArray[SIZE];
	int incr[] = {5, 3, 1};
	const int numinc = sizeof(incr) / sizeof(incr[0]);

	srand(time(NULL));
	fillArray(arreglo, SIZE, MAXRAND);

	cloneArray(arreglo, testArray, SIZE);
	printf("Bubble sort\n");
	timedBurbuja(testArray, SIZE);
	printf("\n");

	cloneArray(arreglo, testArray, SIZE);
	printf("Quick sort\n");
	timedQuick(testArray, SIZE);
	printf("\n");

	cloneArray(arreglo, testArray, SIZE);
	printf("Insertion sort\n");
	timedInsert(testArray, SIZE);
	printf("\n");

	cloneArray(arreglo, testArray, SIZE);
	printf("Shell sort\n");
	timedShellsort(testArray, SIZE, incr, numinc);

	return 0;
}