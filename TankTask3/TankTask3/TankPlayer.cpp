#include "TankPlayer.h"
#include "Bullet.h"
#include <vector>

void TankPlayer::mBulletSpawn(GameObject* bulletSpawn)
{
	spawnPoint = bulletSpawn;
}

void TankPlayer::OnUpdate(float deltaTime)
{
	//Bullet bullet;
	// for ref. the bullet texture - raylib::Texture2D bulletSprite("res/bulletBlue1_outline.png");

	/*int numberOfBullets;
	std::vector<GameObject>();*/

	

	const float MOVESPEED = 150.0f;
	const float TURNSPEED = 0.03f;
	const float ROTATESPEED = 0.06f;
	const float BULLETSPEED = 150.0f;

	float yMove = 0.0f;
	float rotateMove = 0.0f;

	float turretRotate = 0.0f;

	float bulletShoot = 0.0f;

	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		yMove += MOVESPEED;
	}

	if (IsKeyDown(KeyboardKey::KEY_S))
	{
		yMove -= MOVESPEED;
	}

	if (IsKeyDown(KeyboardKey::KEY_A))
	{
		rotateMove -= TURNSPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_D))
	{
		rotateMove += TURNSPEED;
	}

	if (IsKeyDown(KeyboardKey::KEY_E) || IsKeyDown(KeyboardKey::KEY_RIGHT))
	{
		turretRotate += ROTATESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_Q) || IsKeyDown(KeyboardKey::KEY_LEFT))
	{
		turretRotate -= ROTATESPEED;
	}

	if (IsKeyDown(KeyboardKey::KEY_SPACE))
	{
		Bullet* b = new Bullet();
		//sets the bullet to the root
		b->SetParent(GameObject::getRoot());
		//this currently sets its position to where the tank is
		//b->SetLocalPosition(GetWorldPosition());
		b->SetLocalPosition(spawnPoint->GetWorldPosition());
		//b->SetLocalPosition(GetChild(0)->GetChild(0)->GetWorldPosition());
		//this sets the rotation of the bullet to the same as the turret
		b->SetLocalRotation(GetChild(0)->GetWorldRotation());
		//b->Translate(50, GetLocalRotation());
		
	}

	MathClasses::Vector3 finalMove = GetForward() * (yMove * deltaTime);
	Translate(finalMove);
	Rotate(rotateMove);
	GetChild(0)->Rotate(turretRotate);

}
