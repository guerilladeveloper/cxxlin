#ifndef _VECTOR_H_

#include <cmath>
#include "cxxlin_defines.h"

template <uint32 D,typename T>
struct vec
{
	T e[D];

	vec(const T elements[D]);
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

template <uint32 D, typename T>
vec<D,T> operator*(const T& scalar,const vec<D,T>& vector);

template <uint32 D, typename T>
T dot(const vec<D,T>& lhs,const vec<D,T>& rhs);

#include "cxxlin_vec.inl"

#define _VECTOR_H_
#endif
