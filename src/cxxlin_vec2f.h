#ifndef _CXXLIN_VEC2F_H_

#include "cxxlin_vec.h"

template <>
struct vec<2,real32>
{
	union
	{
		struct
		{
			real32 x;
			real32 y;
		};
		struct
		{
			real32 w;
			real32 h;
		};
	};


	vec(real32 x,real32 y);
	vec(real32 val);
	vec();
	vec(const vec& other);
	template <uint32 D>
	vec(const vec<D,real32>& other);
	vec operator+(const vec& rhs);
	vec operator-(const vec& rhs);
	vec operator-();
	vec operator*(real32 scalar);
	vec operator/(real32 scalar);
	bool32 operator==(const vec& rhs);
	bool32 operator!=(const vec& rhs);
	vec& operator=(const vec& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator*=(real32 scalar);
	vec& operator/=(real32 scalar);

	real32& operator[](uint32 index);
	const real32& operator[](uint32 index) const;

	real32 dot(const vec& rhs) const;
	vec& normalize();

	real32 len_sq() const;
	real32 len_sq32() const;
	real32 len() const;
	real32 len32() const;
	real64 len_sq64() const;
	real64 len64() const;
};

vec<2,real32> operator*(real32 scalar,const vec<2,real32>& vector);

real32 dot(const vec<2,real32>& lhs,const vec<2,real32>& rhs);

vec<2,real32> normal(const vec<2,real32>& vector);

template <uint32 D>
vec<2,real32>::vec(const vec<D,real32>& other)
{
	if (D<2)
	{
		for (uint32 i=0;i<D;++i)
		{
			*(&x+i)=other[i];
		}
		for (uint32 i=D;i<2;++i)
		{
			*(&x+i)=0.0f;
		}
		*(&x+1)=1.0f;
	}
	else
	{
		for (uint32 i=0;i<2;++i)
		{
			*(&x+i)=other[i];
		}
	}
}

typedef vec<2,real32> vec2f;

#define _CXXLIN_VEC2F_H_
#endif
