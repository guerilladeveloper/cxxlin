
template <typename T>
vec<2,T>::vec(const T elements[2])
{
	x=elements[0];
	y=elements[1];
}

template <typename T>
vec<2,T>::vec(const T& val)
{
	x=val;
	y=val;
}

template <typename T>
vec<2,T>::vec()
	: vec(T(0)) { }

template <typename T>
vec<2,T>::vec(const vec<2,T>& other)
{
	x=other.x;
	y=other.y;
}

template <typename T>
vec<2,T>::vec(const T& x,const T& y)
{
	this->x=x;
	this->y=y;
}

template <typename T>
template <uint32 D>
vec<2,T>::vec(const vec<D,T>& other)
{
	if (D>=2)
	{
		x=other[0];
		y=other[1];
	}
	else
	{
		x=other[0];
		y=T(1);
	}
}

template <typename T>
vec<2,T> vec<2,T>::operator+(const vec<2,T>& rhs) const
{
	return vec<2,T>(x+rhs.x,y+rhs.y);
}

template <typename T>
vec<2,T> vec<2,T>::operator-(const vec<2,T>& rhs) const
{
	return vec<2,T>(x-rhs.x,y-rhs,y);
}

template <typename T>
vec<2,T> vec<2,T>::operator-() const
{
	return vec<2,T>(-x,-y);
}

template <typename T>
vec<2,T> vec<2,T>::operator*(const T& scalar) const
{
	return vec<2,T>(x*scalar,y*scalar);
}

template <typename T>
vec<2,T> vec<2,T>::operator/(const T& scalar) const
{
	return vec<2,T>(x/scalar,y/scalar);
}

template <typename T>
bool32 vec<2,T>::operator==(const vec<2,T>& rhs) const
{
	return this==&rhs||
		(x==rhs.x&&y==rhs.y);
}

template <typename T>
bool32 vec<2,T>::operator!=(const vec<2,T>& rhs) const
{
	return !(*this==rhs);
}

template <typename T>
vec<2,T>& vec<2,T>::operator=(const vec<2,T>& rhs)
{

	if (this!=&rhs)
	{
		x=rhs.x;
		y=rhs.y;
	}
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator-=(const vec<2,T>& rhs)
{

	if (this!=&rhs)
	{
		x=x-rhs.x;
		y=y-rhs.y;
	}
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator+=(const vec<2,T>& rhs)
{

	if (this!=&rhs)
	{
		x=x+rhs.x;
		y=y+rhs.y;
	}
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator*=(const T& scalar)
{
	x=x*scalar;
	y=y*scalar;
	return *this;
}

template <typename T>
vec<2,T>& vec<2,T>::operator/=(const T& scalar)
{
	x=x/scalar;
	y=y/scalar;
	return *this;
}

template <typename T>
T& vec<2,T>::operator[](uint32 index)
{
	ASSERT(index==0||index==1);
	if (index==0)
	{
		return x;
	}
	else
	{
		return y;
	}
}

template <typename T>
const T& vec<2,T>::operator[](uint32 index) const
{
	ASSERT(index==0||index==1);
	if (index==0)
	{
		return x;
	}
	else
	{
		return y;
	}
}


template <typename T>
T vec<2,T>::dot(const vec<2,T>& rhs) const
{
	return x*rhs.x+y*rhs.y;
}

template <typename T>
vec<2,T> operator*(const T& scalar,const vec<2,T>& vector)
{
	return vec<2,T>(scalar*vector.x,scalar*vector.y);
}

template <typename T>
T dot(const vec<2,T>& lhs,const vec<2,T>& rhs)
{
	return lhs.dot(rhs);
}
