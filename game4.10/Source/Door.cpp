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

	
	int Door::GetNextX() {  //�^�ǤU�@�Ӫ���X�y��
		return NextDoor->GetX();
	}

	int Door::GetNextY() { //�^�ǤU�@�Ӫ���Y�y��
		return NextDoor->GetY();
	}

	Door Door::GetNextDoor() {  //�^�ǫ���
		return *NextDoor;
	}


	void Door::Initialize(int px,int py,int num,int m ,Door* h) {//�]�w������m�Ҧb�a�ϤU�@�Ӫ����a��
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
		if (map == 0) {  //���a��0�ɬ��@�몺��
			door.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			door.OnShow();
		}
		else {  //��l�����P�P����
			Gate.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			Gate.OnShow();
		}
	}

	void Door::SetEnter(bool flag) { //�]�w�O�_���W
		Enter = flag;
	}
	
	bool Door::IsEnter(Kirby *k) {
		if (map == 0) {  //���a��0�ɬ��@�몺��
			if ((k->GetX1() + k->GetX2()) / 2 >= x && (k->GetX1() + k->GetX2()) / 2 <= x + door.Width() && (k->GetY1() + k->GetY2()) / 2 >= y && (k->GetY1() + k->GetY2()) / 2 <= y + door.Height() && Enter)
				return true;
			else
				return false;
		}
		else {  //��l�����P�P����
			if ((k->GetX1() + k->GetX2()) / 2 >= x && (k->GetX1() + k->GetX2()) / 2 <= x + Gate.Width() && (k->GetY1() + k->GetY2()) / 2 >= y && (k->GetY1() + k->GetY2()) / 2 <= y + Gate.Height() && Enter)
				return true;
			else
				return false;
		}
	}
}