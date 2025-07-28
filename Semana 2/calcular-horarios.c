#include <stdio.h>

int cantsegundos(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int leerNumero() {
    int num = 0;
    char c;
    int digitos = 0;
    
    while ((c = getchar()) >= '0' && c <= '9' && digitos < 2) {
        num = num * 10 + (c - '0');
        digitos++;
    }
    
    // Si no leímos exactamente 2 dígitos, es un error
    if (digitos != 2) {
        return -1;
    }
    
    // "Devolver" el último carácter leído al buffer
    ungetc(c, stdin);
    
    return num;
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
    
    // Verificar primer ':'
    if (!verificarSeparador()) return 0;
    
    // Leer minutos
    *m = leerNumero();
    if (*m == -1) return 0;
    
    // Verificar segundo ':'
    if (!verificarSeparador()) return 0;
    
    // Leer segundos
    *s = leerNumero();
    if (*s == -1) return 0;
    
    // Consumir newline
    getchar();
    
    // Validar rangos de tiempo
    return validarTiempo(*h, *m, *s);
}

void imprimirResultados(int maxSegundos, int malCargados) {
    if (maxSegundos != -1) {
        printf("Mayor cantidad de segundos: %d\n", maxSegundos);
    }
    printf("Cantidad de horarios mal cargados: %d\n", malCargados);
}

int main() {
    int n, h, m, s;
    int maxSegundos = -1;
    int malCargados = 0;

    printf("Ingrese la cantidad de horarios: ");
    scanf("%d", &n);
    getchar(); // Consumir el newline después del número

    for (int i = 0; i < n; i++) {
        if (!leerHorario(&h, &m, &s)) {
            printf("UNO DE LOS HORARIOS MAL CARGADOS\n");
            malCargados++;
            break;
        }

        int segundos = cantsegundos(h, m, s);
        if (segundos > maxSegundos) {
            maxSegundos = segundos;
        }
    }

    imprimirResultados(maxSegundos, malCargados);

    return 0;
}
