#include <stdio.h>
#include <time.h>
#include "cxxlin.h"

int main(int argc,char* argv[])
{
	vec2f v0=VEC2_ONE<real32>;
	vec2f v1=VEC2_XAXIS<real32>;
	vec2f blended=lerp(v0,0.75f,v1);
	real32 d=v0.dot(v1);
	d=dot(v0,v1);
	real32 l=len(v0);
	vec2f had=v0.hadamard(v1);

	printf("%f,%f\n",blended.x,blended.y);

	vec3f v2=VEC3_ONE<real32>;
	vec3f v3=VEC3_ZAXIS<real32>;

	vec3f sum=v2+v3;
	vec3f diff=v2-v3;
	vec3f normal=v2.normal();
	vec3f blended1=lerp(v2,0.21f,v3);

	vec4f v4=VEC3_ONE<real32>;
	vec4f v5=VEC3_ZAXIS<real32>;

	vec4f sum1=v2+v3;
	vec4f diff1=v2-v3;
	vec4f normal1=v2.normal();
	vec4f blended2=lerp(v2,0.21f,v3);
	return 0;
}
