
template <uint32 D>
vec<D,real32*>::vec(const real32* elements[D])
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=elements[i];
	}
}

template <uint32 D>
vec<D,real32*>::vec(real32* val)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=val;
	}
}

template <uint32 D>
vec<D,real32*>::vec()
	:vec<D,real32*>(0) 
{
}

template <uint32 D>
vec<D,real32*>::vec(const vec<D,real32*>& other)
{
	for (uint32 i=D;i<D;++i)
	{
		e[i]=other.e[i];
	}
}

template <uint32 D>
vec<D,real32*>::vec(const vec<D,real32>& other)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=&other.e[i];
	}
}

template <uint32 D>
template <uint32 D2>
vec<D,real32*>::vec(const vec<D2,real32>& other)
{
	ASSERT(D<=D2);
	for (uint32 i=0;i<D;++i)
	{
		this->operator[](i)=&other[i];
	}
}

template <uint32 D>
template <uint32 D2>
vec<D,real32*>::vec(const vec<D2,real32*>& other)
{
	ASSERT(D<=D2);
	for (uint32 i=0;i<D;++i)
	{
		this->operator[](i)=other[i];
	}
}
		
template <uint32 D>
vec<D,real32> vec<D,real32*>::operator+(const vec<D,real32>& rhs)
{
	vec<D,real32> result={};

	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=*e[i]+*rhs.e[i];
	}
	return result;
}

template <uint32 D>
vec<D,real32> vec<D,real32*>::operator-(const vec<D,real32*>& rhs)
{
	vec<D,real32> result={};

	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=*e[i]-*rhs.e[i];
	}
	return result;
}


template <uint32 D>
vec<D,real32> vec<D,real32*>::operator-()
{
	vec<D,real32> result={};
	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=-*e[i];
	}
	return result;
}

template <uint32 D>
vec<D,real32> vec<D,real32*>::operator*(real32 scalar)
{
	vec<D,real32> result={};
	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=*e[i]*scalar;
	}
	return result;
}

template <uint32 D>
vec<D,real32> vec<D,real32*>::operator/(real32 scalar)
{
	vec<D,real32> result={};
	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=*e[i]/scalar;
	}
	return result;
}

template <uint32 D>
bool32 vec<D,real32*>::operator==(const vec<D,real32*>& rhs)
{
	bool32 result=1;

	if (this!=&rhs)
	{
		for (uint32 i=0;i<D;++i)
		{
			if (*e[i]!=*rhs.e[i])
			{
				result=0;
				break;
			}
		}
	}
	return result;
}

template <uint32 D>
bool32 vec<D,real32*>::operator!=(const vec<D,real32*>& rhs)
{
	return !(*this==rhs);
}


template <uint32 D>
vec<D,real32*>& vec<D,real32*>::operator=(const vec<D,real32*>& rhs)
{
	for (uint32 i=0;i<D;++i)
	{
		e[i]=rhs.e[i];
	}
	return *this;
}

template <uint32 D>
vec<D,real32*>& vec<D,real32*>::operator+=(const vec<D,real32*>& rhs)
{
	for (uint32 i=0;i<D;++i)
	{
		*e[i]+=*rhs.e[i];
	}

	return *this;
}

template <uint32 D>
vec<D,real32*>& vec<D,real32*>::operator-=(const vec<D,real32*>& rhs)
{
	for (uint32 i=0;i<D;++i)
	{
		*e[i]-=*rhs.e[i];
	}

	return *this;
}

template <uint32 D>
vec<D,real32*>& vec<D,real32*>::operator*=(real32 scalar)
{
	for (uint32 i=0;i<D;++i)
	{
		*e[i]*=scalar;
	}

	return *this;
}

template <uint32 D>
vec<D,real32*>& vec<D,real32*>::operator/=(real32 scalar)
{
	for (uint32 i=0;i<D;++i)
	{
		*e[i]/=scalar;
	}

	return *this;
}

template <uint32 D>
real32* vec<D,real32*>::operator[](uint32 index)
{
	ASSERT(index>=0&&index<D);
	return e[index];
}


template <uint32 D>
const real32* vec<D,real32*>::operator[](uint32 index) const
{
	ASSERT(index>=0&&index<D);
	return e[index];
}

template <uint32 D>
real32 vec<D,real32*>::dot(const vec<D,real32*>& rhs) const
{
	real32 result=0.0f;
	for (uint32 i=0;i<D;++i)
	{
		result=result+*e[i]*(*rhs.e[i]);
	}
	return result;
}

template <uint32 D>
vec<D,real32*>& vec<D,real32*>::normalize()
{
	real32 l=len();
	for (uint32 i=0;i<D;++i)
	{
		*e[i]/=l;
	}
	return *this;
}

template <uint32 D>
real32 vec<D,real32*>::len_sq() const
{
	return (real32)dot(*this);
}

template <uint32 D>
real32 vec<D,real32*>::len_sq32() const
{
	return len_sq();
}

template <uint32 D>
real32 vec<D,real32*>::len() const
{
	return (real32)sqrt((real64)len_sq32());
}

template <uint32 D>
real32 vec<D,real32*>::len32() const
{
	return len();
}

template <uint32 D>
real64 vec<D,real32*>::len_sq64() const
{
	return (real64)dot(*this);
}

template <uint32 D>
real64 vec<D,real32*>::len64() const
{
	return (real64)sqrt(len_sq64());
}

template <uint32 D>
vec<D,real32> operator*(real32 scalar, const vec<D,real32*>& vector)
{
	vec<D,real32> result={};
	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=scalar*(*vector.e[i]);
	}
	return result;
}

template <uint32 D>
vec<D,real32*> dot(const vec<D,real32*>& lhs, const vec<D,real32*>& rhs)
{
	return lhs.dot(rhs);
}

template <uint32 D>
vec<D,real32> normal(const vec<D,real32*>& vector)
{
	real32 l=vector.len();
	vec<D,real32> result;
	for (uint32 i=0;i<D;++i)
	{
		result.e[i]=vector[i]/l;
	}
	return result;
}
