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
		// 被踢
		if ((kirby->GetType() == 0 && HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && kirby->IsKick()) ||
			((kirby->GetType() == 1 || kirby->GetType() == 2) && HitRectangle(kirby->GetX1(), kirby->GetY1() + 40, kirby->GetX2(), kirby->GetY1() + 60) && kirby->IsKick())) {
			hp -= 10;
			Ishurted = true;
		}
		// 被空氣砲擊中
		else if (kirby->GetGas()->IsAlive() && HitRectangle(kirby->GetGas()->GetX1() + 10, kirby->GetGas()->GetY1() + 10, kirby->GetGas()->GetX2() - 10, kirby->GetGas()->GetY2() - 10)) {
			hp -= 10;
			Ishurted = true;
			kirby->GetGas()->SetAlive(false);
		}
		// 被星星擊中
		else if (kirby->GetStar()->IsAlive() && HitRectangle(kirby->GetStar()->GetX1() + 10, kirby->GetStar()->GetY1() + 10, kirby->GetStar()->GetX2() - 10, kirby->GetStar()->GetY2() - 10)) {
			hp -= 20;
			Ishurted = true;
			kirby->GetStar()->SetAlive(false);
		}
			
		// 被電
		else if (kirby->GetType() == 1 && kirby->IsAttack() && !kirby->IsDown() && HitRectangle(kirby->GetX1() - 40, kirby->GetY1() - 10, kirby->GetX1() + 90, kirby->GetY1() + 110)){  // -10補償圖片 +145.+158是雷電圖檔的大小
				hp -= 10;
				Ishurted = true;
			}
			
		// 被燒
		else if (kirby->GetType() == 2 && kirby->IsAttack() && !kirby->IsDown() && (
		   (kirby->IsRight() && HitRectangle(kirby->GetX1() + 63, kirby->GetY1() + 12, kirby->GetX1() + 203, kirby->GetY1() + 90)) ||    // 卡比面相右噴火
		   (!kirby->IsRight() && HitRectangle(kirby->GetX1() - 112, kirby->GetY1() + 12, kirby->GetX1() - 12, kirby->GetY1() + 90)))) {   // 卡比面相左噴火
			 hp -= 10;
			 Ishurted = true;
		}

		else {
			Ishurted = false;
		}
			
		if (kirby->IsSuck() && (x - kirby->GetX1() > 2 || x - kirby->GetX1() < -2 || y - kirby->GetY1() > 2 || y - kirby->GetY1() < -2))
			is_alive = true;
		else if (hp <= 0)
		{
			CAudio::Instance()->Play(enemyDie);
			is_alive = false;
		}
			
	}

	void Enemy::Sucked(Kirby* kirby)
	{
		if (ComputeDistance(kirby->GetX1(), kirby->GetY1()) < 150.0 && kirby->IsSuck() && ((kirby->IsRight() && x - kirby->GetX1() >= 0) || (!kirby->IsRight() && x - kirby->GetX2() <= 0)))
		{
			hp -= 10;
			if (hp <= 0)
				is_sucked = true;
		}
		else
			is_sucked = false;
	}

	void Enemy::SetAlive(bool flag)
	{
		is_alive = flag;
	}

	bool Enemy::IsAlive() {
		return is_alive;
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