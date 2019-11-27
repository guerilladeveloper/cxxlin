#ifndef _CXXLIN_VEC3F_H_

#include "cxxlin_vec.h"

template <>
struct vec<3,real32>
{
	union
	{
		struct
		{
			real32 x;
			real32 y;
			real32 z;
		};
		struct
		{
			real32 w;
			real32 h;
			real32 d;
		};
		struct
		{
			real32 r;
			real32 g;
			real32 b;
		};
	};

	vec(real32 x,real32 y,real32 z);
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
	vec cross(const vec& rhs) const;
	vec& normalize();

	real32 len_sq() const;
	real32 len_sq32() const;
	real32 len() const;
	real32 len32() const;
	real64 len_sq64() const;
	real64 len64() const;
};

vec<3,real32> operator*(real32 scalar,const vec<3,real32>& vector);

real32 dot(const vec<3,real32>& lsh,const vec<3,real32>& rhs);

vec<3,real32> cross(const vec<3,real32>& lsh,const vec<3,real32>& rhs);

vec<3,real32> normal(const vec<3,real32>& vector);

template <uint32 D>
vec<3,real32>::vec(const vec<D,real32>& other)
{
	if (D<3)
	{
		for (uint32 i=0;i<D;++i)
		{
			(*this)[i]=other[i];
		}
		for (uint32 i=D;i<3;++i)
		{
			(*this)[i]=0.0f;
		}
		(*this)[2]=1.0f;
	}
	else
	{
		for (uint32 i=0;i<3;++i)
		{
			(*this)[i]=other[i];
		}
	}
}

typedef vec<3,real32> vec3f;

#define _CXXLIN_VEC3F_H_
#endif
