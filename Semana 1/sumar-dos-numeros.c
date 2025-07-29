#include<stdio.h>

/*
Imprimir la suma de dos variables enteras que se leen por teclado
*/

int main (){
	int a, b;
	printf("Ingrese dos numeros a y b: ");
	scanf("%d %d", &a, &b);
	printf("La suma de los numeros %d y %d es: %d", a, b, a + b);
	return 0;
}