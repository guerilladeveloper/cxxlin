
template <uint32 N,typename T>
mat<N,N,T>::mat(const T elements[N*N])
{
	for (uint32 i=0;i<N*N;++i)
	{
		e[i]=elements[i];
	}
}

template <uint32 N,typename T>
mat<N,N,T>::mat(const T& val)
{
	for (uint32 c=0;c<N;++c)
	{
		for (uint32 r=0;r<N;++r)
		{
			e[r+c*N]=c==r?val:T(0);
		}
	}
}

template <uint32 N,typename T>
mat<N,N,T>::mat(const mat<N,N,T>& other)
{
	for (uint32 i=0;i<N*N;++i)
	{
		e[i]=other.e[i];
	}
}

template <uint32 N,typename T>
mat<N,N,T>::mat()
	:mat(T(1)) { }

template <uint32 N,typename T>
mat<N,N,T> mat<N,N,T>::operator+(const mat<N,N,T>& rhs) const
{
	mat<N,N,T> result;
	for (uint32 i=0;i<N*N;++i)
	{
		result.e[i]=e[i]+rhs.e[i];
	}
	return result;
}

template <uint32 N,typename T>
mat<N,N,T> mat<N,N,T>::operator-(const mat<N,N,T>& rhs) const
{
	mat<N,N,T> result;
	for (uint32 i=0;i<N*N;++i)
	{
		result.e[i]=e[i]-rhs.e[i];
	}
	return result;
}

template <uint32 N,typename T>
mat<N,N,T> mat<N,N,T>::operator*(const T& scalar) const
{
	mat<N,N,T> result;
	for (uint32 i=0;i<N*N;++i)
	{
		result.e[i]=e[i]*scalar;
	}
	return result;
}

template <uint32 N,typename T>
mat<N,N,T> mat<N,N,T>::operator*(const mat<N,N,T>& rhs) const
{
	mat<N,N,T> result;
	for (uint32 c=0;c<N;++c)
	{
		for (uint32 r=0;r<N;++r)
		{
			vec<N,T> rowVec=get_row(r);
			vec<N,T> columnVec=rhs.get_column(c);
			T val=rowVec.dot(columnVec);
			result.get(c,r)=val;
		}
	}
	return result;
}

template <uint32 N,typename T>
mat<N,N,T>& mat<N,N,T>::operator=(const mat<N,N,T>& rhs)
{
	if (this!=&rhs)
	{
		for (uint32 i=0;i<N*N;++i)
		{
			e[i]=rhs.e[i];
		}
	}
	return *this;
}

template <uint32 N,typename T>
mat<N,N,T>& mat<N,N,T>::operator+=(const mat<N,N,T>& rhs)
{
	if (this!=&rhs)
	{
		for (uint32 i=0;i<N*N;++i)
		{
			e[i]+=rhs.e[i];
		}
	}
	return *this;
}

template <uint32 N,typename T>
mat<N,N,T>& mat<N,N,T>::operator-=(const mat<N,N,T>& rhs)
{
	if (this!=&rhs)
	{
		for (uint32 i=0;i<N*N;++i)
		{
			e[i]-=rhs.e[i];
		}
	}
	return *this;
}

template <uint32 N,typename T>
mat<N,N,T>& mat<N,N,T>::operator*=(const mat<N,N,T>& rhs)
{
	mat<N,N,T>& lhs=*this;
	for (uint32 c=0;c<N;++c)
	{
		for (uint32 r=0;r<N;++r)
		{
			vec<N,T> rowVec=get_row(r);
			vec<N,T> columnVec=rhs.get_column(c);
			T val=columnVec.dot(rowVec);
			get(c,r)=val;
		}
	}
	return lhs;
}

template <uint32 N,typename T>
vec<N,T> mat<N,N,T>::transform(const vec<N,T>& vector) const
{
	vec<N,T> result;
	for (uint32 c=0;c<N;++c)
	{
		vec<N,T> columnVec=get_column(c);
		result+=vector[c]*columnVec;
	}
	return result;
}

template <uint32 N,typename T>
mat<N-1,N-1,T> mat<N,N,T>::minor(uint32 columnToRemove,uint32 rowToRemove)
{
	mat<N-1,N-1,T> result;
	return result;
}

template <uint32 N,typename T>
mat<N,N,T> mat<N,N,T>::transpose() const
{
	mat<N,N,T> result;
	for (uint32 c=0;c<N;++c)
	{
		vec<N,T> columnVec=get_column(c);
		result.set_column(columnVec);
	}
	return result;
}

template <uint32 N,typename T>
T& mat<N,N,T>::get(uint32 column,uint32 row)
{
	return e[row+column*N];
}

template <uint32 N,typename T>
const T& mat<N,N,T>::get(uint32 column,uint32 row) const
{
	return e[row+column*N];
}

template <uint32 N,typename T>
vec<N,T> mat<N,N,T>::get_column(uint32 column) const
{
	vec<N,T> result;
	for (uint32 r=0;r<N;++r)
	{
		result[r]=get(column,r);
	}
	return result;
}

template <uint32 N,typename T>
vec<N,T> mat<N,N,T>::get_row(uint32 row) const
{
	vec<N,T> result;
	for (uint32 c=0;c<N;++c)
	{
		result[c]=get(c,row);
	}
	return result;
}

template <uint32 N,typename T>
mat<N,N,T>& mat<N,N,T>::set_column(uint32 column,const vec<N,T>& val)
{
	for (uint32 r=0;r<N;++r)
	{
		get(column,r)=val[r];
	}
	return *this;
}

template <uint32 N,typename T>
mat<N,N,T>& mat<N,N,T>::set_row(uint32 row,const vec<N,T>& val)
{
	for (uint32 c=0;c<N;++c)
	{
		get(c,row)=val[c];
	}
	return *this;
}

template <uint32 N,typename T>
vec<N,T> operator*(const vec<N,T>& vector,const mat<N,N,T>& matrix)
{
	return matrix.transform(vector);
}

