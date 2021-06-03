// Options07.h
//
//

#ifndef Options07_h
#define Options07_h

#include "BinModel02.h"

class EurOption
{
private:
    int N;                      // step to expiry

public:
    void SetN(int N_) { N = N_; }
    virtual double Payoff(double z) = 0;
    // pricing European option
    double PriceByCRR(BinModel model);
};

class AmOption
{
private:
    int N;                      // steps to expiry

public:
    void SetN(int N_) { N = N_; }
    virtual double Payoff(double z) = 0;
    //pricing American option
    double PriceBySnell(BinModel model);
};

class Call :public EurOption, public AmOption
{
private:
    double K;                   // strike price

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};

class Put :public EurOption, public AmOption
{
private:
    double K;                   // strike price

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};

#endif // !Options07_h
