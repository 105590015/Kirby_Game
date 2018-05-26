#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Fire.h"

namespace game_framework {

	Fire::Fire(): Enemy() {

	}



	int Fire::GetX2() {
		return x + index->Width();
	}

	int Fire::GetY2() {
		return y + index->Width();
	}

	void Fire::Initialize(int ix,int iy) {
		x = ix;
		y = iy;

		hp = 10;
		counter = 0;
		is_alive = true;
		is_sucked = false;

		IsAttacking = false;	

		RightOrLeft = true;
		index = &Walk_L;
	}

	void Fire::LoadBitmap() {
		originR.AddBitmap(".\\RES\\Fire\\Fire_walk_R_2.bmp", RGB(255, 255, 255));
		originL.AddBitmap(".\\RES\\Fire\\Fire_walk_L_2.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_0.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_1.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_2.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_3.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_4.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_5.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_6.bmp", RGB(255, 255, 255));
		Walk_L.AddBitmap(".\\RES\\Fire\\Fire_walk_L_7.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_0.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_1.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_2.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_3.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_4.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_5.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_6.bmp", RGB(255, 255, 255));
		Walk_R.AddBitmap(".\\RES\\Fire\\Fire_walk_R_7.bmp", RGB(255, 255, 255));

		die.AddBitmap(".\\RES\\die1.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die2.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die3.bmp", RGB(255, 255, 255));

		Sucked_L.AddBitmap(".\\RES\\Fire\\Fire_sucked_L_0.bmp", RGB(255, 255, 255));
		Sucked_L.AddBitmap(".\\RES\\Fire\\Fire_sucked_L_1.bmp", RGB(255, 255, 255));
		Sucked_R.AddBitmap(".\\RES\\Fire\\Fire_sucked_R_0.bmp", RGB(255, 255, 255));
		Sucked_R.AddBitmap(".\\RES\\Fire\\Fire_sucked_R_1.bmp", RGB(255, 255, 255));

		Attack_R.AddBitmap(".\\RES\\Fire\\Fire_Attack_R_0.bmp", RGB(255, 255, 255));
		Attack_R.AddBitmap(".\\RES\\Fire\\Fire_Attack_R_1.bmp", RGB(255, 255, 255));
		Attack_R.AddBitmap(".\\RES\\Fire\\Fire_Attack_R_2.bmp", RGB(255, 255, 255));
		Attack_L.AddBitmap(".\\RES\\Fire\\Fire_Attack_L_0.bmp", RGB(255, 255, 255));
		Attack_L.AddBitmap(".\\RES\\Fire\\Fire_Attack_L_1.bmp", RGB(255, 255, 255));
		Attack_L.AddBitmap(".\\RES\\Fire\\Fire_Attack_L_2.bmp", RGB(255, 255, 255));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_0.bmp", RGB(0, 0, 115));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_1.bmp", RGB(0, 0, 115));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_2.bmp", RGB(0, 0, 115));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_3.bmp", RGB(0, 0, 115));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_4.bmp", RGB(0, 0, 115));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_5.bmp", RGB(0, 0, 115));
		attack.AddBitmap(".\\RES\\FireKirby\\attack3_6.bmp", RGB(0, 0, 115));
	}

	void Fire::OnMove(Map* m,Kirby* k) {
		if (is_alive) {

			Hurted(k);
			Sucked(k);

			if (ComputeDistance(k->GetX1(), k->GetY1()) < 200.0) {
				if (x - k->GetX1() > 0)
					RightOrLeft = false;
				else if (x - k->GetX1() < 0)
					RightOrLeft = true;
			}

			if (RightOrLeft)
				index = &Walk_R;
			else
				index = &Walk_L;

			if (is_sucked) {

				if (RightOrLeft)
					index = &Sucked_R;
				else
					index = &Sucked_L;

				if (x < (k->GetX1() + k->GetX2()) / 2)
					x += 3;
				else
					x -= 3;

				if (y > k->GetY1())
					y -= 3;
				else
					y += 3;

				if (HitRectangle(k->GetX1() + 10, k->GetY1() + 10, k->GetX2() - 10, k->GetY2() - 10)) {
					is_alive = false;
					k->SetBig(true);
					k->SetEat(2);
				}
			}


			else {
				Attack(m, k);
				if (!RightOrLeft)
				{
					if (!m->isEmpty(GetX1() - 1, GetY1() + Walk_L.Height() / 2)) //走到限制區域最左要掉頭
						RightOrLeft = true;
					else if (ComputeDistance(k->GetX1(), k->GetY1()) > 200.0)
					{
						x -= 1;
						counter = 0;
					}
					else
					{
						counter++;
						if (counter < 90)
						{
							index = &Attack_L;
							IsAttacking = true;
						}
						else if (counter >= 90 && counter <= 180)
						{
							index = &originL;
							IsAttacking = false;
						}
						else if (counter > 180)
							counter = 0;
					}
				}
				else if (RightOrLeft)
				{
					if (!m->isEmpty(GetX2() + 1, GetY2() - Walk_L.Height() / 2))  //走到限制區域最右要掉頭
						RightOrLeft = false;
					else if (ComputeDistance(k->GetX1(), k->GetY1()) > 200.0)
					{
						x += 1;
						counter = 0;
					}
					else
					{
						counter++;
						if (counter < 90)
						{
							index = &Attack_R;
							IsAttacking = true;
						}
						else if (counter >= 90 && counter <= 180)
						{
							index = &originR;
							IsAttacking = false;
						}
						else if (counter > 180)
							counter = 0;
					}	
				}

				if (m->isEmpty(x, y + 1+index->Height()) && m->isEmpty(x,y+1+index->Height())) {
					y += 1;
				}
			}

			index->OnMove();
		}
	}

	void Fire::Attack(Map* m,Kirby* k) {
		if (HitRectangle(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()) && !k->IsKick())
			k->Hurted(m);
		if(HitFire(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()) && IsAttacking)
			k->Hurted(m);
	}

	void Fire::OnShow(Map* m, Kirby* k) {
		die.SetTopLeft(m->ScreenX(x), m->ScreenY(y));

		if (is_alive) {
			index->SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			index->OnShow();

			if (index == &Attack_R)
			{
				attack.SetTopLeft(m->ScreenX(x + 58), m->ScreenY(y - 8));
				attack.OnShow();
				attack.OnMove();
			}
			else if (index == &Attack_L)
			{
				attack.SetTopLeft(m->ScreenX(x - 85), m->ScreenY(y - 8));
				attack.OnShow();
				attack.OnMove();
			}
		}
		else
		{
			if (!die.IsFinalBitmap() && !is_sucked)
			{
				die.OnShow();
				die.OnMove();
			}
		}
	}

	bool Fire::HitFire(int tx1, int ty1, int tx2, int ty2)
	{
		int x1;	// 左上角x座標
		int y1;	// 左上角y座標
		int x2;	// 右下角x座標
		int y2;	// 右下角y座標
		if (RightOrLeft)
			x1 = GetX1() + 58;
		else
			x1 = GetX1() - 85;

		y1 = GetY1() - 8;
		x2 = x1 + 80;
		y2 = y1 + 80;
		// 檢測矩形與參數矩形是否有交集
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}
}

