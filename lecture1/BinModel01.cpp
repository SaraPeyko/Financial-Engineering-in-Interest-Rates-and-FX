// BinModel01.cpp
//
// Seperate Compilation
#include <iostream>
#include <cmath>

int getInputData(double& S0, double& U, double& D, double& R) {

    // entering data
    std::cout << "Enter S0: "; std::cin >> S0;          // 100
    std::cout << "Enter U: "; std::cin >> U;            // 0.9
    std::cout << "Enter D: "; std::cin >> D;            // -0.3
    std::cout << "Enter R: "; std::cin >> R;            // 0.1

    /*
    
    // 1. make sure S0>0, (1+U)>0, (1+D)>0, (1+R)>0, U<D otherwise interchange U <-> D
    if (S0 <= 0 || U <= -1.0 || D <= -1.0 || R <= -1.0 || U <= D) {

        std::cout << "Illegal data ranges\n";
        std::cout << "Terminating program\n";

        return 1;
    }

     // 2. checking for arbitrage D<R<U; q>1 or q<0; q=(R-D)/(U-D)
    if (R <= D || R >= U) {

        std::cout << "Arbitrage exists\n";
        std::cout << "Terminating program\n";
        return 1;
    }

    std::cout << "Input data checked\n";
    std::cout << "There is no arbitrage\n";

    */

    return 0;
}

// Computing risk-neutral probability
double riskNeutralProb(double U, double D, double R) {

    double q = (R - D) / (U - D);
    return q;
}

double S(double S0, double U, double D, int n, int i) {

    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}