#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Gas.h"

namespace game_framework {
	Gas::Gas() : Bullet()
	{
	}

	int  Gas::GetX2()
	{
		return x + gas.Width();
	}

	int  Gas::GetY2()
	{
		return y + gas.Height();
	}

	void Gas::LoadBitmap()
	{
		gas.LoadBitmap(".\\RES\\gas.bmp", RGB(255, 255, 255));
	}

	void Gas::OnMove(Map *m, bool direction)
	{
		if (direction && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - gas.Height() / 2))
			x += STEP_SIZE;
		else if(!direction && m->isEmpty(GetX2() - STEP_SIZE, GetY2() - gas.Height() / 2))
			x -= STEP_SIZE;
	}

	void Gas::OnShow(Map *m)
	{
		gas.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - gas.Height() / 2) && m->isEmpty(GetX2() - STEP_SIZE, GetY2() - gas.Height() / 2))
		{
			gas.ShowBitmap();
			isAlive = true;
		}
		else
			isAlive = false;
	}
}