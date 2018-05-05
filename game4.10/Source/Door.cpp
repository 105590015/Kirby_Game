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

	int Door::GetNextX() {
		return NextDoor->GetX();
	}

	int Door::GetNextY() {
		return NextDoor->GetY();
	}


	void Door::Initialize(int px,int py,int num ,Door* h) {
		x = px;
		y = py;
		mapNum = num;
		NextDoor = h;
	}

	void Door::LoadBitmap() {
		door.AddBitmap(".\\RES\\Door\\door_0.bmp", RGB(255, 255, 255));
		door.AddBitmap(".\\RES\\Door\\door_1.bmp", RGB(255, 255, 255));
		door.AddBitmap(".\\RES\\Door\\door_2.bmp", RGB(255, 255, 255));
		door.AddBitmap(".\\RES\\Door\\door_3.bmp", RGB(255, 255, 255));

		
	}

	void Door::OnMove() {
		door.OnMove();
	}

	void Door::OnShow(Map *m) {
		door.SetTopLeft(m->ScreenX(x),m->ScreenY(y));
		door.OnShow();
	}

	void Door::SetEnter(bool flag) {
		Enter = flag;
	}
	
	bool Door::IsEnter(Kirby *k) {

		if ((k->GetX1() + k->GetX2()) / 2 >= x && (k->GetX1() + k->GetX2()) / 2 <= x + door.Width() && (k->GetY1() + k->GetY2()) / 2 >= y && (k->GetY1() + k->GetY2()) / 2 <= y + door.Height() && Enter)
			return true;
		else
			return false;
	}
}