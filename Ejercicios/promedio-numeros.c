#include<stdio.h>
#define CANTIDAD 5

/*
Calcular la suma y el promedio de 5 valores introducidos por teclado.
*/


int main(){
	float valores[CANTIDAD], promedio = 0;
	
	for (int i=0; i<CANTIDAD; i++){
		printf("Ingrese un numero: ");
		scanf("%f", &valores[i]);
		promedio += valores[i];
	}
	
	promedio /= CANTIDAD;
	printf("El promedio de los 5 numeros ingresados es: %.2f", promedio);
	
	return 0;
}