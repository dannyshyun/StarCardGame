#pragma once

//---------------------------------------------------------------------------------
//	Vector3 �N���X�i x y z ������N���X�j
//---------------------------------------------------------------------------------
class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3();  //	�R���X�g���N�^
    Vector3( float x, float y, float z );

    void clear();                           //	�[��������
    void set( float x, float y, float z );  //	�l�̃Z�b�g
    void set( Vector3 &v );

    float GetLength();                //	�����擾
    void  normalize();                //	���K��
    void  SetLength( float length );  //	�����ݒ�

    Vector3 &operator=( const Vector3 &v );  //	= ���Z�q�̃I�[�o�[���[�h

    Vector3 &
        operator+=( const Vector3 &v );  //	+= ���Z�q�̃I�[�o�[���[�h
    Vector3      &
        operator-=( const Vector3 &v );  //	-= ���Z�q�̃I�[�o�[���[�h
    Vector3 &operator*=( const float f );     //	*= ���Z�q�̃I�[�o�[���[�h
    Vector3 &operator/=( const float f );     //	/= ���Z�q�̃I�[�o�[���[�h
};

//	+ ���Z�q�̃I�[�o�[���[�h
Vector3 operator+( const Vector3 &v0, const Vector3 &v1 );
//	- ���Z�q�̃I�[�o�[���[�h
Vector3 operator-( const Vector3 &v0, const Vector3 &v1 );
//	* ���Z�q�̃I�[�o�[���[�h
Vector3 operator*( const Vector3 &v, const float f );
//	/ ���Z�q�̃I�[�o�[���[�h
Vector3 operator/( const Vector3 &v, const float f );

//	�Q�� Vector2 �̋��������߂�
float GetVector3Distance( Vector3 &p0, Vector3 &p1 );
