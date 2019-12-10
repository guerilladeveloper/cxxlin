#ifndef _CXXLIN_VEC2_H_

#include "cxxlin_vec.h"

template <typename T>
struct vec<2,T>
{
	static const uint32 DIM=2;

	T x;
	T y;

	explicit vec(const T elements[2]);
	explicit vec(const T& val);
	vec();
	vec(const T& x,const T& y);
	vec(const vec& other);
	template <uint32 D>
	vec(const vec<D,T>& other);

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
};

template <typename T>
static const vec<2,T> VEC2_ONE=vec<2,T>(T(1));
template <typename T>
static const vec<2,T> VEC2_XAXIS=vec<2,T>(T(1),T(0));
template <typename T>
static const vec<2,T> VEC2_YAXIS=vec<2,T>(T(0),T(1));

template <typename T>
vec<2,T> operator*(const T& scalar,const vec<2,T>& vector);

template <typename T>
T dot(const vec<2,T>& lhs,const vec<2,T>& rhs);

#include "cxxlin_vec2.inl"

template <typename T>
using vec2=vec<2,T>;

typedef vec<2,real32> vec2f;

#define _CXXLIN_VEC2_H_
#endif
