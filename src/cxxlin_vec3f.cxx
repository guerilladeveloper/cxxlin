#include "cxxlin_vec3f.h"

vec<3,real32>::vec(real32 x,real32 y,real32 z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}


vec<3,real32>::vec(real32 val)
{
	x=val;
	y=val;
	z=val;
}

vec<3,real32>::vec()
	:vec(0.0f) 
{
}


vec<3,real32>::vec(const vec<3,real32>& other)
{
	x=other.x;
	y=other.y;
	z=other.z;
}

vec<3,real32> vec<3,real32>::operator+(const vec<3,real32>& rhs)
{
	return vec<3,real32>(x+rhs.x,y+rhs.y,z+rhs.z);
}


vec<3,real32> vec<3,real32>::operator-(const vec<3,real32>& rhs)
{
	return vec<3,real32>(x-rhs.x,y-rhs.y,z-rhs.z);
}



vec<3,real32> vec<3,real32>::operator-()
{
	return vec<3,real32>(-x,-y,-z);
}


vec<3,real32> vec<3,real32>::operator*(real32 scalar)
{
	return vec<3,real32>(x*scalar,y*scalar,z*scalar);
}


vec<3,real32> vec<3,real32>::operator/(real32 scalar)
{
	return vec<3,real32>(x/scalar,y/scalar,z/scalar);

}


bool32 vec<3,real32>::operator==(const vec<3,real32>& rhs)
{
	return (this==&rhs)||(x==rhs.x&&y==rhs.y&&z==rhs.z);
}


bool32 vec<3,real32>::operator!=(const vec<3,real32>& rhs)
{
	return !(*this==rhs);
}



vec<3,real32>& vec<3,real32>::operator=(const vec<3,real32>& rhs)
{
	if (this!=&rhs)
	{
		x=rhs.x;
		y=rhs.y;
		z=rhs.z;
	}

	return *this;
}


vec<3,real32>& vec<3,real32>::operator+=(const vec<3,real32>& rhs)
{
	if (this!=&rhs)
	{
		x+=rhs.x;
		y+=rhs.y;
		z+=rhs.z;
	}

	return *this;
}


vec<3,real32>& vec<3,real32>::operator-=(const vec<3,real32>& rhs)
{
	x-=rhs.x;
	y-=rhs.y;
	z-=rhs.z;
	return *this;
}


vec<3,real32>& vec<3,real32>::operator*=(real32 scalar)
{
	x*=scalar;
	y*=scalar;
	z*=scalar;

	return *this;
}


vec<3,real32>& vec<3,real32>::operator/=(real32 scalar)
{
	x/=scalar;
	y/=scalar;
	z/=scalar;

	return *this;
}


real32& vec<3,real32>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<3);
	return *(&x+index);
}


const real32& vec<3,real32>::operator[](uint32 index) const
{
	ASSERT(index>=0&&index<3);
	return *(&x+index);
}



real32 vec<3,real32>::dot(const vec<3,real32>& rhs) const
{
	return x*rhs.x+y*rhs.y+z*rhs.z;
}


vec<3,real32> vec<3,real32>::cross(const vec<3,real32>& rhs) const
{
	return vec<3,real32>(y*rhs.z-z*rhs.y,
			x*rhs.z-z*rhs.x,
			x*rhs.y-y*rhs.x);
}

real32 vec<3,real32>::len_sq() const
{
	return (real32)dot(*this);
}


real32 vec<3,real32>::len_sq32() const
{
	return len_sq();
}


real32 vec<3,real32>::len() const
{
	return (real32)sqrt((real64)len_sq32());
}


real32 vec<3,real32>::len32() const
{
	return len();
}


real64 vec<3,real32>::len_sq64() const
{
	return (real64)dot(*this);
}


real64 vec<3,real32>::len64() const
{
	return (real64)sqrt(len_sq64());
}


vec<3,real32> operator*(real32 scalar, const vec<3,real32>& vector)
{
	return vec<3,real32>(scalar*vector.x,scalar*vector.y,
			scalar*vector.z);
}


real32 dot(const vec<3,real32>& lhs, const vec<3,real32>& rhs)
{
	return lhs.dot(rhs);
}


vec<3,real32> cross(const vec<3,real32>& lhs, const vec<3,real32>& rhs)
{
	return lhs.cross(rhs);
}
