// Options03.cpp
//
// Functions Pointers

#include "Options03.h"
#include "BinModel01.h"
#include <iostream>
#include <vector>

int GetInputData(int& N, double& K) {

    std::cout << "Enter steps to expiry N: "; std::cin >> N;
    std::cout << "Enter strike price K: "; std::cin >> K;

    return 0;
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K)) {

    double q = riskNeutralProb(U, D, R);
    std::vector<double> Price(N + 1);

    for (int i = 0; i <= N; i++) {

        Price[i] = Payoff(S(S0, U, D, N, i), K);
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

double PutPayoff(double z, double K) {

    if (z < K)return K - z;
    return 0.0;
}

/*
    Add two new payoffs, Digital Calls and Digital Puts and find the price of these options
    Digital Call = 1 if z > K, and zero otherwise.
    Digital Put = 1 if z < K, and zero otherwise.
*/

double DigitalCall(double z, double K) {

    if (z > K)return 1;
    return 0.0;
}

double DigitalPut(double z, double K) {

    if (z < K)return 1;
    return 0.0;
}