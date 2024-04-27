#include<stdio.h>
#include<getopt.h>
#include <stdlib.h>
#include <ctype.h>

float kmph = 0;

int m = 0;
float km = 0;

int total_sec = 0;

struct tspec
{
	int h;
	int min;
	int s;
};

struct tspec tt;  // total time
struct tspec r;  // rhythm minpkm
struct tspec t1k;
struct tspec t5k;
struct tspec t10k;
struct tspec tmm;
struct tspec tm;


void help(void)
{
	printf("Usage:\n"
			"\truncalc [-k km] [-m m] -t hh:mm:ss\n");
}


void sec_to_ts(int sec, struct tspec *t)
{
	t->h = sec / 3600; // 3600 segundos en una hora
	sec %= 3600; // Calculamos el resto de segundos
	t->min = sec / 60; // 60 segundos en un minuto
	t->s = sec % 60; // El resto son los segundos
}

void get_minpkm(void)
{
	int spm = 1000 * total_sec / m;
	sec_to_ts(spm, &r);
}

void get_kmph(void)
{
	kmph = m * 3600 / total_sec / 1000.0;
}


void get_tpk(int dist, struct tspec *t)
{
	int sec_in_dist = total_sec * dist / m;
	sec_to_ts(sec_in_dist, t);
}

int main(int argc, char *argv[])
{
	int o;

	while ((o = getopt(argc, argv, "m:k:t:")) != -1)
		switch(o)
		{
			case 'm':
				m = atoi(optarg);
				break;
			case 'k':
				km = atof(optarg);
				m = km * 1000 + m;
				break;
			case 't':
				if (sscanf(optarg, "%d:%d:%d", &tt.h, &tt.min, &tt.s) != 3)
					printf("Error al analizar la cadena.\n");
				break;
			case '?':
                if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf (stderr, "Unknown option character `\\x%x'.\n",
							optopt);
                return 1;
			default:
                fprintf(stderr, "Error desconocido\n");
				help();
				abort();
		}

	total_sec = tt.h * 3600 + tt.min * 60 + tt.s;

	get_minpkm();
	get_kmph();
	get_tpk(1000, &t1k);
	get_tpk(5000, &t5k);
	get_tpk(10000, &t10k);
	get_tpk(21097, &tmm);
	get_tpk(42195, &tm);

	printf("min/km: %02d:%02d:%02d\n", r.h, r.min, r.s);  // % %02d:%02d
	printf("km/h: %.2f\n", kmph);
	printf(" 1 km: %02d:%02d:%02d\n", t1k.h, t1k.min, t1k.s);
	printf(" 5 km: %02d:%02d:%02d\n", t5k.h, t5k.min, t5k.s);
	printf("10 km: %02d:%02d:%02d\n", t10k.h, t10k.min, t10k.s);
	printf("Med Marathon (21097 m): %02d:%02d:%02d\n", tmm.h, tmm.min, tmm.s);
	printf("Marathon (42195 m): %02d:%02d:%02d\n", tm.h, tm.min, tm.s);

	return 0;
}




