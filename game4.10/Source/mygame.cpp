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
	StartAnimation.AddBitmap(IDB_TITLE_0);
	StartAnimation.AddBitmap(IDB_TITLE_1);
	StartAnimation.AddBitmap(IDB_TITLE_2);
	StartAnimation.AddBitmap(IDB_TITLE_3);
	StartAnimation.AddBitmap(IDB_TITLE_4);
	StartAnimation.AddBitmap(IDB_TITLE_5);
	StartAnimation.AddBitmap(IDB_TITLE_6);
	StartAnimation.AddBitmap(IDB_TITLE_7);
	StartAnimation.AddBitmap(IDB_TITLE_8);
	StartAnimation.AddBitmap(IDB_TITLE_9);
	StartAnimation.AddBitmap(IDB_TITLE_10);
	StartAnimation.AddBitmap(IDB_TITLE_11);
	StartAnimation.AddBitmap(IDB_TITLE_12);
	StartAnimation.AddBitmap(IDB_TITLE_13);
	StartAnimation.AddBitmap(IDB_TITLE_14);
	StartAnimation.AddBitmap(IDB_TITLE_15);
	StartAnimation.AddBitmap(IDB_TITLE_16);
	StartAnimation.AddBitmap(IDB_TITLE_17);
	StartAnimation.AddBitmap(IDB_TITLE_18);
	StartAnimation.AddBitmap(IDB_TITLE_19);
	
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
	counter--;
	if (counter < 0)
		GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
	counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
}

void CGameStateOver::OnShow()
{
	/*CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC*/
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
	map.Initialize();
	kirby.Initialize(0,120);
	monster1.Initialize(320, 240, 320, 400, true);
	CAudio::Instance()->Play(AUDIO_BACKGROUND, true);
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	map.OnMove(kirby.GetX1(),kirby.GetY1());
	kirby.OnMove(&map);
	monster1.OnMove(&map, &kirby);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	// 載入資料
	map.LoadBitmap(IDB_ForeGround);
	kirby.LoadBitmap();		
	monster1.LoadBitmap();
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
	const char KEY_Run = 0x43;
	if (nChar == KEY_LEFT)
		kirby.SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		kirby.SetMovingRight(true);
	if (nChar == KEY_UP)
		kirby.SetMovingUp(true);
	if (nChar == KEY_DOWN)
		kirby.SetMovingDown(true);
	if (nChar == KEY_SPACE)
		kirby.SetSpace(true);
	if (nChar == KEY_Attack)
		kirby.SetAttack(true);
	if (nChar == KEY_Jump && !kirby.IsFly() && !map.isEmpty(kirby.GetX1() + 10, kirby.GetY1() + 20 + 1)) //按下X,卡比不是在飛行且落地才可跳躍(320.240是地圖補償20是卡比的身高)
		kirby.SetJump(true);
	if (nChar == KEY_ESC)
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	if (nChar == KEY_Run)
		kirby.SetRun(true);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25;   // keyboard左箭頭
	const char KEY_UP    = 0x26;   // keyboard上箭頭
	const char KEY_RIGHT = 0x27;   // keyboard右箭頭
	const char KEY_DOWN  = 0x28;   // keyboard下箭頭
	const char KEY_SPACE = ' ';    // keyboard空白鍵
	const char KEY_Attack = 0x5A;  // keyboard Z鍵
	const char KEY_Run = 0x43;
	if (nChar == KEY_LEFT)
		kirby.SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		kirby.SetMovingRight(false);
	if (nChar == KEY_UP)
		kirby.SetMovingUp(false);
	if (nChar == KEY_DOWN)
		kirby.SetMovingDown(false);
	if (nChar == KEY_Attack)
		kirby.SetAttack(false);
	if (nChar == KEY_Run)
		kirby.SetRun(false);

	
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
	map.SetMouse(point.x, point.y);

}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	map.IsLclick(true);
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	map.IsLclick(false);
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	map.IsRclick(true);
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	map.IsRclick(false);
}

void CGameStateRun::OnShow()
{
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
	map.OnShow("map.txt");
	kirby.OnShow(&map);
	monster1.OnShow(&map, &kirby);
}
}