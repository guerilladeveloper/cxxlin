#ifndef _CXXLIN_VEC2F_H_

#include "cxxlin_vec.h"

template <>
struct vec<2,real32>
{
	static const uint32 DIM=2;

	real32 x;
	real32 y;

	explicit vec(const real32 elements[2]);
	vec(const real32& val);
	vec();
	vec(const real32& x,const real32& y);
	vec(const vec& other);
	template <uint32 D>
	vec(const vec<D,real32>& other);

	vec operator+(const vec& rhs) const;
	vec operator-(const vec& rhs) const;
	vec operator-() const;
	vec operator*(const real32& scalar) const;
	vec operator/(const real32& scalar) const;
	bool32 operator==(const vec& rhs) const;
	bool32 operator!=(const vec& rhs) const;
	vec& operator=(const vec& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator*=(const real32& scalar);
	vec& operator/=(const real32& scalar);

	operator real32() const;
	operator real32&();
	real32& operator[](uint32 index);
	const real32& operator[](uint32 index) const;

	real32 dot(const vec& rhs) const;

	real32 len_sq() const;
	real32 len() const;
};

static const vec<2,real32> VEC2F_ONE=vec<2,real32>(1.0f);
static const vec<2,real32> VEC2F_XAXIS=vec<2,real32>(1.0f,0.0f);
static const vec<2,real32> VEC2F_YAXIS=vec<2,real32>(0.0f,1.0f);

vec<2,real32> operator*(const real32& scalar,const vec<2,real32>& vector);
real32 dot(const vec<2,real32>& lhs,const vec<2,real32>& rhs);
real32 len_sq(const vec<2,real32>& vector);
real32 len(const vec<2,real32>& vector);

#define _CXXLIN_VEC2F_H_
#endif
