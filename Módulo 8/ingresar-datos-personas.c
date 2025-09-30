/*
1.1 Crear el archivo de texto PERSONA.TXT de tal forma que cada línea contenga un
registro con los datos de una persona con los siguientes campos: nombre, apellido, fecha
de nacimiento (dia(nn), mes(nn), año(nnnn), mes en letras), los datos son ingresados por
teclado a excepción del mes en letras que debe ser generado según el número del mes
ingresado. Utilizar una estructura para representar los datos de las personas, un arreglo
de punteros para representar los meses del año y el indicador de fin de archivo para
finalizar el ingreso de registros 
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char nombre[20];
    char apellido[20];
    int dia;
    int mes;
    int anio;
    char mes_letra[15];
} Persona;

int main() {
    // Arreglo de punteros para los meses del año (REQUISITO)
    char *meses[12] = {
        "Enero",
        "Febrero", 
        "Marzo",
        "Abril",
        "Mayo",
        "Junio",
        "Julio",
        "Agosto",
        "Septiembre",
        "Octubre",
        "Noviembre",
        "Diciembre"
    };
    
    FILE *pA;
    
    pA = fopen("PERSONA.TXT", "w");
    
    if (pA == NULL){
        printf("\nError al crear el archivo PERSONA.TXT");
        return 1;
    }
    
    Persona persona;
    
    printf("=== INGRESO DE PERSONAS ===\n");
    printf("(Ingrese EOF o Ctrl+Z en Windows / Ctrl+D en Linux para terminar)\n\n");
    
    printf("Ingrese nombre: ");
    // Usar indicador de fin de archivo (EOF) para finalizar (REQUISITO)
    while(scanf("%s", persona.nombre) != EOF){
        printf("Ingrese apellido: ");
        if(scanf("%s", persona.apellido) == EOF) break;
        
        printf("Ingrese dia (dd): ");
        if(scanf("%d", &persona.dia) == EOF) break;
        
        printf("Ingrese mes (1-12): ");
        if(scanf("%d", &persona.mes) == EOF) break;
        
        printf("Ingrese anio (aaaa): ");
        if(scanf("%d", &persona.anio) == EOF) break;
        
        // Validar mes y generar mes en letras usando el arreglo de punteros
        if(persona.mes >= 1 && persona.mes <= 12){
            strcpy(persona.mes_letra, meses[persona.mes - 1]);
        } else {
            strcpy(persona.mes_letra, "Invalido");
        }
        
        // Escribir en el archivo: nombre apellido dia mes anio mes_en_letras
        fprintf(pA, "%s %s %02d %02d %04d %s\n", 
                persona.nombre, 
                persona.apellido, 
                persona.dia, 
                persona.mes, 
                persona.anio,
                persona.mes_letra);
        
        printf("\nRegistro guardado.\n");
        printf("Ingrese nombre: ");
    }
    
    fclose(pA);
    printf("\n\nArchivo PERSONA.TXT creado exitosamente.\n");
    
    return 0;
}
