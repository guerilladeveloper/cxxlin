#ifndef _CXXLIN_VECFPTR_H_

#include "cxxlin_vec.h"

template <uint32 D>
struct vec<D,real32*>
{
	real32* e[D];

	vec(const real32* elements[D]);
	vec(real32* val);
	vec();
	vec(const vec& other);
	template <uint32 D2>
	vec(const vec<D2,real32*>& other);
	vec(const vec<D,real32>& other);
	template <uint32 D2>
	vec(const vec<D,real32>& other);
	vec<D,real32> operator+(const vec& rhs);
	vec<D,real32> vec operator-(const vec& rhs);
	vec operator-();
	vec<D,real32> operator*(real32 scalar);
	vec<D,real32> operator/(real32 scalar);
	bool32 operator==(const vec& rhs);
	bool32 operator!=(const vec& rhs);
	vec& operator=(const vec& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator*=(real32 scalar);
	vec& operator/=(real32 scalar);

	real32* operator[](uint32 index);
	const real32* operator[](uint32 index) const;

	real32 dot(const vec& rhs) const;
	vec& normalize();

	real32 len_sq() const;
	real32 len_sq32() const;
	real32 len() const;
	real32 len32() const;
	real64 len_sq64() const;
	real64 len64() const;
};

template <uint32 D>
vec<D,real32> operator*(real32 scalar,const vec<D,real32>& vector);

template <uint32 D>
real32 dot(const vec<D,real32>& lhs,const vec<D,real32>& rhs);

template <uint32 D>
vec<D,real32> normal(const vec<D,real32>& vector);

#include "cxxlin_vecfptr.inl"

#define _CXXLIN_VECFPTR_H_
#endif
