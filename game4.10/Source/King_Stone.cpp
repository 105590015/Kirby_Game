#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "King_Stone.h"

namespace game_framework {
	Stone::Stone() : Enemy() {
	}

	void Stone::LoadBitmap()
	{
		stone.AddBitmap(".\\RES\\King\\stone_0.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_1.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_2.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_3.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_4.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_5.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_6.bmp", RGB(255, 251, 255));
		stone.AddBitmap(".\\RES\\King\\stone_7.bmp", RGB(255, 251, 255));
	}

	void Stone::Init(int sx, int sy)
	{
		x = sx;
		y = sy;
		is_alive = false;
		is_sucked = false;
	}

	void Stone::OnShow(Map* m, Kirby* k)
	{
		stone.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		if (is_alive)
		{
			stone.OnMove();
			stone.OnShow();
		}
	}

	void Stone::OnMove(Map* m, Kirby* k)
	{
		if (y >= SIZE_Y - stone.Height())
			is_alive = false;
		if (is_alive)
		{
			Sucked(k);
			if (!is_sucked)
			{
				Attack(m, k);
				y++;
			}
			else if (is_sucked)
			{
				if (x > (k->GetX1() + k->GetX2()) / 2)
					x -= 3;
				else
					x += 3;
				if (y > k->GetY1())
					y -= 3;
				else
					y += 3;
				if (HitRectangle(k->GetX1() + 10, k->GetY1() + 10, k->GetX2() - 10, k->GetY2() - 10))
				{
					k->SetBig(true);
					k->SetEat(0);
					is_alive = false;
				}
			}
		}
		else
			y = 0;
	}

	void Stone::Attack(Map* m, Kirby* k)
	{
		if (HitRectangle(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()))
			k->Hurted(m);
	}

	void Stone::Sucked(Kirby* kirby)
	{
		if (ComputeDistance(kirby->GetX1(), kirby->GetY1()) < 150.0 && kirby->IsSuck() && ((kirby->IsRight() && x - kirby->GetX1() >= 0) || (!kirby->IsRight() && x - kirby->GetX2() <= 0)))
			is_sucked = true;
		else
			is_sucked = false;
	}

	void Stone::SetAlive(bool flag)
	{
		is_alive = flag;
	}

	int Stone::GetX2()
	{
		return x + stone.Width();
	}

	int Stone::GetY2()
	{
		return y + stone.Height();
	}

	bool Stone::IsAlive() {
		return is_alive;
	}
}