#ifndef _CXXLIN_MAT_H_

#include "cxxlin_vec.h"

template <uint32 C,uint32 R,typename T>
struct mat
{
	static const uint32 COLUMNS=C;
	static const uint32 ROWS=R;

	T e[C*R];

	mat(const T e[C*R]);
	mat(const mat& other);
	mat();

	mat operator+(const mat& rhs) const;
	mat operator-(const mat& rhs) const;
	mat operator*(const T& scalar) const;
	mat operator*(const mat& rhs) const;
	mat& operator=(const mat& rhs);
	mat& operator+=(const mat& rhs);
	mat& operator-=(const mat& rhs);
	mat& operator*=(const T& scalar);
	mat& operator*=(const mat& rhs);

};

#define _CXXLIN_MAT_H_
#endif
