#include <stdio.h>
#include <string.h>

#define MAX 100

/*
1) Una persona tiene 𝑁 fechas en formato 𝑑𝑑/𝑚𝑚/𝑎𝑎𝑎𝑎 (se ingresan solamente de esa
manera- cadena), y le pide a usted que diseñe un programa que le imprima en pantalla
las 𝑁 fechas (en el mismo formato), pero en orden cronológico.

Entrada del programa:
En la primera línea se coloca el valor de 𝑁. Luego siguen 𝑁 líneas que contienen las
fechas en el formato 𝑑𝑑/𝑚𝑚/𝑎𝑎𝑎𝑎. El alumno debe asumir que las fechas proporcionadas
son válidas, así como el valor de 𝑁.

3 ------ (Caso 1)
19/05/2025
05/05/2005
12/05/2005

2 ---- (Caso 2)
20/02/2007
01/01/2000

Salida del programa:
Se deben imprimir las 𝑁 fechas ordenadas cronológicamente. Cada fecha se imprime en
una línea.

Salida (1)
05/05/2005
12/05/2005
19/05/2025

Salida (2)
01/01/2000
20/02/2007
*/

void leerFechas(int N, char fechas[][11], int dia[], int mes[], int anio[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Ingrese la fecha %d en formato dd/mm/aaaa: ", i + 1);
        scanf("%s", fechas[i]);

        dia[i] = (fechas[i][0] - '0') * 10 + (fechas[i][1] - '0');
        mes[i] = (fechas[i][3] - '0') * 10 + (fechas[i][4] - '0');
        anio[i] = (fechas[i][6] - '0') * 1000 + (fechas[i][7] - '0') * 100 + (fechas[i][8] - '0') * 10 + (fechas[i][9] - '0');
    }
}

void intercambiar(int i, int j, char fechas[][11], int dia[], int mes[], int anio[]) {
    char tempStr[11];
    strcpy(tempStr, fechas[i]);
    strcpy(fechas[i], fechas[j]);
    strcpy(fechas[j], tempStr);

    int td = dia[i], tm = mes[i], ta = anio[i];
    dia[i] = dia[j]; mes[i] = mes[j]; anio[i] = anio[j];
    dia[j] = td; mes[j] = tm; anio[j] = ta;
}

void ordenarFechas(int N, char fechas[][11], int dia[], int mes[], int anio[]) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if ((anio[j] > anio[j+1]) ||
                (anio[j] == anio[j+1] && mes[j] > mes[j+1]) ||
                (anio[j] == anio[j+1] && mes[j] == mes[j+1] && dia[j] > dia[j+1])) {
                intercambiar(j, j+1, fechas, dia, mes, anio);
            }
        }
    }
}

void imprimirFechas(int N, char fechas[][11]) {
    int i;
    printf("\nFechas ordenadas cronologicamente:\n");
    for (i = 0; i < N; i++) {
        printf("%s\n", fechas[i]);
    }
}

int main() {
    int N;
    char fechas[MAX][11];
    int dia[MAX], mes[MAX], anio[MAX];

    printf("=== Ordenador de Fechas ===\n");
    printf("Ingrese la cantidad de fechas a ordenar: ");
    scanf("%d", &N);

    leerFechas(N, fechas, dia, mes, anio);
    ordenarFechas(N, fechas, dia, mes, anio);
    imprimirFechas(N, fechas);

    return 0;
}
