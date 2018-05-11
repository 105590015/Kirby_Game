/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	StartAnimation.AddBitmap(".\\RES\\Start\\title_0.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_1.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_2.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_3.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_4.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_5.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_6.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_7.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_8.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_9.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_10.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_11.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_12.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_13.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_14.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_15.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_16.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_17.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_18.bmp");
	StartAnimation.AddBitmap(".\\RES\\Start\\title_19.bmp");
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE)
		GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
	else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// 關閉遊戲
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{	
	
	StartAnimation.SetTopLeft(0, 0);
	StartAnimation.OnMove();
	StartAnimation.OnShow();


	// /*Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好*/
	//CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	//fp=pDC->SelectObject(&f);					// 選用 font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	//if (ENABLE_GAME_PAUSE)
	//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	//pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	//CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC*/

}								

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
}

void CGameStateOver::OnBeginState()
{
}

void CGameStateOver::OnInit()
{
}

void CGameStateOver::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over !");
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)
{	
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
	map[0].Initialize();
	map[1].Initialize();
	
	kirby.Initialize(640,400);

	door[0].Initialize(123,  37, 1, 0, &door1[0]);
	door[1].Initialize(621,  37, 1, 0, &door1[0]);
	door[2].Initialize(1118,  37, 1, 0, &door1[0]);
	door[3].Initialize(83, 328, 1, 0, &door1[0]);
	door[4].Initialize(248, 369, 1, 0, &door1[0]);
	door[5].Initialize(993, 367, 1, 0, &door1[0]);
	door[6].Initialize(1159, 326, 1, 0, &door1[1]);
	door[7].Initialize(993, 367, 1, 0, &door1[0]);
	door[8].Initialize(993, 367, 1, 0, &door1[0]);
	door[9].Initialize(993, 367, 1, 0, &door1[0]);

	door1[0].Initialize(30, 425, 0,1, &door[5]);
	door1[1].Initialize(4450, 350, 0, 1, &door[6]);
<<<<<<< HEAD
=======

	normalMonster[0].Initialize(50, 80, 50, 200, false);
	normalMonster[1].Initialize(550, 80, 550, 670, false);
	normalMonster[2].Initialize(1020, 80, 1015, 1188, false);
	normalMonster[3].Initialize(1240, 60, 0, 60, false);
	normalMonster[4].Initialize(1614, 60, 370, 870, false);
	normalMonster[5].Initialize(2190, 60, 1170, 1230, false);

	spark.Initialize(640, 80);



	CAudio::Instance()->Play(AUDIO_BACKGROUND, true);
>>>>>>> 277b838514a2591e1c7221f0c8d96f6957c84bc7

	normalMonster1.Initialize(417, 467, 287, 571, false);
	normalMonster2.Initialize(947, 467, 795, 1125, false);
	normalMonster3.Initialize(2459, 517, 2367, 2571, false);
	normalMonster4.Initialize(2903, 517, 2725, 3073, false);
	normalMonster5.Initialize(3495, 59, 3377, 3635, false);
	normalMonster6.Initialize(3745, 477, 3659, 4151, false);
	spark1.Initialize(675, 393);
	spark2.Initialize(1673, 163);
	spark3.Initialize(3247, 269);
	spark4.Initialize(4045, 477);

	CAudio::Instance()->Play(AUDIO_BACKGROUND, true);
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	index->OnMove(kirby.GetX1(), kirby.GetY1());
	if (Istransiting) {
		Transition.OnMove();
		Transition.SetDelayCount(8);
	}
	
	else {
		
		if (kirby.IsAlive())
			kirby.OnMove(index);
		if (mapNum == 0)
		{
			for (int i = 0; i < 10; i++) {
				door[i].OnMove();
				if (door[i].IsEnter(&kirby)) {
					Istransiting = true;
					Transition.Reset();
					gate = &door[i];
					//mapNum = door.GetMapNum();
					//index = &map[1];
					//kirby.SetXY(door.GetNextX()-50,door.GetNextY());
				}
			}
		}
		if (mapNum == 1) {
<<<<<<< HEAD
			monster[0] = &normalMonster1;
			monster[1] = &normalMonster2;
			monster[2] = &normalMonster3;
			monster[3] = &normalMonster4;
			monster[4] = &normalMonster5;
			monster[5] = &normalMonster6;
			monster[6] = &spark1;
			monster[7] = &spark2;
			monster[8] = &spark3;
			monster[9] = &spark4;
			for (int m = 0; m < 10; m++)
				monster[m]->OnMove(index, &kirby);
=======
			
			spark.OnMove(index, &kirby);
			normalMonster[0].OnMove(index, &kirby);
			normalMonster[1].OnMove(index, &kirby);
			normalMonster[2].OnMove(index, &kirby);
			normalMonster[3].OnMove(index, &kirby);
			normalMonster[4].OnMove(index, &kirby);
			normalMonster[5].OnMove(index, &kirby);
>>>>>>> 277b838514a2591e1c7221f0c8d96f6957c84bc7
			for (int i = 0; i < 2; i++) {
				door1[i].OnMove();
				if (door1[i].IsEnter(&kirby)) {
					Istransiting = true;
					Transition.Reset();
					gate = &door1[i];
					//mapNum = door1.GetMapNum();
					//index = &map[0];
					//kirby.SetXY(door1.GetNextX()-50, door1.GetNextY());
				}
			}
		}
	}

	if (Transition.IsFinalBitmap()) {
		Istransiting = false;
	}

	if (Transition.GetCurrentBitmapNumber() == 7) {
		mapNum = gate->GetMapNum();
		index = &map[mapNum];
		kirby.SetXY(gate->GetNextDoor().GetX() - 50, gate->GetNextDoor().GetY2()-kirby.GetHeight());
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{		
		Transition.AddBitmap(".//Map//Transition_7.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_6.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_5.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_4.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_3.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_2.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_1.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_0.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_1.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_2.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_3.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_4.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_5.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_6.bmp", RGB(0, 0, 0));
		Transition.AddBitmap(".//Map//Transition_7.bmp", RGB(0, 0, 0));
		
		map[0].LoadBitmap(".//Map//foreground.bmp", RGB(255, 255, 255), ".//Map//background.bmp", ".//Map//map.txt");
		map[1].LoadBitmap(".//Map//map1.bmp", RGB(255, 255, 255), ".//Map//background_1.bmp", ".//Map//map1.txt");
		kirby.LoadBitmap();
		monster[0] = &normalMonster1;
		monster[1] = &normalMonster2;
		monster[2] = &normalMonster3;
		monster[3] = &normalMonster4;
		monster[4] = &normalMonster5;
		monster[5] = &normalMonster6;
		monster[6] = &spark1;
		monster[7] = &spark2;
		monster[8] = &spark3;
		monster[9] = &spark4;
		for (int m = 0; m < 10; m++)
			monster[m]->LoadBitmap();
		for (int i = 0; i < 10;i++)
			door[i].LoadBitmap();
		door1[0].LoadBitmap();
		door1[1].LoadBitmap();
		index = &map[0];
		mapNum = 0;
		gate = &door[5];

	CAudio::Instance()->Load(AUDIO_BACKGROUND, "sounds\\Kirby_background.mp3");  //背景音樂
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;       // keyboard Esc
	const char KEY_LEFT  = 0x25;   // keyboard左箭頭
	const char KEY_UP    = 0x26;   // keyboard上箭頭
	const char KEY_RIGHT = 0x27;   // keyboard右箭頭
	const char KEY_DOWN  = 0x28;   // keyboard下箭頭
	const char KEY_SPACE = ' ';    // keyboard空白鍵
	const char KEY_Jump = 0x58;    // keyboard X鍵
	const char KEY_Attack = 0x5A;  // keyboard Z鍵
	const char KEY_Run = 0x43;     // keyboard C鍵
	if (nChar == KEY_LEFT)
		kirby.SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		kirby.SetMovingRight(true);
	if (nChar == KEY_UP) {
		kirby.SetMovingUp(true);
		if(mapNum==0)
			for (int i = 0; i < 10;i++)
				door[i].SetEnter(true);

		if (mapNum == 1)
			for (int i = 0; i < 2;i++)
				door1[i].SetEnter(true);
	}
	if (nChar == KEY_DOWN)
		kirby.SetMovingDown(true);
	if (nChar == KEY_SPACE)
		kirby.SetSpace(true);
	if (nChar == KEY_Attack)
		kirby.SetAttack(true);
	if (nChar == KEY_Run)
		kirby.SetRun(true);
	if (nChar == KEY_Jump && !kirby.IsFly() && !index->isEmpty((kirby.GetX2() + kirby.GetX2()) / 2, kirby.GetY2() + 1)) //按下X,卡比不是在飛行且落地才可跳躍
		kirby.SetJump(true);
	if (nChar == KEY_ESC)
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25;   // keyboard左箭頭
	const char KEY_UP    = 0x26;   // keyboard上箭頭
	const char KEY_RIGHT = 0x27;   // keyboard右箭頭
	const char KEY_DOWN  = 0x28;   // keyboard下箭頭
	const char KEY_SPACE = ' ';    // keyboard空白鍵
	const char KEY_Attack = 0x5A;  // keyboard Z鍵
	const char KEY_Run = 0x43;     // keyboard C鍵
	if (nChar == KEY_LEFT)
		kirby.SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		kirby.SetMovingRight(false);
	if (nChar == KEY_UP) {
		kirby.SetMovingUp(false);
		if(mapNum==0)
			for (int i = 0; i < 10;i++)
				door[i].SetEnter(false);
		if (mapNum == 1)
			for (int i = 0; i < 2;i++)
				door1[i].SetEnter(false);
	}
	if (nChar == KEY_DOWN)
		kirby.SetMovingDown(false);
	if (nChar == KEY_Attack)
	{
		kirby.SetAttack(false);
		kirby.SetSuck(false);
	}
	if (nChar == KEY_Run)
		kirby.SetRun(false);
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
	index->SetMouse(point.x, point.y);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	index->IsLclick(true);


}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	index->IsLclick(false);
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	index->IsRclick(true);
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	index->IsRclick(false);
}

void CGameStateRun::OnShow()
{
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。


	//map.OnShow();
	index->OnShow();
	if (mapNum == 0) {
		for (int i = 0; i < 10;i++)
			door[i].OnShow(index);
		
<<<<<<< HEAD
	}

	if (mapNum == 1) {
		for (int i = 0; i < 2;i++)
			door1[i].OnShow(index);
		monster[0] = &normalMonster1;
		monster[1] = &normalMonster2;
		monster[2] = &normalMonster3;
		monster[3] = &normalMonster4;
		monster[4] = &normalMonster5;
		monster[5] = &normalMonster6;
		monster[6] = &spark1;
		monster[7] = &spark2;
		monster[8] = &spark3;
		monster[9] = &spark4;
		for (int m = 0; m < 10; m++)
			monster[m]->OnShow(index, &kirby);
	}
=======
	}

	if (mapNum == 1) {
		for (int i = 0; i < 2;i++)
			door1[i].OnShow(index);

		spark.OnShow(index);
		normalMonster[0].OnShow(index, &kirby);
		normalMonster[1].OnShow(index, &kirby);
		normalMonster[2].OnShow(index, &kirby);
		normalMonster[3].OnShow(index, &kirby);
		normalMonster[4].OnShow(index, &kirby);
		normalMonster[5].OnShow(index, &kirby);
	}
>>>>>>> 277b838514a2591e1c7221f0c8d96f6957c84bc7
	
	if(kirby.IsAlive()) kirby.OnShow(index);
	else if(kirby.GetY1()<=1) GotoGameState(GAME_STATE_OVER);
	else kirby.Die(index);


	if (Istransiting) {
		Transition.OnShow();
	}
}
}