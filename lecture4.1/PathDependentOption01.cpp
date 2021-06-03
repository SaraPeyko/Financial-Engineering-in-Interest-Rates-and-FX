// PathDependentOption01.cpp
//
//

#include "PathDependentOption01.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel model, long N) {

    double H = 0.0;
    SamplePath S(m);        // you need to supply the size of the vector of doubles here!

    for (long i = 0; i < N; i++) {

        model.GenerateSamplePath(T, m, S);
        H += Payoff(S);
    }

    return exp(-model.r * T) * H / N;
}

double ArthmAsianCall::Payoff(SamplePath& S) {

    double Ave = 0.0;

    for (int k = 0; k < m; k++) {
        Ave = (k * Ave + S[k]) / (k + 1.0);
    }

    if (Ave < K)
        return 0.0;

    return Ave - K;
}