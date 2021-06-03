// Options01.cpp
//
// Binomial Pricer

#include "Options01.h"
#include "BinModel01.h"
#include <vector>
#include <iostream>

int GetInputData(int& N, double& K) {

    std::cout << "Enter steps to expiry N: "; std::cin >> N;
    std::cout << "Enter strike price K: "; std::cin >> K;

    return 0;
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K) {

    double q = riskNeutralProb(U, D, R);
    std::vector<double> Price(N + 1);

    for (int i = 0; i <= N; i++) {
        
        Price[i] = CallPayoff(S(S0, U, D, N, i), K);
    }

    for (int n = N - 1; n >= 0; n--) {

        for (int i = 0; i <= n; i++) {

            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + R);
        }
    }

    return Price[0];
}

double CallPayoff(double z, double K) {

    if (z > K)return z - K;
    return 0.0;
}

