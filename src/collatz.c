/*
Shows Collatz conjecture results.

Prints the number of steps to reach number 1 as result, meaning that the
conjecture works for the given number. Otherwise if a result were yet reached
this will mean that the Collatz conjecture fails, and you can reclaim your
award.

Good luck!
*/

#include<stdio.h>
#include<stdlib.h>


int founded(int a, int b[], int c)
{
    for (c--;c>=0;c--) if (a == b[c]) return 1;
    return 0;
}


int collatz(int x)
{
    int steps;
    int *data;
    int *temp;

    steps = 0;
    data = malloc(sizeof(int));

    for(steps=0;;steps++)
    {
        data[steps] = x;
        if (x % 2) x = x * 3 + 1;
        else x /= 2;

        temp = realloc(data, (steps + 2) * sizeof(int));
        if (temp != NULL) data = temp;
        else
        {
            free(data);
            printf("Error allocating memory!\n");
            return 1;
        }

        if (x < 2)
        {
            printf("1\n");
            break;
        }

        if (founded(x, data, steps))
        {
            printf("You win: %d\n",x);
            break;
        }

        printf("%d\n", data[steps]);

    }

    free(data);
    return 0;
}


int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int n = strtol(argv[1], NULL, 10);
        collatz(n);
    }
    else
    {
        printf("Only one natural number is required");
        return 1;
    }
    return 0;
}




