#pragma once
#include "Bullet.h"
#include "Gas.h"
#include "Star.h"
#include "Header.h"

namespace game_framework {
	class BulletFactory
	{
	public:
		virtual Bullet* CreateBullet() = 0;
	};

	class GasFactory : BulletFactory
	{
	public:
		Bullet* CreateBullet()
		{
			return new Gas();
		}
	};

	class StarFactory : BulletFactory
	{
	public:
		Bullet* CreateBullet()
		{
			return new Star();
		}
	};

	class NewBulletFactory : BulletFactory
	{
	public:
		Bullet* CreateBullet()
		{
			return new NewBullet();
		}
	};
}