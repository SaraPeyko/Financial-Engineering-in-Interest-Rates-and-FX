// PathDependentOption03.cpp
//
//

#include "PathDependentOption03.h"
#include <cmath>

void Rescale(SamplePath& S, double x) {

    int m = S.size();
    for (int j = 0; j < m; j++) {

        S[j] = x * S[j];
    }
}

double PathDepOption::PriceByMC(BSModel model, long N, double epsilon) {

    double H = 0.0, Hsq = 0.0, Heps = 0.0;
    SamplePath S(m);
    for (long i = 0; i < N; i++) {

        model.GenerateSamplePath(T, m, S);

        H = (i * H + Payoff(S)) / (i + 1.0);

        Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);

        Rescale(S, 1.0 + epsilon);

        Heps = (i * Heps + Payoff(S)) / (i + 1.0);
    }

    Price = exp(-model.r * T) * H;
    PricingError = exp(-model.r * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
    delta = exp(-model.r * T) * (Heps - H) / (model.S0 * epsilon);

    return Price;
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