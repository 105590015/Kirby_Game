#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "NormalMonster.h"
#include "Monster_State.h"

namespace game_framework {
	NormalMonster::NormalMonster() : Enemy()
	{
	}

	void NormalMonster::Initialize(int ox, int oy)
	{
		RightOrLeft = true;
		x = ox;
		y = oy;
		hp = 10;
		count = 0;
		velocity = 2;
		is_alive = true;
		is_sucked = false;
		IsKing = false;
		monsterState = new WalkLeftState();
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
		if (monsterState != nullptr)
			monsterState->HandleDraw(m, kirby, this);
	}

	void NormalMonster::OnMove(Map *m, Kirby *kirby)
	{
		if (is_alive)
		{
			Hurted(kirby);
			Sucked(kirby);		
			if(!is_sucked)
				Attack(m, kirby);
			if (is_sucked)
			{
				if (x > (kirby->GetX1() + kirby->GetX2()) / 2)
					x -= 3;
				else
					x += 3;
				if (y > kirby->GetY1())
					y -= 3;
				else
					y += 3;
				if (HitRectangle(kirby->GetX1() + 10, kirby->GetY1() + 10, kirby->GetX2() - 10, kirby->GetY2() - 10))
				{
					kirby->SetBig(true);
					kirby->SetEat(0);
					is_alive = false;
				}
			}
			else if (is_alive && !is_sucked && !RightOrLeft)
			{
				if (!m->isEmpty(GetX1() - 1, GetY1() + goLeft.Height() / 2)) //走到限制區域最左要掉頭
					RightOrLeft = true;
				else
					x -= 1;
			}
			else if (is_alive && !is_sucked && RightOrLeft)
			{
				if (!m->isEmpty(GetX2() + 1, GetY2() - goLeft.Height() / 2))  //走到限制區域最右要掉頭
					RightOrLeft = false;
				else
					x += 1;
			} 
			if (is_alive && !is_sucked && m->isEmpty(GetX1(), GetY2() + velocity) && m->isEmpty(GetX2(), GetY2() + velocity))  //地吸引力
			{
				count++;
				y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				if (velocity < 5 && count == 30)
				{
					velocity++; // 受重力影響，下次的下降速度增加
					count = 0;
				}
			}
			else if (m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1))  // 當y座標還沒碰到地板
				y += 1;
			else
			{
				velocity = 2; // 重設重力加速度
				count = 0;
			}
		}
	}

	void NormalMonster::Attack(Map *m, Kirby* kirby)
	{
		if (HitRectangle(kirby->GetX1(), kirby->GetY1(), kirby->GetX2(), kirby->GetY2()) && !kirby->IsKick())
			kirby->Hurted(m);
	}
}