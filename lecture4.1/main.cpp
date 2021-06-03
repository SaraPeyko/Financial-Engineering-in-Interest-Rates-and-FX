// main.cpp
//
//

#include <iostream>
#include "PathDependentOption01.h"

int main() {

    double S0 = 100, r = 0.03, sigma = 0.2;
    BSModel model(S0, r, sigma);

    double T = 1.0 / 12.0, K = 100.0;           // Expiry is 1 month
    int m = 30;                                 // Daily observations for one month

    ArthmAsianCall option(T, K, m);
    long N = 100000;

    std::cout << "Asian Call Price = " << option.PriceByMC(model, N) << '\n';

    return 0;
}