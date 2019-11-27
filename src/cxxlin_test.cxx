#include "cxxlin_vec.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include "cxxlin_vecf.h"
#include <stdio.h>

#include "cxxlin_vec2f.cxx"
#include "cxxlin_vec3f.cxx"
#include "cxxlin_vec4f.cxx"

int main(int argc,char* argv[])
{
	vec2f pos=vec3f(2.0f);
	vec4f hom=vec4f(pos);

	vec<5,real32> v5f;
	v5f.normalize();

	vec<2,uint32> v2u;

	vec<2,real32> v2f;
	vec<5,uint32> v5u;

	printf("%f,%f,%f,%f\n",hom[0],hom[1],hom[2],hom[3]);

	return 0;
}
