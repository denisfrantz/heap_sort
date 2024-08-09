#include <stdio.h>
#include <stdlib.h>
#define TAM 13

void inicializa_heap (int *lista, int i, int fim) {
	int j, aux;
	
	aux = lista[i];
	j = (i * 2) + 1;
	
	while (j <= fim) {
		if (j < fim) {
			if (lista[j] < lista[j + 1])
				j++;
		}
		
		if (aux < lista[j]) {
			lista[i] = lista[j];
			i = j;
			j = (i * 2) + 1;
		}
		else 
			j = fim + 1;
	}
	lista[i] = aux;
}

void heapSort (int *lista) {
	int i, aux;
	
	for (i = (TAM - 1)/2; i >= 0; i--) 
		inicializa_heap (lista, i, TAM - 1);
		
	for (i = TAM - 1; i >= 1; i--) {
		aux = lista[0];
		lista[0] = lista[i];
		lista[i] = aux;
		inicializa_heap (lista, 0, i - 1);
	}
	
	printf ("\n\nLISTA ORDENADA\n==============\n");
	for (i = 0; i < TAM; i++)
		printf ("%d   ", lista[i]);
}

int main() {
	int lista[TAM], i, *l;
	
	srand(time(NULL));
	
	printf ("LISTA ORIGINAL\n==============\n");
	for (i = 0; i < TAM; i++) {
		lista[i] = rand() % 101;
		printf ("%d   ", lista[i]);
	}
	
	l = lista;
	
	heapSort(l);
	
	return 0;
}
