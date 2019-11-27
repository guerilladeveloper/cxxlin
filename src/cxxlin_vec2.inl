
template <typename T>
vec<2,T>::vec(const T& x,const T& y)
{
	this->x=x;
	this->y=y;
}

template <typename T>
vec<2,T>::vec(const T& val)
{
	x=val;
	y=val;
}

template <typename T>
vec<2,T>::vec()
	:vec(T(0)) 
{
}

template <typename T>
vec<2,T>::vec(const vec<2,T>& other)
{
	x=other.x;
	y=other.y;
}

template <typename T>
template <uint32 D>
vec<2,T>::vec(const vec<D,T>& other)
{
	if (D<2)
	{
		for (uint32 i=0;i<D;++i)
		{
			*(&x+i)=other[i];
		}
		for (uint32 i=D;i<2;++i)
		{
			*(&x+i)=T(0);
		}
		*(&x+1)=T(1);
	}
	else
	{
		for (uint32 i=0;i<2;++i)
		{
			*(&x+i)=other[i];
		}
	}
}

template <typename T>
vec<2,T> vec<2,T>::operator+(const vec<2,T>& rhs)
{
	return vec<2,T>(x+rhs.x,y+rhs.y);
}

template <typename T>
vec<2,T> vec<2,T>::operator-(const vec<2,T>& rhs)
{
	return vec<2,T>(x-rhs.x,y-rhs.y);
}


template <typename T>
vec<2,T> vec<2,T>::operator-()
{
	return vec<2,T>(-x,-y);
}

template <typename T>
vec<2,T> vec<2,T>::operator*(const T& scalar)
{
	return vec<2,T>(x*scalar,y*scalar);
}

template <typename T>
vec<2,T> vec<2,T>::operator/(const T& scalar)
{
	return vec<2,T>(x/scalar,y/scalar);

}

template <typename T>
bool32 vec<2,T>::operator==(const vec<2,T>& rhs)
{
	return (this==&rhs)||(x==rhs.x&&y==rhs.y);
}

template <typename T>
bool32 vec<2,T>::operator!=(const vec<2,T>& rhs)
{
	return !(*this==rhs);
}


template <typename T>
vec<2,T>& vec<2,T>::operator=(const vec<2,T>& rhs)
{
	x=rhs.x;
	y=rhs.y;
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator+=(const vec<2,T>& rhs)
{
	x+=rhs.x;
	y+=rhs.y;
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator-=(const vec<2,T>& rhs)
{
	x-=rhs.x;
	y-=rhs.y;
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator*=(const T& scalar)
{
	x*=scalar;
	y*=scalar;

	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator/=(const T& scalar)
{
	x/=scalar;
	y/=scalar;

	return *this;
}

template <typename T>
T& vec<2,T>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<2);
	return *(&x+index);
}

template <typename T>
const T& vec<2,T>::operator[](uint32 index) const
{
	ASSERT(index>=0&&index<2);
	return *(&x+index);
}


template <typename T>
T vec<2,T>::dot(const vec<2,T>& rhs)
{
	return x*rhs.x+y*rhs.y;
}

template <typename T>
real32 vec<2,T>::len_sq()
{
	return (real32)dot(*this);
}

template <typename T>
real32 vec<2,T>::len_sq32()
{
	return len_sq();
}

template <typename T>
real32 vec<2,T>::len()
{
	return (real32)sqrt((real64)len_sq32());
}

template <typename T>
real32 vec<2,T>::len32()
{
	return len();
}

template <typename T>
real64 vec<2,T>::len_sq64()
{
	return (real64)dot(*this);
}

template <typename T>
real64 vec<2,T>::len64()
{
	return (real64)sqrt(len_sq64());
}

template <typename T>
vec<2,T> operator*(const T& scalar, const vec<2,T>& vector)
{
	return vec<2,T>(scalar*vector.x,scalar*vector.y);
}

template <typename T>
vec<2,T> dot(const vec<2,T>& lhs, const vec<2,T>& rhs)
{
	return lhs.dot(rhs);
}
