#include <stdio.h>
#include <getopt.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define PROGRAM "Bytes."
#define VERSION "0.1."
#define DESCRIPTION "Get the bytes."
#define EXECUTABLE "bytes"


void version (void)
{
	printf ("%s Version: %s\n", PROGRAM, VERSION);
}

void help (int error)
{
	char text[] = "\nUsage:\n\n"

	"\tbits [nbits] [options]\n\n"

	"\t-b num     Set input as bytes.\n"
	"\t-k num     Set input as Kilobytes.\n"
	"\t-m num     Set input as Megabytes.\n"
	"\t-g num     Set input as Gigabytes.\n"
	"\t-t num     Set input as Terabytes.\n"
	"\t-p num     Set input as Petabytes.\n"
	"\t-e num     Set input as Exabytes.\n"
	"\t-z num     Set input as Zettabytes.\n"
	"\t-y num     Set input as Yottabytes.\n\n"

	"\t-h         Show this help and exit.\n"
	"\t-v         Show program version and exit.\n";

	if (error)
		fprintf (stderr, "%s\n", text);
	else
	{
		version();
		printf ("%s\n%s\n", DESCRIPTION, text);
	}
}


int is_integer (char * s)
/* Determines if passed string is a positive integer */
{
    short c;
    short sc = strlen(s);

    for ( c = 0; c < sc; c++ )
    {
        if (isdigit (s[c]))
            continue;
        else
			return 0;
    }
    return 1;
}


long double getbits(int bytes, int factor, int magnitude, char *b_str)
{
	long double b = 0;

	if (is_integer(b_str))
		b = strtold(b_str, NULL);
	else
	{
		fprintf(stderr, "This is not an integer: %s\n", b_str);
		return 1;
	}

	if(bytes)
			b *= 8;

	for (int i=0; i<magnitude; i++)
		b *= factor;

	return b;
}

long double getbytes(int factor, int magnitude, long double b)
{
	double module = 0.0;
	int module_int = 0;

	b /= 8;

	for (int i=0; i<magnitude; i++)
	{
		b /= factor;
		module = modf(b, &module);
	}
	
	module_int = module * 100;
	return module_int?0:b;
}


void printout(int factor, long double b)
{
	char **name = NULL;

	char *b2name[] = {"Bytes", 
		"Kibibytes", "Mebibytes", "Gibibytes", "Tebibytes", "Pebibytes",
		"Exbibytes", "Zebibytes", "Yobibytes"};
	char *b10name[] = {"Bytes", 
	   	"Kilobytes", "Megabytes", "Gigabytes", "Terabytes", "Petabytes",
		"Exabytes", "Zettabytes", "Yottabytes"};

	if (factor == 1024)
		name = b2name;
	else if (factor == 1000)
		name = b10name;

	printf ("Bits: %.0Lf\n", b);

	for (short i=0; i<=sizeof(name); i++)
		printf("%s: %.0Lf\n", *(name + i), getbytes(factor, i, b));
		//printf("%s: %.0Lf (%.20Lf)\n", *(name + i), getbytes(factor, i, b), getbytes(factor, i, b));
}

int main(int argc, char **argv)
{
	int sflag = 1024;
	int nflag = 0;
	int magnitude = -1;
	char *input = NULL;

	int c;
	while ((c = getopt (argc, argv, "hvnsbkmgtpezy")) != -1)
	{
		switch (c)
		{
			case 'h':  // Show help
				help(0);
				return 0;
			case 'v':  // Show program version
				version();
				return 0;
			case 's':  // Switch to SI metrics
				sflag = 1000;
				break;
			case 'n':
				nflag = 1;
				break;
			case 'b':
				magnitude = 0;
				break;
			case 'k':
				magnitude = 1;
				break;
			case 'm':
				magnitude = 2;
				break;
			case 'g':
				magnitude = 3;
				break;
			case 't':
				magnitude = 4;
				break;
			case 'p':
				magnitude = 5;
				break;
			case 'e':
				magnitude = 6;
				break;
			case 'z':
				magnitude = 7;
				break;
			case 'y':
				magnitude = 8;
				break;
			case '?':
				if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n"
					"See help with option `-h'.\n", optopt);
				else
					fprintf (stderr, "Unknown option character `\\x%x'.\n",
							optopt);
				return 1;
			default:
				abort ();
		}
	}

	input = argv[optind];

	if ((argc - optind) > 1)
	{
		fprintf(stderr, "Too much non-option arguments: %d.\n", argc - 1);
		help(1);
		return 1;
	}
	else if (argc > 4)
	{
		fprintf(stderr, "Too much arguments: %d.\n", argc - 1);
		help(1);
		return 1;
	}

	printout(sflag, getbits(nflag, sflag, magnitude, input));

	return 0;
}
