// Matrix.h
//
//

#ifndef Matrix_h
#define Matrix_h

#include <vector>

typedef std::vector<double> Vector;
typedef std::vector<Vector> Matrix;

Vector operator*(const Matrix& C, const Vector& V);
Vector operator*(const double& a, const Vector& V);

Vector operator+(const double& a, const Vector& V);
Vector operator+(const Vector& V, const Vector& W);

Vector operator*(const Vector& V, const Vector& W);
Vector exp(const Vector& V);

double operator^(const Vector& V, const Vector& W);

#endif // !Matrix_h

