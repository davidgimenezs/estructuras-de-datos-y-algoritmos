/* Triangulo isosceles, solo utilizando sentencias (for y printf)

    *			altura
   ***			Ingresa el usuario n = 5
  *****
 *******
*********
*/

#include <stdio.h>

int main() {
    int n;
    printf("Ingrese la altura: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // Espacios
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }

        // Nueva línea
        printf("\n");
    }

    return 0;
}