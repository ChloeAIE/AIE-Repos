#pragma once
#include "SpriteObject.h"

class TankPlayer : public SpriteObject
{
protected:

		void OnUpdate(float deltaTime) override;

public:

		TankPlayer();

		void mBulletSpawn(GameObject* bulletSpawn);

		GameObject* spawnPoint;
};

