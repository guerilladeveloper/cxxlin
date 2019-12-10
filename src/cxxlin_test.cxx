#include <stdio.h>
#include <time.h>
#include "cxxlin_vec.h"
#include "cxxlin_vec1.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include "cxxlin_vec4.h"

#include "cxxlin_vec2f.h"
#include "cxxlin_vec3f.h"
#include "cxxlin_vec4f.h"

int main(int argc,char* argv[])
{

	vec2f v0=VEC2F_ONE;
	real32 l=len(v0);

	vec2fptr v1=v0;

	v1[0]=-1.0f;

	printf("v0: %f,%f\n",v0[0],v0[1]);
	printf("%f\n",l);

	vec3f v2=VEC3F_ZAXIS;
	vec3f v3=VEC3F_ONE;
	vec3f v4=cross(v2,v3);
	printf("v4:%f,%f,%f\n",v4[0],v4[1],v4[2]);
	return 0;
}
