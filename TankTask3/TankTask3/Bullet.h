#pragma once
#include "SpriteObject.h"

class Bullet : public SpriteObject
{
protected:
	raylib::Texture2D* bulletTexture;
	void OnUpdate(float deltaTime) override;
	void OnDraw();

public:
	Bullet();

	//void Update(float deltaTime);
	//void Draw();
};

