#ifndef __Geometry_H__
#define __Geometry_H__

#include <math.h>
#include <iostream>

using namespace std;

class Vector2D
{
public:

    Vector2D(): X(0), Y(0) {}
    Vector2D(float x, float y): X(x), Y(y) {}
    ~Vector2D() {}
    
    float getX() { return X; }
    float getY() { return Y; }

    void setX(float x) { X = x; }
    void setY(float y) { Y = y; }

    float length() { return sqrt(X * X + Y * Y); }

    Vector2D& operator=(const Vector2D& v2)
    {
        X = v2.X;
        Y = v2.Y;
        
        return *this;
    }

    Vector2D operator+(const Vector2D& v2) const
    {
        return Vector2D(X + v2.X, Y + v2.Y);
    }
    
    Vector2D& operator+=(const Vector2D& v2)
    {
        X += v2.X;
        Y += v2.Y;
        
        return *this;
    }
    
    Vector2D operator-(const Vector2D& v2) const
    {
        return Vector2D(X - v2.X, Y - v2.Y);
    }
    
    Vector2D& operator-=(const Vector2D& v2)
    {
        X -= v2.X;
        Y -= v2.Y;
        
        return *this;
    }

    Vector2D operator*(float scalar)
    {
        return Vector2D(X * scalar, Y * scalar);
    }

    Vector2D& operator*=(float scalar)
    {
        X *= scalar;
        Y *= scalar;
        
        return *this;
    }
    
    Vector2D operator/(float scalar)
    {
        return Vector2D(X / scalar, Y / scalar);
    }

    Vector2D& operator/=(float scalar)
    {
        X /= scalar;
        Y /= scalar;
        
        return *this;
    }
    
    void normalize()
    {
        float l = length();
        if(l > 0)
        {
            (*this) *= 1 / l;
        }
    }

    void show()
    {
        cout << "(" << X << ", " << Y << ")" << endl;
    }

private:

    float X;
    float Y;
};

class Rectangle
{
public:

    Rectangle() : origin(Vector2D(0, 0)), width(0), height(0) {}
    Rectangle(Vector2D origin, float width, float height) : origin(origin),
        width(width), height(height) {}
    ~Rectangle() {}

    float area()
    {
        if (width < 0 || height < 0)
        {
            return -1;
        }

        return width * height;
    }

    bool contains(Vector2D point)
    {
        if (width < 0 || height < 0)
        {
            return false;
        }

        float Ox = origin.getX();
        float Oy = origin.getY();

        float Px = point.getX();
        float Py = point.getY();

        return (Px >= Ox && Py >= Oy) &&
               (Px <= (Ox + width) && Py >= Oy) &&
               (Px >= Ox && Py <= (Oy + height)) &&
               (Px <= (Ox + width) && Py <= (Oy + height));
    }
    
private:

    Vector2D origin;

    float width;
    float height;
};

#endif // __Geometry_H__
