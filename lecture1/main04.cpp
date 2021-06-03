// main04.cpp
//
// Seperate Compilation

#include <iostream>
#include <cmath>
#include "BinModel01.h"

int main() {

    double S0, U, D, R;

    // make use S0>1, (1+U)>0, (1+D)>0, (1+R)>0, U<D otherwise interchange U <-> D
    if (getInputData(S0, U, D, R) == 1)return 1;

    // compute the risk-neutral probability
    double q = riskNeutralProb(U, D, R);
    std::cout << "Risk neutral probability q = " << q << '\n';

    // compute stock price at n=3, i=2
    int n = 3, i = 2;
    std::cout << "S(" << n << "," << i << ") = " << S(S0, U, D, n, i) << '\n';

    return 0;
}