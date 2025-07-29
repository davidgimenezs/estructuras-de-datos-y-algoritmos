#include <stdio.h>
#include <math.h>

/*
(Opcional) Resolver la ecuación de segundo grado ax^2 + bx + c = 0, suponiendo 
que tiene siempre raíces reales. Los valores de a, b y c se ingresan por teclado.
*/

// Vamos a hacer uno mas facha, vamos a considerar raices complejas cuando discriminante < 0

int main() {
    float a, b, c, discriminante, parte_real, parte_imaginaria;

    printf("Ingrese los coeficientes a, b y c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminante = b*b - 4*a*c;

    if (a == 0) {
        printf("No es una ecuacion cuadratica (a no puede ser cero).\n");
        return 1;
    }

    if (discriminante > 0) {
        float r1 = (-b + sqrt(discriminante)) / (2*a);
        float r2 = (-b - sqrt(discriminante)) / (2*a);
        printf("Raices reales distintas: %.2f y %.2f\n", r1, r2);
    } else if (discriminante == 0) {
        float r = -b / (2*a);
        printf("Raiz real doble: %.2f\n", r);
    } else {
        parte_real = -b / (2*a);
        parte_imaginaria = sqrt(-discriminante) / (2*a);
        printf("Raices complejas:\n");
        printf("%.2f + %.2fi\n", parte_real, parte_imaginaria);
        printf("%.2f - %.2fi\n", parte_real, parte_imaginaria);
    }

    return 0;
}
