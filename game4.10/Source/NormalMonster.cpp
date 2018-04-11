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
		if (IsAlive())
		{
			goLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			goRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			isSuckedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			isSuckedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			die.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			if (!IsSucked() && !RightOrLeft)
			{
				goLeft.OnShow();
				goLeft.OnMove();
			}
			else if (!IsSucked() && RightOrLeft)
			{
				goRight.OnShow();
				goRight.OnMove();
			}
			else if (IsSucked() && !RightOrLeft && x!=kirby->GetX1() && y!=kirby->GetY1())
				isSuckedL.ShowBitmap();
			else if (IsSucked() && RightOrLeft && x != kirby->GetX1() && y != kirby->GetY1())
				isSuckedR.ShowBitmap();
			hurted(kirby);
		}
		else
		{
			die.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			if (!die.IsFinalBitmap())
			{
				die.OnShow();
				die.OnMove();
			}
		}
	}

	void NormalMonster::OnMove(Map *m, Kirby *kirby)
	{
		if(IsAlive())
			Attack(kirby);
		if (IsAlive() && !IsSucked() && !RightOrLeft && m->isEmpty(GetX1() - 1, GetY1() + goLeft.Height() / 2))
		{
			if (x <= startX) //ǐ跋办程オ璶奔繷
				RightOrLeft = true;
			else
				x -= 1;
		}
		else if(IsAlive() && !IsSucked() && RightOrLeft && m->isEmpty(GetX2() + 1, GetY2() - goLeft.Height() / 2))
		{
			if (x >= endX)  //ǐ跋办程璶奔繷
				RightOrLeft = false;
			else
				x += 1;
		}
		else if (IsSucked())
		{
			if (x > kirby->GetX1())
				x -= 1;
			else if (x < kirby->GetX1())
				x += 1;
			if (y > kirby->GetY1())
				y -= 1;
			else if (y < kirby->GetY1())
				y += 1;
		}
		if (IsAlive() && !IsSucked() && m->isEmpty(GetX2() - goLeft.Width() / 2, GetY2() + 1)) //ま
				y += 1;
	}

	void NormalMonster::Attack(Kirby* kirby)
	{
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && !kirby->IsKick())
			kirby->Hurted();
	}
}