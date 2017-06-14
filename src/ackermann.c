/* Implements the Ackermann function to obtain big numbers. Too big even for
 our universe. */

#include <stdio.h>
#include <stdlib.h>


int A(int m, int n)
{
    if (!m) return n + 1;
    if (!n) return A(m - 1, 1);
    return A(m - 1, A(m, n - 1));
}


int main(int argc, char *argv[])
{
    int n1 = strtol(argv[1], NULL, 10);
    int n2 = strtol(argv[2], NULL, 10);

    if (!(n1 < 0) && !(n2 < 0))
    {
        printf("%d", A(n1, n2));
    }
    else printf("Invalid arguments. They must be 2 numbers >= 0");
    return 0;
}
