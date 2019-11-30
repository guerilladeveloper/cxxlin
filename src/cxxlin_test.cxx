#include "cxxlin_vec.h"
#include "cxxlin_vec2.h"
#include "cxxlin_vec3.h"
#include "cxxlin_vecf.h"
//#include "cxxlin_vecptr.h"
//#include "cxxlin_vecref.h"
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

	vec<2,real32> v2f=vec<2,real32>(3.14);
	vec<2,real32> v2f2=vec<2,real32>(5.0f,2.1f);
	vec<4,uint32> v4u;

	printf("%f,%f\n",v2f[0],v2f[1]);

	vec<2,real32*> ptrVec;
	ptrVec[0]=&v2f.x;
	ptrVec[1]=&v2f.y;
	*ptrVec[0]=1.0f;

	printf("%f,%f\n",v2f[0],v2f[1]);
	printf("%f,%f\n",*ptrVec[0],*ptrVec[1]);
	
	v2f=v2f+v2f2;

	printf("%f,%f\n",*ptrVec[0],*ptrVec[1]);

	vec<4,uint32&> uPtrVec=vec<4,uint32*>(v4u.e);

	*uPtrVec[0]=50;
	printf("%d,%d\n",v4u[0],v4u[1]);
	return 0;
}
