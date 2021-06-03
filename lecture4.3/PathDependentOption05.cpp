// PathDependentOption05.cpp
//
//

#include "PathDependentOption05.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel model, long N) {

    double H = 0.0;
    SamplePath S(m);
    for (long i = 0; i < N; i++) {

        model.GenerateSamplePath(T, m, S);
        H = (i * H + Payoff(S)) / (i + 1.0);
    }

    return exp(-model.r * T) * H;
}

double ArthmAsianCall::Payoff(SamplePath& S) {

    double Ave = 0.0;
    int d = S[0].size();
    Vector one(d);

    for (int i = 0; i < d; i++) {
        one[i] = 1.0;
    }

    for (int k = 0; k < m; k++) {
        Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
    }

    if (Ave < K) return 0.0;

    return Ave - K;
}