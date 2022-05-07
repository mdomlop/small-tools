/*
 If a chessboard were to have wheat placed upon each square such that one
grain were placed on the first square, two on the second, four on the third,
and so on (doubling the number of grains on each subsequent square), how many
grains of wheat would be on the chessboard at the finish?


The last value must be 18446744073709551615
 */

#include <iostream>


int main()
{
    int i = 0;
    unsigned long x = 1;
    unsigned long t = 1;
    for (i; i < 64; i++)
    {
        std::cout << i + 1 << ": " << x << ", " << t << std::endl;
        x = x * 2;
        t =  t + x;
    }

    return 0;
}
