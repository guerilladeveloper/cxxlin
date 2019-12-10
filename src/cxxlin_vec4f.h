#ifndef _CXXLIN_VEC4F_H_

#include "cxxlin_vec.h"

template <>
struct vec<4,real32>
{
	static const uint32 DIM=4;

	real32 x;
	real32 y;
	real32 z;
	real32 w;

	explicit vec(const real32 elements[4]);
	vec(const real32& val);
	vec();
	vec(const real32& x,const real32& y,const real32& z,const real32& w);
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
};


static const vec<4,real32> VEC4F_ONE=vec<4,real32>(real32(1));

static const vec<4,real32> VEC4F_XAXIS=vec<4,real32>(real32(1),real32(0),real32(0),real32(0));

static const vec<4,real32> VEC4F_YAXIS=vec<4,real32>(real32(0),real32(1),real32(0),real32(0));

static const vec<4,real32> VEC4F_ZAXIS=vec<4,real32>(real32(0),real32(0),real32(1),real32(0));

static const vec<4,real32> VEC4F_WAXIS=vec<4,real32>(real32(0),real32(0),real32(0),real32(1));

vec<4,real32> operator*(const real32& scalar,const vec<4,real32>& vector);
real32 dot(const vec<4,real32>& lhs,const vec<4,real32>& rhs);

#define _CXXLIN_VEC4F_H_
#endif
