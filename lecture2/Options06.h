// Options06.h
//
//

#ifndef Options06_h
#define Options06_h

#include "BinModel02.h"

class EurOption {

private:
    int N;                      // steps to expiry

public:
    void SetN(int N_) { N = N_; }

    // Payoff defined to return 0.0
    // Use a pure virtual function replace by 
    // virtual double payoff Payoff(double z) = 0
    virtual double Payoff(double z) { return 0.0; }

    // pricing European option
    double PriceByCRR(BinModel model);
};

class Call :public EurOption {

private:
    double K;                   // strike price

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();

    virtual double Payoff(double z);

};

class Put :public EurOption {

private:
    double K;                   // strike price

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();

    virtual double Payoff(double z);
};

/*
    A double digital option is particular option (financial derivative)
    At maturity, the payoff is 1 if the spot price of the underlying asset is between two numbers,
    the lower and upper strikes of the option; otherwise it is 0

    long position means holding the stock with expectation it will rise in value
    short position means selling the stock you don't own

    A double digital with lower strike K1 and upper strike K2 can be replicated by
    going long a digical option with K1 and short position with K2

*/

class doubDigit :public EurOption {

private:
    double K1, K2;                  // strike price

public:
    void setK(double K1_, double K2_) {
        K1 = K1_;
        K2 = K2_;
    }

    int GetInputData();
    virtual double Payoff(double z);
};
#endif // !Options06_h

