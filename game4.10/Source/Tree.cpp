#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Tree.h"

namespace game_framework {
	Tree::Tree() :Enemy() {
	}

	int Tree::GetX2() {
		return x + index->Width();
	}

	int Tree::GetY2() {
		return y + index->Height();
	}

	void Tree::LoadBitmap() {
		normal.AddBitmap(".\\RES\\King\\King_normal_0.bmp", RGB(255, 255, 255));
		normal.AddBitmap(".\\RES\\King\\King_normal_0.bmp", RGB(255, 255, 255));
		normal.AddBitmap(".\\RES\\King\\King_normal_0.bmp", RGB(255, 255, 255));
		normal.AddBitmap(".\\RES\\King\\King_normal_0.bmp", RGB(255, 255, 255));
		normal.AddBitmap(".\\RES\\King\\King_normal_1.bmp", RGB(255, 255, 255));
		normal.AddBitmap(".\\RES\\King\\King_normal_2.bmp", RGB(255, 255, 255));
		hurted.AddBitmap(".\\RES\\King\\King_hurted_0.bmp", RGB(255, 255, 255));
		hurted.AddBitmap(".\\RES\\King\\King_hurted_1.bmp", RGB(255, 255, 255));
		mad.AddBitmap(".\\RES\\King\\King_mad_0.bmp", RGB(255, 255, 255));
		mad.AddBitmap(".\\RES\\King\\King_mad_1.bmp", RGB(255, 255, 255));
		mad.AddBitmap(".\\RES\\King\\King_mad_2.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\King\\King_die_0.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\King\\King_die_1.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\King\\King_die_2.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\King\\King_die_3.bmp", RGB(255, 255, 255));
		for (int i = 0; i < 12; i++)
			stone[i].LoadBitmap();
	}

	void Tree::Initialize(int px, int py) {
		x = px;
		y = py;

		hp = 30;
		counter = 0;
		is_alive = true;
		is_sucked = false;
		IsAttacking = false;
		RightOrLeft = true;
		IsKing = true;

		index = &normal;
		stone[0].Init(0, 0);
		stone[1].Init(54, 0);
		stone[2].Init(108, 0);
		stone[3].Init(162, 0);
		stone[4].Init(216, 0);
		stone[5].Init(270, 0);
		stone[6].Init(324, 0);
		stone[7].Init(378, 0);
		stone[8].Init(432, 0);
		stone[9].Init(486, 0);
		stone[10].Init(540, 0);
		stone[11].Init(594, 0);
	}

	void Tree::OnMove(Map* m, Kirby* k) {

		if (is_alive) {

			Hurted(k);
			Attack(m, k);

			for (int i = 0; i < 12; i++) {
					stone[i].OnMove(m,k);
			}

			if (Ishurted && !hurted.IsFinalBitmap())
				index = &hurted;
			else {
				counter++;
				if (counter >= 50 && counter <= 150) {
					index = &mad;
					StoneAttack(m, k);
				}

				else if (counter >= 400) {
					counter = 0;
				}
				else {
					index = &normal;
				}
			}
		}
		else
		{
			index = &die;
			for (int i = 0; i < 12; i++) {
				stone[i].SetAlive(false);
			}
		}

		index->OnMove();
	}

	void Tree::OnShow(Map* m, Kirby* k) {
		index->SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		index->SetDelayCount(16);
		index->OnShow();

		for (int i = 0; i < 12; i++)
			if(stone[i].IsAlive())
				stone[i].OnShow(m, k);
	}

	void Tree::Attack(Map* m, Kirby* k) {
		if (HitRectangle(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()) && !k->IsKick())
			k->Hurted(m);
	}

	void Tree::StoneAttack(Map* m, Kirby* k) {
		int r = rand() % 360;
		for (int i = 0; i < 12 ; i++)
			if (r == i)
				stone[i].SetAlive(true);
	}
}