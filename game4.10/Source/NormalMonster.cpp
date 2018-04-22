#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "NormalMonster.h"

namespace game_framework {
	NormalMonster::NormalMonster() : Enemy()
	{
	}

	void NormalMonster::Initialize(int ox, int oy, int sx, int ex, bool direction)
	{
		x = ox;
		y = oy;
		startX = sx;
		endX = ex;
		RightOrLeft = direction;
		hp = 10;
		is_alive = true;
		is_sucked = false;
	}

	int NormalMonster::GetX2()
	{
		return x + goRight.Width();
	}

	int NormalMonster::GetY2()
	{
		return y + goRight.Height();
	}

	void NormalMonster::LoadBitmap()
	{
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_1.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_2.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_3.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_4.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_5.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_6.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_7.bmp", RGB(0, 219, 255));
		goLeft.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_L_8.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_1.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_2.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_3.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_4.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_5.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_6.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_7.bmp", RGB(0, 219, 255));
		goRight.AddBitmap(".\\RES\\NormalMonster\\NormalMonster_R_8.bmp", RGB(0, 219, 255));
		isSuckedL.LoadBitmap(".\\RES\\NormalMonster\\NormalMonster_Sucked_L.bmp", RGB(0, 219, 255));
		isSuckedR.LoadBitmap(".\\RES\\NormalMonster\\NormalMonster_Sucked_R.bmp", RGB(0, 219, 255));
		die.AddBitmap(".\\RES\\die1.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die2.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die3.bmp", RGB(255, 255, 255));
	}

	void NormalMonster::OnShow(Map *m, Kirby *kirby)
	{			
		goLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		goRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		isSuckedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		isSuckedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		die.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		if (is_alive)
		{
			if (!is_sucked && !RightOrLeft)
			{
				goLeft.OnShow();
				goLeft.OnMove();
			}
			else if (!is_sucked && RightOrLeft)
			{
				goRight.OnShow();
				goRight.OnMove();
			}
			else if (is_sucked && !((x - kirby->GetX1() >= -1) && (x - kirby->GetX1() <= 1)) || !((y - kirby->GetY1() >= -1) && (y - kirby->GetY1() <= 1)))
			{
				if(!RightOrLeft)
					isSuckedL.ShowBitmap();
				else
					isSuckedR.ShowBitmap();
			}				
		}
		else
		{
			die.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			if (!die.IsFinalBitmap() && !is_sucked)
			{
				die.OnShow();
				die.OnMove();
			}
		}
	}

	void NormalMonster::OnMove(Map *m, Kirby *kirby)
	{
		if (is_alive)
		{
			Hurted(kirby);
			Sucked(kirby);
			if(!is_sucked)
				Attack(kirby);
			if (is_alive && !is_sucked && !RightOrLeft && m->isEmpty(GetX1() - 1, GetY1() + goLeft.Height() / 2))
			{
				if (x <= startX) //ǐ跋办程オ璶奔繷
					RightOrLeft = true;
				else
					x -= 1;
			}
			else if (is_alive && !is_sucked && RightOrLeft && m->isEmpty(GetX2() + 1, GetY2() - goLeft.Height() / 2))
			{
				if (x >= endX)  //ǐ跋办程璶奔繷
					RightOrLeft = false;
				else
					x += 1;
			}
			else if (is_sucked)
			{
				if (x > kirby->GetX1())
					x -= STEP_SIZE;
				else if (x < kirby->GetX1())
					x += STEP_SIZE;
				if (y > kirby->GetY1())
					y -= STEP_SIZE;
				else if (y < kirby->GetY1())
					y += STEP_SIZE;
				if ((x - kirby->GetX1() >= -1) && (x - kirby->GetX1() <= 1) && (y - kirby->GetY1() >= -1) && (y - kirby->GetY1() <= 1))
					is_alive = false;
			}
			if (is_alive && is_sucked && m->isEmpty(GetX2() - goLeft.Width() / 2, GetY2() + 1)) //ま
				y += 1;
		}
	}

	void NormalMonster::Attack(Kirby* kirby)
	{
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && !kirby->IsKick())
			kirby->Hurted();
	}
}