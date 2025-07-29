#include<stdio.h>
#include<ctype.h>

/*
Escribir un programa que lea una letra minúscula y que la muestre en mayúsculas en pantalla.
*/

int main(){
	char letra;
	int mayus;
	
	while(letra < 97 || letra > 122){
		printf("Ingrese una letra minuscula: ");
		scanf(" %c", &letra); 
		/* 
		scanf("%c", &letra) lee exactamente un caracter, que puede ser 
		el newline \n de la respuesta fallida anterior, entonces hay que
		poner un espacio antes " %c" para que no imprima dos veces.
		por que? no se :)
		*/
	}
	
	mayus = toupper(letra);
	
	printf("%c", mayus);
		
	return 0;
}