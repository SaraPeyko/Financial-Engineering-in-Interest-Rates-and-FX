// Options04.cpp
//
// A strike price is the set price at which a derivative contract 
// can be bought or sold when it is exercised

#include "Options04.h"
#include "BinModel02.h"
#include <iostream>
#include <vector>

int GetInputData(int& N, double& K) {

    std::cout << "Enter steps to expiry N: "; std::cin >> N;
    std::cout << "Enter strike price K: "; std::cin >> K;

    return 0;
}

// Call options, the strike price is where the security can be bought by the option holder
double CallPayoff(double z, double K) {

    if (z > K)return z - K;
    return 0.0;
}

// Put options, the strike price is the price at which security can be sold
double PutPayoff(double z, double K) {

    if (z < K)return K - z;
    return 0.0;
}

double PriceByCRR(BinModel model, int N, double K, double (*Payoff)(double z, double K))
{
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