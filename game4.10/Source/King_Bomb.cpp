#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "King_Bomb.h"

namespace game_framework {
	King_Bomb::King_Bomb()
	{
		is_alive = false;
	}

	void King_Bomb::LoadBitmap()
	{
		bomb.LoadBitmap(".//RES//Bombar//Bombar_bomb.bmp", RGB(255, 255, 255));
		fire.AddBitmap(".//RES//Bombar//Bombar_fire1.bmp", RGB(255, 255, 255));
		fire.AddBitmap(".//RES//Bombar//Bombar_fire2.bmp", RGB(255, 255, 255));
		fire.AddBitmap(".//RES//Bombar//Bombar_fire3.bmp", RGB(255, 255, 255));
	}

	void King_Bomb::Init(int sx, int sy)
	{
		x = sx;
		y = sy;
		counter = 0;
		is_alive = true;
	}

	void King_Bomb::OnShow(Map* m, Kirby* kirby)
	{
		bomb.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		fire.SetTopLeft(m->ScreenX(x), m->ScreenY(y));

		if (!m->isEmpty(GetX1() + bomb.Width() / 2, GetY2() + STEP_SIZE) || fire.GetCurrentBitmapNumber() != 0 || counter != 0)
		{
			fire.OnMove();
			fire.OnShow();

			if (fire.IsFinalBitmap())
			{
				is_alive = false;
				fire.Reset();
			}
		}
		else
			bomb.ShowBitmap();
	}

	void King_Bomb::OnMove(Map* m, Kirby* kirby)
	{	
		Attack(m, kirby);

		if (m->isEmpty(GetX1() + bomb.Width() / 2, GetY2() + STEP_SIZE) && counter == 0)
			y += STEP_SIZE;
		else if(counter == 0)
		{
			x -= 32;
			y -= 25;
			counter++;
		}
	}

	void King_Bomb::Attack(Map* m, Kirby* kirby)
	{
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()))
			kirby->Hurted(m);

		if (!m->isEmpty(GetX1() + bomb.Width() / 2, GetY2() + 1))
		{
			if (kirby->GetX2() >= x && kirby->GetX1() <= x + fire.Width() && kirby->GetY2() >= y && kirby->GetY1() <= y + fire.Height())
				kirby->Hurted(m);
		}
	}

	int King_Bomb::GetX2()
	{
		return x + bomb.Width();
	}

	int King_Bomb::GetY2()
	{
		return y + bomb.Height();
	}
}