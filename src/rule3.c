#include <stdio.h>
#include <stdlib.h>

#define EXECUTABLE "rule3"


int main (int argc, const char ** argv)
{
    long double cantidad, valor, cantidadreq, resultado;

	char * usage = "Usage:\n\trule3 cant value [reqvalue or nothing for 1]\n";

	switch (argc)
	{
		case 4:
			cantidad = atof(argv[1]);
			valor = atof(argv[2]);
			cantidadreq = atof(argv[3]);
			break;
		case 3:
			cantidad = atof(argv[1]);
			valor = atof(argv[2]);
			cantidadreq = 1.0;
			break;
		default:
			fprintf(stderr, "Sorry. I need 2 or 3 numbers.\n");
			fprintf(stderr, "%s", usage);
			return 1;
			break;
	}

	resultado = cantidadreq * valor / cantidad;

    printf("%.1Lf -> %.2Lf\n%.1Lf -> %.2Lf\n", cantidad, valor, cantidadreq, resultado);

    return 0;
}
