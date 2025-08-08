#include <stdio.h>
#define N 5
/*
Desarrollar un programa en lenguaje C que tome una matriz bidimensional (N*N) de números
enteros y la ordene siguiendo el criterio específico del ejemplo
Dada la siguiente matriz de entrada:

        {50, 14, 15, 17, 21},
        {31, 18, 10, 40, 15},
        {35, 46, 47, 18, 44},
        {11, 26, 32, 27, 40},
        {30, 30, 22, 14, 44}

Resultado final:

        {30, 40, 44, 47, 50},
        {21, 30, 35, 44, 46},
        {15, 18, 27, 32, 40},
        {14, 15, 18, 26, 31},
        {10, 11, 14, 17, 22}
*/

void ingresar(int M[N][N]) {
	printf("Ingrese los elementos de la matriz %dx%d:\n", N, N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("M[%d][%d]: ", i, j);
			scanf("%d", &M[i][j]);
		}
	}
}

void imprimir(int M[N][N]) {	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf(" %d", M[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}

void ordenar(int M[N][N]) {
	int total = N * N;
	int A[N*N], k = 0;
	 for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[k++] = M[i][j];

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (A[i] > A[j]) {
                int t = A[i]; A[i] = A[j]; A[j] = t;
            }
        }
    }

    int aux = total - 1;
    
    for (int s = 0; s <= 2 * (N - 1); s++) {
        int i_inicio, i_fin;
        if (s < N) {
            i_inicio = s;
            i_fin = 0;
        } 
        else {
            i_inicio = N - 1;
            i_fin = s - (N - 1);
        }
        for (int i = i_inicio; i >= i_fin; i--) {
            int j = s - i;
            
            int fila_final = j;
            int columna_final = N - 1 - i;
            
            M[fila_final][columna_final] = A[aux--];
        }
    }
}

int main() {
    /* Caso de prueba:
    int M[N][N] = {
        {50, 14, 15, 17, 21},
        {31, 18, 10, 40, 15},
        {35, 46, 47, 18, 44},
        {11, 26, 32, 27, 40},
        {30, 30, 22, 14, 44}
    };*/
    int M[N][N];
    ingresar(M);
    ordenar(M);
    imprimir(M);
    
    return 0;
}
