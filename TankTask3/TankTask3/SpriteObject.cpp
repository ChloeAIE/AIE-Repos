#include "SpriteObject.h"
#include "GameObject.h"
#include "Utils.h"

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = MathClasses::Vector3(0.5f, 0.5f, 0.5f);
	Tint = MathClasses::Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	MathClasses::Vector3 pos = GetWorldPosition();
	float rot = GetWorldRotation() * Rad2Deg;
	MathClasses::Vector3 sc1 = GetWorldScale();

	//draw sprite with raylib
	Sprite->Draw(
		raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
		raylib::Rectangle(pos.x, pos.y, Sprite->width * sc1.x, Sprite->height * sc1.y),
		raylib::Vector2(Sprite->width * Origin.x * sc1.x, Sprite->height * Origin.y * sc1.y),
		rot,
		raylib::Color(Tint.colour));
}
