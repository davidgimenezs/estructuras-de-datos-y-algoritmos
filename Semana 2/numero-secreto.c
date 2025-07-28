#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define cantidad 10
#define MIN_NUM 1
#define MAX_NUM 100

/*
Existe un juego llamado "Adivina mi numero", el cual consiste en que un niño trata de adivinar el
numero (entero, y entre 1 y 100) pensado por el otro niño. Las reglas del juego son las siguientes:
	- El niño pregunta al otro si un numero que dice es el pensado por el segundo.
	- Si el numero es correcto , el primer niño gana el juego. Si no lo acierta, el siguiente niño debe
	  indicarle si el numero es mayor o menor del que penso. El primer niño tiene 10 oportunidades para
	  adivinar el numero, y si no lo hace, el juego es ganado por el segundo.
	- El algoritmo debe indicar el ganador del juego.
	
Obs: en este problema, el segundo niño es la computadora (el numero puede ser generado aleatoriamente
o predeterminado por el programador); mientras que el usuario es el primer niño.
*/


int main (){
	int numero, contador;
	int intentos = 1;
	int respuesta;
	bool ganar = false;

	srand(time(NULL));

	respuesta = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
	
	printf("=== JUEGO DEL NUMERO SECRETO ===\n");
	printf("Adivina el numero entre %d y %d\n", MIN_NUM, MAX_NUM);
	printf("Tienes %d intentos!\n\n", cantidad);
	
	while(intentos <= cantidad){
		
		printf("Intento %d/%d - Ingrese un numero: ", intentos, cantidad);
		scanf("%d", &numero);
		
		if (numero < respuesta){
			printf("El numero %d es menor al numero secreto\n", numero);
		}
		else if (numero > respuesta){
			printf("El numero %d es mayor al numero secreto\n", numero);
		}
		else if (numero == respuesta){
			ganar = true;
			printf("Felicidades! el numero %d ES el numero secreto\n", numero);
			break;
		}
		
		intentos++;

		if(intentos <= cantidad && !ganar){
			printf("Te quedan %d intentos\n\n", cantidad - intentos + 1);
		}
	}
	
	if (ganar == true){
		printf("\n*** HAZ GANADO EL JUEGO DEL NUMERO SECRETO! ***\n");
		printf("Lo lograste en %d intento(s)!\n", intentos);
	}
	else{
		printf("\n*** NO HAZ GANADO EL JUEGO DEL NUMERO SECRETO! ***\n");
		printf("El numero secreto era: %d\n", respuesta);
		printf("Mejor suerte la proxima!\n");
	}
	
	return 0;
}
