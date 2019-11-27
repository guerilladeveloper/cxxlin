#include "cxxlin_vec.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include <stdio.h>

#include "cxxlin_vec2f.cxx"
#include "cxxlin_vec3f.cxx"

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
	printf("%f,%f\n",test.x,test.y);

	vec3f test2=vec3f(10.14f,0.2f,41.0);
	vec3f test3=vec3f(1.12f);

	vec3f test4=cross(test2,test3);

	printf("%f,%f,%f\n",test2.x,test2.y,test2.z);
	printf("%f,%f,%f\n",test3.x,test3.y,test3.z);
	printf("%f,%f,%f\n",test4.x,test4.y,test4.z);
	return 0;
}
