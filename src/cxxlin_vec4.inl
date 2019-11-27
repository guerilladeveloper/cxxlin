
template <typename T>
vec<4,T>::vec(const T& x,const T& y,const T& z,const T& w)
{
	this->x=x;
	this->y=y;
	this->z=z;
	this->w=w;
}

template <typename T>
vec<4,T>::vec(const T& val)
{
	x=val;
	y=val;
	z=val;
	w=val;
}

template <typename T>
vec<4,T>::vec()
	:vec(T(0)) 
{
}

template <typename T>
vec<4,T>::vec(const vec<4,T>& other)
{
	x=other.x;
	y=other.y;
	z=other.z;
	w=other.w;
}

template <typename T>
template <uint32 D>
vec<4,T>::vec(const vec<D,T>& other)
{
	if (D<4)
	{
		for (uint32 i=0;i<D;++i)
		{
			(*this)[i]=other[i];
		}
		for (uint32 i=D;i<4;++i)
		{
			(*this)[i]=T(0);
		}
		(*this)[3]=T(1);
	}
	else
	{
		for (uint32 i=0;i<4;++i)
		{
			(*this)[i]=other[i];
		}
	}
}
template <typename T>
vec<4,T> vec<4,T>::operator+(const vec<4,T>& rhs)
{
	return vec<4,T>(x+rhs.x,y+rhs.y,z+rhs.z,w+rhs.w);
}

template <typename T>
vec<4,T> vec<4,T>::operator-(const vec<4,T>& rhs)
{
	return vec<4,T>(x-rhs.x,y-rhs.y,z-rhs.z,w-rhs.w);
}


template <typename T>
vec<4,T> vec<4,T>::operator-()
{
	return vec<4,T>(-x,-y,-z,-w);
}

template <typename T>
vec<4,T> vec<4,T>::operator*(const T& scalar)
{
	return vec<4,T>(x*scalar,y*scalar,z*scalar,w*scalar);
}

template <typename T>
vec<4,T> vec<4,T>::operator/(const T& scalar)
{
	return vec<4,T>(x/scalar,y/scalar,z/scalar,w/scalar);

}

template <typename T>
bool32 vec<4,T>::operator==(const vec<4,T>& rhs)
{
	return (this==&vector)||(x==rhs.x&&y==rhs.y&&z==rhs.z&&
			w==rhs.w);
}

template <typename T>
bool32 vec<4,T>::operator!=(const vec<4,T>& rhs)
{
	return !(*this==rhs);
}


template <typename T>
vec<4,T>& vec<4,T>::operator=(const vec<4,T>& rhs)
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

template <typename T>
vec<4,T>& vec<4,T>::operator+=(const vec<4,T>& rhs)
{
	if (this!=&rhs)
	{
		x+=rhs.x;
		y+=rhs.y;
		z+=rhs.z;
		w+=rhs.w;
	}

	return *this;
}

template <typename T>
vec<4,T>& vec<4,T>::operator-=(const vec<4,T>& rhs)
{
	if (this!=&rhs)
	{
		x-=rhs.x;
		y-=rhs.y;
		z-=rhs.z;
		w-=rhs.w;
	}

	return *this;
}

template <typename T>
vec<4,T>& vec<4,T>::operator*=(const T& scalar)
{
	if (this!=&rhs)
	{
		x*=scalar;
		y*=scalar;
		z*=scalar;
		w*=scalar;
	}

	return *this;
}

template <typename T>
vec<4,T>& vec<4,T>::operator/=(const T& scalar)
{
	if (this!=&rhs)
	{
		x/=scalar;
		y/=scalar;
		z/=scalar;
		w/=scalar;
	}

	return *this;
}

template <typename T>
T& vec<4,T>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<4);
	return *(&x+index);
}
template <typename T>
const T& vec<4,T>::operator[](uint32 index) const
{
	ASSERT(index>=0&&index<4);
	return *(&x+index);
}


template <typename T>
T vec<4,T>::dot(const vec<4,T>& rhs)
{
	return x*rhs.x+y*rhs.y+z*rhs.z+w*rhs.w;
}

template <typename T>
real32 vec<4,T>::len_sq()
{
	return (real32)dot(*this);
}

template <typename T>
real32 vec<4,T>::len_sq32()
{
	return len_sq();
}

template <typename T>
real32 vec<4,T>::len()
{
	return (real32)sqrt((real64)len_sq32());
}

template <typename T>
real32 vec<4,T>::len32()
{
	return len();
}

template <typename T>
real64 vec<4,T>::len_sq64()
{
	return (real64)dot(*this);
}

template <typename T>
real64 vec<4,T>::len64()
{
	return (real64)sqrt(len_sq64());
}

template <typename T>
vec<4,T> operator*(const T& scalar, const vec<4,T>& vector)
{
	return vec<4,T>(scalar*vector.x,scalar*vector.y,
			scalar*vector.z,scalar*vector.w);
}

template <typename T>
T dot(const vec<4,T>& lhs, const vec<4,T>& rhs)
{
	return lhs.dot(rhs);
}
