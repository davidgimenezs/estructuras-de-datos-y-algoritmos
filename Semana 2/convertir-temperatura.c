#include<stdlib.h>

/*
Supongamos que F es un entero que indica la temperatura en grados Fahrenheit,
y queremos transformarla en grados Celsius, almacenando el valor en el entero 
C. ¿Son equivalentes las siguientes expresiones?:
C = 5 * (F - 32) / 9;
C = 5 / 9 * (F - 32);
*/


int main(){
	int F, C1, C2;
	printf("Ingrese la temperatura en Fahrenheit: ");
	scanf("%d", &F);
	
	C1 = 5 * (F - 32) / 9;
	C2 = 5 / 9 * (F - 32);
	
	if(C1 == C2){
		printf("Ambos SON iguales");
	}
	else{
		printf("NO son iguales");
	}
	
	return 0;
}

