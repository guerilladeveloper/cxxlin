#ifndef _CXXLIN_VEC2FPTR_H_

#include "cxxlin_vec2f.h"

template <>
struct vec<2,real32*>
{
	static const uint32 DIM=2;

	real32* x;
	real32* y;

	explicit vec(real32* elements[2]);
	explicit vec(real32 elements[2]);
	vec(real32& val);
	vec();
	vec(real32* x,real32* y);
	vec(real32& x,real32& y);
	vec(const vec& other);
	vec(vec<2,real32>& other);
	template <uint32 D>
	vec(const vec<D,real32*>& other);
	template <uint32 D>
	vec(const vec<D,real32>& other);

	vec<2,real32> operator+(const vec& rhs) const;
	vec<2,real32> operator-(const vec& rhs) const;
	vec<2,real32> operator-() const;
	vec<2,real32> operator*(const real32& scalar) const;
	vec<2,real32> operator/(const real32& scalar) const;
	bool32 operator==(const vec& rhs) const;
	bool32 operator==(const vec<2,real32>& rhs) const;
	bool32 operator!=(const vec& rhs) const;
	bool32 operator!=(const vec<2,real32>& rhs) const;
	vec& operator=(const vec& rhs);
	vec& operator=(const vec<2,real32>& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator-=(const vec<2,real32>& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator+=(const vec<2,real32>& rhs);
	vec& operator*=(const real32& scalar);
	vec& operator/=(const real32& scalar);

	operator real32() const;
	operator real32&();
	real32& operator[](uint32 index);
	const real32& operator[](uint32 index) const;

	real32 dot(const vec& rhs) const;
	real32 dot(const vec<2,real32>& rhs) const;

	real32 len_sq() const;
	real32 len() const;
};

vec<2,real32> operator*(const real32& scalar,const vec<2,real32>& vector);
real32 dot(const vec<2,real32>& lhs,const vec<2,real32>& rhs);
real32 len_sq(const vec<2,real32>& vector);
real32 len(const vec<2,real32>& vector);

typedef vec<2,real32*> vec2fptr;
#define _CXXLIN_VEC2FPTR_H_
#endif
