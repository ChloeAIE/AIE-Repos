#pragma once
#include "SpriteObject.h"
#include "Sphere.h"

class Barrel : public SpriteObject
{
	MathClasses::Vector3 pos;

public:
	Barrel();
	Barrel(MathClasses::Vector3 pos);
};

