#ifndef _CXXLIN_VEC4F_H_

#include "cxxlin_vec.h"

template <>
struct vec<4,real32>
{
	union
	{
		struct
		{
			real32 x;
			real32 y;
			real32 z;
			real32 w;
		};
		struct
		{
			real32 r;
			real32 g;
			real32 b;
			real32 a;
		};
	};

	vec(real32 x,real32 y,real32 z,real32 w);
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

vec<4,real32> operator*(real32 scalar,const vec<4,real32>& vector);

real32 dot(const vec<4,real32>& lsh,const vec<4,real32>& rhs);

vec<4,real32> cross(const vec<4,real32>& lsh,const vec<4,real32>& rhs);

vec<4,real32> normal(const vec<4,real32>& vector);

template <uint32 D>
vec<4,real32>::vec(const vec<D,real32>& other)
{
	if (D<4)
	{
		for (uint32 i=0;i<D;++i)
		{
			(*this)[i]=other[i];
		}
		for (uint32 i=D;i<4;++i)
		{
			(*this)[i]=0.0f;
		}
		(*this)[3]=1.0f;
	}
	else
	{
		for (uint32 i=0;i<4;++i)
		{
			(*this)[i]=other[i];
		}
	}
}

typedef vec<4,real32> vec4f;

#define _CXXLIN_VEC4F_H_
#endif

