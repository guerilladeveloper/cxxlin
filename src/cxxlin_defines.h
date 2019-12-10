#ifndef _CXXLIN_DEFINES_H_

#include <cstdint>

typedef uint32_t bool32;
typedef bool32 b32;
typedef uint32_t uint32;
typedef uint32 u32;
typedef float real32;
typedef real32 r32;
typedef double real64;
typedef real64 r64;
typedef uint64_t uint64;

#ifdef CXXLIN_DEBUG
#ifdef ASSERT
#undef ASSERT(P)
#endif
#define ASSERT(P) if(!(P)) { int x=*((int*)0); } 0
#else
#ifdef ASSERT
#undef ASSERT(P)
#endif
#define ASSERT(P)
#endif

#define _CXXLIN_DEFINES_H_
#endif
