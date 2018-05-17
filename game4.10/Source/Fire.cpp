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
		StepSize = 1;
		index = &Walk_L;
		

	}

	void Fire::LoadBitmap() {
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
	}

	void Fire::OnMove(Map* m,Kirby* k) {
		if (is_alive) {

			Hurted(k);
			Sucked(k);

			if (x - k->GetX1() > 0) {
				RightOrLeft = false;
				StepSize = -1;
			}
			else if (x - k->GetX1() < 0) {
				RightOrLeft = true;
				StepSize = 1;
			}

			if (RightOrLeft)
				index = &Walk_R;
			if (!RightOrLeft)
				index = &Walk_L;

			if (is_sucked) {

				if (RightOrLeft)
					index = &Sucked_R;
				if (!RightOrLeft)
					index = &Sucked_L;

				if (x < k->GetX1())
					x += 3;
				else if (x > k->GetX2())
					x -= 3;

				if (y > k->GetY2())
					y -= 3;
				else if (y < k->GetY1())
					y += 3;

				if (x >= k->GetX1() && x <= k->GetX2() && y >= k->GetY1() && y <= k->GetY2()) {
					is_alive = false;
					k->SetBig(true);
					k->SetEat(1);
				}
			}


			else {
				if (abs(k->GetX1() - x) < SIZE_X  && m->isEmpty(x+index->Width()+1,y)&& RightOrLeft) {
					x += StepSize;
				}
				else if(abs(k->GetX1() - x) < SIZE_X && m->isEmpty(x -1, y) && !RightOrLeft) {
					x += StepSize;
				}
				else
				{
					x += 0;
				}

				if (m->isEmpty(x, y + 1+index->Height()) && m->isEmpty(x,y+1+index->Height())) {
					y += 1;
				}
			}

			index->OnMove();
		}

		
	}

	void Fire::Attack(Map* m,Kirby* k) {

	}

	void Fire::OnShow(Map* m, Kirby* k) {
		if (is_alive) {
			index->SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			index->OnShow();
		}
	}
}

