#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"

namespace game_framework {
	Enemy::Enemy(int ox, int oy)
	{
		x = ox;
		y = oy;
		hp = 100;
		is_alive = RightOrLeft = true;
	}

	bool Enemy::IsAlive()
	{
		return is_alive;
	}

	void Enemy::SetXY(int nx, int ny)
	{

	}

	bool Enemy::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		return false;
	}

	void Enemy::OnShow(Map *m)
	{

	}

	void Enemy::OnMove(Map *m)
	{

	}

	void Enemy::Attack()
	{

	}

	void Enemy::hurted()
	{

	}
}