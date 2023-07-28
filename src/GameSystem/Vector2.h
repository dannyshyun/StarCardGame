#pragma once
struct Vector2
{
    int x;
    int y;
    Vector2( int x, int y );
    void operator+=( const Vector2 &other );
    void operator-=( const Vector2 &other );
    void operator+=( const int other );
    void operator-=( const int other );

    Vector2 operator+( const int other );
    Vector2 operator-( const int other );
    Vector2 operator*( const int other );

    Vector2 operator+( const Vector2 &other );
    Vector2 operator-( const Vector2 &other );
    void    operator=( const int other );
};

struct Vector2F
{
    float x;
    float y;
    void  operator+=( const Vector2F &other );
    void  operator-=( const Vector2F &other );
    void  operator+=( const float other );
    void  operator-=( const float other );

    Vector2F operator+( const float other );
    Vector2F operator-( const float other );
    Vector2F operator*( const float other );

    Vector2F operator+( const Vector2F &other );
    Vector2F operator-( const Vector2F &other );
    void     operator=( const float other );
};
