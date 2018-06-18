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
	StartAnimation.AddBitmap(".\\RES\\Start\\title_0.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_1.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_2.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_3.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_4.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_5.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_6.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_7.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_8.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_9.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_10.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_11.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_12.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_13.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_14.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_15.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_16.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_17.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_18.bmp", RGB(255, 255, 255));
	StartAnimation.AddBitmap(".\\RES\\Start\\title_19.bmp", RGB(255, 255, 255));
	background.LoadBitmap(".\\RES\\Start\\background.bmp");
	pressStart.LoadBitmap(".\\RES\\Start\\Press_start.bmp", RGB(248, 248, 248));
}

void CGameStateInit::OnBeginState()
{
	page = 0;
	if(!CAudio::Instance()->IsLoaded(start))
		CAudio::Instance()->Load(start, "Sounds\\start.mp3");
	CAudio::Instance()->Play(start, true);
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE)
	{
		if (page == 0)
			page++;
		else
		{
			CAudio::Instance()->Stop(start);
			GotoGameState(GAME_STATE_RUN); // 切換至GAME_STATE_RUN
		}
	}
	else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// 關閉遊戲
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (page == 0)
		page++;
	else
	{
		CAudio::Instance()->Stop(start);
		GotoGameState(GAME_STATE_RUN); // 切換至GAME_STATE_RUN
	}
}

void CGameStateInit::OnShow()
{	
	if (page == 0)
	{
		background.SetTopLeft(0, 0);
		StartAnimation.SetTopLeft(0, 0);
		pressStart.SetTopLeft(60, 380);
		background.ShowBitmap();
		StartAnimation.OnMove();
		StartAnimation.OnShow();
		pressStart.ShowBitmap();
	}
	else
	{
		// /*Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好*/
		CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f,*fp;
		f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
		fp=pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255 , 255, 0));
		pDC->TextOut(35, 50, "操作 : ");
		pDC->TextOut(65, 80, "↑ : 吸氣飛翔、進入傳送門   ↓ : 蹲下、變身");
		pDC->TextOut(65, 110, "← : 左移   → : 右移");
		pDC->TextOut(65, 140, "Z : 攻擊、吸怪   ↓ + Z : 踢擊");
		pDC->TextOut(65, 170, "X : 跳躍");
		pDC->TextOut(65, 200, "C : 跑步(按住加左右移)");
		pDC->TextOut(65, 230, "Esc : 關閉遊戲");
		pDC->TextOut(35, 260, "密技 : ");
		pDC->TextOut(65, 290, "S : 血量補滿");
		pDC->TextOut(35, 350, "打敗兩隻魔王，拿回碎片拯救世界吧 ! 卡比");
		pDC->TextOut(220, 380, "(按下空白鍵開始)");
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC*/
	}
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
	if(counter==0)
		GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
	counter = 300;
}

void CGameStateOver::OnInit()
{
}

void CGameStateOver::OnShow()
{
	counter--;
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)",counter/30);
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
	map[2].Initialize();
	map[3].Initialize();
	map[4].Initialize();

	Mirror_L.SetTopLeft(608, -100);
	Mirror_R.SetTopLeft(608, -100);
	
	kirby.Initialize(640,400);

	door[0].Initialize(123,  37, 1, 0, &door1[0]);
	door[1].Initialize(621,  37, 2, 0, &door2);
	door[2].Initialize(1118,  37, 4, 0, &door4[0]);
	door[3].Initialize(83, 328, 4, 0, &door4[1]);
	door[4].Initialize(248, 369, 4, 0, &door4[0]);
	door[5].Initialize(993, 367, 1, 0, &door1[0]);
	door[6].Initialize(1159, 326, 1, 0, &door1[1]);
	door[7].Initialize(207, 575, 1, 0, &door1[1]);
	door[8].Initialize(620, 614, 3, 0, &door3);
	door[9].Initialize(1036, 574, 4, 0, &door4[1]);

	door1[0].Initialize(30, 425, 0,1, &door[5]);
	door1[1].Initialize(4450, 350, 0, 1, &door[6]);


	door2.Initialize(320, 240, 0, 2, &door[1]);

	door3.Initialize(150, 350, 0, 3, &door[8]);

	door4[0].Initialize(48, 435, 0, 4, &door[4]);
	door4[1].Initialize(3140, 240 , 0, 4, &door[3]);

	ResetMonster();

	tree.Initialize(450, 100);
	airplane.Initialize(450, 60);

	Mirror_L_Y = -10;
	Mirror_R_Y = -10;

	end_Y = 0;

	mapNum = 0;
	index = &map[mapNum];
	
	gate = &door[5];

	CAudio::Instance()->Play(AUDIO_BACKGROUND, true);
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	index->OnMove(kirby.GetX1(), kirby.GetY1());

	Mirror_R.OnMove();
	Mirror_L.OnMove();

	if (Istransiting) {
		Transition.OnMove();
		Transition.SetDelayCount(4);
	}
	else if (MovingMirror) {
		map[0].SetXY(320, 160);
		
		if (Show_Mirror_R && Mirror_R_Y != 327) {
			Mirror_R_Y += 1;
			Mirror_R.SetTopLeft(map[0].ScreenX(608), map[0].ScreenY(Mirror_R_Y));
		}
		else if (Show_Mirror_L && Mirror_L_Y != 327 ) {
			Mirror_L_Y += 1;
			Mirror_L.SetTopLeft(map[0].ScreenX(608), map[0].ScreenY(Mirror_L_Y));
		}
		else {
			MovingMirror = false;
		}
	}
	else if (isEnd)
	{
		end_Y--;
		if (end_Y == -1)
		{
			CAudio::Instance()->Stop(AUDIO_BACKGROUND);
			CAudio::Instance()->Play(ending);
		}
		else if (end_Y == -1050)
		{
			CAudio::Instance()->Stop(ending);
			CAudio::Instance()->Play(AUDIO_BACKGROUND);
			isEnd = false;
			end_Y = 1;
		}
	}
	else {
		
		if (kirby.IsAlive())
			kirby.OnMove(index);

		if (mapNum == 0)
		{
			for (int i = 0; i < 10; i++) {
				door[i].OnMove();
				if (door[i].IsEnter(&kirby)) {
					door[i].SetEnter(false);
					Istransiting = true;
					Transition.Reset();
					gate = &door[i];
				}
			}
		}

		if (mapNum == 1) {
			for (int m = 0; m < 10; m++)
				monster[m]->OnMove(index, &kirby);

			for (int i = 0; i < 2; i++) {
				door1[i].OnMove();
				if (door1[i].IsEnter(&kirby)) {
					door1[i].SetEnter(false);
					Istransiting = true;
					Transition.Reset();
					gate = &door1[i];
				}
			}
		}

		if (mapNum == 2) {
			airplane.OnMove(index,&kirby);
			if (!airplane.IsAlive())
			{
				if (!Show_Mirror_R) {
					MovingMirror = true;
					Show_Mirror_R = true;
					Istransiting = true;
					Transition.Reset();
					Mirror_L.Reset();
					Mirror_R.Reset();
				}
				else {
					door2.OnMove();
					if (door2.IsEnter(&kirby)) {
						door2.SetEnter(false);
						Istransiting = true;
						Transition.Reset();
						gate = &door2;
					}
				}
			}
		}

		if (mapNum == 3) {
			tree.OnMove(index,&kirby);
			if (!tree.IsAlive()) {
				if (!Show_Mirror_L) {
					MovingMirror = true;
					Show_Mirror_L = true;
					Istransiting = true;
					Transition.Reset();
				}
				else {
					door3.OnMove();
					if (door3.IsEnter(&kirby)) {
						door3.SetEnter(false);
						Istransiting = true;
						Transition.Reset();
						gate = &door3;
					}
				}
			}
		}

		if (mapNum == 4) {
			door4[0].OnMove();
			door4[1].OnMove();

			for (int m = 0; m < 3; m++)
				monster[m]->OnMove(index, &kirby);

			for (int i = 0; i < 2; i++) {
				if (door4[i].IsEnter(&kirby)) {
					door4[i].SetEnter(false);
					Istransiting = true;
					Transition.Reset();
					gate = &door4[i];
				}
			}
		}
	}

	if (Transition.IsFinalBitmap()) {
		Istransiting = false;
	}

	if (Transition.GetCurrentBitmapNumber() == 7  && !MovingMirror) {
		mapNum = gate->GetMapNum();
		index = &map[mapNum];
		ResetMonster();
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

	Mirror_L.AddBitmap(".//RES//Door//mirror_L_0.bmp", RGB(255, 255, 255));
	Mirror_L.AddBitmap(".//RES//Door//mirror_L_1.bmp", RGB(255, 255, 255));
	Mirror_L.AddBitmap(".//RES//Door//mirror_L_2.bmp", RGB(255, 255, 255));
	Mirror_L.AddBitmap(".//RES//Door//mirror_L_3.bmp", RGB(255, 255, 255));

	Mirror_R.AddBitmap(".//RES//Door//mirror_R_0.bmp", RGB(255, 255, 255));
	Mirror_R.AddBitmap(".//RES//Door//mirror_R_1.bmp", RGB(255, 255, 255));
	Mirror_R.AddBitmap(".//RES//Door//mirror_R_2.bmp", RGB(255, 255, 255));
	Mirror_R.AddBitmap(".//RES//Door//mirror_R_3.bmp", RGB(255, 255, 255));
		
	end.LoadBitmap(".//RES//end.bmp");

	map[0].LoadBitmap(".//Map//foreground.bmp", RGB(255, 255, 255), ".//Map//background.bmp", ".//Map//map.txt");
	map[1].LoadBitmap(".//Map//map1.bmp", RGB(255, 255, 255), ".//Map//background_1.bmp", ".//Map//map1.txt");
	map[2].LoadBitmap(".//Map//Boss_map.bmp", RGB(255, 255, 255), ".//Map//background_2.bmp", ".//Map//map2.txt");
	map[3].LoadBitmap(".//Map//King_foreground.bmp", RGB(255, 255, 255), ".//Map//King_background.bmp", ".//Map//map3.txt");
	map[4].LoadBitmap(".//Map//foreground_4.bmp", RGB(255, 255, 255), ".//Map//background_4.bmp", ".//Map//map4.txt");
	kirby.LoadBitmap();
	monster[0] = &fire1[0];
	monster[1] = &fire1[1];
	monster[2] = &normalMonster1[0];
	monster[3] = &normalMonster1[1];
	monster[4] = &normalMonster1[2];
	monster[5] = &normalMonster1[3];
	monster[6] = &spark1[0];
	monster[7] = &spark1[1];
	monster[8] = &spark1[2];
	monster[9] = &spark1[3];
	fire4[0].LoadBitmap();
	spark4[0].LoadBitmap();
	normalMonster4[0].LoadBitmap();

	for (int m = 0; m < 10; m++)
		monster[m]->LoadBitmap();
	for (int i = 0; i < 10;i++)
		door[i].LoadBitmap();
	door1[0].LoadBitmap();
	door1[1].LoadBitmap();
	door2.LoadBitmap();
	door3.LoadBitmap();
	for (int i = 0; i < 2; i++)
		door4[i].LoadBitmap();

	tree.LoadBitmap();
	airplane.LoadBitmap();

	CAudio::Instance()->Load(AUDIO_BACKGROUND, "Sounds\\Kirby_background.mp3");  //背景音樂
	CAudio::Instance()->Load(jump, "Sounds\\jump.wav");
	CAudio::Instance()->Load(landing, "Sounds\\landing.wav");
	CAudio::Instance()->Load(kick, "Sounds\\kick.wav");
	CAudio::Instance()->Load(die, "Sounds\\die.wav");
	CAudio::Instance()->Load(fly, "Sounds\\fly.wav");
	CAudio::Instance()->Load(hurted, "Sounds\\hurted.wav");
	CAudio::Instance()->Load(run, "Sounds\\run.wav");
	CAudio::Instance()->Load(suck, "Sounds\\suck.wav");
	CAudio::Instance()->Load(gasSound, "Sounds\\gas.wav");
	CAudio::Instance()->Load(starSound, "Sounds\\star.wav");
	CAudio::Instance()->Load(swallow, "Sounds\\swallow.wav");
	CAudio::Instance()->Load(spark, "Sounds\\spark.wav");
	CAudio::Instance()->Load(fire, "Sounds\\fire.wav");
	CAudio::Instance()->Load(enemyDie, "Sounds\\enemyDie.wav");
	CAudio::Instance()->Load(lostAbility, "Sounds\\lostAbility.wav");
	CAudio::Instance()->Load(ending, "Sounds\\ending.mp3");
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;       // keyboard Esc
	const char KEY_LEFT  = 0x25;   // keyboard左箭頭
	const char KEY_UP    = 0x26;   // keyboard上箭頭
	const char KEY_RIGHT = 0x27;   // keyboard右箭頭
	const char KEY_DOWN  = 0x28;   // keyboard下箭頭
	const char KEY_Jump = 0x58;    // keyboard X鍵
	const char KEY_Attack = 0x5A;  // keyboard Z鍵
	const char KEY_Run = 0x43;     // keyboard C鍵
	const char KEY_Restore = 0x53;     // keyboard S鍵
	
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

		if (mapNum == 2)
			door2.SetEnter(true);

		if (mapNum == 3)
			door3.SetEnter(true);

		if (mapNum == 4)
			for (int i = 0; i < 2; i++)
				door4[i].SetEnter(true);
	}
	if (nChar == KEY_DOWN)
	{
		kirby.SetMovingDown(true);
		if (kirby.IsBig())
			CAudio::Instance()->Play(swallow);
	}
	if (nChar == KEY_Attack)
	{
		kirby.SetAttack(true);
		if (!MovingMirror)
		{
			if (kirby.IsFly())
				CAudio::Instance()->Play(gasSound);
			else if (kirby.IsDown())
				CAudio::Instance()->Play(kick);
			else if (kirby.GetType() == 0 && !kirby.IsBig())
				CAudio::Instance()->Play(suck);
			else if (kirby.GetType() == 0 && kirby.IsBig())
				CAudio::Instance()->Play(starSound);
			else if (kirby.GetType() == 1)
				CAudio::Instance()->Play(spark);
			else if (kirby.GetType() == 2)
				CAudio::Instance()->Play(fire);
		}
	}
	if (nChar == KEY_Run)
	{
		kirby.SetRun(true);
		if (!kirby.IsFly() && !index->isEmpty((kirby.GetX1() + kirby.GetX2()) / 2, kirby.GetY2() + 1) && kirby.IsMove())
			CAudio::Instance()->Play(run);
	}
	if (nChar == KEY_Jump && !kirby.IsFly() && (!index->isEmpty(kirby.GetX1(), kirby.GetY2() + 1) || !index->isEmpty(kirby.GetX2(), kirby.GetY2() + 1))) //按下X,卡比不是在飛行且落地才可跳躍
		kirby.SetJump(true);
	if (nChar == KEY_ESC)
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	if (nChar == KEY_Restore)
		kirby.Restore();
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25;   // keyboard左箭頭
	const char KEY_UP    = 0x26;   // keyboard上箭頭
	const char KEY_RIGHT = 0x27;   // keyboard右箭頭
	const char KEY_DOWN  = 0x28;   // keyboard下箭頭
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
			for (int i = 0; i < 2; i++)
				door1[i].SetEnter(false);
		if (mapNum == 2)
			door2.SetEnter(false);
		if (mapNum==3)
			door3.SetEnter(false);
		if (mapNum == 4)
			for (int i = 0; i < 2; i++)
				door4[i].SetEnter(false);
	}
	if (nChar == KEY_DOWN)
		kirby.SetMovingDown(false);
	if (nChar == KEY_Attack)
	{
		kirby.SetAttack(false);
		kirby.SetSuck(false);
		CAudio::Instance()->Stop(suck);
		CAudio::Instance()->Stop(spark);
		CAudio::Instance()->Stop(fire);
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

void CGameStateRun::ResetMonster()
{
	if (mapNum == 1) {
		normalMonster1[0].Initialize(947, 467);
		normalMonster1[1].Initialize(2459, 517);
		normalMonster1[2].Initialize(2903, 517);
		normalMonster1[3].Initialize(3495, 59);
		spark1[0].Initialize(675, 393);
		spark1[1].Initialize(1673, 163);
		spark1[2].Initialize(3247, 269);
		spark1[3].Initialize(4045, 477);
		fire1[0].Initialize(417, 467);
		fire1[1].Initialize(3745, 477);

		monster[0] = &fire1[0];
		monster[1] = &fire1[1];
		monster[2] = &normalMonster1[0];
		monster[3] = &normalMonster1[1];
		monster[4] = &normalMonster1[2];
		monster[5] = &normalMonster1[3];
		monster[6] = &spark1[0];
		monster[7] = &spark1[1];
		monster[8] = &spark1[2];
		monster[9] = &spark1[3];
	}

	if (mapNum == 4) {
		fire4[0].Initialize(410, 400);

		spark4[0].Initialize(1125, 525);

		normalMonster4[0].Initialize(1600, 525);

		monster[0] = &fire4[0];
		monster[1] = &spark4[0];
		monster[2] = &normalMonster4[0];
	}
}

void CGameStateRun::OnShow()
{
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
	end.SetTopLeft(0, end_Y);
	index->OnShow();
	if (mapNum == 0) {
		for (int i = 0; i < 10;i++)
			door[i].OnShow(index);

		if (Show_Mirror_L) {
			Mirror_L.SetTopLeft(map[0].ScreenX(608), map[0].ScreenY(Mirror_L_Y));
			Mirror_L.OnShow();
		}
		if (Show_Mirror_R) {
			Mirror_R.SetTopLeft(map[0].ScreenX(608), map[0].ScreenY(Mirror_R_Y));
			Mirror_R.OnShow();
		}
	}
	else if (mapNum == 1) {
		for (int i = 0; i < 2;i++)
			door1[i].OnShow(index);
		for (int m = 0; m < 10; m++)
			monster[m]->OnShow(index, &kirby);
	}
	else if (mapNum == 2) {
		airplane.OnShow(index,&kirby);
		if(!airplane.IsAlive())
			door2.OnShow(index);
	}
	else if (mapNum == 3) {
		tree.OnShow(index,&kirby);
		if (!tree.IsAlive()) {
			door3.OnShow(index);
		}
	}
	else if(mapNum == 4) {
		for (int i = 0; i < 2; i++)
			door4[i].OnShow(index);
		for (int m = 0; m < 3; m++)
			monster[m]->OnShow(index, &kirby);
	}

	if (kirby.IsAlive()) {
		kirby.OnShow(index);
	}
	else if (kirby.GetY1() <= 1)
	{
		// 卡比死掉就不用播消失能力的音效
		CAudio::Instance()->Stop(lostAbility);
		// 鏡子重置
		Show_Mirror_L = false;
		Show_Mirror_R = false;
		Mirror_L_Y = -10;
		Mirror_R_Y = -10;
		GotoGameState(GAME_STATE_OVER);
	}
	else 
		kirby.Die(index);
	
	if (MovingMirror && Transition.GetCurrentBitmapNumber()>6) {
		map[0].SetXY(320, 160);
		map[0].OnShow();
		if (Show_Mirror_L) {
			Mirror_L.SetTopLeft(map[0].ScreenX(608), map[0].ScreenY(Mirror_L_Y));
			Mirror_L.OnShow();
		}

		if (Show_Mirror_R) {
			Mirror_R.SetTopLeft(map[0].ScreenX(608), map[0].ScreenY(Mirror_R_Y));
			Mirror_R.OnShow();
		}
	}
	
	if (Istransiting) {
		Transition.OnShow();
	}

	if (Show_Mirror_L && Show_Mirror_R && Mirror_L_Y == 327 && Mirror_R_Y == 327 && end_Y == 0)
		isEnd = true;

	if (isEnd)
		end.ShowBitmap();
}
}