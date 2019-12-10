

template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat(const T elements[C*R])
{
	for (uint32 i=0;i<C*R;++i)
	{
		e[i]=elements[i];
	}
}


template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat(const T& diagonal)
{
	for (uint32 r=0;r<R;++r)
	{
		for (uint32 c=0;c<C;++c)
		{
			e[r+R*c]=r==c?diagonal:T(0);
		}
	}
}

template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat()
	: mat(T(0)) { }

template <uint32 C,uint32 R,typename T>
mat<C,R,T>::mat(const mat<C,R,T>& other)
{
	for (uint32 i=0;i<C*R;++i)
	{
		e[i]=other.e[i];
	}
}
