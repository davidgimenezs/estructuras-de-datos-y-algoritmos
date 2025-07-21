#include<stdio.h>

/*  21/jul/2025
	01. Escriba un programa que solicite al usuario dos enteros a y b intercambie los dos
	números sin usar ninguna variable auxiliar (aux).  								       */

int main () {
	int a, b;
	
	printf("Ingrese el numero a: ");
	scanf("%d", &a);
	printf("Ingrese el numero b: ");
	scanf("%d", &b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	/* 
	puntos extras si entendes por que funciona hacer esto bitwise :)
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	*/
	
	printf("El nuevo numero a es: %d, y el nuevo numero y: %d", a, b);
	
	return 0;
}