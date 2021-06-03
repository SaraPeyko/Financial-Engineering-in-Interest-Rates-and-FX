// PathDependentOption04.cpp
//
//

#include "PathDependentOption04.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel model, long N) {

    double H = 0.0, Hsq = 0.0;
    SamplePath S(m);
    for (long i = 0; i < N; i++) {

        model.GenerateSamplePath(T, m, S);
        H = (i * H + Payoff(S)) / (i + 1.0);
        Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);
    }

    Price = exp(-model.r * T) * H;
    PricingError = exp(-model.r * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
    return Price;
}

double PathDepOption::PriceByVarRedMC(BSModel model, long N, PathDepOption& CVOption) {

    DifferenceOfOptions VarRedOpt(T, m, this, &CVOption);

    Price = VarRedOpt.PriceByMC(model, N + CVOption.PriceByBSFormula(model));

    PricingError = VarRedOpt.PricingError;

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