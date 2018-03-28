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
		const int X_POS = 280;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		flyDelay = 46;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isSpace = isFly = false;
		is_alive = RightOrLeft = true;
	}

	bool Kirby::IsAlive()
	{
		return is_alive;
	}

	void Kirby::LoadBitmap()
	{
		originR.LoadBitmap(IDB_KB_R_0, RGB(255, 255, 255));
		originL.LoadBitmap(IDB_KB_L_0, RGB(255, 255, 255));
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
			RightOrLeft = false;        //�]�w���V����
			if((isMovingUp&&flyDelay<1) || !isMovingUp)  //�V�����椤�Υ��`�V����
				if(m->isEmpty(x + 319 - 1, y + 239))//�P�_����O�_�i��
					x -= STEP_SIZE;
		}
		if (isMovingRight)
		{
			RightOrLeft = true;          //�]�w���V�k��
			if((isMovingUp&&flyDelay<1) || !isMovingUp)   //�V�k���椤�Υ��`�V�k��
				if (m->isEmpty(x + 319 + 1, y + 239))   //�P�_�k��O�_�i��
					x += STEP_SIZE;
		}
		if (isMovingUp)
		{
			if (flyDelay > 0)             //����e���˼�
				flyDelay--;
			else if (m->isEmpty(x + 319, y + 239 - 1))  //�P�_�W���O�_�i��
				y -= STEP_SIZE;
		}
		if (isMovingDown)
			if (m->isEmpty(x + 319, y + 239 + 1))   //�P�_����O�_�i��
				y += STEP_SIZE;
		if (isSpace)
		{
			PrepareFlyRight.Reset();
			PrepareFlyLeft.Reset();
			flyDelay = 46;
		}
	}

	void Kirby::OnShow(Map *m)
	{
		if (is_alive) {
			originR.SetTopLeft(x, y);
			originL.SetTopLeft(x, y);
			GoLeft.SetTopLeft(x, y);
			GoRight.SetTopLeft(x, y);
			PrepareFlyRight.SetTopLeft(x, y);
			PrepareFlyLeft.SetTopLeft(x, y);
			FlyRight.SetTopLeft(x, y);
			FlyLeft.SetTopLeft(x, y);
		}

		if (isMovingLeft && !isMovingUp)
		{
			GoLeft.OnShow();
			GoLeft.OnMove();
		}
		if (isMovingRight && !isMovingUp && !isMovingLeft)
		{
			GoRight.OnShow();
			GoRight.OnMove();
		}
		if (isMovingUp&&RightOrLeft)      //���ۥk���W
		{
			if (flyDelay > 0)             //����e���˼�
			{
				PrepareFlyRight.OnShow();
				PrepareFlyRight.OnMove();
				flyDelay--;
			}
			else
			{
				FlyRight.OnShow();
				FlyRight.OnMove();
			}
		}
		if (isMovingUp && !RightOrLeft)       //���ۥ����W
		{
			if (flyDelay > 0)               //����e�˼�
			{
				PrepareFlyLeft.OnShow();
				PrepareFlyLeft.OnMove();
				flyDelay--;
			}
			else
			{
				FlyLeft.OnShow();
				FlyLeft.OnMove();
			}
		}
		if(!(isMovingDown|| isMovingLeft|| isMovingRight|| isMovingUp)&&RightOrLeft)         //���ۥk����
			originR.ShowBitmap();
		if (!(isMovingDown || isMovingLeft || isMovingRight || isMovingUp) && !RightOrLeft)  //���V������
			originL.ShowBitmap();
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