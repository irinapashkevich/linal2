#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;

    Matrix3D::Matrix3D(){
    };

    Matrix3D::Matrix3D(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33){
         data[0]=(a11);
         data[1]=(a12);
         data[2]=(a13);
         data[3]=(a21);
         data[4]=(a22);
         data[5]=(a23);
         data[6]=(a31);
         data[7]=(a32);
         data[8]=(a33);
    };

    Matrix3D::~Matrix3D(){
    }

    double Matrix3D::getM(int i, int j) const{
        return this->data[i*3+j];
    };

    void Matrix3D::setM(int i, int j, double x){
        this->data[i*3+j]=x;
    };

    double Matrix3D::det(){
        return this->data[0]*(this->data[4]*this->data[8]-this->data[5]*this->data[7])-data[1]*(this->data[3]*this->data[8]-this->data[5]*this->data[6])+data[2]*(this->data[3]*this->data[7]-this->data[4]*this->data[6]);
    };

    Matrix3D Matrix3D::operator+ (const Matrix3D& m2) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                M.setM(i, j, this->data[i*3+j]+m2.getM(i, j));
            }
        }
        return M;
    };

    Matrix3D Matrix3D::operator- (const Matrix3D& m2) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                M.setM(i, j, this->data[i*3+j]-m2.getM(i, j));
            }
        }
        return M;
    };

    Matrix3D Matrix3D::operator* (const double a) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                M.setM(i, j, this->data[i*3+j]*a);
            }
        }
        return M;
    };


    Matrix3D Matrix3D::operator* (const Matrix3D& m2) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                double a=0;
                for (int k=0; k<3; k++)
                {
                    a+=this->data[i*3+k]*m2.getM(k, j);
                }
                M.setM(i, j, a);
            }
        }
        return M;
    };

    Vector3D Matrix3D::operator* (const Vector3D& v) const{
        Vector3D V;
        double a=this->data[0]*v.getX()+this->data[1]*v.getY()+this->data[2]*v.getZ();
        double b=this->data[3]*v.getX()+this->data[4]*v.getY()+this->data[5]*v.getZ();
        double c=this->data[6]*v.getX()+this->data[7]*v.getY()+this->data[8]*v.getZ();
        V.setX(a);
        V.setY(b);
        V.setZ(c);
        return V;
    };

    Matrix3D operator* (double a, const Matrix3D& m){
    Matrix3D M;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            M.setM(i, j, m.getM(i, j)*a);
        }
    }
    return M;
    };

    std::ostream& operator<<(std::ostream& os, const Matrix3D& m) {
    os<<"(";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            os<<m.getM(i, j);
            if ((i!=2) || (j!=2))
                os<<"; ";
        }
    }
    os << ")";
    return os;
    };

    std::istream& operator>>(std::istream &is, Matrix3D &m){
    double a[3][3];
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            is>>a[i][j];
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            m.setM(i, j, a[i][j]);
        }
    }
    return is;
    };

