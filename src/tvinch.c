/* TVInch - Calcula las pulgadas diagonales de un rectángulo (TV)
 * de proporciones conocidas.
 *
 * Ejemplo:
 *
 * tvinch 110.69 62.26
 *
 * Calcularía las pulgadas de una tv de 110.69 cm * 62.26 cm.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INCH 2.54 // cm in a inch.

#define EXECUTABLE "tvinch"

static int gcd (int a, int b)
{
		return (b == 0) ? a : gcd (b, a%b);
}

int main(int argc, char ** argv)
{
	float hsize, vsize, dsize;

	char usage[] = "Usage:\n\n\t"
		EXECUTABLE " hsize vsize\n\n"
		"Where:\n\n"
		"`hsize' is horizontal size in cm.\n"
		"`vsize' is horizontal size in cm.\n"
		"\nFor example, for calculate the diagonal of a screen\n"
		"of 110.69 cm * 62.26 cm,\n"
		"you must to execute:\n\n\t"
		EXECUTABLE " 110.69 62.26\n";

	switch (argc)
	{
		case 3:
			hsize = atoi(argv[1]);
			vsize = atoi(argv[2]);
			break;
		default:
			fprintf(stderr, "Sorry, I need 2 numbers > 0.\n\n%s", usage);
			return 1;
	}


	dsize = pow(hsize, 2) + pow(vsize, 2);
	dsize = sqrt(dsize) / INCH;  /* Paso a centímetros */

	printf("Diagonal: %.2f inch\n", dsize);
	printf("Aspect ratio: %.2f \n", gcd(hsize, vsize));

	return 0;
}



