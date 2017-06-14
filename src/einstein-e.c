/*
Ejercicio: pc-p4.16

La famosa ecuación de Einstein para conversión de una masa m en energía viene dada por la fórmula

E = mc^2
        c es la velocidad de la luz
        c = 2.997925 * 10^10 cm/sg

Escribir un programa que lea una masa en gramos y obtenga la cantidad de energía producida cuando la masa se convierte en energía.
Nota: Si la masa se da en gramos, la fórmula produce la energía en ergios.

*/

#include <stdio.h>

int main (void)
{
    long double e, m;
    const long double c2 = 343886617528564510758027657216.0; /* El resultado de calcular (2.997925 * 10^10)^2 */

    printf("Introduzca la masa en gramos: ");
    scanf("%Lf", &m);

    e = m * c2;

    printf("La energía producida será %.0Lf ergios.\n", e);


    return 0;
}
