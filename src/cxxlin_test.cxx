#include <stdio.h>
#include <time.h>
#include "cxxlin.h"

int main(int argc,char* argv[])
{
	vec<5,real32> v5f;
	v5f[0]=1.0f;
	v5f[1]=1.0f;
	v5f[2]=1.0f;
	v5f[3]=1.0f;
	v5f[4]=1.0f;

	real32* buff=v5f.data();
	printf("%f\n",buff[0]);
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

	mat<2,2,real32> mat0;
	mat0.get(0,0)=1.0f;
	mat0.get(0,1)=0.0f;
	mat0.get(1,0)=0.0f;
	mat0.get(1,1)=1.0f;
	mat<2,2,real32> mat1;
	mat1.get(0,0)=1.0f;
	mat1.get(0,1)=0.0f;
	mat1.get(1,0)=0.0f;
	mat1.get(1,1)=1.0f;
	mat<2,2,real32> mat2=mat0*mat1;
	real32 angle=PI32/4.0f;
	mat2.get(0,0)=cosine(angle);
	mat2.get(0,1)=sine(angle);
	mat2.get(1,0)=-sine(angle);
	mat2.get(1,1)=cosine(angle);

	vec<2,real32> pos=VEC2_ONE<real32>;
	printf("%f,%f\n",pos.x,pos.y);
	pos=(pos*mat2).normalize();
	printf("( %f, %f )\n( %f, %f )\n",mat2.get(0,0),mat2.get(1,0),
			mat2.get(0,1),mat2.get(1,1));

	printf("%f,%f\n",pos.x,pos.y);
	return 0;
}
