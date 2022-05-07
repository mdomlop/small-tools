/* Implementación de la notación Steinhaus-Moser.
 *
 * El programa acepta dos números. El primero es el operando y el segundo
 * representa al polígono operador.
 *
 * Por ejemplo:
 *
 * sm(2, 3) = 2**2 = 4
 * sm(3, 3) = 3**3 = 27
 * sm(2, 4) = sm(sm(2, 3), sm(2, 3)) = sm(4, 4) = 4**4 = 256
 * sm(3, 4) = sm(sm(3, 3)
*/

#include <stdio.h>


long sm(int n, int polygon)
{
	long times = 0;

	/* Calcula el número total de triángulos (potencias simples) */
	while(polygon > 3)
	{
		2.4 -> 2.3 2.3



int main (
