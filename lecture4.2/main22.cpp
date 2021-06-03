// main22.cpp
//
//

#include <iostream>
#include "PathDependentOption04.h"
#include "GmtrAsianCall.h"

int main() {

    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel model(S0, r, sigma);

    double T = 1.0 / 12.0, K = 100.0;
    int m = 30;

    ArthmAsianCall Option(T, K, m);
    GmtrAsianCall CVOption(T, K, m);

    long N = 30000;

    Option.PriceByVarRedMC(model, N, CVOption);
    std::cout << "Arithmetric call price: " << Option.Price << '\n';
    std::cout << "Error: " << Option.PricingError << '\n';

    Option.PriceByMC(model, N);
    std::cout << "Price by direct MC: " << Option.Price << '\n';
    std::cout << "MC Error: " << Option.PricingError << '\n';

}