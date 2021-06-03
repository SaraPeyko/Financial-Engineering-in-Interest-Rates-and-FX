// main14.cpp
//

#include "BinLattice02.h"
#include "BinModel02.h"
#include "Options09.h"

int main() {

    BinModel model;

    if (model.GetInputData() == 1)return 1;

    Put Option;
    Option.GetInputData();

    BinLattice<double> PriceTree;
    BinLattice<bool> StoppingTree;

    Option.PriceBySnell(model, PriceTree, StoppingTree);
    std::cout << "American put prices: \n";
    PriceTree.Display();

    std::cout << "American put exercise policy: \n";
    StoppingTree.Display();

    return 0;
}