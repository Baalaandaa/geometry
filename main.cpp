#include <bits/stdc++.h>

using namespace std;


const double EPS = 1e-6; //Calculations precision
const int OUTPUT_PRECISION = 10;



template<typename T = double>
struct Vec2{

    T x, y;
    Vec2(): x(0), y(0){}
    Vec2(T val): x(val), y(val){}
    Vec2(T x_, T y_): x(x_), y(y_){}
    Vec2(const Vec2<T> &oth): x(oth.x), y(oth.y){}

    //Input, output in format "2.0 5.0"
    friend istream& operator>> (istream& in, Vec2<T> &a){
        in >> a.x >> a.y;
        return in;
    }

    friend ostream& operator<< (ostream& out, const Vec2<T> &a){
        out << fixed << setprecision(OUTPUT_PRECISION);
        out << a.x << ' ' << a.y;
        return out;
    }

    //Add, subtract
    Vec2<T> operator+ (const Vec2<T>& oth) const{
        return Vec2<T>(x + oth.x, y + oth.y);
    }

    Vec2<T> operator- (const Vec2<T>& oth) const{
        return Vec2<T>(x - oth.x, y - oth.y);
    }

    void operator+= (const Vec2<T>& oth){
        x += oth.x;
        y += oth.y;
    }

    void operator-= (const Vec2<T>& oth){
        x -= oth.x;
        y -= oth.y;
    }

    //Multiply and divide on scalar
    Vec2<T> operator* (const T k) const{
        return Vec2<T>(x * k, y * k);
    }

    Vec2<T> operator/ (const T k) const{
        return Vec2<T>(x / k, y / k);
    }

    void operator*= (const T k){
        x *= k;
        y *= k;
    }

    void operator/= (const T k){
        x /= k;
        y /= k;
    }

    //Unary operator- (-a == a * (-1))
    Vec2<T> operator- () const{
        return Vec2<T>(-x, -y);
    }

    //Scalar multiplication
    T operator* (const Vec2<T>& oth) const{
        return x * oth.x + y * oth.y;
    }

    //Pseudo-vector multiplication
    T operator% (const Vec2<T> &oth) const{
        return x * oth.y - y * oth.x;
    }

    //Signed angle between vectors
    double operator^ (const Vec2<T> &oth) const{
        return atan2((*this % oth), (*this * oth));
    }

    [[nodiscard]] Vec2<T> rotate(const double ang) const{
        double sn = sin(ang), cs = cos(ang);
        return Vec2<T>(x * cs - y * sn, x * sn + y * cs);
    }

    // Returns squared vector length
    T square_length() const{
        return x * x + y * y;
    }

    // Returns vector length
    double length() const{
        return sqrt(square_length());
    }

    //Returns normalized vector
    Vec2<T> normalize() const{
        return *this / length();
    };

    //Return perpendicular vector
    Vec2<T> normal() const{
        return Vec2(y, x);
    }

};

template<typename T = double>
using Point = Vec2<T>;

int main() {
    Point<double> a(5, 5), b(7, -7);
    cout << (a - b) << '\n' << (a + b) << '\n' << a * b << ' ' << a * 2 << ' ' << a / 3 << ' ' << (a ^ b);
    return 0;
}
