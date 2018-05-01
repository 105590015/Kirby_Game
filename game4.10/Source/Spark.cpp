#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include"Spark.h"

namespace game_framework {
	Spark::Spark():Enemy() {

	}

	int Spark::GetX2() {
		return x + index->Width();
	}

	int Spark::GetY2() {
		return y + index->Height();
	}

	void Spark::LoadBitmap() {
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_0.bmp", RGB(255,255,255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_1.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_2.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_3.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_4.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_5.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_6.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_L_7.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_0.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_1.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_2.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_3.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_4.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_5.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_6.bmp", RGB(255, 255, 255));
		Jump_L.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_7.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_0.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_1.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_2.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_3.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_4.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_5.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_6.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_7.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_8.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_9.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_10.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_11.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_12.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_13.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_14.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_15.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_16.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_17.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_18.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_19.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_20.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_21.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_22.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_23.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_24.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_25.bmp", RGB(255, 255, 255));
		Attack.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_26.bmp", RGB(255, 255, 255));
		Sucked_L.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_L_0.bmp", RGB(255, 255, 255));
		Sucked_L.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_L_1.bmp", RGB(255, 255, 255));
		Sucked_R.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_R_0.bmp", RGB(255, 255, 255));
		Sucked_R.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_R_1.bmp", RGB(255, 255, 255));
		Stand_L.AddBitmap(".\\RES\\Spirky\\Spirky_L_0.bmp", RGB(255, 255, 255));
		Stand_L.AddBitmap(".\\RES\\Spirky\\Spirky_L_1.bmp", RGB(255, 255, 255));
		Stand_R.AddBitmap(".\\RES\\Spirky\\Spirky_R_0.bmp", RGB(255, 255, 255));
		Stand_R.AddBitmap(".\\RES\\Spirky\\Spirky_R_1.bmp", RGB(255, 255, 255));
	}

	void Spark::Initialize(int px,int py) {
		x = px;
		y = py;
		hp = 10;
		is_alive = true;
		is_sucked = false;
		IsRising = false;
		init_velocity = 20;
		RightOrLeft = true;
		floor = y;
		index =& Stand_R;
		velocity = init_velocity;

	}

	void Spark::OnMove(Map* m,Kirby* k) {

		if (x - k->GetX1() > 0)
			RightOrLeft = false;
		else
			RightOrLeft = true;

		if (IsRising) {
			index = &Jump_L;
			index->SetDelayCount(50);
			if (velocity > 0) {
				y -= velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				IsRising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}

		else {				// �U�����A
			if (y < floor - 1) {  // ��y�y���٨S�I��a�O
				y += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				y = floor - 1;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				IsRising = true;	// �����ϼu�A�U���אּ�W��
				velocity = init_velocity; // ���]�W�ɪ�l�t��
			}
		}

		if(is_alive)
			index->OnMove();

	}
	void Spark::OnShow(Map* m) {
		if (is_alive) {
			index->SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			index->OnShow();
		}

	}
}