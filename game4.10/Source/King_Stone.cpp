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
			y++;
			Attack(m, k);
		}
		else
			y = 0;
	}

	void Stone::Attack(Map* m, Kirby* k)
	{
		if (HitRectangle(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()))
			k->Hurted(m);
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
}