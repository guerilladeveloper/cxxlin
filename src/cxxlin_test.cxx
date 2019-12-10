#include <stdio.h>
#include <time.h>
#include "cxxlin_vec.h"
#include "cxxlin_vec1.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include "cxxlin_vec4.h"

#include "cxxlin_vec2f.h"
#include "cxxlin_vec2fptr.h"

int main(int argc,char* argv[])
{

	vec2f v0=VEC2F_ONE;
	real32 l=len(v0);

	vec2fptr v1=v0;

	v1[0]=-1.0f;

	printf("v0: %f,%f\n",v0[0],v0[1]);
	printf("%f\n",l);
	return 0;
}
