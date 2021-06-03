// main09.cpp
//
//

#include "BinModel02.h"
#include "Options05.h"
#include <iostream>

int main() {

    BinModel model;
    if (model.GetInputData() == 1)return 1;

    Call Option1;
    Option1.GetInputData();
    std::cout << "European call option price: " << Option1.PriceByCRR(model, Option1.GetK()) << "\n\n";

    Put Option2;
    Option2.GetInputData();
    std::cout << "European put option data: " << Option2.PriceByCRR(model, Option2.GetK()) << '\n';

    return 0;
}