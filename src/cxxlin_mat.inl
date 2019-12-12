

template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat(const T elements[C*R])
{
	for (uint32 i=0;i<C*R;++i)
	{
		e[i]=elements[i];
	}
}


template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat(const mat<C,R,T>& other)
{
	for (uint32 i=0;i<C*R;++i)
	{
		e[i]=other.e[i];
	}
}

template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat()
	: mat(T(0)) { }

template <uint32 C,uint32 R,typename T>
mat<C,R,T> mat<C,R,T>::operator+(const mat<C,R,T>& rhs) const
{
	mat<C,R,T> result;
	for (uint32 i=0;i<C*R;++y)
	{
		result.e[i]=e[i]+rhs.e[i];
	}
	return result;
}

template <uint32 C,uint32 R,typename T>
mat<C,R,T> mat<C,R,T>::operator-(const mat<C,R,T>& rhs) const
{
	mat<C,R,T> result;
	for (uint32 i=0;i<C*R;++y)
	{
		result.e[i]=e[i]-rhs.e[i];
	}
	return result;
}

template <uint32 C,uint32 R,typename T>
mat<C,R,T> mat<C,R,T>::operator*(const T& scalar) const
{
	mat<C,R,T> result;
	for (uint32 i=0;i<C*R;++y)
	{
		result.e[i]=e[i]*scalar;
	}
	return result;
}
