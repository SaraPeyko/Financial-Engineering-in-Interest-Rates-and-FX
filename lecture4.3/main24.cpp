// main24.cpp
//
//

#include <iostream>
#include "PathDependentOption05.h"

int main() {

    int d = 3;
    Vector S0(d);
    S0[0] = 40.0;
    S0[1] = 60.0;
    S0[2] = 100.0;

    double r = 0.03;
    Matrix C(d);
    for (int i = 0; i < d; i++) {
        C[i].resize(d);
    }
    C[0][0] = 0.1;  C[0][1] = -0.1; C[0][2] = 0.0;
    C[1][0] = -0.1; C[1][1] = 0.2;  C[1][2] = 0.0;
    C[2][0] = 0.0;  C[2][1] = 0.0;  C[2][2] = 0.3;

    BSModel model(S0, r, C);

    double T = 1.0 / 12.0, K = 200.0;
    int m = 30;
    ArthmAsianCall Option(T, K, m);

    long N = 30000;
    std::cout << "Arithmetric Basket Call Price: " << Option.PriceByMC(model, N) << '\n';

}