#include<stdio.h>
#include<math.h>

#define PI 3.14159

/*
 Luego de ingresar el radio por teclado, hallar la circunferencia y el área de un círculo. 
*/

int main(){
	float radio, circunferencia, area;
	printf("Ingrese el radio del circulo: ");
	scanf("%f", &radio);
	printf("El radio del circulo es %.2fcm\n", radio);
	circunferencia = 2 * PI * radio;
	area = PI * pow(radio, 2);
	printf("La circunferencia del circulo es %.2fcm\n", circunferencia);
	printf("El area del circulo es %.2fcm^2\n", area);
}