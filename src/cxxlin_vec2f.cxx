#include "cxxlin_vec2f.h"

vec<2,real32>::vec(real32 x,real32 y)
{
	this->x=x;
	this->y=y;
}


vec<2,real32>::vec(real32 val)
{
	x=val;
	y=val;
}


vec<2,real32>::vec()
	:vec(real32(0)) 
{
}


vec<2,real32>::vec(const vec<2,real32>& other)
{
	x=other.x;
	y=other.y;
}

vec<2,real32> vec<2,real32>::operator+(const vec<2,real32>& rhs)
{
	return vec<2,real32>(x+rhs.x,y+rhs.y);
}


vec<2,real32> vec<2,real32>::operator-(const vec<2,real32>& rhs)
{
	return vec<2,real32>(x-rhs.x,y-rhs.y);
}



vec<2,real32> vec<2,real32>::operator-()
{
	return vec<2,real32>(-x,-y);
}


vec<2,real32> vec<2,real32>::operator*(real32 scalar)
{
	return vec<2,real32>(x*scalar,y*scalar);
}


vec<2,real32> vec<2,real32>::operator/(real32 scalar)
{
	return vec<2,real32>(x/scalar,y/scalar);

}


bool32 vec<2,real32>::operator==(const vec<2,real32>& rhs)
{
	return (this==&rhs)||(x==rhs.x&&y==rhs.y);
}


bool32 vec<2,real32>::operator!=(const vec<2,real32>& rhs)
{
	return !(*this==rhs);
}



vec<2,real32>& vec<2,real32>::operator=(const vec<2,real32>& rhs)
{
	x=rhs.x;
	y=rhs.y;
	return *this;
}


vec<2,real32>& vec<2,real32>::operator+=(const vec<2,real32>& rhs)
{
	x+=rhs.x;
	y+=rhs.y;
	return *this;
}


vec<2,real32>& vec<2,real32>::operator-=(const vec<2,real32>& rhs)
{
	x-=rhs.x;
	y-=rhs.y;
	return *this;
}


vec<2,real32>& vec<2,real32>::operator*=(real32 scalar)
{
	x*=scalar;
	y*=scalar;

	return *this;
}


vec<2,real32>& vec<2,real32>::operator/=(real32 scalar)
{
	x/=scalar;
	y/=scalar;

	return *this;
}


real32& vec<2,real32>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<2);
	return *(&x+index);
}


const real32& vec<2,real32>::operator[](uint32 index) const
{
	ASSERT(index>=0&&index<2);
	return *(&x+index);
}



real32 vec<2,real32>::dot(const vec<2,real32>& rhs) const
{
	return x*rhs.x+y*rhs.y;
}

vec<2,real32>& vec<2,real32>::normalize()
{
	real32 l=len();
	x/=l;
	y/=l;
	return *this;
}

real32 vec<2,real32>::len_sq() const
{
	return (real32)dot(*this);
}


real32 vec<2,real32>::len_sq32() const
{
	return len_sq();
}


real32 vec<2,real32>::len() const
{
	return (real32)sqrt((real64)len_sq32());
}


real32 vec<2,real32>::len32() const
{
	return len();
}


real64 vec<2,real32>::len_sq64() const
{
	return (real64)dot(*this);
}


real64 vec<2,real32>::len64() const
{
	return (real64)sqrt(len_sq64());
}


vec<2,real32> operator*(real32 scalar, const vec<2,real32>& vector)
{
	return vec<2,real32>(scalar*vector.x,scalar*vector.y);
}


real32 dot(const vec<2,real32>& lhs, const vec<2,real32>& rhs)
{
	return lhs.dot(rhs);
}

vec<2,real32> normal(const vec<2,real32>& vector)
{
	vec<2,real32> result;
	real32 l=vector.len();
	result.x=vector.x/l;
	result.y=vector.y/l;
	return result;
}

