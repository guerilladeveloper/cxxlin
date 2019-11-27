#ifndef _CXXLIN_VEC4_H_

#include "cxxlin_vec.h"

template <typename T>
struct vec<4,T>
{
	T x;
	T y;
	T z;
	T w;

	vec(const T& x,const T& y,const T& z,const T& w);
	vec(const T& val);
	vec();
	vec(const vec& other);
	vec operator+(const vec& rhs);
	vec operator-(const vec& rhs);
	vec operator-();
	vec operator*(const T& scalar);
	vec operator/(const T& scalar);
	bool32 operator==(const vec& rhs);
	bool32 operator!=(const vec& rhs);
	vec& operator=(const vec& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator*=(const T& scalar);
	vec& operator/=(const T& scalar);

	T& operator[](uint32 index);

	T dot(const vec& rhs);

	real32 len_sq();
	real32 len_sq32();
	real32 len();
	real32 len32();
	real64 len_sq64();
	real64 len64();
};

template <typename T>
vec<4,T> operator*(const T& scalar,const vec<4,T>& vector);

template <typename T>
T dot(const vec<4,T>& lsh,const vec<4,T>& rhs);

#include "cxxlin_vec2.inl"

template <typename T>
using vec4=vec<4,T>;

#define _CXXLIN_VEC4_H_
#endif