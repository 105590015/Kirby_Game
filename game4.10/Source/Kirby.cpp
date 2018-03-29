#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBall: Ball class
	/////////////////////////////////////////////////////////////////////////////

	Kirby::Kirby()
	{
		Initialize();
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

	void Kirby::Initialize()
	{
		const int X_POS = 640;
		const int Y_POS = 480;
		x = X_POS;
		y = Y_POS;
		flyDelay = 46;
		JumpDelay = 30;
		ExhaleDelay = 10;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isSpace = isJump = isFly = false;
		is_alive = RightOrLeft = true;
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
	}

	void Kirby::OnMove(Map *m)
	{
		if (isMovingLeft)
		{
			//�H�U�⦡��x + 320�Py + 240�O�ɦa�ϲ��ʪ���l;�d�񪺹Ϥj�p�j�h��20 * 20, x + 10�Py + 10�O�N�P�_�I�����I�]�b�d�񤤤�
			RightOrLeft = false;        //�]�w���V����
			if (m->isEmpty(x + 10 - STEP_SIZE, y + 10) && !isMovingDown && ((isMovingUp&&flyDelay < 1) || !isMovingUp))  //���P�_����O�_�i���B�S����Down�A���A�n�O�V�����椤�Υ��`�V����
			{
				if (x <= 0) //���
					x = 0;
				else
					x -= STEP_SIZE;
			}
		}
		if (isMovingRight)
		{
			RightOrLeft = true;          //�]�w���V�k��
			if (m->isEmpty(x + 10 + STEP_SIZE, y + 10) && !isMovingDown && ((isMovingUp&&flyDelay < 1) || !isMovingUp))   //���P�_�k��O�_�i���B�S����Down�A���A�n�O�V�k���椤�Υ��`�V�k��
			{
				if (x >= m->GetWidth() - GoRight.Width())  //���
					x = m->GetWidth() - GoRight.Width();
				else
					x += STEP_SIZE;
			}
		}
		if (isMovingUp)
		{
			if (flyDelay > 0)             //����e���˼�
				flyDelay--;
			else if (m->isEmpty(x + 10, y + 10 - STEP_SIZE))  //�P�_�W���O�_�i��
			{
				if (y <= 0)  //���
					y = 0;
				else
					y -= STEP_SIZE;
			}
		}
		if (isSpace)
		{
			PrepareFlyRight.Reset();
			PrepareFlyLeft.Reset();
			flyDelay = 46;
			isFly = false;
		}
		if (isJump)
		{
			JumpDelay--;
			if(m->isEmpty(x + 10, y + 10 - 4))  //�|���|�����Y
				y -= 4;
			if (JumpDelay == 0)
			{
				JumpDelay = 30;
				isJump = false;
			}
		}
		if(!(isMovingUp || isJump) && m->isEmpty(x + 10, y + 20 + 1)) //�a�l�ޤO
			y += 1;
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
		}
		if (isJump && RightOrLeft)
			JumpRight.ShowBitmap();
		else if (isJump && !RightOrLeft)
			JumpLeft.ShowBitmap();
		else if (isMovingUp && RightOrLeft)      //���ۥk���W
		{
			if (flyDelay > 0)             //����e���˼�
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
		else if (isMovingUp && !RightOrLeft)   //���ۥ����W
		{
			if (flyDelay > 0)               //����e�˼�
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
		else if (isSpace && RightOrLeft)   //�V�k�R��
		{
			ExhaleDelay--;
			ExhaleRight.ShowBitmap();
			if (ExhaleDelay == 0)
			{
				ExhaleDelay = 10;
				isSpace = false;
			}
		}
		else if (isSpace && !RightOrLeft)  //�V���R��
		{
			ExhaleDelay--;
			ExhaleLeft.ShowBitmap();
			if (ExhaleDelay == 0)
			{
				ExhaleDelay = 10;
				isSpace = false;
			}
		}
		else if (isFly && RightOrLeft)  //���ۥk���椤�a�l�ޤO
		{
			FlyRight.OnShow();
			FlyRight.OnMove();
		}
		else if (isFly && !RightOrLeft) //���V�����椤�a�ߤޤO
		{
			FlyLeft.OnShow();
			FlyLeft.OnMove();
		}
		else if (isMovingDown && RightOrLeft && !m->isEmpty(x + 10, y + 20 + 1))  //���V�k�Y�p
			DownRight.ShowBitmap();
		else if (isMovingDown && !RightOrLeft && !m->isEmpty(x + 10, y + 20 + 1))  //���V���Y�p
			DownLeft.ShowBitmap();
		else if (isMovingLeft && !isFly)  //�@��V����
		{
			GoLeft.OnShow();
			GoLeft.OnMove();
		}
		else if (isMovingRight && !isFly)  //�@��V�k��
		{
			GoRight.OnShow();
			GoRight.OnMove();
		}
		else if (RightOrLeft)   //���ۥk
			originR.ShowBitmap();
		else if (!RightOrLeft)  //���ۥ�
			originL.ShowBitmap();
		if (!isMovingUp)   //�S�l��N�nreset�l��ʵe
		{
			PrepareFlyRight.Reset();
			PrepareFlyLeft.Reset();
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

	void Kirby::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	bool Kirby::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = x;				// �d�񥪤W��x�y��
		int y1 = y;				// �d�񥪤W��y�y��
		int x2 = x1 + originR.Width();	// �d��k�U��x�y��
		int y2 = y1 + originR.Height();	// �d��k�U��y�y��
									//
									// �˴��d�񪺯x�λP�ѼƯx�άO�_���涰
									//
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}
}