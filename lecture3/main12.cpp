// main12.cpp
//
//

#include "BinModel02.h"
#include "Options07.h"
#include <iostream>

int main() {

    BinModel model;
    if (model.GetInputData() == 1)return 1;

    Call Option1;
    Option1.GetInputData();
    std::cout << "European call option price: " << Option1.PriceByCRR(model) << '\n';
    std::cout << "American call option price: " << Option1.PriceBySnell(model) << '\n';

    Put Option2;
    Option2.GetInputData();
    std::cout << "European put option price: " << Option2.PriceByCRR(model) << '\n';
    std::cout << "American put option price: " << Option2.PriceBySnell(model) << '\n';

    return 0;
}