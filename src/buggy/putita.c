#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float pythagoras_ratio(int wr, int hr)
{
	float relsize = sqrt(pow(wr, 2) + pow(hr, 2));
	return  relsize;
}



int main(int argc, char ** argv)
{
	int wratio = atoi(argv[1]);
	int hratio = atoi(argv[2]);
	int dsize = atoi(argv[3]); /* En pulgadas */

	float wsize, hsize, area;

	dsize = dsize * 2.54;  /* Paso a centímetros */

	wsize = dsize * wratio / pythagoras_ratio(wratio, hratio);
	hsize = dsize * hratio / pythagoras_ratio(wratio, hratio);
	area = wsize * hsize;

	printf("Las dimensiones de la pantalla son:\n"
	"Ancho: %.2f cm\n"
	"Alto: %.2f cm\n"
	"Área: %.2f cm2\n"
	, wsize, hsize, area);

	return 0;
}



