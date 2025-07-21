#include<stdio.h>
#include<math.h>

/*  21/jul/2025
    03. Escriba un programa que imprima el área y el perímetro del triángulo:
	A=(b*a)/2   P=(a+b+c)/2  											       

	yo tengo un problema personal con este ejercicio en todas las cátedras de programación de la facultad
	porque no es un ejercicio completamente planteado, entiendo que lo que quieren hacer aprender es a
	poder hacer operaciones algebráicas y definir, introducir e imprimir variables, pero para pedirte
	area de un triangulo hay más consideraciones de las que "la solución" tiene, por ejemplo, validar si
	es un triángulo, base*altura / 2 se usa solo en triángulos rectángulos, entonces necesitamos usar heron
	      ___________________
	A = \/S*(S-a)*(S-b)*(S-c) , donde A es el área del triángulo, S es el semi-perímetro y a,b,c los lados.
	*/

int main () {
	float lado_a, lado_b, lado_c, area, perimetro;
	
	printf("Ingrese el lado A: ");
	scanf("%f", &lado_a);
	printf("Ingrese el lado B: ");
	scanf("%f", &lado_b);
	printf("Ingrese el lado C: ");
	scanf("%f", &lado_c);
	
	// Se verifica la desigualdad triangular, para poder afirmar que los 3 lados forman un triangulo
	if (lado_a + lado_b > lado_c && lado_a + lado_c > lado_b && lado_b + lado_c > lado_a){
    	// SI es un triángulo
		perimetro = lado_a + lado_b + lado_c;

		printf("El perimetro del triangulo es: %.2f", perimetro);
		
		perimetro = perimetro / 2;
		
		area = 	sqrt(perimetro * (perimetro - lado_a) * (perimetro - lado_b) * (perimetro - lado_c));
		
		printf(" y el area es: %.2f", area);
    } 
	else {
		//NO es un triángulo
        printf("Estos valores no forman un triangulo.");
    }
	
	return 0;	
}