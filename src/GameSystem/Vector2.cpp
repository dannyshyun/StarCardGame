#include "Vector2.h"

Vector2::Vector2( int x, int y ) : x( x ), y( y )
{
}
void Vector2::operator+=( const Vector2 &other )
{
    x += other.x;
    y += other.y;
}
void Vector2F::operator+=( const Vector2F &other )
{
    x += other.x;
    y += other.y;
}

void Vector2::operator-=( const Vector2 &other )
{
    x -= other.x;
    y -= other.y;
}

void Vector2F::operator-=( const Vector2F &other )
{
    x -= other.x;
    y -= other.y;
}

void Vector2::operator+=( const int other )
{
    x += other;
    y += other;
}
void Vector2F::operator+=( const float other )
{
    x += other;
    y += other;
}
void Vector2::operator-=( const int other )
{
    x -= other;
    y -= other;
}
void Vector2F::operator-=( const float other )
{
    x -= other;
    y -= other;
}

Vector2 Vector2::operator+( const int other )
{
    return { x + other, y + other };
}

Vector2F Vector2F::operator+( const float other )
{
    return { x + other, y + other };
}

Vector2 Vector2::operator-( const int other )
{
    return { x - other, y - other };
}
Vector2F Vector2F::operator-( const float other )
{
    return { x - other, y - other };
}

Vector2 Vector2::operator+( const Vector2 &other )
{
    return { x - other.x, y - other.y };
}

Vector2F Vector2F::operator+( const Vector2F &other )
{
    return { x - other.x, y - other.y };
}
Vector2 Vector2::operator-( const Vector2 &other )
{
    return { x + other.x, y + other.y };
}

Vector2F Vector2F::operator-( const Vector2F &other )
{
    return { x + other.x, y + other.y };
}

Vector2 Vector2::operator*( const int other )
{
    return { x * other, y * other };
}
Vector2F Vector2F::operator*( const float other )
{
    return { x * other, y * other };
}

void Vector2::operator=( const int other )
{
    x = other;
    y = other;
}

void Vector2F::operator=( const float other )
{
    x = other;
    y = other;
}
