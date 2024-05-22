#include "Bullet.h"
#include "raylib-cpp.hpp"
#include "GameObject.h"

Bullet::Bullet()
{
	

	////SpriteObject newBullet;
	bulletTexture = new raylib::Texture2D("res/bulletBlue1_outline.png");


	this->Sprite = bulletTexture;
	//bulletSprite.SetParent(GameObject::getRoot());
	//bulletSprite.SetLocalPosition(500, 500);
	//

	//const float fireSpeed = 200.0f;

	//float shellSpeed = 0.0f;

	
	
	//bulletSprite.Draw();

}
void Bullet::OnUpdate(float deltaTime)
{
	int bulletSpeed = 500;

	MathClasses::Vector3 bulletShoot = GetForward() * (bulletSpeed * deltaTime);
	Translate(bulletShoot);
}

void Bullet::OnDraw()
{
	SpriteObject::OnDraw();
}

//void Bullet::Update(float deltaTime)
//{
//	OnUpdate(deltaTime);
//}
//
//void Bullet::Draw()
//{
//	OnDraw();
//}
