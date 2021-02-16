#include <bits/stdc++.h>

using namespace std;


const double EPS = 1e-6; //Calculations precision
const int OUTPUT_PRECISION = 10;



template<typename T = double>
struct Vec2{

    T x, y;
    Vec2(): x(0), y(0){}
    explicit Vec2(T val): x(val), y(val){}
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

    Vec2<T>& operator+= (const Vec2<T>& oth){
        x += oth.x;
        y += oth.y;
        return *this;
    }

    Vec2<T>& operator-= (const Vec2<T>& oth){
        x -= oth.x;
        y -= oth.y;
        return *this;
    }

    //Multiply and divide on scalar
    Vec2<T> operator* (const T k) const{
        return Vec2<T>(x * k, y * k);
    }

    Vec2<T> operator/ (const T k) const{
        return Vec2<T>(x / k, y / k);
    }

    //Thx to Alexey @minus_vseros Pozdnyakov
    //Thx to Grigoriy @princebelkovetz Belkovetz
    //Thx to all discord cummunity
    //Fuck Artem Akimov!
    //With love, Kirill @baalaandaa Balandin

    Vec2<T>& operator*= (const T k){
        x *= k;
        y *= k;
        return *this;
    }

    Vec2<T>& operator/= (const T k){
        x /= k;
        y /= k;
        return *this;
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
    [[nodiscard]] T square_length() const{
        return x * x + y * y;
    }

    // Returns vector length
    [[nodiscard]] double length() const{
        return sqrt(square_length());
    }

    //Returns normalized vector
    [[nodiscard]] Vec2<T> normalize() const{
        return *this / length();
    };

    //Return perpendicular vector
    [[nodiscard]] Vec2<T> normal() const{
        return Vec2(-y, x);
    }

};

template<typename T = double>
using Point = Vec2<T>;


template<typename T = double>
struct Line{

    T a, b, c;

    Line(): a(0), b(0), c(0){}

    Line(const T& a_, const T& b_, const T& c_): a(a_), b(b_), c(c_){}

    Line(const Point<T>& l_, const Point<T>& r_): a(r_.y - l_.y), b(l_.x - r_.x), c(r_ % l_){}

    Line(const Line<T>& oth): a(oth.a), b(oth.b), c(oth.c){}

    //Input, output in format "2.0 5.0"
    friend istream& operator>> (istream& in, Line<T> &l){
        in >> l.a >> l.b >> l.c;
        return in;
    }

    friend ostream& operator<< (ostream& out, const Line<T> &l){
        out << fixed << setprecision(OUTPUT_PRECISION) << l.a << ' ' << l.b << ' ' << l.c;
        return out;
    }

    //Normal vector
    Vec2<T> normal() const{
        return Vec2<T>(a, b);
    }

    //Directive vector
    Vec2<T> directive() const{
        return Vec2<T>(-b, a);
    }

    //Angle between line and vector
    double operator^(const Vec2<T>& oth) const{
        return directive() ^ oth;
    }

    //Angle between line and line
    double operator^(const Line<T>& oth) const{
        return oth ^ directive();
    }

    //Rotate line around point a(a \in line)
    Line<T> rotate(const Point<T>& pt, const double &angle) const{
        return Line<T> (pt, pt + (directive().rotate(angle)));
    }

    //Parallel move
    Line<T> move(const double &dist) const{
        return Line<T> (a, b, c + dist * normal().length());
    }

    //Checks whether line contains point
    bool check(const Point<T>& pt) const{
        return (abs(a * pt.x + b * pt.y + c) < EPS);
    }

};


template<typename T = double>
T dist(const Point<T> &a, const Point<T> &b){
    return (a - b).length();
}

template<typename T = double>
T dist(const Point<T> &pt, const Line<T> &ln){
    return abs(pt.x * ln.a + pt.y * ln.b + ln.c) / ln.normal().length();
}

template<typename T = double>
optional<Point<T>> intersect(const Line<T> &a, const Line<T> &b){
    T d = a.a * b.b - b.a * a.b;
    T d1 = (-a.c) * b.b - (-b.c) * a.b;
    T d2 = a.a * (-b.c) - b.a * (-a.c);
    if(d == 0){
        return nullopt;
    }
    return Point<T>(d1 / d, d2 / d);
}

template<typename T = double>
T dist(const Line<T> &a, const Line<T> &b){
    if(auto pt = intersect(a, b)){
        return 0;
    } else {
        return abs(b.c - a.c) / a.normal();
    }
}

int main() {

    return 0;
}
