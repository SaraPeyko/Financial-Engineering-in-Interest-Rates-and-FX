// Example01.cpp
//
//

#include <iostream>

/*
    The number of path to reach node (n,i) is:

        C^(i_n) = n! / i!(n-i)!
*/

double NewtonSymb(int N, int n) {

    if (n<0 || n>N)
        return 0;

    double result = 1;

    for (int i = 1; i <= n; i++)
        result = result * (N - n + i) / i;

    return result;
}

int main() {

    std::cout << NewtonSymb(5, 3) << '\n';              // 5! / (3!*2!) = 10

    return 0;
}