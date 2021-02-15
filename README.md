# Competitive programming geometry lib

**_IF YOU WANT TO USE THIS CODE, PLEASE MENTION AUTHOR_**

## Constants

```c++
    const double EPS = 1e-6; //Calculations precision
    const int OUTPUT_PRECISION = 10; //Output precision
```

## Classes

### Point(== Vec2)
```c++
template<typename T = double>
class Point{
    
    T x, y;
    
    Point(): x(0), y(0);
    Point(T val): x(val), y(val);
    Point(T x_, T y_): x(x_), y(y_);
    
    T square_length const; // Returns squared vector length
    double length() const; // Returns vector length
    Point normalize() const; //Returns normalized vector 
    
    //Input, output in format "2.0 5.0"
    friend istream& operator>> (istream& in, Point &a);
    friend ostream& operator<< (ostream& in, Point &a);
 
    //Add, subtract
    Point operator+ (const Point& oth) const;
    Point operator- (const Point& oth) const;
    
    //Multiply and divide on scalar
    Point operator* (const T k) const;
    Point operator/ (const T k) const;

    //Unary operator- (-a == a * (-1))
    Point operator- () const;

    //Scalar multiplication
    Point operator* (const Point& oth) const;
    
    //Pseudo-vector multiplication
    Point operator% (const Point &oth) const;
    
    //Signed angle between vectors
    double operator^ (cosnt Point &oth) const;

};
```