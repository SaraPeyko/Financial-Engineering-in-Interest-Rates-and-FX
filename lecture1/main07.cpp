// main07.cpp
//
// Function Pointers

#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>

int main()
{
    double S0, U, D, R;

    if (getInputData(S0, U, D, R) == 1)return 1;

    double K;           // strike price
    int N;              // steps to expiry

    std::cout << "\nEnter call option price:\n";
    GetInputData(N, K);
    std::cout << "European call option price: " << PriceByCRR(S0, U, D, R, N, K, CallPayoff) << '\n';

    std::cout << "\nEnter put option price:\n";
    GetInputData(N, K);
    std::cout << "European put option price: " << PriceByCRR(S0, U, D, R, N, K, PutPayoff) << '\n';

    std::cout << "\nEnter digical call option price:\n";
    GetInputData(N, K);
    std::cout << "European put option price: " << PriceByCRR(S0, U, D, R, N, K, DigitalCall) << '\n';

    std::cout << "\nEnter digital put option price:\n";
    GetInputData(N, K);
    std::cout << "European put option price: " << PriceByCRR(S0, U, D, R, N, K, DigitalPut) << '\n';

    return 0;
}