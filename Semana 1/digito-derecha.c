#include<stdio.h>

/*  21/jul/2025
	02. Escribir un programa en C++ que lea por teclado dos números (suponer que 
	el usuario siempre cargará números enteros y positivos) y muestre en pantalla 
	el primer digito (el que está más a la derecha) de la suma de ambos            */

int main () {
	int a, b;
	
	printf("Ingrese el numero a: ");
	scanf("%d", &a);
	printf("Ingrese el numero b: ");
	scanf("%d", &b);
	
	// didacticamente nio puedo usar una variable temporal para hacer la suma y el digito pero aper
	
	a = a + b;
	b = a % 10;
	
	printf("El digito mas a la derecha de la suma a = %d es: %d", a, b);

	return 0;
}