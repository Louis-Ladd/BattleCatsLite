#include "vec2.h"

Vec2 AddVec2(Vec2 vec_a, Vec2 vec_b)
{
    Vec2 result;
    result.x = vec_a.x + vec_b.x;
    result.y = vec_a.y + vec_b.y;
    return result;
}

Vec2 SubVec2(Vec2 vec_a, Vec2 vec_b)
{
    Vec2 result;
    result.x = vec_a.x - vec_b.x;
    result.y = vec_a.y - vec_b.y;
    return result;
}

float DistanceVec2(Vec2 vec_a, Vec2 vec_b)
{
    return sqrt(powf(vec_b.x - vec_a.x, 2) + powf(vec_b.y - vec_a.y, 2));
}
