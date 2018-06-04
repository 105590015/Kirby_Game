#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "King_Airplane.h"

namespace game_framework {
	King_Airplane::King_Airplane() : Enemy()
	{
	}

	void King_Airplane::LoadBitmap()
	{
		downL.LoadBitmap(".\\RES\\Bombar\\Bombar_downL.bmp", RGB(255,255,255));
		downR.LoadBitmap(".\\RES\\Bombar\\Bombar_downR.bmp", RGB(255, 255, 255));
		dieL.LoadBitmap(".\\RES\\Bombar\\Bombar_dieL.bmp", RGB(255, 255, 255));
		dieR.LoadBitmap(".\\RES\\Bombar\\Bombar_dieR.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_1.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_2.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_3.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_4.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_5.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_6.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_7.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_8.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_9.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_10.bmp", RGB(255, 255, 255));
		goLeft.AddBitmap(".\\RES\\Bombar\\Bombar_goL_11.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_1.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_2.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_3.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_4.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_5.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_6.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_7.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_8.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_9.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_10.bmp", RGB(255, 255, 255));
		goRight.AddBitmap(".\\RES\\Bombar\\Bombar_goR_11.bmp", RGB(255, 255, 255));
		bomb1.LoadBitmap();
		bomb2.LoadBitmap();
		bomb3.LoadBitmap();
	}

	void King_Airplane::OnShow(Map* m, Kirby* kirby)
	{
		downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		dieL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		dieR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		goLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		goRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));

		if (is_alive)
		{
			if (RightOrLeft)
			{
				goRight.OnMove();
				goRight.OnShow();
			}
			else
			{
				goLeft.OnMove();
				goLeft.OnShow();
			}

			if (bomb1.IsAlive())
				bomb1.OnShow(m, kirby);
			if (bomb2.IsAlive())
				bomb2.OnShow(m, kirby);
			if (bomb3.IsAlive())
				bomb3.OnShow(m, kirby);
		}
		else
		{
			if (m->isEmpty(GetX1() + goRight.Width() / 2, GetY2() + 1)) //還在空中
			{
				if (RightOrLeft)
					downR.ShowBitmap();
				else
					downL.ShowBitmap();
			}
			else  //落地了
			{
				if (RightOrLeft)
					dieR.ShowBitmap();
				else
					dieL.ShowBitmap();
			}
		}
	}

	void King_Airplane::OnMove(Map* m, Kirby* kirby)
	{
		if (is_alive)
		{
			Attack(m,kirby);
			Hurted(kirby);

			if (RightOrLeft)
			{
				counter++;
				x += STEP_SIZE;
				if (x >= m->GetWidth() - goRight.Width())  //碰邊要回頭
					RightOrLeft = false;
			}
			else
			{
				counter++;
				x -= STEP_SIZE;
				if (x <= 0) //碰邊要回頭
					RightOrLeft = true;
			}

			y += UporDown;
			if (y <= 20)
				UporDown = 1;
			else if(y >= 250)
				UporDown = -1;

			if (counter == 90 && !bomb1.IsAlive())
				bomb1.Init(x, (GetY1() + GetY2()) / 2);
			else if (counter == 180 && !bomb2.IsAlive())
				bomb2.Init(x, (GetY1() + GetY2()) / 2);
			else if (counter == 270 && !bomb3.IsAlive())
				bomb3.Init(x, (GetY1() + GetY2()) / 2);

			if (counter == 270)
				counter = 0;
			
			if (bomb1.IsAlive())
				bomb1.OnMove(m, kirby);
			if (bomb2.IsAlive())
				bomb2.OnMove(m, kirby);
			if (bomb3.IsAlive())
				bomb3.OnMove(m, kirby);
		}
		else
		{
			if (m->isEmpty(GetX1() + goRight.Width() / 2, GetY2())) //墜落
				y += STEP_SIZE;
		}
	}

	void King_Airplane::Initialize(int sx, int sy)
	{
		x = sx;
		y = sy;
		hp = 30;
		counter = 0;
		UporDown = 1;
		is_alive = true;
		is_sucked = false;
		RightOrLeft = false;
	}

	void King_Airplane::Attack(Map* m, Kirby* kirby)
	{
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && kirby->IsAlive())
			kirby->Hurted(m);
	}

	int King_Airplane::GetX2()
	{
		return x + goRight.Width();
	}

	int King_Airplane::GetY2()
	{
		return y + goRight.Height();
	}
}