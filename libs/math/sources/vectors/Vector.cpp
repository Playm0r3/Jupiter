//
// Created by Warren on 02/10/2026.
//

#include "jmath/vectors/Vector.h"

#include <algorithm>
#include <exception>

#define DIV_0(param) if(param == 0) throw std::exception()

namespace jupiter::math
{
    Vector3::Vector3(const Vector4& v) : x(v.x), y(v.y), z(v.z)
    {
    }

    Vector4::Vector4(double w, const Vector3& v) : w(w), x(v.x), y(v.y), z(v.z)
    {
    }

    Vector add(const Vector& a, const Vector& b) { return {a.x + b.x, a.y + b.y}; }
    Vector3 add(const Vector3& a, const Vector3& b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
    Vector4 add(const Vector4& a, const Vector4& b) { return {a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z}; }

    Vector add(const Vector& v, double scalar) { return {v.x + scalar, v.y + scalar}; }
    Vector3 add(const Vector3& v, double scalar) { return {v.x + scalar, v.y + scalar, v.z + scalar}; }
    Vector4 add(const Vector4& v, double scalar) { return {v.w + scalar, v.x + scalar, v.y + scalar, v.z + scalar}; }

    Vector sub(const Vector& a, const Vector& b) { return {a.x - b.x, a.y - b.y}; }
    Vector3 sub(const Vector3& a, const Vector3& b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
    Vector4 sub(const Vector4& a, const Vector4& b) { return {a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z}; }

    Vector had(const Vector& a, const Vector& b) { return {a.x * b.x, a.y * b.y}; }
    Vector3 had(const Vector3& a, const Vector3& b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
    Vector4 had(const Vector4& a, const Vector4& b) { return {a.w * b.w, a.x * b.x, a.y * b.y, a.z * b.z}; }

    Vector mul(const Vector& v, double scalar) { return {v.x * scalar, v.y * scalar}; }
    Vector3 mul(const Vector3& v, double scalar) { return {v.x * scalar, v.y * scalar, v.z * scalar}; }
    Vector4 mul(const Vector4& v, double scalar) { return {v.w * scalar, v.x * scalar, v.y * scalar, v.z * scalar}; }

    double dot(const Vector& a, const Vector& b) { return a.x * b.x + a.y * b.y; }
    double dot(const Vector3& a, const Vector3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    double dot(const Vector4& a, const Vector4& b) { return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z; }
    double dot3(const Vector4& a, const Vector4& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

    Vector div(const Vector& a, const double& s)
    {
        DIV_0(s);
        return {a.x / s, a.y / s};
    }

    Vector3 div(const Vector3& a, const double& s)
    {
        DIV_0(s);
        return {a.x / s, a.y / s, a.z / s};
    }

    Vector4 div(const Vector4& a, const double& s)
    {
        DIV_0(s);
        return {a.w / s, a.x / s, a.y / s, a.z / s};
    }

    Vector mid(const Vector& a, const Vector& b) { return div(add(a, b), 2); }
    Vector3 mid(const Vector3& a, const Vector3& b) { return div(add(a, b), 2); }
    Vector4 mid(const Vector4& a, const Vector4& b) { return {(a.w + b.w) / 2, div(add(Vector3{a}, Vector3{b}), 2)}; }

    double dis(const Vector& a, const Vector& b) { return sub(a, b).length(); }
    double dis(const Vector3& a, const Vector3& b) { return sub(a, b).length(); }
    double dis(const Vector4& a, const Vector4& b) { return sub(a, b).length3(); }

    double vec(const Vector& a, const Vector& b) { return a.x * b.y - a.y * b.x; }

    Vector3 vec(const Vector3& a, const Vector3& b)
    {
        return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
    }

    Vector3 vec(const Vector4& a, const Vector4& b)
    {
        return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
    }

    double ang(const Vector& a, const Vector& b)
    {
        double c = dot(a, b) / (a.length() * b.length());
        return acos(std::clamp(c, -1.0, 1.0));
    }

    double ang(const Vector3& a, const Vector3& b)
    {
        double c = dot(a, b) / (a.length() * b.length());
        return acos(std::clamp(c, -1.0, 1.0));
    }

    double ang(const Vector4& a, const Vector4& b)
    {
        double c = dot(a, b) / (a.length3() * b.length3());
        return acos(std::clamp(c, -1.0, 1.0));
    }

    Vector Vector::operator+(const Vector& a) const { return add(*this, a); }
    Vector3 Vector3::operator+(const Vector3& a) const { return add(*this, a); }
    Vector4 Vector4::operator+(const Vector4& a) const { return add(*this, a); }

    Vector Vector::operator-(const Vector& a) const { return sub(*this, a); }
    Vector3 Vector3::operator-(const Vector3& a) const { return sub(*this, a); }
    Vector4 Vector4::operator-(const Vector4& a) const { return sub(*this, a); }

    double Vector::operator*(const Vector& a) const { return dot(*this, a); }
    double Vector3::operator*(const Vector3& a) const { return dot(*this, a); }
    double Vector4::operator*(const Vector4& a) const { return dot(*this, a); }

    Vector Vector::operator*(const double& a) const { return mul(*this, a); }
    Vector3 Vector3::operator*(const double& a) const { return mul(*this, a); }
    Vector4 Vector4::operator*(const double& a) const { return mul(*this, a); }

    Vector Vector::operator/(const double& s) const
    {
        DIV_0(s);
        return div(*this, s);
    }

    Vector3 Vector3::operator/(const double& s) const
    {
        DIV_0(s);
        return div(*this, s);
    }

    Vector4 Vector4::operator/(const double& s) const
    {
        DIV_0(s);
        return div(*this, s);
    }

    Vector Vector::operator+=(const Vector& v)
    {
        x += v.x; y += v.y;
        return *this;
    }
    Vector Vector::operator-=(const Vector& v) { return {x - v.x, y - v.y}; }
    Vector Vector::operator*=(const Vector& v) { return {x * v.x, y * v.y}; }

    Vector Vector::operator/=(const Vector& v)
    {
        DIV_0(v.x);
        DIV_0(v.y);
        return {x / v.x, y / v.y};
    }

    Vector Vector::operator+=(const double& v)  { return {x + v, y + v}; }
    Vector Vector::operator-=(const double& v)  { return {x - v, y - v}; }
    Vector Vector::operator*=(const double& v)  { return {x * v, y * v}; }

    Vector Vector::operator/=(const double& v)
    {
        DIV_0(v);
        return {x / v, y / v};
    }

    Vector3 Vector3::operator+=(const Vector3& v) const { return {x + v.x, y + v.y, z + v.z}; }
    Vector3 Vector3::operator-=(const Vector3& v) const { return {x - v.x, y - v.y, z - v.z}; }
    Vector3 Vector3::operator*=(const Vector3& v) const { return {x * v.x, y * v.y, z * v.z}; }

    Vector3 Vector3::operator/=(const Vector3& v) const
    {
        DIV_0(v.x);
        DIV_0(v.y);
        DIV_0(v.y);
        return {x / v.x, y / v.y, z / v.z};
    }

    Vector3 Vector3::operator+=(const double& v) const { return {x + v, y + v, z + v}; }
    Vector3 Vector3::operator-=(const double& v) const { return {x - v, y - v, z - v}; }
    Vector3 Vector3::operator*=(const double& v) const { return {x * v, y * v, z * v}; }

    Vector3 Vector3::operator/=(const double& v) const
    {
        DIV_0(v);
        return {x / v, y / v, z / v};
    }

    Vector4 Vector4::operator+=(const Vector4& v) const { return {w + v.w, x + v.x, y + v.y, z + v.z}; }
    Vector4 Vector4::operator-=(const Vector4& v) const { return {w - v.w, x - v.x, y - v.y, z - v.z}; }
    Vector4 Vector4::operator*=(const Vector4& v) const { return {w * v.w, x * v.x, y * v.y, z * v.z}; }

    Vector4 Vector4::operator/=(const Vector4& v) const
    {
        DIV_0(v.x);
        DIV_0(v.y);
        DIV_0(v.y);
        DIV_0(v.w);
        return {w / v.w, x / v.x, y / v.y, z / v.z};
    }

    Vector4 Vector4::operator+=(const double& v) const { return {w + v, x + v, y + v, z + v}; }
    Vector4 Vector4::operator-=(const double& v) const { return {w - v, x - v, y - v, z - v}; }
    Vector4 Vector4::operator*=(const double& v) const { return {w * v, x * v, y * v, z * v}; }

    Vector4 Vector4::operator/=(const double& v) const
    {
        DIV_0(v);
        return {w / v, x / v, y / v, z / v};
    }
}
