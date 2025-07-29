#include <stdio.h>

/*
Escriba un programa en C que:
- Lea una serie de horarios en formato hh:mm:ss y en ningun caso como variable entera (int).
- La cantidad de horarios a ingresar define el usuario al principio.
- Los horarios deben ser cambiados a segundos.
- Imprimir el mayor horario desde el inicio del dia en segundos.
- Si las horas insertadas superan las 24 horas, los minutos 60 y los segundos 60 imprimir "UNO DELOS HORARIOS MAL CARGADOS"
- Al final imprimir la cantidad de horarios mal cargados o que estan fuera del rango normal
- NO UTILIZAR cadenas de caracteres ni vectores para resolver este ejercicio.
- Se debe implementar la funcion int cantsegundos(), que lee los horarios en el formato propuesto y retorna la cantidad de segundos.
*/

int cantsegundos(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int leerNumero() {
    char c1, c2;
    
    // Leer exactamente 2 caracteres
    c1 = getchar();
    c2 = getchar();

    if (c1 < '0' || c1 > '9' || c2 < '0' || c2 > '9') {
        return -1;
    }

    return (c1 - '0') * 10 + (c2 - '0');
}

int verificarSeparador() {
    char c = getchar();
    return (c == ':') ? 1 : 0;
}

int validarTiempo(int h, int m, int s) {
    return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
}

int leerHorario(int *h, int *m, int *s) {
    // Leer horas
    *h = leerNumero();
    if (*h == -1) return 0;
    
    if (!verificarSeparador()) return 0;
    
    // Leer minutos
    *m = leerNumero();
    if (*m == -1) return 0;

    if (!verificarSeparador()) return 0;
    
    // Leer segundos
    *s = leerNumero();
    if (*s == -1) return 0;
    
    getchar();
    
    return validarTiempo(*h, *m, *s);
}

void imprimirResultados(int maxSegundos) {
    if (maxSegundos != -1) {
        printf("Mayor cantidad de segundos: %d\n", maxSegundos);
    } else {
        printf("No se ingresaron horarios validos\n");
    }
}

int main() {
    int n, h, m, s;
    int maxSegundos = -1;
    int horariosMalCargados = 0;

    printf("Ingrese la cantidad de horarios: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Ingrese horario %d (hh:mm:ss): ", i + 1);
        if (!leerHorario(&h, &m, &s)) {
            printf("UNO DELOS HORARIOS MAL CARGADOS\n");
            horariosMalCargados++;
            continue;
        }

        int segundos = cantsegundos(h, m, s);
        if (segundos > maxSegundos) {
            maxSegundos = segundos;
        }
    }

    imprimirResultados(maxSegundos);
    printf("Cantidad de horarios mal cargados: %d\n", horariosMalCargados);

    return 0;
}
