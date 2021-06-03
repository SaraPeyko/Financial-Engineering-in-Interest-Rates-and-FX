// Options03.h
//
// Function Pointers

#ifndef Options03_h
#define Options03_h

// inputting and displaying option data
int GetInputData(int& N, double& K);

// pricing European option
double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K));

// computing call payoff
double CallPayoff(double z, double K);

// computing put payoff
double PutPayoff(double z, double K);

// computing digital call payoff
double DigitalCall(double z, double K);

// computing digital put payoff
double DigitalPut(double z, double K);

#endif // !Options03_h
