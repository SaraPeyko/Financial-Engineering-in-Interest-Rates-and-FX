// PathDependentOption01.h
//
//

#ifndef PathDepOption01_h
#define PathDepOption01_h

#include "BSModel01.h"

class PathDepOption {

public:
    double T;
    int m;                                              // m is the number of points

    double PriceByMC(BSModel model, long N);            // N is the number of simulations
    virtual double Payoff(SamplePath& S) = 0;

};

class ArthmAsianCall :public PathDepOption {

public:
    double K;                                           // strike price

    // constructor
    ArthmAsianCall(double T_, double K_, int m_) {

        T = T_;
        K = K_;
        m = m_;
    }

    double Payoff(SamplePath& S);
};
#endif // !PathDepOption01_h

