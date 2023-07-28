﻿#include "Vector3.h"

//---------------------------------------------------------------------------------
//	コンストラクタ
//---------------------------------------------------------------------------------
Vector3::Vector3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
Vector3::Vector3( float x, float y, float z )
{
    this->x = x;
    this->y = y;
    this->z = z;
}
//---------------------------------------------------------------------------------
//	ゼロ初期化（ＸＹＺの値を０にします）
//---------------------------------------------------------------------------------
void Vector3::clear()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
//---------------------------------------------------------------------------------
//	値のセット（ＸＹＺをそれぞれ受け取るバージョン）
//---------------------------------------------------------------------------------
void Vector3::set( float x, float y, float z )
{
    this->x = x;
    this->y = y;
    this->z = z;
}
//---------------------------------------------------------------------------------
//	値のセット（ Vector3 を受け取るバージョン ）
//---------------------------------------------------------------------------------
void Vector3::set( Vector3 &v )
{
    x = v.x;
    y = v.y;
    z = v.z;
}
//---------------------------------------------------------------------------------
//	長さ取得
//---------------------------------------------------------------------------------
float Vector3::GetLength()
{
    return sqrtf( x * x + y * y + z * z );
}
//---------------------------------------------------------------------------------
//	正規化（ベクトルの長さを１にする）
//---------------------------------------------------------------------------------
void Vector3::normalize()
{
    float length = GetLength();
    if( length > 0.0f )
    {
        x = x / length;
        y = y / length;
        z = z / length;
    }
}
//---------------------------------------------------------------------------------
//	長さ設定
//---------------------------------------------------------------------------------
void Vector3::SetLength( float length )
{
    normalize();
    x = x * length;
    y = y * length;
    z = z * length;
}

//---------------------------------------------------------------------------------
//	= 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 &Vector3::operator=( const Vector3 &v )
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
//---------------------------------------------------------------------------------
//	+= 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 &Vector3::operator+=( const Vector3 &v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}
//---------------------------------------------------------------------------------
//	-= 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 &Vector3::operator-=( const Vector3 &v )
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}
//---------------------------------------------------------------------------------
//	*= 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 &Vector3::operator*=( const float f )
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}
//---------------------------------------------------------------------------------
//	/= 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 &Vector3::operator/=( const float f )
{
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

//---------------------------------------------------------------------------------
//	+ 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 operator+( const Vector3 &v0, const Vector3 &v1 )
{
    Vector3 v;
    v.x = v0.x + v1.x;
    v.y = v0.y + v1.y;
    v.z = v0.z + v1.z;
    return v;
}
//---------------------------------------------------------------------------------
//	- 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 operator-( const Vector3 &v0, const Vector3 &v1 )
{
    Vector3 v;
    v.x = v0.x - v1.x;
    v.y = v0.y - v1.y;
    v.z = v0.z - v1.z;
    return v;
}
//---------------------------------------------------------------------------------
//	* 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 operator*( const Vector3 &v, const float f )
{
    Vector3 r;
    r.x = v.x * f;
    r.y = v.y * f;
    r.z = v.z * f;
    return r;
}
//---------------------------------------------------------------------------------
//	/ 演算子のオーバーロード
//---------------------------------------------------------------------------------
Vector3 operator/( const Vector3 &v, const float f )
{
    Vector3 r;
    r.x = v.x / f;
    r.y = v.y / f;
    r.z = v.z / f;
    return r;
}

//---------------------------------------------------------------------------------
//	２つの Vector3 の距離を求める
//---------------------------------------------------------------------------------
float GetVector3Distance( Vector3 &p0, Vector3 &p1 )
{
    Vector3 v = p0 - p1;
    return v.GetLength();
}
