//
// Created by Warren on 02/10/2026.
//

#ifndef JUPITER_VECTOR_H
#define JUPITER_VECTOR_H

#include <cmath>
#include <string>

namespace jupiter::math
{
    struct Vector;
    struct Vector3;
    struct Vector4;

    struct Vector
    {
        double x = 0.0;
        double y = 0.0;

        Vector(double x, double y) : x(x), y(y) {}
        Vector(const Vector& copy) = default;
        Vector(float angle, float rayon) : x(cos(angle) * rayon), y(sin(angle) * rayon) {}

        [[nodiscard]] double length() const { return sqrt(x * x + y * y); }
        [[nodiscard]] double length2() const { return x * x + y * y; }
        [[nodiscard]] Vector opp() const { return {-x, -y}; }
        [[nodiscard]] std::string toString() const {return "(x: " + std::to_string(x) + ", y: " + std::to_string(y) + ")";}

        Vector operator+(const Vector& v) const;
        Vector operator-(const Vector& v) const;
        double operator*(const Vector& v) const;
        Vector operator*(const double& s) const;
        Vector operator/(const double& s) const;
        Vector operator+=(const Vector& v);
        Vector operator-=(const Vector& v);
        Vector operator*=(const Vector& s);
        Vector operator/=(const Vector& s);
        Vector operator+=(const double& v);
        Vector operator-=(const double& v);
        Vector operator*=(const double& s);
        Vector operator/=(const double& s);

    };

    struct Vector3
    {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

        Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
        Vector3(const Vector3& copy) = default;
        Vector3(float rayon, float theta, float phi) : x(cos(theta) * rayon), y(sin(theta) * rayon), z(sin(phi) * rayon) {}
        Vector3(const Vector4& v);

        [[nodiscard]] double length() const { return sqrt(x * x + y * y + z * z); }
        [[nodiscard]] double length2() const { return x * x + y * y + z * z; }
        [[nodiscard]] double opp() const { return sqrt(x * x + y * y + z * z); }
        [[nodiscard]] std::string toString() const {return "(x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z) + ")";}

        Vector3 operator+(const Vector3& v) const;
        Vector3 operator-(const Vector3& v) const;
        double operator*(const Vector3& v) const;
        Vector3 operator*(const double& s) const;
        Vector3 operator/(const double& s) const;
        Vector3 operator+=(const Vector3& v) const;
        Vector3 operator-=(const Vector3& v) const;
        Vector3 operator*=(const Vector3& s) const;
        Vector3 operator/=(const Vector3& s) const;
        Vector3 operator+=(const double& v) const;
        Vector3 operator-=(const double& v) const;
        Vector3 operator*=(const double& s) const;
        Vector3 operator/=(const double& s) const;
    };

    struct Vector4
    {
        double w = 0.0;
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

        Vector4(double w, double x, double y, double z) : w(w), x(x), y(y), z(z) {};
        Vector4(double w, const Vector3& v);

        [[nodiscard]] double length() const {return sqrt(x * x + y * y + z * z + w * w); }
        [[nodiscard]] double length2() const {return x * x + y * y + z * z + w * w; }
        [[nodiscard]] double length3() const {return x * x + y * y + z * z; }
        [[nodiscard]] Vector4 opp() const {return {-w, -x, -y, -z}; }
        [[nodiscard]] std::string toString() const {return "(x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z) + ", w: " + std::to_string(w) + ")";}

        Vector4 operator+(const Vector4& a) const;
        Vector4 operator-(const Vector4& a) const;
        double operator*(const Vector4& v) const;
        Vector4 operator*(const double& s) const;
        Vector4 operator/(const double& s) const;
        Vector4 operator+=(const Vector4& v) const;
        Vector4 operator-=(const Vector4& v) const;
        Vector4 operator*=(const Vector4& s) const;
        Vector4 operator/=(const Vector4& s) const;
        Vector4 operator+=(const double& v) const;
        Vector4 operator-=(const double& v) const;
        Vector4 operator*=(const double& s) const;
        Vector4 operator/=(const double& s) const;
    };

    Vector add(const Vector& a, const Vector& b);
    Vector3 add(const Vector3& a, const Vector3& b);
    Vector4 add(const Vector4& a, const Vector4& b);

    Vector add(const Vector& v, double scalar);
    Vector3 add(const Vector3& v, double scalar);
    Vector4 add(const Vector4& v, double scalar);

    Vector sub(const Vector& a, const Vector& b);
    Vector3 sub(const Vector3& a, const Vector3& b);
    Vector4 sub(const Vector4& a, const Vector4& b);

    Vector had(const Vector& a, const Vector& b);
    Vector3 had(const Vector3& a, const Vector3& b);
    Vector4 had(const Vector4& a, const Vector4& b);

    Vector mul(const Vector& v, double scalar);
    Vector3 mul(const Vector3& v, double scalar);
    Vector4 mul(const Vector4& v, double scalar);

    double dot(const Vector& a, const Vector& b);
    double dot(const Vector3& a, const Vector3& b);
    double dot(const Vector4& a, const Vector4& b);
    double dot3(const Vector4& a, const Vector4& b);

    Vector div(const Vector& a, const double& s);
    Vector3 div(const Vector3& a, const double& s);
    Vector4 div(const Vector4& a, const double& s);

    Vector mid(const Vector& a, const Vector& b);
    Vector3 mid(const Vector3& a, const Vector3& b);
    Vector4 mid(const Vector4& a, const Vector4& b);

    double dis(const Vector& a, const Vector& b);
    double dis(const Vector3& a, const Vector3& b);
    double dis(const Vector4& a, const Vector4& b);

    double vec(const Vector& a, const Vector& b);
    Vector3 vec(const Vector3& a, const Vector& b);
    Vector3 vec(const Vector4& a, const Vector4& b);

    double ang(const Vector& a, const Vector& b);
    double ang(const Vector3& a, const Vector3& b);
    double ang(const Vector4& a, const Vector4& b);
}

#endif //JUPITER_VECTOR_H
