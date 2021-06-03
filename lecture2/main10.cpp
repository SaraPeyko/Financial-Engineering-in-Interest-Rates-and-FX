// main10.cpp
//
//

#include "BinModel02.h"
#include "Options06.h"
#include <iostream>

int main() {

    BinModel model;
    if (model.GetInputData() == 1)return 1;

    /*
            Call option1;
            option1.GetInputData();
            std::cout << "European call option price: " << option1.PriceByCRR(model) << "\n\n";

            Put option2;
            option2.GetInputData();
            std::cout << "European put option price: " << option2.PriceByCRR(model) << "\n\n";
    */

    doubDigit option3;
    option3.GetInputData();
    std::cout << "Double digital option price: " << option3.PriceByCRR(model) << '\n';


    return 0;
}