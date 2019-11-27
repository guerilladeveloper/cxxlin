#include "cxxlin_vec4f.h"

vec<4,real32>::vec(real32 x,real32 y,real32 z,real32 w)
{
	this->x=x;
	this->y=y;
	this->z=z;
	this->w=w;
}


vec<4,real32>::vec(real32 val)
{
	x=val;
	y=val;
	z=val;
	w=val;
}

vec<4,real32>::vec()
	:vec(0.0f) 
{
}


vec<4,real32>::vec(const vec<4,real32>& other)
{
	x=other.x;
	y=other.y;
	z=other.z;
	w=other.w;
}

vec<4,real32> vec<4,real32>::operator+(const vec<4,real32>& rhs)
{
	return vec<4,real32>(x+rhs.x,y+rhs.y,z+rhs.z,w+rhs.w);
}


vec<4,real32> vec<4,real32>::operator-(const vec<4,real32>& rhs)
{
	return vec<4,real32>(x-rhs.x,y-rhs.y,z-rhs.z,w-rhs.w);
}



vec<4,real32> vec<4,real32>::operator-()
{
	return vec<4,real32>(-x,-y,-z,-w);
}


vec<4,real32> vec<4,real32>::operator*(real32 scalar)
{
	return vec<4,real32>(x*scalar,y*scalar,z*scalar,w*scalar);
}


vec<4,real32> vec<4,real32>::operator/(real32 scalar)
{
	return vec<4,real32>(x/scalar,y/scalar,z/scalar,w/scalar);

}


bool32 vec<4,real32>::operator==(const vec<4,real32>& rhs)
{
	return (this==&rhs)||(x==rhs.x&&y==rhs.y&&z==rhs.z&&
			w==rhs.w);
}


bool32 vec<4,real32>::operator!=(const vec<4,real32>& rhs)
{
	return !(*this==rhs);
}



vec<4,real32>& vec<4,real32>::operator=(const vec<4,real32>& rhs)
{
	if (this!=&rhs)
	{
		x=rhs.x;
		y=rhs.y;
		z=rhs.z;
		w=rhs.w;
	}

	return *this;
}


vec<4,real32>& vec<4,real32>::operator+=(const vec<4,real32>& rhs)
{
	x+=rhs.x;
	y+=rhs.y;
	z+=rhs.z;
	w+=rhs.w;

	return *this;
}


vec<4,real32>& vec<4,real32>::operator-=(const vec<4,real32>& rhs)
{
	x-=rhs.x;
	y-=rhs.y;
	z-=rhs.z;
	w-=rhs.w;
	return *this;
}


vec<4,real32>& vec<4,real32>::operator*=(real32 scalar)
{
	x*=scalar;
	y*=scalar;
	z*=scalar;
	w*=scalar;

	return *this;
}


vec<4,real32>& vec<4,real32>::operator/=(real32 scalar)
{
	x/=scalar;
	y/=scalar;
	z/=scalar;

	return *this;
}


real32& vec<4,real32>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<4);
	return *(&x+index);
}


const real32& vec<4,real32>::operator[](uint32 index) const
{
	ASSERT(index>=0&&index<4);
	return *(&x+index);
}

real32 vec<4,real32>::dot(const vec<4,real32>& rhs) const
{
	return x*rhs.x+y*rhs.y+z*rhs.z+w*rhs.w;
}

real32 vec<4,real32>::len_sq() const
{
	return (real32)dot(*this);
}


real32 vec<4,real32>::len_sq32() const
{
	return len_sq();
}


real32 vec<4,real32>::len() const
{
	return (real32)sqrt((real64)len_sq32());
}


real32 vec<4,real32>::len32() const
{
	return len();
}


real64 vec<4,real32>::len_sq64() const
{
	return (real64)dot(*this);
}


real64 vec<4,real32>::len64() const
{
	return (real64)sqrt(len_sq64());
}


vec<4,real32> operator*(real32 scalar, const vec<4,real32>& vector)
{
	return vec<4,real32>(scalar*vector.x,scalar*vector.y,
			scalar*vector.z,scalar*vector.w);
}


real32 dot(const vec<4,real32>& lhs, const vec<4,real32>& rhs)
{
	return lhs.dot(rhs);
}
