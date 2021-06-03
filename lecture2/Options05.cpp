// Options05.cpp
//
//

#include "Options05.h"
#include "BinModel02.h"
#include <iostream>
#include <vector>

double EurOption::PriceByCRR(BinModel model, double K) {

    double q = model.RiskNeutralProb();
    std::vector<double> Price(N + 1);
    for (int i = 0; i <= N; i++) {

        Price[i] = Payoff(model.S(N, i), K);
    }

    for (int n = N - 1; n >= 0; n--) {

        for (int i = 0; i <= n; i++) {

            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + model.GetR());
        }
    }

    return Price[0];
}

double CallPayoff(double z, double K) {

    if (z > K)return z - K;
    return 0.0;
}

int Call::GetInputData() {

    std::cout << "Enter call option data:\n";

    int N;
    std::cout << "Enter steps to expiry N: "; std::cin >> N;
    SetN(N);

    std::cout << "Enter strike price K: "; std::cin >> K;

    return 0;
}

double PutPayoff(double z, double K) {

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