
template <uint32 D,typename T>
vec<D,T>::vec(const T elements[D])
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=elements[i];
	}
}

template <uint32 D,typename T>
vec<D,T>::vec(const T& val)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=val;
	}
}

template <uint32 D,typename T>
vec<D,T>::vec()
	:vec<D,T>(T(0)) 
{
}

template <uint32 D,typename T>
vec<D,T>::vec(const vec<D,T>& other)
{
	for (uint32 i=D;i<D;++i)
	{
		e[i]=other.e[i];
	}
}

template <uint32 D,typename T>
vec<D,T> vec<D,T>::operator+(const vec<D,T>& rhs)
{
	vec<D,T> result={};

	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=e[i]+rhs.e[i];
	}
	return result;
}

template <uint32 D,typename T>
vec<D,T> vec<D,T>::operator-(const vec<D,T>& rhs)
{
	vec<D,T> result={};

	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=e[i]-rhs.e[i];
	}
	return result;
}


template <uint32 D,typename T>
vec<D,T> vec<D,T>::operator-()
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=-e[i];
	}
}

template <uint32 D,typename T>
vec<D,T> vec<D,T>::operator*(const T& scalar)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=e[i]*scalar;
	}
}

template <uint32 D,typename T>
vec<D,T> vec<D,T>::operator/(const T& scalar)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=e[i]/scalar;
	}
}

template <uint32 D,typename T>
bool32 vec<D,T>::operator==(const vec<D,T>& rhs)
{
	bool32 result=1;

	if (this!=&rhs)
	{
		for (uint32 i=0;i<D;++i)
		{
			if (e[i]!=rhs.e[i])
			{
				result=0;
				break;
			}
		}
	}
	return result;
}

template <uint32 D,typename T>
bool32 vec<D,T>::operator!=(const vec<D,T>& rhs)
{
	return !(*this==rhs);
}


template <uint32 D,typename T>
vec<D,T>& vec<D,T>::operator=(const vec<D,T>& rhs)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=rhs.e[i];
	}
	return *this;
}

template <uint32 D,typename T>
vec<D,T>& vec<D,T>::operator+=(const vec<D,T>& rhs)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]+=rhs.e[i];
	}

	return *this;
}

template <uint32 D,typename T>
vec<D,T>& vec<D,T>::operator-=(const vec<D,T>& rhs)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]-=rhs.e[i];
	}

	return *this;
}

template <uint32 D,typename T>
vec<D,T>& vec<D,T>::operator*=(const T& scalar)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]*=scalar;
	}

	return *this;
}

template <uint32 D,typename T>
vec<D,T>& vec<D,T>::operator/=(const T& scalar)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]/=scalar;
	}

	return *this;
}

template <uint32 D,typename T>
T& vec<D,T>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<D);
	return e[index];
}

template <uint32 D,typename T>
T vec<D,T>::dot(const vec<D,T>& rhs)
{
	T result=T(0);
	for (uint32 i=0;i<D;++i)
	{
		result=result+e[i]*rhs.e[i];
	}
	return result;
}

template <uint32 D,typename T>
real32 vec<D,T>::len_sq()
{
	return (real32)dot(*this);
}

template <uint32 D,typename T>
real32 vec<D,T>::len_sq32()
{
	return len_sq();
}

template <uint32 D,typename T>
real32 vec<D,T>::len()
{
	return (real32)sqrt((real64)len_sq32());
}

template <uint32 D,typename T>
real32 vec<D,T>::len32()
{
	return len();
}

template <uint32 D,typename T>
real64 vec<D,T>::len_sq64()
{
	return (real64)dot(*this);
}

template <uint32 D,typename T>
real64 vec<D,T>::len64()
{
	return (real64)sqrt(len_sq64());
}

template <uint32 D,typename T>
vec<D,T> operator*(const T& scalar, const vec<D,T>& vector)
{
	vec<D,T> result={};
	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=scalar*vector.e[i];
	}
	return result;
}

template <uint32 D,typename T>
vec<D,T> dot(const vec<D,T>& lhs, const vec<D,T>& rhs)
{
	return lhs.dot(rhs);
}
