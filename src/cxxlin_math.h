#ifndef _CXXLIN_MATH_H_

#include <cmath>
#include "cxxlin_defines.h"

static const real32 PI32=3.14159265;
static const real64 PI64=3.141592653589793238;

inline real32 sqrt(real32 val)
{
	return std::sqrt(val);
}

inline real64 sqrt(real64 val)
{
	return std::sqrt(val);
}

inline real32 cosine(real32 val)
{
	return (real32)cos((real64)val);
}
inline real32 sine(real32 val)
{
	return (real32)sin((real64)val);
}
inline real64 cosine(real64 val)
{
	return cos(val);
}
inline real64 sine(real64 val)
{
	return sin(val);
}
#define _CXXLIN_MATH_H_
#endif
