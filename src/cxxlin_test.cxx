#include <stdio.h>
#include <time.h>
#include "cxxlin_vec.h"
#include "cxxlin_vec1.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include "cxxlin_vec4.h"

#include "cxxlin_vec2f.h"

int main(int argc,char* argv[])
{

	vec2f v0=VEC2F_ONE;
	real32 l=len(v0);
	printf("%f\n",l);
	return 0;
}
