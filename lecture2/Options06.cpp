// Options06.cpp
//
//

#include "Options06.h"
#include "BinModel02.h"
#include <iostream>
#include <vector>

double EurOption::PriceByCRR(BinModel model) {

    double q = model.RiskNeutralProb();
    std::vector<double> Price(N + 1);
    for (int i = 0; i <= N; i++) {

        Price[i] = Payoff(model.S(N, i));
    }

    for (int n = N - 1; n >= 0; n--) {

        for (int i = 0; i <= n; i++) {

            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + model.GetR());
        }
    }

    return Price[0];
}

double Put::Payoff(double z) {

    if (z < K)return K - z;
    return 0.0;
}

int Put::GetInputData() {

    std::cout << "Enter put option data:\n";
    int N;
    std::cout << "Enter steps to expiry N: "; std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K: "; std::cin >> K;

    return 0;
}

double Call::Payoff(double z) {

    if (z > K)return z - K;
    return 0.0;
}

int Call::GetInputData() {

    std::cout << "Enter call option data:\n";
    int N;
    std::cout << "Enter steps to expity N: "; std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K: "; std::cin >> K;

    return 0;
}

double doubDigit::Payoff(double z) {

    if (z > K1 || z < K2)return 1;
    return 0.0;
}

int doubDigit::GetInputData() {

    std::cout << "Enter double digital option data:\n";
    int N;
    std::cout << "Enter steps to expiry N: "; std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K1: "; std::cin >> K1;
    std::cout << "Enter strike price K2: "; std::cin >> K2;

    return 0;
}