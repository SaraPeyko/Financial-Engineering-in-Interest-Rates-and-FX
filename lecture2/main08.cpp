g// main08.cpp
//
//

#include "BinModel02.h"
#include "Options04.h"
#include <iostream>

int main() {

    BinModel model;
    if (model.GetInputData() == 1)
        return 1;

    double K;               // strike price
    int N;                  // steps to expiry

    std::cout << "Enter call option data:\n";
    GetInputData(N, K);
    std::cout << "European call option price: " << PriceByCRR(model, N, K, CallPayoff) << '\n';

    std::cout << "\nEnter put option data:\n";
    GetInputData(N, K);
    std::cout << "European put option price: " << PriceByCRR(model, N, K, PutPayoff) << '\n';

    return 0;
}