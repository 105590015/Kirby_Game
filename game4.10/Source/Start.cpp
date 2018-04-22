#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Start.h"

namespace game_framework {
	Start::Start() : Bullet()
	{
	}

	int  Start::GetX2()
	{
		return x + start.Width();
	}

	int  Start::GetY2()
	{
		return y + start.Height();
	}

	void Start::LoadBitmap()
	{
		start.AddBitmap(".\\RES\\start1.bmp", RGB(195, 195, 195));
		start.AddBitmap(".\\RES\\start2.bmp", RGB(195, 195, 195));
		start.AddBitmap(".\\RES\\start3.bmp", RGB(195, 195, 195));
		start.AddBitmap(".\\RES\\start4.bmp", RGB(195, 195, 195));
	}

	void Start::OnMove(Map *m, bool direction)
	{
		if (direction && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - start.Height() / 2))
			x += STEP_SIZE;
		else if (!direction && m->isEmpty(GetX2() - STEP_SIZE, GetY2() - start.Height() / 2))
			x -= STEP_SIZE;
	}

	void Start::OnShow(Map *m)
	{		
		start.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - start.Height() / 2) && m->isEmpty(GetX2() - STEP_SIZE, GetY2() - start.Height() / 2))
		{
			start.OnMove();
			start.OnShow();
			isAlive = true;
		}
		else
			isAlive = false;
	}
}