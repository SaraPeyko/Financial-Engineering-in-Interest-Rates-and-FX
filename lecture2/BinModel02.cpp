// BinModel02.cpp
//
//

#include "BinModel02.h"
#include <iostream>

double BinModel::RiskNeutralProb() {

    return (R - D) / (U - D);
}

double BinModel::S(int n, int i) {

    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

int BinModel::GetInputData() {

    // entering data
    std::cout << "Enter S0: "; std::cin >> S0;
    std::cout << "Enter U: "; std::cin >> U;
    std::cout << "Enter D: "; std::cin >> D;
    std::cout << "Enter R: "; std::cin >> R;
    std::cout << '\n';

    /*
        // making sure that 0<S0, -1<R<U, -1<R
        if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0) {

            std::cout << "Illegal data ranges\n";
            std::cout << "Terminating program\n";

            return 1;
        }

        // checking for arbitrage
        if (R >= U || R <= D) {

            std::cout << "Arbitrage exists\n";
            std::cout << "Terminating program\n";

            return 1;
        }

        std::cout << "Input data checked\n";
        std::cout << "There is no arbitrage\n";

    */
    

    return 0;
}

double BinModel::GetR() { return R; }

