#ifndef _CXXLIN_VEC_H_

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
	template <uint32 D2>
	vec(const vec<D2,T>& other);
	vec operator+(const vec& rhs) const;
	vec operator-(const vec& rhs) const;
	vec operator-() const;
	vec operator*(const T& scalar) const;
	vec operator/(const T& scalar) const;
	bool32 operator==(const vec& rhs) const;
	bool32 operator!=(const vec& rhs) const;
	vec& operator=(const vec& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator*=(const T& scalar);
	vec& operator/=(const T& scalar);

	T& operator[](uint32 index);
	const T& operator[](uint32 index) const;

	T dot(const vec& rhs) const;

	real32 len_sq() const;
	real32 len_sq32() const;
	real32 len() const;
	real32 len32() const;
	real64 len_sq64() const;
	real64 len64() const;
};

template <uint32 D, typename T>
vec<D,T> operator*(const T& scalar,const vec<D,T>& vector);

template <uint32 D, typename T>
T dot(const vec<D,T>& lhs,const vec<D,T>& rhs);

#include "cxxlin_vec.inl"

#define _CXXLIN_VEC_H_
#endif
