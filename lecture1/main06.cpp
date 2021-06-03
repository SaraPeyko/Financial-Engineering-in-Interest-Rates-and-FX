// main06.cpp
//
// Pointer

#include "BinModel01.h"
#include "Options02.h"
#include <iostream>
#include <cmath>

int main() {

    double S0, U, D, R;

    if (getInputData(S0, U, D, R) == 1)
        return 1;

    double K;                   // strike price
    int N;                      // steps to expiry

    std::cout << "Enter call options data:\n";
    GetInputData(&N, &K);
    std::cout << "European call option price: " << PriceByCRR(S0, U, D, R, N, K) << '\n';

    return 0;
}