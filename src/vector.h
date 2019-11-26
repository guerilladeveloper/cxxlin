#ifndef _VECTOR_H_

template <unsigned int D,typename T>
struct vec
{
	T e[D];

	vec operator+(const vec& rhs);
	vec operator-(const vec& rhs);
	vec operator-();
	vec operator*(const T& scalar);
	vec operator/(const T& scalar);
	bool32 operator==(const vec& rhs);
	bool32 operator!=(const vec& rhs);
	vec& operator=(const vec& rhs);
	vec& operator-=(const vec& rhs);
	vec& operator+=(const vec& rhs);
	vec& operator*=(const T& scalar);

	T& operator[](uint32 index);

	vec dot(const vec& rhs);
};

template <unsigned int D, typename T>
vec<D,T> operator*(const T& scalar,const vec<D,T>& vector);


#define _VECTOR_H_
#endif
