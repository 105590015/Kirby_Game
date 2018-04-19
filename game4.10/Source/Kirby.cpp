#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby.h"

namespace game_framework {
	Kirby::Kirby()
	{
	}

	int Kirby::GetX1()
	{
		return x;
	}

	int Kirby::GetY1()
	{
		return y;
	}

	int Kirby::GetX2()
	{
		return x + originR.Width();
	}

	int Kirby::GetY2()
	{
		return y + originR.Height();
	}

	void Kirby::Initialize(int px,int py)  //設定在腳色在螢幕的初始位置
	{
		const int X_POS = px;
		const int Y_POS = py;
		x = X_POS;
		y = Y_POS;
		hp = 5;
		jumpDistance = 60;
		kickDistance = 48;
		exhaleDelay = 10;
		gasDistance = startDistance = 0;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isSpace = isJump = isAttack = isKick = isFly = isHurted = isSuck = isBig = isSwallow = isRunning = false;
		isAlive = rightOrLeft = true;
		gas.LoadBitmap();
		start.LoadBitmap();
	}

	bool Kirby::IsAlive()
	{
		return isAlive;
	}

	bool Kirby::IsFly()
	{
		return isFly;
	}

	bool Kirby::IsKick()
	{
		return isKick;
	}

	bool Kirby::IsSuck()
	{
		return isSuck;
	}

	void Kirby::LoadBitmap()
	{
		originR.LoadBitmap(".\\RES\\Kirby\\KB_R_0.bmp", RGB(255, 255, 255));
		originL.LoadBitmap(".\\RES\\Kirby\\KB_L_0.bmp", RGB(255, 255, 255));
		exhaleR.LoadBitmap(".\\RES\\Kirby\\KB_Exhale_R.bmp", RGB(255, 255, 255));
		exhaleL.LoadBitmap(".\\RES\\Kirby\\KB_Exhale_L.bmp", RGB(255, 255, 255));
		jumpR.LoadBitmap(".\\RES\\Kirby\\KB_Jump_R.bmp", RGB(255, 255, 255));
		jumpL.LoadBitmap(".\\RES\\Kirby\\KB_Jump_L.bmp", RGB(255, 255, 255));
		downR.LoadBitmap(".\\RES\\Kirby\\KB_Down_R.bmp", RGB(255, 255, 255));
		downL.LoadBitmap(".\\RES\\Kirby\\KB_Down_L.bmp", RGB(255, 255, 255));
		landingL.LoadBitmap(".\\RES\\Kirby\\KB_Landing_L.bmp", RGB(255, 255, 255));
		landingR.LoadBitmap(".\\RES\\Kirby\\KB_Landing_R.bmp", RGB(255, 255, 255));
		downAttackL.LoadBitmap(".\\RES\\Kirby\\KB_DownAttack_L.bmp", RGB(255, 255, 255));
		downAttackR.LoadBitmap(".\\RES\\Kirby\\KB_DownAttack_R.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_1.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_2.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_3.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_4.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_5.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_6.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_7.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_8.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_9.bmp", RGB(255, 255, 255));
		goL.AddBitmap(".\\RES\\Kirby\\KB_L_10.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_1.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_2.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_3.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_4.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_5.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_6.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_7.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_8.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_9.bmp", RGB(255, 255, 255));
		goR.AddBitmap(".\\RES\\Kirby\\KB_R_10.bmp", RGB(255, 255, 255));
		prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_1.bmp", RGB(255, 255, 255));
		prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_2.bmp", RGB(255, 255, 255));
		prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_3.bmp", RGB(255, 255, 255));
		prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_4.bmp", RGB(255, 255, 255));
		prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_5.bmp", RGB(255, 255, 255));
		flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_6.bmp", RGB(255, 255, 255));
		flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_7.bmp", RGB(255, 255, 255));
		flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_8.bmp", RGB(255, 255, 255));
		flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_9.bmp", RGB(255, 255, 255));
		flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_10.bmp", RGB(255, 255, 255));
		flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_11.bmp", RGB(255, 255, 255));
		prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_1.bmp", RGB(255, 255, 255));
		prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_2.bmp", RGB(255, 255, 255));
		prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_3.bmp", RGB(255, 255, 255));
		prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_4.bmp", RGB(255, 255, 255));
		prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_5.bmp", RGB(255, 255, 255));
		flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_6.bmp", RGB(255, 255, 255));
		flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_7.bmp", RGB(255, 255, 255));
		flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_8.bmp", RGB(255, 255, 255));
		flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_9.bmp", RGB(255, 255, 255));
		flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_10.bmp", RGB(255, 255, 255));
		flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_11.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_1.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_2.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_3.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_4.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_1.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_2.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_3.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_4.bmp", RGB(255, 255, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_0.bmp", RGB(207,176,255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_1.bmp", RGB(207, 176, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_2.bmp", RGB(207, 176, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_3.bmp", RGB(207, 176, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_4.bmp", RGB(207, 176, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_5.bmp", RGB(207, 176, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_6.bmp", RGB(207, 176, 255));
		runL.AddBitmap(".\\RES\\Kirby\\RUN_L_7.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_0.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_1.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_2.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_3.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_4.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_5.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_6.bmp", RGB(207, 176, 255));
		runR.AddBitmap(".\\RES\\Kirby\\RUN_R_7.bmp", RGB(207, 176, 255));
		suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_1.bmp", RGB(255, 255, 255));
		suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_2.bmp", RGB(255, 255, 255));
		suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_3.bmp", RGB(255, 255, 255));
		suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_4.bmp", RGB(255, 255, 255));
		suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_1.bmp", RGB(255, 255, 255));
		suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_2.bmp", RGB(255, 255, 255));
		suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_3.bmp", RGB(255, 255, 255));
		suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_4.bmp", RGB(255, 255, 255));
		// 含東西的卡比
		bigOriginR.LoadBitmap(".\\RES\\Kirby\\BKB_R_0.bmp", RGB(255, 255, 255));
		bigOriginL.LoadBitmap(".\\RES\\Kirby\\BKB_L_0.bmp", RGB(255, 255, 255));
		bigJumpR.LoadBitmap(".\\RES\\Kirby\\BKB_Jump_R.bmp", RGB(255, 255, 255));
		bigJumpL.LoadBitmap(".\\RES\\Kirby\\BKB_Jump_L.bmp", RGB(255, 255, 255));
		bigLandingR.LoadBitmap(".\\RES\\Kirby\\BKB_Landing_R.bmp", RGB(255, 255, 255));
		bigLandingL.LoadBitmap(".\\RES\\Kirby\\BKB_Landing_L.bmp", RGB(255, 255, 255));
		threwR.LoadBitmap(".\\RES\\Kirby\\BKB_Threw_R.bmp", RGB(255, 255, 255));
		threwL.LoadBitmap(".\\RES\\Kirby\\BKB_Threw_L.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_1.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_2.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_3.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_4.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_5.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_6.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_7.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_8.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_9.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_10.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_11.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_12.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_13.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_14.bmp", RGB(255, 255, 255));
		bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_15.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_1.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_2.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_3.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_4.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_5.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_6.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_7.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_8.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_9.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_10.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_11.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_12.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_13.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_14.bmp", RGB(255, 255, 255));
		bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_15.bmp", RGB(255, 255, 255));
		swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_1.bmp", RGB(255, 255, 255));
		swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_2.bmp", RGB(255, 255, 255));
		swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_3.bmp", RGB(255, 255, 255));
		swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_4.bmp", RGB(255, 255, 255));
		swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_5.bmp", RGB(255, 255, 255));
		swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_1.bmp", RGB(255, 255, 255));
		swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_2.bmp", RGB(255, 255, 255));
		swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_3.bmp", RGB(255, 255, 255));
		swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_4.bmp", RGB(255, 255, 255));
		swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_5.bmp", RGB(255, 255, 255));
	}

	void Kirby::OnMove(Map *m)
	{
		//被攻擊且不是在空中也沒超出邊界時
		if (isHurted)
		{
			isFly = false;
			if (m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
				y++;
			if (rightOrLeft && m->isEmpty(GetX1() - STEP_SIZE, GetY1() + hurtedR.Height() / 2) && x - STEP_SIZE >= 0)
				x -= STEP_SIZE;
			else if(!rightOrLeft && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - hurtedL.Height() / 2) && x + STEP_SIZE <= m->GetWidth() - goR.Width())
				x += STEP_SIZE;
		}
		else
		{
			if (isMovingLeft && !isSuck && !isSwallow)
			{
				rightOrLeft = false;        //設定面向左邊
				//先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
				if (m->isEmpty(GetX1() - STEP_SIZE, GetY1() + goL.Height() / 2) && !isMovingDown && (isFly || !isMovingUp))  
				{
					if (x <= 0) //邊界
						x = 0;
					else if (isRunning && !isFly && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
						x -= STEP_SIZE * 2;
					else
						x -= STEP_SIZE;
				}
			}
			else if (isMovingRight && !isSuck && !isSwallow)
			{
				rightOrLeft = true;          //設定面向右邊
				//先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
				if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - goR.Height() / 2) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x >= m->GetWidth() - goR.Width())  //邊界
						x = m->GetWidth() - goR.Width();
					else if (isRunning && !isFly && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
						x += STEP_SIZE * 2;
					else
						x += STEP_SIZE;
				}
			}
			if (isMovingUp && !isBig)
			{
				if (isFly && m->isEmpty(GetX1() + flyR.Width() / 2, GetY1() - STEP_SIZE))  //判斷飛行中上面是否可走
				{
					if (y <= 0)  //邊界
						y = 0;
					else
						y -= STEP_SIZE;
				}
			}
			if (isJump)
			{
				jumpDistance-=3;
				if (m->isEmpty(GetX1() + jumpR.Width() / 2, GetY1() - 3))  //會不會撞到頭
					y -= 3;
				if (jumpDistance == 0)
				{
					jumpDistance = 60;
					isJump = false;
				}
			}
		}
		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))  //地吸引力
		{
			if (isFly)
				y += 1;
			else
			{
				if (y >= m->GetHeight() - goR.Height())
					y = m->GetHeight() - goR.Height();
				else
					y += STEP_SIZE;
			}
		}
	}

	void Kirby::OnShow(Map *m)
	{
		if (isAlive) {    //全部動畫位子設定
			originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			goL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			goR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			prepareFlyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			prepareFlyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			flyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			flyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			exhaleR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			exhaleL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			jumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			jumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			landingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			landingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			downAttackR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			hurtedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			hurtedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			runR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			runL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			suckL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			suckR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigOriginR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigOriginL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigJumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigJumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigLandingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigLandingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			threwR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			threwL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigGoL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bigGoR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			swallowR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			swallowL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			Attack(m);
		}

		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			prepareFlyR.Reset();
			prepareFlyL.Reset();
		}

		if (isHurted)   // 被攻擊
		{
			isBig = false;
			if (rightOrLeft)
			{
				hurtedR.OnMove();
				hurtedR.OnShow();
			}
			else
			{
				hurtedL.OnMove();
				hurtedL.OnShow();
			}
			if (hurtedL.IsFinalBitmap() || hurtedR.IsFinalBitmap())
			{
				isHurted = false;
				hurtedL.Reset();
				hurtedR.Reset();
			}
		}
		else if (isBig)
		{
			if (isSuck)
				isAttack = false;
			if (isJump)   //跳躍
			{
				if (rightOrLeft)
					bigJumpR.ShowBitmap();
				else
					bigJumpL.ShowBitmap();
			}
			else if (isAttack)  //吐怪
			{
				if (rightOrLeft)
					threwR.ShowBitmap();
				else
					threwL.ShowBitmap();
				if (!isSuck)
					isBig = false;
			}
			else if (isSwallow || (isMovingDown && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)))   //吞食
			{		
				isSwallow = true;
				if (rightOrLeft)
				{
					swallowR.OnMove();
					swallowR.OnShow();
				}
				else
				{
					swallowL.OnMove();
					swallowL.OnShow();
				}
				if (swallowR.IsFinalBitmap() || swallowL.IsFinalBitmap())
				{
					isSwallow = false;
					isBig = false;
				}	
			}
			else if (m->isEmpty(GetX2() - bigOriginR.Width() / 2, GetY2() + 1))  //自由落體
			{
				if (rightOrLeft)
					bigLandingR.ShowBitmap();
				else
					bigLandingL.ShowBitmap();
			}
			else if (isMovingLeft)   //向左走
			{
				if (isRunning)
					bigGoL.SetDelayCount(2);
				else
					bigGoL.SetDelayCount(10);
				bigGoL.OnShow();
				bigGoL.OnMove();
			}
			else if (isMovingRight)   //向右走
			{
				if (isRunning)
					bigGoR.SetDelayCount(2);
				else
					bigGoR.SetDelayCount(10);
				bigGoR.OnShow();
				bigGoR.OnMove();
			}
			else if (rightOrLeft)   //面相右
				bigOriginR.ShowBitmap();
			else if (!rightOrLeft)  //面相左
				bigOriginL.ShowBitmap();
		}
		else
		{
			if (isJump)   //跳躍
			{
				if(rightOrLeft)
					jumpR.ShowBitmap();
				else
					jumpL.ShowBitmap();
			}
			else if (isSpace && isFly)   //吐氣
			{
				exhaleDelay--;
				if(rightOrLeft)
					exhaleR.ShowBitmap();
				else
					exhaleL.ShowBitmap();
				if (exhaleDelay == 0)
				{
					exhaleDelay = 10;
					prepareFlyR.Reset();
					prepareFlyL.Reset();
					isFly = false;
					isSpace = false;
				}
			}
			else if (isMovingUp)
			{
				if (prepareFlyR.IsFinalBitmap() || prepareFlyL.IsFinalBitmap())   //飛行前吸氣
				{
					isFly = true;
					if (rightOrLeft)
					{
						flyR.OnShow();
						flyR.OnMove();
					}
					else
					{
						flyL.OnShow();
						flyL.OnMove();
					}
				}
				else
				{
					if (rightOrLeft)
					{
						prepareFlyR.OnShow();
						prepareFlyR.OnMove();
					}
					else
					{
						prepareFlyL.OnShow();
						prepareFlyL.OnMove();
					}
				}
			}
			else if (isFly)  //飛行中地吸引力
			{
				if (rightOrLeft)
				{
					flyR.OnShow();
					flyR.OnMove();
				}
				else
				{
					flyL.OnShow();
					flyL.OnMove();
				}
			}
			else if (!isFly && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))  //自由落體
			{
				if (rightOrLeft)
					landingR.ShowBitmap();
				else
					landingL.ShowBitmap();
			}
			else if (isKick && !isFly)   //踢擊
			{
				if(rightOrLeft)
					downAttackR.ShowBitmap();
				else
					downAttackL.ShowBitmap();
			}
			else if (isAttack)  //吸怪
			{
				isSuck = true;
				if (rightOrLeft)
				{
					suckR.OnMove();
					suckR.OnShow();
				}
				else
				{
					suckL.OnMove();
					suckL.OnShow();
				}
			}
			else if (isMovingDown && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))   //縮小
			{
				if(rightOrLeft)
					downR.ShowBitmap();
				else
					downL.ShowBitmap();
			}
			else if (!isFly && isRunning)  //跑
			{
				if (!rightOrLeft)
				{
					runL.OnShow();
					runL.OnMove();
				}
				else
				{
					runR.OnShow();
					runR.OnMove();
				}
			}
			else if (!isFly && isMovingLeft)   //一般向左走
			{
				goL.OnShow();
				goL.OnMove();
			}
			else if (!isFly && isMovingRight)   //一般向右走
			{
				goR.OnShow();
				goR.OnMove();
			}
			else if (rightOrLeft)   //面相右
				originR.ShowBitmap();
			else if (!rightOrLeft)  //面相左
				originL.ShowBitmap();
		}
	}

	void Kirby::Hurted()
	{
		hp--;
		isHurted = true;
	}

	void Kirby::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Kirby::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Kirby::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Kirby::SetMovingUp(bool flag)
	{
		if (isBig)
			isMovingUp = false;
		else
			isMovingUp = flag;
	}

	void Kirby::SetSpace(bool flag)
	{
		isSpace = flag;
	}

	void Kirby::SetJump(bool flag)
	{
		isJump = flag;
	}

	void Kirby::SetAttack(bool flag)
	{
		isAttack = flag;
	}

	void Kirby::SetSuck(bool flag)
	{
		isSuck = flag;
	}

	void Kirby::SetBig(bool flag)
	{
		isBig = flag;
	}

	void Kirby::SetRun(bool flag) {
		isRunning = flag;
	}

	void Kirby::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Kirby::Attack(Map *m)
	{
		//------空氣彈------
		if (isFly && isSpace)
		{
			gas.SetXY(x, y);
			gasDistance = 70;
			bulletDirection = rightOrLeft;
		}
		if (gasDistance != 0)
		{
			gasDistance -= STEP_SIZE;
			gas.OnMove(m, bulletDirection);
			gas.OnShow(m);
		}

		//------星星------
		if (isBig && isAttack && !isSuck)
		{
			start.SetXY(x, y);
			startDistance = 150;
			bulletDirection = rightOrLeft;
		}
		if (startDistance != 0)
		{
			startDistance -= STEP_SIZE;
			start.OnMove(m, bulletDirection);
			start.OnShow(m);
		}

		//------踢擊------
		if (!isFly && !isBig && (isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			kickDistance -= 3;
			if (rightOrLeft && m->isEmpty(GetX2() + 3, GetY2() - 2) && x + 3 <= m->GetWidth() - downAttackR.Width())  //右邊會不會踢牆(y-2是補償圖檔大小的差異)
				x += 3;
			else if (!rightOrLeft && m->isEmpty(GetX1() - 3, GetY2() - 2) && x - 3 >= 0)  //左邊會不會踢牆(y-2是補償圖檔大小的差異)
				x -= 3;
			//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
			if (kickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
			{
				kickDistance = 48;
				isKick = false;
			}
		}
	}
}