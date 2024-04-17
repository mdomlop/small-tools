/*
Ejercicio: pc-p4.16

La famosa ecuación de Einstein para conversión de una masa m en energía viene
dada por la fórmula

E = mc^2
        c es la velocidad de la luz
        c = 2.997925 * 10^10 cm/sg

Escribir un programa que lea una masa en gramos y obtenga la cantidad de
energía producida cuando la masa se convierte en energía.

Nota: Si la masa se da en gramos, la fórmula produce la energía en ergios.

*/

#include <stdio.h>

#define EXECUTABLE  "einstein-e"

#define J 10000000  /* Un julio son 10 millones de ergios */
#define TJ 1000000000000  /* (1 TJ = 10^12 J */
#define kT 4.184  /* Terajulios */
#define mT 1000  /* Kilotones */
#define HIROSHIMA 16  /* Kilotones */
#define TSAR 50 /* Megatones */


int main (void)
{
    long double e, m;
    const long double c2 = 343886617528564510758027657216.0; /* El resultado de
    calcular (2.997925 * 10^10)^2 */

    printf("Introduzca la masa en gramos: ");
    scanf("%Lf", &m);

    e = m * c2;

    printf("La energía producida es %.0Lf ergios.\n", e);
    printf("Lo cual equivale a unas %.0Lf bombas como la de Hiroshima.\n",
            e / J / TJ / kT / HIROSHIMA);
    printf("Y a unas %.0Lf bombas tipo Zar.\n",
            e / J / TJ / kT / mT / TSAR);


    return 0;
}
