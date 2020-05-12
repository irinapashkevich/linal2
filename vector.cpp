#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;


    Vector3D::Vector3D(){};
    Vector3D::Vector3D(double x, double y, double z): x(x), y(y), z(z) {
    };

    // Деструктор
    Vector3D::~Vector3D(){};

    // Получение координат
    double Vector3D::getX() const{
        return x;
    };
    double Vector3D::getY() const{
        return y;
    };

    double Vector3D::getZ() const{
        return z;
    };

    void Vector3D::setX(double x){
        this->x=x;
    };
    void Vector3D::setY(double y){
        this->y=y;
    };
    void Vector3D::setZ(double z){
        this->z=z;
    };

    Vector3D Vector3D::operator+ (const Vector3D& v2) const{
        return Vector3D(x + v2.x, y + v2.y, z + v2.z);
    };

    Vector3D Vector3D::operator- (const Vector3D& v2) const{
        return Vector3D(x - v2.x, y - v2.y, z - v2.z);
    };

    Vector3D Vector3D::operator* (const double a) const{
        return Vector3D(x*a , y*a, z*a);
    };

    double Vector3D::operator* (const Vector3D& v2) const{
        return x*v2.getX() + y*v2.getY() + z*v2.getZ();
    };

    Vector3D operator* (double a, const Vector3D& v){
    return Vector3D(v.getX()*a, v.getY()*a, v.getZ()*a);
    };

    std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "(" << v.getX() << "; " << v.getY() << "; " <<v.getZ() << ")";
    return os;
    };

    std::istream& operator>>(std::istream &is, Vector3D &v){
    double x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
    };


