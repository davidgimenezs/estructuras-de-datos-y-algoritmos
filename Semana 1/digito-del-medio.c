#include<stdio.h>

/*
Leer un numero de 5 cifras e imprimir el digito de las centenas.
*/

int main(){
	int numero;
	
	do{
		printf("Ingrese un numero de 5 cifras: ");
		scanf("%d", &numero);
		
	}while(numero < 10000 || numero > 99999);

	numero = (numero % 1000) / 100;
	
	printf("Cifra: %d", numero);
	
	return 0;
}