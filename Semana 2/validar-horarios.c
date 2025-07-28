#include <stdio.h>

int cantsegundos(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int leerNumero() {
    char c1, c2;
    
    // Leer exactamente 2 caracteres
    c1 = getchar();
    c2 = getchar();
    
    // Verificar que ambos son dígitos
    if (c1 < '0' || c1 > '9' || c2 < '0' || c2 > '9') {
        return -1;
    }
    
    // Convertir a número
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

void imprimirResultados(int maxSegundos) {
    if (maxSegundos != -1) {
        printf("Mayor cantidad de segundos: %d\n", maxSegundos);
    }
}

int main() {
    int n, h, m, s;
    int maxSegundos = -1;

    printf("Ingrese la cantidad de horarios: ");
    scanf("%d", &n);
    getchar(); // Consumir el newline después del número

    for (int i = 0; i < n; i++) {
        if (!leerHorario(&h, &m, &s)) {
            printf("UNO DE LOS HORARIOS MAL CARGADOS\n");
            break;
        }

        int segundos = cantsegundos(h, m, s);
        if (segundos > maxSegundos) {
            maxSegundos = segundos;
        }
    }

    imprimirResultados(maxSegundos);

    return 0;
}
