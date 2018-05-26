#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Bullet.h"

namespace game_framework {
	Bullet::Bullet()
	{
	}

	int  Bullet::GetX1()
	{
		return x;
	}

	int  Bullet::GetY1()
	{
		return y;
	}

	int  Bullet::GetX2()
	{
		return x + 20;
	}

	int  Bullet::GetY2()
	{
		return y + 20;
	}

	void Bullet::SetXY(int sx, int sy)
	{
		x = sx;
		y = sy;
	}

	void Bullet::SetAlive(bool flag)
	{
		isAlive = flag;
	}

	bool Bullet::IsAlive()
	{
		return isAlive;
	}
}