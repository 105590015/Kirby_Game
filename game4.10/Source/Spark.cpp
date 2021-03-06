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
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_0.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_1.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_2.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_3.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_4.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_5.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_6.bmp", RGB(255, 255, 255));
		Jump_R.AddBitmap(".\\RES\\Spirky\\Spirky_jump_R_7.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_0.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_1.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_2.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_3.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_4.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_5.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_6.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_7.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_8.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_9.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_10.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_11.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_12.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_13.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_14.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_15.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_16.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_17.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_18.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_19.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_20.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_21.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_22.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_23.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_24.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_25.bmp", RGB(255, 255, 255));
		ATK.AddBitmap(".\\RES\\Spirky\\Spirky_Attack_26.bmp", RGB(255, 255, 255));
		AttackRange.AddBitmap(".\\RES\\Spirky\\Spirky_AttackRange.bmp", RGB(255, 255, 25));
		Sucked_L.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_L_0.bmp", RGB(255, 255, 255));
		Sucked_L.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_L_1.bmp", RGB(255, 255, 255));
		Sucked_R.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_R_0.bmp", RGB(255, 255, 255));
		Sucked_R.AddBitmap(".\\RES\\Spirky\\Spirky_Sucked_R_1.bmp", RGB(255, 255, 255));
		Stand_L.AddBitmap(".\\RES\\Spirky\\Spirky_L_0.bmp", RGB(255, 255, 255));
		Stand_L.AddBitmap(".\\RES\\Spirky\\Spirky_L_1.bmp", RGB(255, 255, 255));
		Stand_R.AddBitmap(".\\RES\\Spirky\\Spirky_R_0.bmp", RGB(255, 255, 255));
		Stand_R.AddBitmap(".\\RES\\Spirky\\Spirky_R_1.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die1.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die2.bmp", RGB(255, 255, 255));
		die.AddBitmap(".\\RES\\die3.bmp", RGB(255, 255, 255));
	}

	void Spark::Initialize(int px,int py) {
		x = px;
		y = py;
		hp = 10;
		counter = 0;
		is_alive = true;
		is_sucked = false;
		IsRising = false;
		IsAttacking = false;
		IsKing = false;
		init_velocity = 15;
		RightOrLeft = true;
		StepSize = 1;
		index =& Stand_R;
		velocity = init_velocity;
	}

	void Spark::Attack(Map *m, Kirby* k) {
		if (HitRectangle(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()) && !k->IsKick())
			k->Hurted(m);
		if(IsAttacking && HitSpark(k->GetX1(), k->GetY1(), k->GetX2(), k->GetY2()) && !k->IsKick())
			k->Hurted(m);
	}

	void Spark::OnMove(Map* m,Kirby* k) {
		if (is_alive) {
			if(!IsAttacking)
				counter++;
			
			Hurted(k);
			Sucked(k);

			if (ComputeDistance(k->GetX1(), k->GetY1()) < 200.0) {
				if (x - k->GetX1() > 0) {
					RightOrLeft = false;
					StepSize = -1;
				}
				else if (x - k->GetX1() < 0) {
					RightOrLeft = true;
					StepSize = 1;
				}
			}

			if (RightOrLeft)
				index = &Stand_R;
			if (!RightOrLeft)
				index = &Stand_L;

			if (is_sucked) {
				IsAttacking = false;
				if (RightOrLeft)
					index = &Sucked_R;
				if (!RightOrLeft)
					index = &Sucked_L;

				if (x < (k->GetX1() + k->GetX2()) / 2)
					x += 3;
				else
					x -= 3;

				if (y > k->GetY1())
					y -= 3;
				else
					y += 3;

				if (HitRectangle(k->GetX1() + 10, k->GetY1() + 10, k->GetX2() - 10, k->GetY2() - 10)) {
					is_alive = false;
					k->SetBig(true);
					k->SetEat(1);
				}
			}

			else {
				Attack(m, k);
				
				if (counter==100) {
					velocity = 10;
					IsRising = true;
				}

				if (counter == 150) {
					velocity = 8;
					IsRising = true;
				}

				if (IsRising) {
					index->SetDelayCount(80);

					if (RightOrLeft)
						index = &Jump_R;
					if (!RightOrLeft)
						index = &Jump_L;

					if (velocity > 0) {
						y -= velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
						velocity--;		// 受重力影響，下次的上升速度降低
						if (x != k->GetX1() && abs(x-k->GetX1())<SIZE_X/2 )
							x += StepSize;
					}
					else {
						IsRising = false; // 當速度 <= 0，上升終止，下次改為下降
						velocity = 1;	// 下降的初速(velocity)為1
					}
				}

				if(!IsRising) {				// 下降狀態
					if (m->isEmpty(x, y + index->Height() + velocity) && m->isEmpty(x + index->Width(), y + index->Height() + velocity)) {  // 當y座標還沒碰到地板
						y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
						velocity++;		// 受重力影響，下次的下降速度增加
						if (x != k->GetX1())
							x += StepSize;
					}
					else if (m->isEmpty(x, y + index->Height() + 1) && m->isEmpty(x + index->Width(), y + index->Height() + 1)) {  // 當y座標還沒碰到地板
						y += 1;
						if (x != k->GetX1())
							x += StepSize;
					}
					else {
						velocity = init_velocity; // 重設上升初始速度

						if (abs(x-k->GetX1()) < 80) {
							
							if (!IsAttacking) {
								tempX = x;
								tempY = y;
								midX = (x + GetX2()) / 2;
								midY = (y + GetY2()) / 2;
								index = &AttackRange;
								IsAttacking = true;
								ATK.SetDelayCount(1);
							}						
						}

						if (ATK.IsFinalBitmap() && IsAttacking) {
							ATK.Reset();
							IsAttacking = false;
							x = tempX;
							y = tempY;
						}
					}
				}

				if (counter > 200) {
					counter = 0;
					IsAttacking = false;
					IsRising = true;
				}
			}

			ATK.OnMove();
			index->OnMove();
		}
	}
	void Spark::OnShow(Map* m, Kirby* k) {
		die.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		if (is_alive) {
			index->SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			index->OnShow();
			if (IsAttacking) {
				ATK.SetTopLeft(m->ScreenX(midX-ATK.Width()/2),m->ScreenY(midY-ATK.Height()/2));
				ATK.OnShow();
			}
		}
		else
		{
			if (!die.IsFinalBitmap() && !is_sucked)
			{
				die.OnShow();
				die.OnMove();
			}
		}
	}

	bool Spark::HitSpark(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = GetX1() - 10;	// 左上角x座標
		int y1 = GetY1() - 10;	// 左上角y座標
		int x2 = GetX2() + 10;	// 右下角x座標
		int y2 = GetY2() + 10;	// 右下角y座標
		// 檢測矩形與參數矩形是否有交集
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}
}