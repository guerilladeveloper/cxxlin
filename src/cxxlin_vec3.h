#ifndef _CXXLIN_VEC3_H_

#include "cxxlin_vec.h"

template <typename T>
struct vec<3,T>
{
	T x;
	T y;
	T z;

	vec(const T& x,const T& y,const T& z);
	vec(const T& val);
	vec();
	vec(const vec& other);
	template <uint32 D>
	vec(const vec<D,T>& other);
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
	const T& operator[](uint32 index) const;

	T dot(const vec& rhs);
	vec cross(const vec& rhs);

	real32 len_sq();
	real32 len_sq32();
	real32 len();
	real32 len32();
	real64 len_sq64();
	real64 len64();
};

template <typename T>
vec<3,T> operator*(const T& scalar,const vec<3,T>& vector);

template <typename T>
T dot(const vec<3,T>& lsh,const vec<3,T>& rhs);

template <typename T>
T cross(const vec<3,T>& lsh,const vec<3,T>& rhs);

#include "cxxlin_vec3.inl"

template <typename T>
using vec3=vec<3,T>;

#define _CXXLIN_VEC3_H_
#endif
