#include <iostream>


int main()
{
    int i = 0;

    while (i < 100000000) {
        i++;
    }

    std::cout << i << std::endl;
    return 0;
}
