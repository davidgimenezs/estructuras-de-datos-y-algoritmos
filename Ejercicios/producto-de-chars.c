#include <stdio.h>

/*
Escribir un programa que permita la introducción por teclado (mediante getchar) de dos
valores enteros de una cifra y que calcule e imprima por pantalla el producto de ellos.
*/

int main() {
    int a, b;
    char ch;

    printf("Ingrese dos números (de una cifra): ");

    do {
        ch = getchar();
    } while (ch < '0' || ch > '9');
    a = ch - '0';

    do {
        ch = getchar();
    } while (ch < '0' || ch > '9');
    b = ch - '0';

    printf("El producto es %d\n", a * b);
    return 0;
}