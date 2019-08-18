#pragma once
#include <ddraw.h>
#include "Bullet.h"
#include "gamelib.h"

namespace game_framework {

	class NewBullet : public Bullet
	{
	public:
		NewBullet() {}

		int GetX2()
		{
			return x + newBullet.Width();
		}

		int GetY2()
		{
			return y + newBullet.Height();
		}

		void LoadBitmap()
		{
			newBullet.LoadBitmap(".\\RES\\die1.bmp", RGB(255, 255, 255));
		}

		void OnMove(Map *m, bool direction)
		{
			if (direction && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - newBullet.Height() / 2))
				x += STEP_SIZE;
			else if (!direction && m->isEmpty(GetX2() - STEP_SIZE, GetY2() - newBullet.Height() / 2))
				x -= STEP_SIZE;
		}

		void OnShow(Map *m)
		{
			newBullet.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - newBullet.Height() / 2) && m->isEmpty(GetX2() - STEP_SIZE, GetY2() - newBullet.Height() / 2))
				newBullet.ShowBitmap();
		}

	protected:
		CMovingBitmap newBullet;
	};
}