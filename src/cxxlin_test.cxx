#include "cxxlin_vec.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include <stdio.h>

#include "cxxlin_vec2f.cxx"

typedef vec<3,real32> vec3f;
typedef vec<4,real32> vec4f;

int main(int argc,char* argv[])
{
#if 0
	vec2f pos=vec3f(2.0f);
	vec4f hom=vec4f(pos);

	vecf<2> v2f=vecf<2>(1.0f);
	v2f.normalize();
	vecf<2> v2f0=normal(v2f);

	printf("%f,%f,%f,%f\n",hom[0],hom[1],hom[2],hom[3]);
#endif

	vec2f test=vec2f(2.0f);
	test.normalize();
	printf("%f,%f",test.x,test.y);

	return 0;
}
