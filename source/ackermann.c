/* Implements the Ackermann function to obtain big numbers.
   Too bigs even for our universe. */

#include <stdio.h>
#include <stdlib.h>

#define EXECUTABLE  "ackermann"

int A(int m, int n)
{
    if (!m) return n + 1;
    if (!n) return A(m - 1, 1);
    return A(m - 1, A(m, n - 1));
}


int main(int argc, char *argv[])
{
	int n1, n2;
	switch (argc)
	{
		case 3:
			n1 = strtol(argv[1], NULL, 10);
			n2 = strtol(argv[2], NULL, 10);
			if (!(n1 < 0) && !(n2 < 0))
			{
				printf("%d\n", A(n1, n2));
			}
			else printf("Invalid arguments. They must be 2 numbers >= 0\n");
			break;
		default:
			printf("Invalid arguments. They must be 2 numbers >= 0\n");
			return 1;
	}

    return 0;
}
