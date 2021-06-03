// PathDependentOption04.h
//
//

#ifndef PathDepOption04_h
#define PathDepOption04_h

#include "BSModel01.h"

class PathDepOption {

public:
    double T, Price, PricingError;
    int m;

    virtual double Payoff(SamplePath& S) = 0;

    double PriceByMC(BSModel model, long N);

    double PriceByVarRedMC(BSModel model, long N, PathDepOption& CVOption);

    virtual double PriceByBSFormula(BSModel model) { return 0.0; }
};

class DifferenceOfOptions : public PathDepOption {

public:
    PathDepOption* Ptr1;
    PathDepOption* Ptr2;

    DifferenceOfOptions(double T_, double m_,
        PathDepOption* Ptr1_,
        PathDepOption* Ptr2_)
    {
        T = T_;
        m = m_;
        Ptr1 = Ptr1_;
        Ptr2 = Ptr2_;
    }

    double Payoff(SamplePath& S) {

        return Ptr1->Payoff(S) - Ptr2->Payoff(S);
    }
};

class ArthmAsianCall :public PathDepOption {

public:
    double K;

    ArthmAsianCall(double K_, double T_, int m_) {

        T = T_;
        K = K_;
        m = m_;
    }

    double Payoff(SamplePath& S);
};

#endif // !PathDepOption04_h
