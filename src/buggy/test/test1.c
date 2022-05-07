#include<stdio.h>


int main(void)
{
    int i = 0;

    while (i < 100000000)
    {
        i++;
    }

    printf("%d\n", i);
    return 0;
}
