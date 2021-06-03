// Optionc09.cpp
//
//

#include "Options09.h"
#include "BinModel02.h"
#include "BinLattice02.h"
#include <vector>
#include <iostream>

double EurOption::PriceByCRR(BinModel model) {

    double q = model.RiskNeutralProb();
    int N = GetN();
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

double AmOption::PriceBySnell(BinModel model, 
    BinLattice<double>& PriceTree, 
    BinLattice<bool>& stoppingTree) {

    double q = model.RiskNeutralProb();
    int N = GetN();
    PriceTree.SetN(N);
    stoppingTree.SetN(N);
    double ContVal;

    for (int i = 0; i <= N; i++) {

        PriceTree.SetNode(N, i, Payoff(model.S(N, i)));
        stoppingTree.SetNode(N, i, 1);
    }

    for (int n = N - 1; n >= 0; n--) {

        for (int i = 0; i <= n; i++) {

            ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) 
                / (1 + model.GetR());

            PriceTree.SetNode(n, i, Payoff(model.S(n, i)));
            stoppingTree.SetNode(n, i, 1);

            if (ContVal > PriceTree.GetNode(n, i))
            {
                PriceTree.SetNode(n, i, ContVal);
                stoppingTree.SetNode(n, i, 0);
            }
            else if (PriceTree.GetNode(n, i) == 0.0)
            {
                stoppingTree.SetNode(n, i, 0);
            }
        }
    }

    return PriceTree.GetNode(0, 0);
}

int Call::GetInputData()
{
    std::cout << "Enter call option data: \n";
    int N;
    std::cout << "Enter steps to expiry N: \n"; std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K: \n"; std::cin >> K;
    std::cout << '\n';

    return 0;
}

double Call::Payoff(double z) {

    if (z > K)return z - K;
    return 0.0;
}

int Put::GetInputData()
{
    std::cout << "Enter put option data: \n";
    int N;
    std::cout << "Enter steps to expiry N: \n"; std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K: \n"; std::cin >> K;
    std::cout << '\n';

    return 0;
}

double Put::Payoff(double z) {

    if (z < K)return K - z;
    return 0.0;
}
