#pragma once
#define PI 3.1415f
#define Rad2Deg (180.0f / PI)
#define Deg2Rad (PI / 180.0f)

constexpr float minf(float a, float b) { return a < b ? a : b; }
constexpr float maxf(float a, float b) { return a > b ? a : b; }
constexpr float clampf(float t, float a, float b)
{
	return maxf(a, minf(b, t));
}




