#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Door.h"
#include <fstream> 


namespace game_framework {
	Door::Door(){
	}

	int Door::GetMapNum() {
		return mapNum;
	}

	int Door::GetHeight() {
		return door.Height();
	}

	int Door::GetWidth() {
		return door.Width();
	}

	int Door::GetX() {
		return x;
	}

	int Door::GetY() {
		return y;
	}

	int Door::GetX2() {
		return x + door.Width();
	}

	int Door::GetY2() {
		return y + door.Height();
	}

	
	int Door::GetNextX() {  //回傳下一個門的X座標
		return NextDoor->GetX();
	}

	int Door::GetNextY() { //回傳下一個門的Y座標
		return NextDoor->GetY();
	}

	Door Door::GetNextDoor() {  //回傳指標
		return *NextDoor;
	}


	void Door::Initialize(int px,int py,int num,int m ,Door* h) {//設定門的位置所在地圖下一個門的地圖
		x = px;
		y = py;
		map = m;
		mapNum = num;
		NextDoor = h;
	}

	void Door::LoadBitmap() {
		door.AddBitmap(".\\RES\\Door\\door_0.bmp", RGB(255, 255, 255));
		door.AddBitmap(".\\RES\\Door\\door_1.bmp", RGB(255, 255, 255));
		door.AddBitmap(".\\RES\\Door\\door_2.bmp", RGB(255, 255, 255));
		door.AddBitmap(".\\RES\\Door\\door_3.bmp", RGB(255, 255, 255));

		Gate.AddBitmap(".\\RES\\Door\\Gate_0.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_1.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_2.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_3.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_4.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_5.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_6.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_7.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_8.bmp", RGB(255, 255, 255));
		Gate.AddBitmap(".\\RES\\Door\\Gate_9.bmp", RGB(255, 255, 255));		
	}

	void Door::OnMove() {
		door.OnMove();
		Gate.OnMove();
		Gate.SetDelayCount(7);
	}

	void Door::OnShow(Map *m) {
		if (map == 0) {  //當為地圖0時為一般的門
			door.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			door.OnShow();
		}
		else {  //其餘為有星星的門
			Gate.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			Gate.OnShow();
		}
	}

	void Door::SetEnter(bool flag) { //設定是否按上
		Enter = flag;
	}
	
	bool Door::IsEnter(Kirby *k) {
		if (map == 0) {  //當為地圖0時為一般的門
			if ((k->GetX1() + k->GetX2()) / 2 >= x && (k->GetX1() + k->GetX2()) / 2 <= x + door.Width() && (k->GetY1() + k->GetY2()) / 2 >= y && (k->GetY1() + k->GetY2()) / 2 <= y + door.Height() && Enter)
				return true;
			else
				return false;
		}
		else {  //其餘為有星星的門
			if ((k->GetX1() + k->GetX2()) / 2 >= x && (k->GetX1() + k->GetX2()) / 2 <= x + Gate.Width() && (k->GetY1() + k->GetY2()) / 2 >= y && (k->GetY1() + k->GetY2()) / 2 <= y + Gate.Height() && Enter)
				return true;
			else
				return false;
		}
	}
}