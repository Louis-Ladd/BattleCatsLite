#ifndef VEC2_H_
#define VEC2_H_

#include <math.h>

typedef struct
{
	float x;
	float y;
} Vec2;

Vec2 AddVec2(Vec2 vec_a, Vec2 vec_b);

Vec2 SubVec2(Vec2 vec_a, Vec2 vec_b);

float DistanceVec2(Vec2 vec_a, Vec2 vec_b);

#endif
