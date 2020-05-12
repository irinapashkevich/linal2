#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "vector.h"

class Matrix3D
{
protected:
    double data[9];
public:
    Matrix3D();
    Matrix3D(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);

    ~Matrix3D();

    double getM(int i, int j) const;

    void setM(int i, int j, double x);

    double det();

    Matrix3D operator+ (const Matrix3D& m2) const;

    Matrix3D operator- (const Matrix3D& m2) const;

    Matrix3D operator* (const double a) const;


    Matrix3D operator* (const Matrix3D& m2) const;

    Vector3D operator* (const Vector3D& v) const;
};

Matrix3D operator* (double a, const Matrix3D& m);

std::ostream& operator<<(std::ostream& os, const Matrix3D& m);

std::istream& operator>>(std::istream &is, Matrix3D &m);

#endif // MATRIX_H_INCLUDED
