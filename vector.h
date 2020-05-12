#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector3D
{
protected:
    double x;
    double y;
    double z;
public:
    // Конструкторы
    Vector3D();

    Vector3D(double x, double y, double z);

    // Деструктор
    ~Vector3D();

    // Получение координат
    double getX()const;

    double getY()const;

    double getZ()const;

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    Vector3D operator+ (const Vector3D& v2) const;

    Vector3D operator- (const Vector3D& v2) const;

    Vector3D operator* (const double a) const;

    double operator* (const Vector3D& v2) const;
};

Vector3D operator* (double a, const Vector3D& v);

std::ostream& operator<<(std::ostream& os, const Vector3D& v);

std::istream& operator>>(std::istream &is, Vector3D &v);

#endif // VECTOR_H_INCLUDED
