# Competitive programming geometry lib

**_IF YOU WANT TO USE THIS CODE, PLEASE MENTION AUTHOR_**

## Constants

```c++
    const double EPS = 1e-6; //Calculations precision
    const int OUTPUT_PRECISION = 10;
```

## structes

### Vec2(== Point)
```c++
template<typename T = double>
struct Vec2{

    T x, y;   
    Vec2(): x(0), y(0);
    Vec2(T val): x(val), y(val);
    Vec2(T x_, T y_): x(x_), y(y_);
    Vec2(const Vec2<T> &oth): x(oth.x), y(oth.y);
    
    //Input, output in format "2.0 5.0"
    friend istream& operator>> (istream& in, Vec2<T> &a);
    friend ostream& operator<< (ostream& out, const Vec2<T> &a);
 
    //Add, subtract
    Vec2<T> operator+ (const Vec2<T>& oth) const;
    Vec2<T> operator- (const Vec2<T>& oth) const;
    Vec2<T>& operator+= (const Vec2<T>& oth);
    Vec2<T>& operator-= (const Vec2<T>& oth);
    
    //Multiply and divide on scalar
    Vec2<T> operator* (const T k) const;
    Vec2<T> operator/ (const T k) const;
    Vec2<T>& operator*= (const T k);
    Vec2<T>& operator/= (const T k);

    //Unary operator- (-a == a * (-1))
    Vec2<T> operator- () const;

    //Scalar multiplication
    T operator* (const Vec2<T>& oth) const;
    
    //Pseudo-vector multiplication
    T operator% (const Vec2<T> &oth) const;
    
    //Signed angle between vectors
    double operator^ (const Vec2<T> &oth) const;

    Vec2<T> rotate(const double ang) const;
    
    T square_length() const; // Returns squared vector length
    double length() const; // Returns vector length
    Vec2<T> normalize() const; //Returns normalized vector 
    Vec2<T> norm() const; //Return perpendicular vector

};
using Point = Vec2;
```
### Line

```c++
template<typename T = double>
struct Line{
    
    T a, b, c;
    
    Line(): a(0), b(0), c(0);
    Line(const T& a_, const T& b_, const T& c_): a(a_), b(b_), c(c_);
    Line(const Point<T>& l_, const Point<T>& r_);
    Line(const Line<T>& oth): a(oth.a), b(oth.b), c(oth.c);

    //Input, output in format "2.0 5.0"
    friend istream& operator>> (istream& in, Line<T> &a);
    friend ostream& operator<< (ostream& out, const Line<T> &a);

    Vec2<T> normal() const;//Normal vector
    Vec2<T> directive() const;//Directive vector

    double operator^(const Vec2<T>& oth) const;//Angle between line and vector
    double operator^(const Line<T>& oth) const;//Angle between line and line
    
    Line<T> rotate(const Point<T>& a, const double &angle) const;//Rotate line around point a(a \in line)
    Line<T> move(const double &dist) const;//Parallel move

    bool check(const Point<T>& pt) const;//Checks if line contains point
   
};
```

### Circle
```c++
template<typename T = double>
struct Circle{
    
    Point<T> o;
    T r;
    
    Circle(): o(), r(0);
    Circle(const T& rad): o(), r(rad);
    Circle(const Point<T>& pt, const T& rad): p(pt), r(rad);
    Circle(const Circle<T>& oth): o(oth.o), r(oth.r);

};
```

### Ray

```c++
template<typename T = double>
struct Ray{
    
    Point<T> a, t;
    
    Ray(): a(), t();
    Ray(const Point<T> &a_): a(a_), t({1, 0});//Ox directed ray
    Ray(const Point<T> &a_, const Point<T> &b_): a(a_), t(b_ - a_);//Ray through points a_, b_ 
    Ray(const Point<T> &a_, const double angle): a(a_), t({cos(angle), sin(angle)});//Ray through a_ and angle angle &shrug; 
    Ray(const Ray<T> &ray): a(ray.a), t(ray.t);

};
```

### Segment
```c++
template<typename T = double>
struct Segment{
    
    Point<T> a, b;
    
    Segment(): a(), b();
    Segment(const Point<T> &a_): a(a_), b({0, 0});
    Segment(const Point<T> &a_, const Point<T> &b_): a(a_), b(b_);//Ray through points a_, b_ 
    Segment(const Segment<T> &seg): a(seg.a), b(seg.b);

};
```

### Polygon
#### Triangle(?)


## Methods

```c++

template<typename T = double>
T dist(const Point<T> &a, const Point<T> &b);

template<typename T = double>
T dist(const Point<T> &a, const Line<T> &b);

template<typename T = double>
T dist(const Line<T> &a, const Line<T> &b);

template<typename T = double>
T dist(const Point<T> &a, const Ray<T> &b);

template<typename T = double>
T dist(const Point<T> &a, const Segment<T> &b);

template<typename T = double>
T dist(const Point<T> &a, const Circle<T> &b);

template<typename T = double>
T dist(const Segment<T> &a, const Segment<T> &b);

template<typename T = double>
T dist(const Segment<T> &a, const Ray<T> &b);

template<typename T = double>
optional<point<T>> intersect(const Line<T> &a, const Line<T> &b);

template<typename T = double>
pair<optional<point<T>>, optional<point<T>>> intersect(const Line<T> &a, const Circle<T> &b);

template<typename T = double>
pair<optional<point<T>>, optional<point<T>>> intersect(const Segment<T> &a, const Circle<T> &b);

template<typename T = double>
pair<optional<point<T>>, optional<point<T>>> intersect(const Ray<T> &a, const Circle<T> &b);

template<typename T = double>
pair<optional<point<T>>, optional<point<T>>> intersect(const Circle<T> &a, const Circle<T> &b);

```