/* TVSize - Calcula las dimensiones de un rectángulo (TV)
 * de proporciones conocidas.
 *
 * Ejemplo:
 *
 * tvsize 16 9 50
 *
 * Calcularía las dimensiones de una tv de 16:9 y 50 pulgadas.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INCH 2.54 // cm in a inch.

#define EXECUTABLE "tvsize"

float pythagoras_ratio(int wr, int hr)
{
	float relsize = sqrt(pow(wr, 2) + pow(hr, 2));
	return  relsize;
}



int main(int argc, char ** argv)
{
	int hratio, vratio, dsize;
	float hsize, vsize, area;

	char usage[] = "Usage:\n\n\t"
		EXECUTABLE " wratio hratio dsize\n\n"
		"Where:\n\n"
		"`hratio' is horizontal proportion.\n"
		"`vratio' is vertical proportion.\n"
		"`dsize' is the diagonal size in inches.\n"
		"\nFor example, for calculate the size of a screen\n"
		"of 50 inches in a 16:9 aspect ratio,\n"
		"you must to execute:\n\n\t"
		EXECUTABLE " 16 9 50\n";

	switch (argc)
	{
		case 4:
			hratio = atoi(argv[1]);
			vratio = atoi(argv[2]);
			dsize = atoi(argv[3]); /* En pulgadas */
			break;
		default:
			fprintf(stderr, "Sorry, I need 3 integers.\n\n%s", usage);
			return 1;
	}


	dsize = dsize * INCH;  /* Paso a centímetros */

	hsize = dsize * hratio / pythagoras_ratio(hratio, vratio);
	vsize = dsize * vratio / pythagoras_ratio(hratio, vratio);
	area = hsize * vsize;

	printf(
	"Width: %.2f cm\n"
	"Height: %.2f cm\n"
	"Area: %.2f cm2\n",
	hsize, vsize, area);

	return 0;
}



