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
		flyDelay = 46;
		JumpDelay = 30;
		KickDistance = 40;
		ExhaleDelay = 10;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isSpace = isJump = isAttack = isKick = isFly = false;
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

	void Kirby::LoadBitmap()
	{
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
	}

	void Kirby::OnMove(Map *m)
	{
		if (isMovingLeft)
		{
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
			}
		}
		else if (isMovingRight)
		{
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
		}
		if (isMovingUp)
		{
			if (flyDelay > 0)             //飛行前的倒數
				flyDelay--;
			else if (m->isEmpty(GetX1() + FlyRight.Width() / 2, GetY1() - STEP_SIZE))  //判斷上面是否可走
			{
				if (y <= 0)  //邊界
					y = 0;
				else
					y -= STEP_SIZE;
			}
		}
		if (isJump)
		{
			JumpDelay--;
			if (m->isEmpty(GetX1() + JumpRight.Width() / 2, GetY1() - 4))  //會不會撞到頭
				y -= 4;
			if (JumpDelay == 0)
			{
				JumpDelay = 30;
				isJump = false;
			}
		}
		if (isMovingDown && (isAttack || isKick) && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			KickDistance-=4;
			if (RightOrLeft && m->isEmpty(GetX2() + 4, GetY2() - 2))        //右邊會不會踢牆(y-2是補償圖檔大小的差異)
				x += 4;
			else if (!RightOrLeft && m->isEmpty(GetX1() - 4, GetY2() - 2))  //左邊會不會踢牆(y-2是補償圖檔大小的差異)
				x -= 4;
			if (KickDistance == 0)
			{
				KickDistance = 40;
				isKick = false;
			}
		}
		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //地吸引力
		{
			if (isFly)
				y += 1;
			else {
				if (y >= m->GetHeight() - GoRight.Height()) {
					y = m->GetHeight() - GoRight.Height();
				}

				y += STEP_SIZE;
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
			RunRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RunLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		}
		if (isJump && RightOrLeft)         //面向右跳
			JumpRight.ShowBitmap();
		else if (isJump && !RightOrLeft)   //面向左跳
			JumpLeft.ShowBitmap();
		else if (isSpace && RightOrLeft && isFly)   //向右吐氣
		{
			ExhaleDelay--;
			ExhaleRight.ShowBitmap();
			if (ExhaleDelay == 0)
			{
				flyDelay = 46;
				ExhaleDelay = 10;
				PrepareFlyRight.Reset();
				PrepareFlyLeft.Reset();
				isFly = false;
				isSpace = false;
			}
		}
		else if (isSpace && !RightOrLeft && isFly)  //向左吐氣
		{
			ExhaleDelay--;
			ExhaleLeft.ShowBitmap();
			if (ExhaleDelay == 0)
			{
				flyDelay = 46;
				ExhaleDelay = 10;
				PrepareFlyRight.Reset();
				PrepareFlyLeft.Reset();
				isFly = false;
				isSpace = false;
			}
		}
		else if (isMovingUp && RightOrLeft)      //面相右按上
		{
			if (flyDelay > 0)              //飛行前的倒數
			{
				PrepareFlyRight.OnShow();
				PrepareFlyRight.OnMove();
				flyDelay--;
			}
			else
			{
				isFly = true;
				FlyRight.OnShow();
				FlyRight.OnMove();
			}
		}
		else if (isMovingUp && !RightOrLeft)   //面相左按上
		{
			if (flyDelay > 0)               //飛行前倒數
			{
				PrepareFlyLeft.OnShow();
				PrepareFlyLeft.OnMove();
				flyDelay--;
			}
			else
			{
				isFly = true;
				FlyLeft.OnShow();
				FlyLeft.OnMove();
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
		{
			GoLeft.OnShow();
			GoLeft.OnMove();
		}
		else if (isMovingRight && !isFly)  //一般向右走
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
			flyDelay = 46;
		}
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

	bool Kirby::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = x;				// 卡比左上角x座標
		int y1 = y;				// 卡比左上角y座標
		int x2 = x1 + originR.Width();	// 卡比右下角x座標
		int y2 = y1 + originR.Height();	// 卡比右下角y座標
		// 檢測卡比的矩形與參數矩形是否有交集
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}
}