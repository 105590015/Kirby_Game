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
		// 被吸
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && kirby->IsKick())
			hp -= 10;
		// 被空氣砲擊中
		if (kirby->GetGas()->IsAlive() && HitRectangle(kirby->GetGas()->GetX1() - 15, kirby->GetGas()->GetY1() - 15, kirby->GetGas()->GetX2() - 15, kirby->GetGas()->GetY2() - 15))
			hp -= 10;
		// 被星星擊中
		if (kirby->GetStar()->IsAlive() && HitRectangle(kirby->GetStar()->GetX1() - 15, kirby->GetStar()->GetY1() - 15, kirby->GetStar()->GetX2() - 15, kirby->GetStar()->GetY2() - 15))
			hp -= 20;
		// 被電
		if (kirby->GetType() == 1 && kirby->IsAttack() && HitRectangle(kirby->GetX1()-10, kirby->GetY1(), kirby->GetX1() + 145, kirby->GetY2() + 158))// -10補償圖片 +145.+158是雷電圖檔的大小
			hp -= 10;
		if (kirby->IsSuck() && (x - kirby->GetX1() > 2 || x - kirby->GetX1() < -2 || y - kirby->GetY1() > 2 || y - kirby->GetY1() < -2))
			is_alive = true;
		else if (hp <= 0)
			is_alive = false;
	}

	void Enemy::Sucked(Kirby* kirby)
	{
		if (ComputeDistance(kirby->GetX1(), kirby->GetY1()) < 150.0 && kirby->IsSuck())
		{
			hp -= 10;
			if (hp <= 0)
				is_sucked = true;
		}
		else
			is_sucked = false;
	}

	void Enemy::OnShow(Map *m, Kirby *kirby)
	{
	}

	void Enemy::OnMove(Map *m, Kirby* kirby)
	{
	}

	void Enemy::LoadBitmap()
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