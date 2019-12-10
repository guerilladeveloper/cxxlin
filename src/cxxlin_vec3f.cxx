#include "cxxlin_vec3f.h"

vec<3,real32>::vec(const real32 elements[3])
{
	x=elements[0];
	y=elements[1];
	z=elements[2];
}


vec<3,real32>::vec(const real32& val)
{
	x=val;
	y=val;
	z=val;
}


vec<3,real32>::vec()
	: vec(real32(0)) { }


vec<3,real32>::vec(const vec<3,real32>& other)
{
	x=other.x;
	y=other.y;
	z=other.z;
}


vec<3,real32>::vec(const real32& x,const real32& y,const real32& z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}


template <uint32 D>
vec<3,real32>::vec(const vec<D,real32>& other)
{
	if (D>=3)
	{
		x=other[0];
		y=other[1];
		z=other[2];
	}
	else if (D==2)
	{
		x=other[0];
		y=other[1];
		z=real32(1);
	}
	else if (D==1)
	{
		x=other[0];
		y=real32(0);
		z=real32(1);
	}
}


vec<3,real32> vec<3,real32>::operator+(const vec<3,real32>& rhs) const
{
	return vec<3,real32>(x+rhs.x,y+rhs.y,z+rhs.z);
}


vec<3,real32> vec<3,real32>::operator-(const vec<3,real32>& rhs) const
{
	return vec<3,real32>(x-rhs.x,y-rhs.y,z-rhs.z);
}


vec<3,real32> vec<3,real32>::operator-() const
{
	return vec<3,real32>(-x,-y,-z);
}


vec<3,real32> vec<3,real32>::operator*(const real32& scalar) const
{
	return vec<3,real32>(x*scalar,y*scalar,z*scalar);
}


vec<3,real32> vec<3,real32>::operator/(const real32& scalar) const
{
	return vec<3,real32>(x/scalar,y/scalar,z/scalar);
}


bool32 vec<3,real32>::operator==(const vec<3,real32>& rhs) const
{
	return this==&rhs||
		(x==rhs.x&&y==rhs.y&&z==rhs.z);
}


bool32 vec<3,real32>::operator!=(const vec<3,real32>& rhs) const
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


vec<3,real32>& vec<3,real32>::operator-=(const vec<3,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=x-rhs.x;
		y=y-rhs.y;
		z=z-rhs.z;
	}
	return *this;
}


vec<3,real32>& vec<3,real32>::operator+=(const vec<3,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=x+rhs.x;
		y=y+rhs.y;
		z=z+rhs.z;
	}
	return *this;
}


vec<3,real32>& vec<3,real32>::operator*=(const real32& scalar)
{
	x=x*scalar;
	y=y*scalar;
	z=z*scalar;
	return *this;
}


vec<3,real32>& vec<3,real32>::operator/=(const real32& scalar)
{
	x=x/scalar;
	y=y/scalar;
	z=z/scalar;
	return *this;
}


real32& vec<3,real32>::operator[](uint32 index)
{
	ASSERT(index==0||index==1||index==2);
	if (index==0)
	{
		return x;
	}
	else if (index==1)
	{
		return y;
	}
	else
	{
		return z;
	}
}


const real32& vec<3,real32>::operator[](uint32 index) const
{
	ASSERT(index==0||index==1||index==2);
	if (index==0)
	{
		return x;
	}
	else if (index==1)
	{
		return y;
	}
	else
	{
		return z;
	}
}



real32 vec<3,real32>::dot(const vec<3,real32>& rhs) const
{
	return x*rhs.x+y*rhs.y+z*rhs.z;
}


vec<3,real32> vec<3,real32>::cross(const vec<3,real32>& rhs) const
{
	return vec<3,real32>(
			y*rhs.z-z*rhs.y,
			x*rhs.z-z*rhs.x,
			x*rhs.y-y*rhs.x);
}


vec<3,real32> operator*(const real32& scalar,const vec<3,real32>& vector)
{
	return vec<3,real32>(scalar*vector.x,scalar*vector.y,scalar*vector.z);
}


real32 dot(const vec<3,real32>& lhs,const vec<3,real32>& rhs)
{
	return lhs.dot(rhs);
}


vec<3,real32> cross(const vec<3,real32>& lhs,const vec<3,real32>& rhs)
{
	return lhs.cross(rhs);
}
