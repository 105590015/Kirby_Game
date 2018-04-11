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
		JumpDistance = 60;
		KickDistance = 42;
		ExhaleDelay = 10;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isSpace = isJump = isAttack = isKick = isFly = isHurted = false;
		is_alive = RightOrLeft = true;
		isRunning = false;
	}

	bool Kirby::IsAlive()
	{
		return is_alive;
	}

	bool Kirby::IsFly()
	{
		return isFly;
	}

	bool Kirby::IsKick()
	{
		return isKick;
	}

	void Kirby::LoadBitmap()
	{
<<<<<<< HEAD
		originR.LoadBitmap(".\\RES\\Kirby\\KB_R_0.bmp", RGB(255, 255, 255));
		originL.LoadBitmap(".\\RES\\Kirby\\KB_L_0.bmp", RGB(255, 255, 255));
		ExhaleRight.LoadBitmap(".\\RES\\Kirby\\KB_Exhale_R.bmp", RGB(255, 255, 255));
		ExhaleLeft.LoadBitmap(".\\RES\\Kirby\\KB_Exhale_L.bmp", RGB(255, 255, 255));
		JumpRight.LoadBitmap(".\\RES\\Kirby\\KB_Jump_R.bmp", RGB(255, 255, 255));
		JumpLeft.LoadBitmap(".\\RES\\Kirby\\KB_Jump_L.bmp", RGB(255, 255, 255));
		DownRight.LoadBitmap(".\\RES\\Kirby\\KB_Down_R.bmp", RGB(255, 255, 255));
		DownLeft.LoadBitmap(".\\RES\\Kirby\\KB_Down_L.bmp", RGB(255, 255, 255));
		LandingLeft.LoadBitmap(".\\RES\\Kirby\\KB_Landing_L.bmp", RGB(255, 255, 255));
		LandingRight.LoadBitmap(".\\RES\\Kirby\\KB_Landing_R.bmp", RGB(255, 255, 255));
		downAttackL.LoadBitmap(".\\RES\\Kirby\\KB_DownAttack_L.bmp", RGB(255, 255, 255));
		downAttackR.LoadBitmap(".\\RES\\Kirby\\KB_DownAttack_R.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_1.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_2.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_3.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_4.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_5.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_6.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_7.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_8.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_9.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(".\\RES\\Kirby\\KB_L_10.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_1.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_2.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_3.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_4.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_5.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_6.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_7.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_8.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_9.bmp", RGB(255, 255, 255));
		GoRight.AddBitmap(".\\RES\\Kirby\\KB_R_10.bmp", RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_1.bmp", RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_2.bmp", RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_3.bmp", RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_4.bmp", RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_5.bmp", RGB(255, 255, 255));
		FlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_6.bmp", RGB(255, 255, 255));
		FlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_7.bmp", RGB(255, 255, 255));
		FlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_8.bmp", RGB(255, 255, 255));
		FlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_9.bmp", RGB(255, 255, 255));
		FlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_10.bmp", RGB(255, 255, 255));
		FlyRight.AddBitmap(".\\RES\\Kirby\\KB_U_R_11.bmp", RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_1.bmp", RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_2.bmp", RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_3.bmp", RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_4.bmp", RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_5.bmp", RGB(255, 255, 255));
		FlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_6.bmp", RGB(255, 255, 255));
		FlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_7.bmp", RGB(255, 255, 255));
		FlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_8.bmp", RGB(255, 255, 255));
		FlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_9.bmp", RGB(255, 255, 255));
		FlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_10.bmp", RGB(255, 255, 255));
		FlyLeft.AddBitmap(".\\RES\\Kirby\\KB_U_L_11.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_1.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_2.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_3.bmp", RGB(255, 255, 255));
		hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_4.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_1.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_2.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_3.bmp", RGB(255, 255, 255));
		hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_4.bmp", RGB(255, 255, 255));
=======
		originR.LoadBitmap(IDB_KB_R_0, RGB(255, 255, 255));
		originL.LoadBitmap(IDB_KB_L_0, RGB(255, 255, 255));
		ExhaleRight.LoadBitmap(IDB_KB_Exhale_R, RGB(255, 255, 255));
		ExhaleLeft.LoadBitmap(IDB_KB_Exhale_L, RGB(255, 255, 255));
		JumpRight.LoadBitmap(IDB_KB_Jump_R, RGB(255, 255, 255));
		JumpLeft.LoadBitmap(IDB_KB_Jump_L, RGB(255, 255, 255));
		DownRight.LoadBitmap(IDB_KB_Down_R, RGB(255, 255, 255));
		DownLeft.LoadBitmap(IDB_KB_Down_L, RGB(255, 255, 255));
		LandingLeft.LoadBitmap(".\\RES\\KB_Landing_L.bmp", RGB(255, 255, 255));
		LandingRight.LoadBitmap(".\\RES\\KB_Landing_R.bmp", RGB(255, 255, 255));
		downAttackL.LoadBitmap(".\\RES\\KB_DownAttack_L.bmp", RGB(255, 255, 255));
		downAttackR.LoadBitmap(".\\RES\\KB_DownAttack_R.bmp", RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_1, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_2, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_3, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_4, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_5, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_6, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_7, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_8, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_9, RGB(255, 255, 255));
		GoLeft.AddBitmap(IDB_KB_L_10, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_1, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_2, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_3, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_4, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_5, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_6, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_7, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_8, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_9, RGB(255, 255, 255));
		GoRight.AddBitmap(IDB_KB_R_10, RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(IDB_KB_U_1, RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(IDB_KB_U_2, RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(IDB_KB_U_3, RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(IDB_KB_U_4, RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(IDB_KB_U_5, RGB(255, 255, 255));
		PrepareFlyRight.AddBitmap(IDB_KB_U_6, RGB(255, 255, 255));
		FlyRight.AddBitmap(IDB_KB_U_7, RGB(255, 255, 255));
		FlyRight.AddBitmap(IDB_KB_U_8, RGB(255, 255, 255));
		FlyRight.AddBitmap(IDB_KB_U_9, RGB(255, 255, 255));
		FlyRight.AddBitmap(IDB_KB_U_10, RGB(255, 255, 255));
		FlyRight.AddBitmap(IDB_KB_U_11, RGB(255, 255, 255));
		FlyRight.AddBitmap(IDB_KB_U_12, RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(IDB_KB_U_L_1, RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(IDB_KB_U_L_2, RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(IDB_KB_U_L_3, RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(IDB_KB_U_L_4, RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(IDB_KB_U_L_5, RGB(255, 255, 255));
		PrepareFlyLeft.AddBitmap(IDB_KB_U_L_6, RGB(255, 255, 255));
		FlyLeft.AddBitmap(IDB_KB_U_L_7, RGB(255, 255, 255));
		FlyLeft.AddBitmap(IDB_KB_U_L_8, RGB(255, 255, 255));
		FlyLeft.AddBitmap(IDB_KB_U_L_9, RGB(255, 255, 255));
		FlyLeft.AddBitmap(IDB_KB_U_L_10, RGB(255, 255, 255));
		FlyLeft.AddBitmap(IDB_KB_U_L_11, RGB(255, 255, 255));
		FlyLeft.AddBitmap(IDB_KB_U_L_12, RGB(255, 255, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_0.bmp", RGB(207,176,255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_1.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_2.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_3.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_4.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_5.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_6.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\RUN_L_7.bmp", RGB(207, 176, 255));	
		RunRight.AddBitmap(".\\RES\\RUN_R_0.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_1.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_2.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_3.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_4.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_5.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_6.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\RUN_R_7.bmp", RGB(207, 176, 255));
>>>>>>> 0192380022e61e8144655f8943a1f1f93256db0a
	}

	void Kirby::OnMove(Map *m)
	{
		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //地吸引力
		{
<<<<<<< HEAD
			if (isFly)
				y += 1;
			else {
				if (y >= m->GetHeight() - GoRight.Height()) {
					y = m->GetHeight() - GoRight.Height();
				}

				y += STEP_SIZE;
=======
			//以下算式的x + 320與y + 240是補地圖移動的位子;卡比的圖大小大多為20 * 20, x + 10與y + 10是將判斷碰撞的點設在卡比中心
			RightOrLeft = false;        //設定面向左邊

			if (m->isEmpty(GetX1() - STEP_SIZE, GetY1() + GoLeft.Height() / 2) && !isMovingDown && ((isMovingUp&&flyDelay < 1) || !isMovingUp)&&isRunning&&!isFly)  //先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
			{
				if (x <= 0) //邊界
					x = 0;
				else
					x -= STEP_SIZE*2;
			}

			else if (m->isEmpty(GetX1() - STEP_SIZE, GetY1() + GoLeft.Height() / 2) && !isMovingDown && ((isMovingUp&&flyDelay < 1) || !isMovingUp))  //先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
			{
				if (x <= 0) //邊界
					x = 0;
				else
					x -= STEP_SIZE;
>>>>>>> 0192380022e61e8144655f8943a1f1f93256db0a
			}
		}
		//被攻擊且不是在空中也沒超出邊界時
		if (isHurted && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1) && x >= 0 && x <= m->GetWidth() - GoRight.Width())
		{
<<<<<<< HEAD
			if (RightOrLeft)
				x -= STEP_SIZE;
			else
				x += STEP_SIZE;
=======
			RightOrLeft = true;          //設定面向右邊

			if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - GoRight.Height() / 2) && !isMovingDown && ((isMovingUp&&flyDelay < 1) || !isMovingUp)&&isRunning&&!isFly)   //先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
			{
				if (x >= m->GetWidth() - GoRight.Width())  //邊界
					x = m->GetWidth() - GoRight.Width();
				else
					x += STEP_SIZE*2;
			}

			else if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - GoRight.Height() / 2) && !isMovingDown && ((isMovingUp&&flyDelay < 1) || !isMovingUp))   //先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
			{
				if (x >= m->GetWidth() - GoRight.Width())  //邊界
					x = m->GetWidth() - GoRight.Width();
				else
					x += STEP_SIZE;
			}
>>>>>>> 0192380022e61e8144655f8943a1f1f93256db0a
		}
		else
		{
			if (isMovingLeft)
			{
				RightOrLeft = false;        //設定面向左邊
				//先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
				if (m->isEmpty(GetX1() - STEP_SIZE, GetY1() + GoLeft.Height() / 2) && !isMovingDown && (isFly || !isMovingUp))  
				{
					if (x <= 0) //邊界
						x = 0;
					else
						x -= STEP_SIZE;
				}
			}
			else if (isMovingRight)
			{
				RightOrLeft = true;          //設定面向右邊
				//先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
				if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - GoRight.Height() / 2) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x >= m->GetWidth() - GoRight.Width())  //邊界
						x = m->GetWidth() - GoRight.Width();
					else
						x += STEP_SIZE;
				}
			}
			if (isMovingUp)
			{
				if (isFly && m->isEmpty(GetX1() + FlyRight.Width() / 2, GetY1() - STEP_SIZE))  //判斷飛行中上面是否可走
				{
					if (y <= 0)  //邊界
						y = 0;
					else
						y -= STEP_SIZE;
				}
			}
			if (isJump)
			{
				JumpDistance-=3;
				if (m->isEmpty(GetX1() + JumpRight.Width() / 2, GetY1() - 3))  //會不會撞到頭
					y -= 3;
				if (JumpDistance == 0)
				{
					JumpDistance = 60;
					isJump = false;
				}
			}
			if ((isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //在地面上蹲下按攻擊
			{
				isKick = true;
				KickDistance -= 3;
				if (RightOrLeft && m->isEmpty(GetX2() + 3, GetY2() - 2))        //右邊會不會踢牆(y-2是補償圖檔大小的差異)
					x += 3;
				else if (!RightOrLeft && m->isEmpty(GetX1() - 3, GetY2() - 2))  //左邊會不會踢牆(y-2是補償圖檔大小的差異)
					x -= 3;
				//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
				if (KickDistance == 0 || x <= downAttackL.Width() || x >= m->GetWidth() - downAttackL.Width() || m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
				{
					KickDistance = 42;
					isKick = false;
				}
			}
		}
	}

	void Kirby::OnShow(Map *m)
	{
		if (is_alive) {    //全部動畫位子設定
			originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			GoLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			GoRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			PrepareFlyRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			PrepareFlyLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			FlyRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			FlyLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			ExhaleRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			ExhaleLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			JumpRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			JumpLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			DownRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			DownLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			LandingLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			LandingRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			downAttackR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
<<<<<<< HEAD
			hurtedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			hurtedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
=======
			RunRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RunLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
>>>>>>> 0192380022e61e8144655f8943a1f1f93256db0a
		}
		if (isHurted)   // 被攻擊
		{
			if (RightOrLeft)
			{
				hurtedR.OnMove();
				hurtedR.OnShow();
			}
			else
			{
				hurtedL.OnMove();
				hurtedL.OnShow();
			}
			if (hurtedL.IsFinalBitmap() || hurtedR.IsFinalBitmap() || m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
				isHurted = false;
		}
		else if (isJump)   //跳躍
		{
			if(RightOrLeft)
				JumpRight.ShowBitmap();
			else
				JumpLeft.ShowBitmap();
		}
		else if (isSpace && isFly)   //吐氣
		{
			ExhaleDelay--;
			if(RightOrLeft)
				ExhaleRight.ShowBitmap();
			else
				ExhaleLeft.ShowBitmap();
			if (ExhaleDelay == 0)
			{
				ExhaleDelay = 10;
				PrepareFlyRight.Reset();
				PrepareFlyLeft.Reset();
				isFly = false;
				isSpace = false;
			}
		}
		else if (isMovingUp)
		{
			if (PrepareFlyRight.IsFinalBitmap() || PrepareFlyLeft.IsFinalBitmap())   //飛行前吸氣
			{
				isFly = true;
				if (RightOrLeft)
				{
					FlyRight.OnShow();
					FlyRight.OnMove();
				}
				else
				{
					FlyLeft.OnShow();
					FlyLeft.OnMove();
				}
			}
			else
			{
				if (RightOrLeft)
				{
					PrepareFlyRight.OnShow();
					PrepareFlyRight.OnMove();
				}
				else
				{
					PrepareFlyLeft.OnShow();
					PrepareFlyLeft.OnMove();
				}
			}
		}
		else if (isFly)  //飛行中地吸引力
		{
			if (RightOrLeft)
			{
				FlyRight.OnShow();
				FlyRight.OnMove();
			}
			else
			{
				FlyLeft.OnShow();
				FlyLeft.OnMove();
			}
		}
		else if (!isFly && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))  //自由落體
		{
			if (RightOrLeft)
				LandingRight.ShowBitmap();
			else
				LandingLeft.ShowBitmap();
		}
<<<<<<< HEAD
		else if (isKick)   //踢擊
		{
			if(RightOrLeft)
				downAttackR.ShowBitmap();
			else
				downAttackL.ShowBitmap();
		}
		else if (isMovingDown && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))   //縮小
		{
			if(RightOrLeft)
				DownRight.ShowBitmap();
			else
				DownLeft.ShowBitmap();
		}

		else if (!isFly && isMovingLeft)   //一般向左走
=======
		else if (isKick && RightOrLeft)    //向右踢擊
			downAttackR.ShowBitmap();
		else if (isKick && !RightOrLeft)   //向左踢擊
			downAttackL.ShowBitmap();
		else if (isMovingDown && RightOrLeft && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))  //面向右縮小
			DownRight.ShowBitmap();
		else if (isMovingDown && !RightOrLeft && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //面向左縮小
			DownLeft.ShowBitmap();
		else if (isMovingLeft && !isFly&&isRunning)  //向左跑
		{
			RunLeft.OnShow();
			RunLeft.OnMove();
		}
		else if (isMovingRight && !isFly&&isRunning)  //向右跑
		{
			RunRight.OnShow();
			RunRight.OnMove();
		}
		else if (isMovingLeft && !isFly)  //一般向左走
>>>>>>> 0192380022e61e8144655f8943a1f1f93256db0a
		{
			GoLeft.OnShow();
			GoLeft.OnMove();
		}
		else if(!isFly && isMovingRight)   //一般向右走
		{
			GoRight.OnShow();
			GoRight.OnMove();
		}
		else if (RightOrLeft)   //面相右
			originR.ShowBitmap();
		else if (!RightOrLeft)  //面相左
			originL.ShowBitmap();
		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			PrepareFlyRight.Reset();
			PrepareFlyLeft.Reset();
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

	void Kirby::SetRun(bool flag) {
		isRunning = flag;
	}

	void Kirby::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}
}