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

	void Kirby::Initialize(int px,int py)  //�]�w�b�}��b�ù�����l��m
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
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_0.bmp", RGB(207,176,255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_1.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_2.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_3.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_4.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_5.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_6.bmp", RGB(207, 176, 255));
		RunLeft.AddBitmap(".\\RES\\Kirby\\RUN_L_7.bmp", RGB(207, 176, 255));	
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_0.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_1.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_2.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_3.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_4.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_5.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_6.bmp", RGB(207, 176, 255));
		RunRight.AddBitmap(".\\RES\\Kirby\\RUN_R_7.bmp", RGB(207, 176, 255));
	}

	void Kirby::OnMove(Map *m)
	{
		//�Q�����B���O�b�Ť��]�S�W�X��ɮ�
		if (isHurted && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
		{
			if (RightOrLeft && m->isEmpty(GetX1() - STEP_SIZE, GetY1() + hurtedR.Height() / 2) && x - STEP_SIZE >= 0)
				x -= STEP_SIZE;
			else if(!RightOrLeft && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - hurtedL.Height() / 2) && x + STEP_SIZE <= m->GetWidth() - GoRight.Width())
				x += STEP_SIZE;
		}
		else
		{
			if (isMovingLeft)
			{
				RightOrLeft = false;        //�]�w���V����
				//���P�_����O�_�i���B�S����Down�A���A�n�O�V�����椤�Υ��`�V����
				if (m->isEmpty(GetX1() - STEP_SIZE, GetY1() + GoLeft.Height() / 2) && !isMovingDown && (isFly || !isMovingUp))  
				{
					if (x <= 0) //���
						x = 0;
					else if (isRunning && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
						x -= STEP_SIZE * 2;
					else
						x -= STEP_SIZE;
				}
			}
			else if (isMovingRight)
			{
				RightOrLeft = true;          //�]�w���V�k��
				//���P�_�k��O�_�i���B�S����Down�A���A�n�O�V�k���椤�Υ��`�V�k��
				if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - GoRight.Height() / 2) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x >= m->GetWidth() - GoRight.Width())  //���
						x = m->GetWidth() - GoRight.Width();
					else if (isRunning && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
						x += STEP_SIZE * 2;
					else
						x += STEP_SIZE;
				}
			}
			if (isMovingUp)
			{
				if (isFly && m->isEmpty(GetX1() + FlyRight.Width() / 2, GetY1() - STEP_SIZE))  //�P�_���椤�W���O�_�i��
				{
					if (y <= 0)  //���
						y = 0;
					else
						y -= STEP_SIZE;
				}
			}
			if (isJump)
			{
				JumpDistance-=3;
				if (m->isEmpty(GetX1() + JumpRight.Width() / 2, GetY1() - 3))  //�|���|�����Y
					y -= 3;
				if (JumpDistance == 0)
				{
					JumpDistance = 60;
					isJump = false;
				}
			}
			if ((isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //�b�a���W�ۤU������
			{
				isKick = true;
				KickDistance -= 3;
				if (RightOrLeft && m->isEmpty(GetX2() + 3, GetY2() - 2) && x + 3 <= m->GetWidth() - downAttackR.Width())        //�k��|���|����(y-2�O���v���ɤj�p���t��)
					x += 3;
				else if (!RightOrLeft && m->isEmpty(GetX1() - 3, GetY2() - 2) && x - 3 >= 0)  //����|���|����(y-2�O���v���ɤj�p���t��)
					x -= 3;
				//��.������.�}�S���a������ϥν���
				if (KickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
				{
					KickDistance = 42;
					isKick = false;
				}
			}
		}
		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //�a�l�ޤO
		{
			if (isFly)
				y += 1;
			else
			{
				if (y >= m->GetHeight() - GoRight.Height())
					y = m->GetHeight() - GoRight.Height();
				else
					y += STEP_SIZE;
			}
		}
	}

	void Kirby::OnShow(Map *m)
	{
		if (is_alive) {    //�����ʵe��l�]�w
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
			hurtedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			hurtedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RunRight.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RunLeft.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		}
		if (isHurted)   // �Q����
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
			{
				isHurted = false;
				hurtedL.Reset();
				hurtedR.Reset();
			}
		}
		else if (isJump)   //���D
		{
			if(RightOrLeft)
				JumpRight.ShowBitmap();
			else
				JumpLeft.ShowBitmap();
		}
		else if (isSpace && isFly)   //�R��
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
			if (PrepareFlyRight.IsFinalBitmap() || PrepareFlyLeft.IsFinalBitmap())   //����e�l��
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
		else if (isFly)  //���椤�a�l�ޤO
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
		else if (!isFly && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))  //�ۥѸ���
		{
			if (RightOrLeft)
				LandingRight.ShowBitmap();
			else
				LandingLeft.ShowBitmap();
		}
		else if (isKick)   //����
		{
			if(RightOrLeft)
				downAttackR.ShowBitmap();
			else
				downAttackL.ShowBitmap();
		}
		else if (isMovingDown && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))   //�Y�p
		{
			if(RightOrLeft)
				DownRight.ShowBitmap();
			else
				DownLeft.ShowBitmap();
		}
		else if (!isFly && isRunning)  //�]
		{
			if (!RightOrLeft)
			{
				RunLeft.OnShow();
				RunLeft.OnMove();
			}
			else
			{
				RunRight.OnShow();
				RunRight.OnMove();
			}
			
		}
		else if (!isFly && isMovingLeft)   //�@��V����
		{
			GoLeft.OnShow();
			GoLeft.OnMove();
		}
		else if(!isFly && isMovingRight)   //�@��V�k��
		{
			GoRight.OnShow();
			GoRight.OnMove();
		}
		else if (RightOrLeft)   //���ۥk
			originR.ShowBitmap();
		else if (!RightOrLeft)  //���ۥ�
			originL.ShowBitmap();
		if (!isMovingUp && !isFly)   //�S�l��]�S����N�nreset�l��ʵe
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