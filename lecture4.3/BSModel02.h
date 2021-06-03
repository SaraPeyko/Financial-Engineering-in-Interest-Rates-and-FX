// BSModel02.h
//
//

#ifndef BSModel02_h
#define BSModel02_h

#include "Matrix.h"

typedef std::vector<Vector> SamplePath;

class BSModel {

public:
    Vector S0, sigma;
    Matrix C;
    double r;

    BSModel(Vector S0_, double r_, Matrix C_);
    void GenerateSamplePath(double T, int m, SamplePath& S);

};
#endif // !BSModel02_h
