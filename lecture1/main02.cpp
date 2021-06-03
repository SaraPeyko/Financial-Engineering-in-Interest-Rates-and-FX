// main02.cpp
//
// Entering Data

#include <iostream>
#include <cmath>

int main() {

    double S0, U, D, R;

    // entering data
    std::cout << "Enter S0: "; std::cin >> S0;              // 100
    std::cout << "Enter U: "; std::cin >> U;                // 0.05
    std::cout << "Enter D: "; std::cin >> D;                // -0.05
    std::cout << "Enter R: "; std::cin >> R;                // 0.1      Can't be greater than U=0.05

    // 1. make sure S0>0, (1+U)>0, (1+D)>0, (1+R)>0
    
    
    /*
    
    if (S0 <= 0 || U <= -1.0 || D <= -1.0 || R <= -1.0 || U <= D) {

        std::cout << "Illegal data ranges\n";
        std::cout << "Terminating program\n";
        return 1;
    }

    // 2. Checking for arbitrage D<R<U; q>1, or q<0; q=(R-D)/(U-D)
    if (R <= D || R >= U) {

        std::cout << "Arbitrage exists\n";
        std::cout << "Terminating program\n";
        return 1;
    }

    std::cout << "Input data checked\n";
    std::cout << "There is no arbitrage\n";
    */
    

    // compute the risk-neutral probability
    double q = (R - D) / (U - D);
    std::cout << "Risk neutral probability: " << q << '\n';

    // compute stock price at n=3, i=2
    int n = 3, i = 2;
    std::cout << "S(" << n << ", " << i << ") = " << S0 * pow(1 + U, i) * pow(1 + D, n - i) << '\n';

    /*
    
        Enter S0: 100
        Enter U: 0.05
        Enter D: -0.05
        Enter R: 0.1
        Risk neutral probability: 1.5
        S(3, 2) = 104.737
  
    */


}