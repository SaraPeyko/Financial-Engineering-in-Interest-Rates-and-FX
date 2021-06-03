// PathDependentOption03.h
//
//

#ifndef PathDepOption03_h
#define PathDepOption03_h

#include "BSModel01.h"

class PathDepOption {

public:
    double T, Price, PricingError, delta;
    int m;

    virtual double Payoff(SamplePath& S) = 0;
    double PriceByMC(BSModel model, long N, double esilon);

};

class ArthmAsianCall : public PathDepOption {

public:
    double K;

    ArthmAsianCall(double T_, double K_, int m_) {
        T = T_;
        K = K_;
        m = m_;
    }

    double Payoff(SamplePath& S);
};

#endif // !PathDepOption03_h

