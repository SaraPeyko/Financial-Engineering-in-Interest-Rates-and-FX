// PathDependentOption02.cpp
//
//

#include "PathDependentOption02.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel model, long N) {

    double H = 0.0, Hsq = 0.0;
    SamplePath S(m);

    for (long i = 0; i < N; i++) {

        model.GenerateSamplePath(T, m, S);
        H += Payoff(S);
        Hsq += pow(Payoff(S), 2);
    }

    H = H / N;

    Hsq = Hsq / N;

    Price = exp(-model.r * T) * H;

    PriceError = exp(-model.r * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);

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