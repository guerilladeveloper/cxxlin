#ifndef _CXXLIN_MAT_H_

#include "cxxlin_vec.h"

template <uint32 C,uint32 R,typename T>
struct mat
{
	static const uint32 COLUMNS=C;
	static const uint32 ROWS=R;
	T e[C*R];

	explicit mat(const T elements[C*R]);
	explicit mat(const T& diagonal);
	mat();
	mat(const mat& other);

	mat operator+(const mat& rhs) const;
	mat operator-(const mat& rhs) const;
	mat operator-() const;
	mat operator*(const T& scalar) const;
	mat operator/(const T& scalar) const;
	mat operator*(const mat& rhs) const;
	bool32 operator==(const mat& rhs) const;
	bool32 operator!=(const mat& rhs) const;
	mat& operator=(const mat& rhs);
	mat& operator+=(const mat& rhs);
	mat& operator-=(const mat& rhs);
	mat& operator*=(const T& scalar);
	mat& operator*=(const mat& rhs);

	T& get(uint32 column,uint32 row);
	const T& get(uint32 column,uint32 row) const;

	vec<C,T> get_row(uint32 row) const;
	vec<R,T> get_column(uint32 column) const;

	void set_row(const vec<C,T>& row);
	void set_column(const vec<R,T>& column);

	mat<R,C> transpose() const;
};

#include "cxxlin_mat.inl"

#define _CXXLIN_MAT_H_
#endif
