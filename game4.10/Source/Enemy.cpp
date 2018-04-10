#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"

namespace game_framework {
	Enemy::Enemy()
	{
	}

	int Enemy::GetX1()
	{
		return x;
	}

	int Enemy::GetY1()
	{
		return y;
	}

	int Enemy::GetX2()
	{
		return 0;
	}

	int Enemy::GetY2()
	{
		return 0;
	}

	bool Enemy::IsAlive()
	{
		return is_alive;
	}

	bool Enemy::IsSucked()
	{
		return is_sucked;
	}

	void Enemy::hurted(int demage)
	{
		hp -= demage;
		if (hp <= 0)
			is_alive = false;
	}

	void Enemy::OnShow(Map *m, Kirby *kirby)
	{
	}

	void Enemy::OnMove(Map *m, Kirby* kirby)
	{
	}

	void Enemy::Attack()
	{
	}
}