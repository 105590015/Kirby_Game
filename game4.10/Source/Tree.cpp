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


	}

	void Tree::Initialize(int px,int py) {
		x = px;
		y = py;

		hp = 10;
		counter = 0;
		is_alive = true;
		is_sucked = false;
		IsAttacking = false;
		RightOrLeft = true;

		index = &normal;
	}

	void Tree::OnMove(Map* m,Kirby* k) {

		if (is_alive) {
			counter++;

		}
		else
		{
			index = &die;
		}

		index->OnMove();
	}

	void Tree::OnShow(Map* m,Kirby* k) {
		index->SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		index->SetDelayCount(16);
		index->OnShow();
	}

	void Tree::Attack(Map* m, Kirby* k) {

	}


}