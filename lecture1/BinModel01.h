// BinModel01.h
//
//

#ifndef BinModel01_h
#define BinModel01_h

// computing riskNeutralProb(double U, double D, double R)
double riskNeutralProb(double U, double D, double R);

// computing the stock price at node (n,i)
double S(double S0, double U, double D, int n, int i);

// inputting, displaying and checking the model data
int getInputData(double& S0, double& U, double& D, double& R);

#endif // !BinModel01_h
