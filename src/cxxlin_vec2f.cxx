#include "cxxlin_vec2f.h"

vec<2,real32>::vec(const real32 elements[2])
{
	x=elements[0];
	y=elements[1];
}

vec<2,real32>::vec(const real32& val)
{
	x=val;
	y=val;
}

vec<2,real32>::vec()
	: vec(0.0f) { }

vec<2,real32>::vec(const vec<2,real32>& other)
{
	x=other.x;
	y=other.y;
}

vec<2,real32>::vec(const real32& x,const real32& y)
{
	this->x=x;
	this->y=y;
}

template <uint32 D>
vec<2,real32>::vec(const vec<D,real32>& other)
{
	if (D>=2)
	{
		x=other[0];
		y=other[1];
	}
	else
	{
		x=other[0];
		y=1.0f;
	}
}

vec<2,real32> vec<2,real32>::operator+(const vec<2,real32>& rhs) const
{
	return vec<2,real32>(x+rhs.x,y+rhs.y);
}

vec<2,real32> vec<2,real32>::operator-(const vec<2,real32>& rhs) const
{
	return vec<2,real32>(x-rhs.x,y-rhs.y);
}

vec<2,real32> vec<2,real32>::operator-() const
{
	return vec<2,real32>(-x,-y);
}

vec<2,real32> vec<2,real32>::operator*(const real32& scalar) const
{
	return vec<2,real32>(x*scalar,y*scalar);
}

vec<2,real32> vec<2,real32>::operator/(const real32& scalar) const
{
	return vec<2,real32>(x/scalar,y/scalar);
}

bool32 vec<2,real32>::operator==(const vec<2,real32>& rhs) const
{
	return this==&rhs||
		(x==rhs.x&&y==rhs.y);
}

bool32 vec<2,real32>::operator!=(const vec<2,real32>& rhs) const
{
	return !(*this==rhs);
}

vec<2,real32>& vec<2,real32>::operator=(const vec<2,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=rhs.x;
		y=rhs.y;
	}
	return *this;
}

vec<2,real32>& vec<2,real32>::operator-=(const vec<2,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=x-rhs.x;
		y=y-rhs.y;
	}
	return *this;
}

vec<2,real32>& vec<2,real32>::operator+=(const vec<2,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=x+rhs.x;
		y=y+rhs.y;
	}
	return *this;
}

vec<2,real32>& vec<2,real32>::operator*=(const real32& scalar)
{
	x=x*scalar;
	y=y*scalar;
	return *this;
}

vec<2,real32>& vec<2,real32>::operator/=(const real32& scalar)
{
	x=x/scalar;
	y=y/scalar;
	return *this;
}

real32& vec<2,real32>::operator[](uint32 index)
{
	ASSERT(index==0||index==1);
	if (index==0)
	{
		return x;
	}
	else
	{
		return y;
	}
}

const real32& vec<2,real32>::operator[](uint32 index) const
{
	ASSERT(index==0||index==1);
	if (index==0)
	{
		return x;
	}
	else
	{
		return y;
	}
}


real32 vec<2,real32>::dot(const vec<2,real32>& rhs) const
{
	return x*rhs.x+y*rhs.y;
}

real32 vec<2,real32>::len_sq() const
{
	return dot(*this);
}

real32 vec<2,real32>::len() const
{
	return (real32)sqrt((double)len_sq());
}

vec<2,real32> operator*(const real32& scalar,const vec<2,real32>& vector)
{
	return vec<2,real32>(scalar*vector.x,scalar*vector.y);
}

real32 dot(const vec<2,real32>& lhs,const vec<2,real32>& rhs)
{
	return lhs.dot(rhs);
}

real32 len_sq(const vec<2,real32>& vector)
{
	return dot(vector,vector);
}

real32 len(const vec<2,real32>& vector)
{
	return (real32)sqrt((double)len_sq(vector));
}
