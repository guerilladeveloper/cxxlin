
template <typename T>
vec<3,T>::vec<3,T>(const T& x,const T& y,const T& z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

template <typename T>
vec<3,T>::vec<3,T>(const T& val)
{
	x=val;
	y=val;
	z=val;
}

template <typename T>
vec<3,T>::vec<3,T>()
	:vec<3,T>(T(0)) 
{
}

template <typename T>
vec<3,T>::vec<3,T>(const vec<3,T>& other)
{
	x=other.x;
	y=other.y;
	z=other.z;
}

template <typename T>
vec<3,T> vec<3,T>::operator+(const vec<3,T>& rhs)
{
	return vec<3,T>(x+rhs.x,y+rhs.y,z+rhs.z);
}

template <typename T>
vec<3,T> vec<3,T>::operator-(const vec<3,T>& rhs)
{
	return vec<3,T>(x-rhs.x,y-rhs.y,z-rhs.z);
}


template <typename T>
vec<3,T> vec<3,T>::operator-()
{
	return vec<3,T>(-x,-y,-z);
}

template <typename T>
vec<3,T> vec<3,T>::operator*(const T& scalar)
{
	return vec<3,T>(x*scalar,y*scalar,z*scalar);
}

template <typename T>
vec<3,T> vec<3,T>::operator/(const T& scalar)
{
	return vec<3,T>(x/scalar,y/scalar,z/scalar);

}

template <typename T>
bool32 vec<3,T>::operator==(const vec<3,T>& rhs)
{
	return (this==&vector)||(x==rhs.x&&y==rhs.y&&z==rhs.z);
}

template <typename T>
bool32 vec<3,T>::operator!=(const vec<3,T>& rhs)
{
	return !(*this==rhs);
}


template <typename T>
vec<3,T>& vec<3,T>::operator=(const vec<3,T>& rhs)
{
	if (this!=&rhs)
	{
		x=rhs.x;
		y=rhs.y;
		z=rhs.z;
	}

	return *this;
}

template <typename T>
vec<3,T>& vec<3,T>::operator+=(const vec<3,T>& rhs)
{
	if (this!=&rhs)
	{
		x+=rhs.x;
		y+=rhs.y;
		z+=rhs.z;
	}

	return *this;
}

template <typename T>
vec<3,T>& vec<3,T>::operator-=(const vec<3,T>& rhs)
{
	if (this!=&rhs)
	{
		x-=rhs.x;
		y-=rhs.y;
		z-=rhs.z;
	}

	return *this;
}

template <typename T>
vec<3,T>& vec<3,T>::operator*=(const T& scalar)
{
	if (this!=&rhs)
	{
		x*=scalar;
		y*=scalar;
		z*=scalar;
	}

	return *this;
}

template <typename T>
vec<3,T>& vec<3,T>::operator/=(const T& scalar)
{
	if (this!=&rhs)
	{
		x/=scalar;
		y/=scalar;
		z/=scalar;
	}

	return *this;
}

template <typename T>
T& vec<3,T>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<3);
	return *(&x+index);
}

template <typename T>
T vec<3,T>::dot(const vec<3,T>& rhs)
{
	return x*rhs.x+y*rhs.y+z*rhs.z;
}

template <typename T>
vec<3,T> vec<3,T>::cross(const vec<3,T>& rhs)
{
	return vec<3,T>(y*rhs.z-z*rhs.y,
			x*rhs.z-z*rhs.x,
			x*rhs.y-y*rhs.x);
}
template <typename T>
real32 vec<3,T>::len_sq()
{
	return (real32)dot(*this);
}

template <typename T>
real32 vec<3,T>::len_sq32()
{
	return len_sq();
}

template <typename T>
real32 vec<3,T>::len()
{
	return (real32)sqrt((real64)len_sq32());
}

template <typename T>
real32 vec<3,T>::len32()
{
	return len();
}

template <typename T>
real64 vec<3,T>::len_sq64()
{
	return (real64)dot(*this);
}

template <typename T>
real64 vec<3,T>::len64()
{
	return (real64)sqrt(len_sq64());
}

template <typename T>
vec<3,T> operator*(const T& scalar, const vec<3,T>& vector)
{
	return vec<3,T>(scalar*vector.x,scalar*vector.y,
			scalar*vector.z);
}

template <typename T>
vec<3,T> dot(const vec<3,T>& lhs, const vec<3,T>& rhs)
{
	return lhs.dot(rhs);
}

template <typename T>
vec<3,T> cross(const vec<3,T>& lhs, const vec<3,T>& rhs)
{
	return lhs.cross(rhs);
}
