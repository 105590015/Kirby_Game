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

	void Enemy::Hurted(Kirby* kirby)
	{
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && kirby->IsKick())
			hp -= 10;
		if ((kirby->IsKick() && hp <= 0) || (kirby->IsSuck() && x - kirby->GetX1() <= 1 && x - kirby->GetX1() >= -1 && y - kirby->GetY1() <= 1 && y - kirby->GetY1() >= -1))
		{
			is_alive = false;
			if (kirby->IsSuck() && x - kirby->GetX1() <= 1 && x - kirby->GetX1() >= -1 && y - kirby->GetY1() <= 1 && y - kirby->GetY1() >= -1)
				kirby->SetBig(true);
		}
	}

	void Enemy::Sucked(Kirby* kirby)
	{
		if (ComputeDistance(kirby->GetX1(), kirby->GetY1()) < 50.0 && kirby->IsSuck())
		{
			hp -= 10;
			if (hp <= 0)
				is_sucked = true;
		}
	}

	void Enemy::OnShow(Map *m, Kirby *kirby)
	{
	}

	void Enemy::OnMove(Map *m, Kirby* kirby)
	{
	}

	void Enemy::Attack(Kirby* kirby)
	{
	}

	bool Enemy::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = GetX1();	// 左上角x座標
		int y1 = GetY1();	// 左上角y座標
		int x2 = GetX2();	// 右下角x座標
		int y2 = GetY2();	// 右下角y座標
		// 檢測矩形與參數矩形是否有交集
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	double Enemy::ComputeDistance(int tx1, int ty1)
	{
		int temp = (x - tx1)*(x - tx1) + (y - ty1)*(y - ty1);
		return sqrt(temp);
	}
}