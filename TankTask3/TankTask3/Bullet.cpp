#include "Bullet.h"
#include "raylib-cpp.hpp"
#include "GameObject.h"
#include "Sphere.h"

Bullet::Bullet()
{
	
	m_collider = new Sphere(GetWorldPosition(), 15);
	m_collider->m_Object = this;
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

	Sphere* s_result = dynamic_cast<Sphere*>(m_collider);
	s_result->center = this->GetWorldPosition();

	MathClasses::Vector3 bulletShoot = GetForward() * (bulletSpeed * deltaTime);
	Translate(bulletShoot);
}

void Bullet::OnDraw()
{
	SpriteObject::OnDraw();
}

void Bullet::OnCollision()
{
	Destroy();
	//destroy self
	//delete(this); //might not work idk
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
