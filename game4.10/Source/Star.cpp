#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Star.h"

namespace game_framework {
	Star::Star() : Bullet()
	{
	}

	int  Star::GetX2()
	{
		return x + star.Width();
	}

	int  Star::GetY2()
	{
		return y + star.Height();
	}

	void Star::LoadBitmap()
	{
		star.AddBitmap(".\\RES\\start1.bmp", RGB(195, 195, 195));
		star.AddBitmap(".\\RES\\start2.bmp", RGB(195, 195, 195));
		star.AddBitmap(".\\RES\\start3.bmp", RGB(195, 195, 195));
		star.AddBitmap(".\\RES\\start4.bmp", RGB(195, 195, 195));
	}

	void Star::OnMove(Map *m, bool direction)
	{
		if (isAlive)
		{
			if (direction && m->isEmpty(GetX2() + STEP_SIZE*2, GetY2() - star.Height() / 2))
				x += STEP_SIZE*2;
			else if (!direction && m->isEmpty(GetX2() - STEP_SIZE*2, GetY2() - star.Height() / 2))
				x -= STEP_SIZE*2;
		}	
	}

	void Star::OnShow(Map *m)
	{		
		star.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		if (isAlive && m->isEmpty(GetX2() + STEP_SIZE*2, GetY2() - star.Height() / 2) && m->isEmpty(GetX2() - STEP_SIZE*2, GetY2() - star.Height() / 2))
		{
			star.OnMove();
			star.OnShow();
		}
		else
			isAlive = false;
	}
}