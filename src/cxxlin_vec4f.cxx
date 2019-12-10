#include "cxxlin_vec4f.h"


vec<4,real32>::vec(const real32 elements[4])
{
	x=elements[0];
	y=elements[1];
	z=elements[2];
	w=elements[4];
}


vec<4,real32>::vec(const real32& val)
{
	x=val;
	y=val;
	z=val;
	w=val;
}


vec<4,real32>::vec()
	: vec(real32(0)) { }


vec<4,real32>::vec(const vec<4,real32>& other)
{
	x=other.x;
	y=other.y;
	z=other.z;
	w=other.w;
}


vec<4,real32>::vec(const real32& x,const real32& y,const real32& z,const real32& w)
{
	this->x=x;
	this->y=y;
	this->z=z;
	this->w=w;
}


template <uint32 D>
vec<4,real32>::vec(const vec<D,real32>& other)
{
	if (D>=4)
	{
		x=other[0];
		y=other[1];
		z=other[2];
		w=other[3];
	}
	else if (D==3)
	{
		x=other[0];
		y=other[1];
		z=other[2];
		w=real32(1);
	}
	else if (D==2)
	{
		x=other[0];
		y=other[1];
		z=real32(0);
		w=real32(1);
	}
	else if (D==1)
	{
		x=other[0];
		y=real32(0);
		z=real32(0);
		w=real32(1);
	}
}


vec<4,real32> vec<4,real32>::operator+(const vec<4,real32>& rhs) const
{
	return vec<4,real32>(x+rhs.x,y+rhs.y,z+rhs.z,w+rhs.w);
}


vec<4,real32> vec<4,real32>::operator-(const vec<4,real32>& rhs) const
{
	return vec<4,real32>(x-rhs.x,y-rhs.y,z-rhs.z,w-rhs.w);
}


vec<4,real32> vec<4,real32>::operator-() const
{
	return vec<4,real32>(-x,-y,-z,-w);
}


vec<4,real32> vec<4,real32>::operator*(const real32& scalar) const
{
	return vec<4,real32>(x*scalar,y*scalar,z*scalar,w*scalar);
}


vec<4,real32> vec<4,real32>::operator/(const real32& scalar) const
{
	return vec<4,real32>(x/scalar,y/scalar,z/scalar,w/scalar);
}


bool32 vec<4,real32>::operator==(const vec<4,real32>& rhs) const
{
	return this==&rhs||
		(x==rhs.x&&y==rhs.y&&z==rhs.z&&w==rhs.w);
}


bool32 vec<4,real32>::operator!=(const vec<4,real32>& rhs) const
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


vec<4,real32>& vec<4,real32>::operator-=(const vec<4,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=x-rhs.x;
		y=y-rhs.y;
		z=z-rhs.z;
		w=w-rhs.w;
	}
	return *this;
}


vec<4,real32>& vec<4,real32>::operator+=(const vec<4,real32>& rhs)
{

	if (this!=&rhs)
	{
		x=x+rhs.x;
		y=y+rhs.y;
		z=z+rhs.z;
		w=w+rhs.w;
	}
	return *this;
}


vec<4,real32>& vec<4,real32>::operator*=(const real32& scalar)
{
	x=x*scalar;
	y=y*scalar;
	z=z*scalar;
	w=w*scalar;
	return *this;
}


vec<4,real32>& vec<4,real32>::operator/=(const real32& scalar)
{
	x=x/scalar;
	y=y/scalar;
	z=z/scalar;
	w=w/scalar;
	return *this;
}


real32& vec<4,real32>::operator[](uint32 index)
{
	ASSERT(index==0||index==1||index==2||index==3);
	if (index==0)
	{
		return x;
	}
	else if (index==1)
	{
		return y;
	}
	else if (index==2)
	{
		return z;
	}
	else
	{
		return w;
	}
}


const real32& vec<4,real32>::operator[](uint32 index) const
{
	ASSERT(index==0||index==1||index==2||index==3);
	if (index==0)
	{
		return x;
	}
	else if (index==1)
	{
		return y;
	}
	else if (index==2)
	{
		return z;
	}
	else
	{
		return w;
	}
}



real32 vec<4,real32>::dot(const vec<4,real32>& rhs) const
{
	return x*rhs.x+y*rhs.y+z*rhs.z+w*rhs.w;
}


vec<4,real32> operator*(const real32& scalar,const vec<4,real32>& vector)
{
	return vec<4,real32>(scalar*vector.x,scalar*vector.y,
			scalar*vector.z,scalar*vector.w);
}


real32 dot(const vec<4,real32>& lhs,const vec<4,real32>& rhs)
{
	return lhs.dot(rhs);
}
