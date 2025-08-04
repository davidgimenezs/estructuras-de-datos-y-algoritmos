/*
Escribir un programa que visualice el vector L2, segun el ejemplo:

10 10 9 5 9 6 9 5 2 2

2 2 5 5 6 9 9 9 10 10

Lista final L2 (resultado del programa)

2 5 6 9 10

Observacion: Se debe resolver de dos formas
	- Sin utilizar un vector auxiliar
	- Utilizando un vector auxiliar
*/

#include<stdio.h>
#define SIZE 10

void ingresar(int array[], int num){
	for (int i=0; i<num; i++){
		printf("Ingrese un elemento de la lista: ");
		scanf("%d", &array[i]);
	}
}

void imprimir(int array[], int num){
	for (int i=0; i<num; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void ordenar(int array[], int num){
	for (int i=0; i<num-1; i++){
		for (int j=0; j<num-i-1; j++){
			if (array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
// Método 1: Sin utilizar vector auxiliar
int eliminarDuplicadosSinAuxiliar(int array[], int num){
	if (num == 0 || num == 1) return num;
	
	int j = 0;
	
	for (int i = 0; i < num-1; i++){
		if (array[i] != array[i+1]){
			array[j++] = array[i];
		}
	}
	array[j++] = array[num-1];
	
	return j;
}

// Método 2: Con vector auxiliar
int eliminarDuplicadosConAuxiliar(int array[], int num, int resultado[]){
	if (num == 0) return 0;
	
	resultado[0] = array[0];
	int j = 1;
	
	for (int i = 1; i < num; i++){
		if (array[i] != array[i-1]){
			resultado[j++] = array[i];
		}
	}
	
	return j;
}

int main(){
	int l1[SIZE], l2[SIZE], l3[SIZE];
	int nuevoTamano;
	
	printf("Ingrese los elementos del array L1:\n");
	ingresar(l1, SIZE);
	
	printf("\nArray original L1:\n");
	imprimir(l1, SIZE);
	
	for(int i = 0; i < SIZE; i++){
		l2[i] = l1[i];
	}
	
	// Método 1: Sin utilizar vector auxiliar
	printf("\n=== METODO 1: SIN VECTOR AUXILIAR ===\n");
	ordenar(l2, SIZE);
	printf("Array ordenado:\n");
	imprimir(l2, SIZE);
	
	nuevoTamano = eliminarDuplicadosSinAuxiliar(l2, SIZE);
	printf("Array L2 final (sin duplicados):\n");
	imprimir(l2, nuevoTamano);
	
	// Método 2: Utilizando vector auxiliar
	printf("\n=== METODO 2: CON VECTOR AUXILIAR ===\n");

	for(int i = 0; i < SIZE; i++){
		l2[i] = l1[i];
	}
	
	ordenar(l2, SIZE);
	printf("Array ordenado:\n");
	imprimir(l2, SIZE);
	
	nuevoTamano = eliminarDuplicadosConAuxiliar(l2, SIZE, l3);
	printf("Array L3 final (sin duplicados, usando vector auxiliar):\n");
	imprimir(l3, nuevoTamano);
	
	return 0;
}