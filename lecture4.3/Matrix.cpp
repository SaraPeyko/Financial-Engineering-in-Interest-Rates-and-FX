// Matrix.cpp
//
//

#include "Matrix.h"
#include <cmath>

Vector operator*(const Matrix& C, const Vector& V) {
    
    int d = C.size();
    Vector W(d);

    for (int j = 0; j < d; j++) {

        W[j] = 0.0;
        for (int i = 0; i < d; i++) {

            W[j] = W[j] + C[j][i] * V[i];
        }
    }

    return W;
}

Vector operator+(const Vector& V, const Vector& W) {

    int d = V.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {

        U[j] = V[j] + W[j];
    }

    return U;
}

Vector operator+(const double& a, const Vector& V) {

    int d = V.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {

       U[j] = a + V[j];
    }

    return U;
}

Vector operator*(const double& a, const Vector& V) {

    int d = V.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {

        U[j] = a * V[j];
    }

    return U;
}

Vector operator*(const Vector& V, const Vector& W) {        // returns Vector, elements v[j]*w[j]

    int d = V.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {

        U[j] = V[j] * W[j];
    }

    return U;
}

Vector exp(const Vector& V) {
    
    int d = V.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {

        U[j] = exp(V[j]);
    }

    return U;
}

double operator^(const Vector& V, const Vector& W) {    // sums the products of the elements, returns double

    double sum = 0.0;
    int d = V.size();
    for (int j = 0.0; j < d; j++) {

        sum = sum + V[j] * W[j];
    }

    return sum;
}