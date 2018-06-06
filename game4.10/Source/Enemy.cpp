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
		// �Q��
		if ((kirby->GetType() == 0 && HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && kirby->IsKick()) ||
			((kirby->GetType() == 1 || kirby->GetType() == 2) && HitRectangle(kirby->GetX1(), kirby->GetY1() + 40, kirby->GetX2(), kirby->GetY1() + 60) && kirby->IsKick())) {
			hp -= 10;
			Ishurted = true;
		}
		// �Q�Ů�����
		else if (kirby->GetGas()->IsAlive() && HitRectangle(kirby->GetGas()->GetX1() + 10, kirby->GetGas()->GetY1() + 10, kirby->GetGas()->GetX2() - 10, kirby->GetGas()->GetY2() - 10)) {
			hp -= 10;
			Ishurted = true;
			kirby->GetGas()->SetAlive(false);
		}
		// �Q�P�P����
		else if (kirby->GetStar()->IsAlive() && HitRectangle(kirby->GetStar()->GetX1() + 10, kirby->GetStar()->GetY1() + 10, kirby->GetStar()->GetX2() - 10, kirby->GetStar()->GetY2() - 10)) {
			hp -= 20;
			Ishurted = true;
			kirby->GetStar()->SetAlive(false);
		}
			
		// �Q�q
		else if (kirby->GetType() == 1 && kirby->IsAttack() && !kirby->IsDown() && HitRectangle(kirby->GetX1() - 40, kirby->GetY1() - 10, kirby->GetX1() + 90, kirby->GetY1() + 110)){  // -10���v�Ϥ� +145.+158�O�p�q���ɪ��j�p
				hp -= 10;
				Ishurted = true;
			}
			
		// �Q�N
		else if (kirby->GetType() == 2 && kirby->IsAttack() && !kirby->IsDown() && (
		   (kirby->IsRight() && HitRectangle(kirby->GetX1() + 63, kirby->GetY1() + 12, kirby->GetX1() + 203, kirby->GetY1() + 90)) ||    // �d�񭱬ۥk�Q��
		   (!kirby->IsRight() && HitRectangle(kirby->GetX1() - 112, kirby->GetY1() + 12, kirby->GetX1() - 12, kirby->GetY1() + 90)))) {   // �d�񭱬ۥ��Q��
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
		int x1 = GetX1();	// ���W��x�y��
		int y1 = GetY1();	// ���W��y�y��
		int x2 = GetX2();	// �k�U��x�y��
		int y2 = GetY2();	// �k�U��y�y��
		// �˴��x�λP�ѼƯx�άO�_���涰
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	double Enemy::ComputeDistance(int tx1, int ty1)
	{
		int temp = (x - tx1)*(x - tx1) + (y - ty1)*(y - ty1);
		return sqrt(temp);
	}
}