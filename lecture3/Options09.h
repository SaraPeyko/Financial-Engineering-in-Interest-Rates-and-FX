// Options09.h
//
//

#ifndef Options09_h
#define Options09_h

#include "BinLattice02.h"
#include "BinModel02.h"

class Option {

private:
    int N;                      // steps to expiry

public:
    void SetN(int N_) { N = N_; }
    int GetN() { return N; }
    virtual double Payoff(double z) = 0;
};

class EurOption :public virtual Option {

public:
    // pricing European option
    double PriceByCRR(BinModel model);
};

class AmOption :public virtual Option {

public:
    // pricing American option
    double PriceBySnell(BinModel model,
        BinLattice<double>& PriceTree,
        BinLattice<bool>& stoppingTree);
};

class Call :public EurOption, public AmOption {

private:
    double K;                   // strike price

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};

class Put :public EurOption, public AmOption {

private:
    double K;                   // strike price

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};

#endif // !Options09_h

