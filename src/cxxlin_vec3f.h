#ifndef _CXXLIN_VEC3F_H_

#include "cxxlin_vec.h"

template <>
struct vec<3,real32>
{
	static const uint32 DIM=3;

	real32 x;
	real32 y;
	real32 z;

	explicit vec(const real32 elements[3]);
	vec(const real32& val);
	vec();
	vec(const real32& x,const real32& y,const real32& z);
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
	vec cross(const vec& rhs) const;

	real32 len_sq() const;
	real32 len() const;
};

static const vec<3,real32> VEC3F_ONE=vec<3,real32>(1.0f);
static const vec<3,real32> VEC3F_XAXIS=vec<3,real32>(1.0f,0.0f,0.0f);
static const vec<3,real32> VEC3F_YAXIS=vec<3,real32>(0.0f,1.0f,0.0f);
static const vec<3,real32> VEC3F_ZAXIS=vec<3,real32>(0.0f,0.0f,1.0f);

vec<3,real32> operator*(const real32& scalar,const vec<3,real32>& vector);
real32 dot(const vec<3,real32>& lhs,const vec<3,real32>& rhs);
vec<3,real32> cross(const vec<3,real32>& lhs,const vec<3,real32>& rhs);
real32 len_sq(const vec<3,real32>& vector);
real32 len(const vec<3,real32>& vector);

#define _CXXLIN_VEC3F_H_
#endif
