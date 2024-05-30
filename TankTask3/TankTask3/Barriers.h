#pragma once
#include "GameObject.h"

class Barriers : public GameObject
{
public:
	Barriers();

	Barriers(MathClasses::Vector3 normal, float direction);
};

