#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "LostAbility.h"

namespace game_framework {
	LostAbility::LostAbility() {
		isAlive = false;
	}

	int LostAbility::GetX()
	{
		return x;
	}

	int LostAbility::GetY()
	{
		return y;
	}

	bool LostAbility::IsAlive()
	{
		return isAlive;
	}

	void LostAbility::SetAlive(bool flag)
	{
		isAlive = flag;
	}

	void LostAbility::Initialize(int t, int sx, int sy)
	{
		x = sx;
		y = sy;
		type = t;
		direction = rand() % 4;  // ���U.���W.�k�W.�k�U�|�Ӥ�V�H��
		time = 240;              // ���8��
		isAlive = true;
	}

	void LostAbility::LoadBitmap()
	{
		star.AddBitmap(".\\RES\\start1.bmp", RGB(195, 195, 195));
		star.AddBitmap(".\\RES\\start2.bmp", RGB(195, 195, 195));
		star.AddBitmap(".\\RES\\start3.bmp", RGB(195, 195, 195));
		star.AddBitmap(".\\RES\\start4.bmp", RGB(195, 195, 195));
	}

	void LostAbility::OnMove(Map *m, int kx, int ky, bool isSuck)
	{
		double temp = sqrt((x - kx)*(x - kx) + (y - ky)*(y - ky));
		if((x - kx < 2) || (x - kx > 2) && (y - ky < -2) && (y - ky > 2)) // �T�{�P�P���}�d��
			time--;
		if (time == 0)
		{
			CAudio::Instance()->Play(lostAbility);
			isAlive = false;
		}
		if (temp < 150.0 && isSuck)
		{
			if (x > kx)
				x -= 3;
			else if (x < kx)
				x += 3;
			if (y > ky)
				y -= 3;
			else if (y < ky)
				y += 3;
		}
		else
		{
			// ���W
			if (direction == 0 && m->isEmpty(x - STEP_SIZE, y - STEP_SIZE) && x - STEP_SIZE > 0 && y - STEP_SIZE > 0)
			{
				x -= STEP_SIZE;
				y -= STEP_SIZE;
			}
			// �k�W
			else if (direction == 1 && m->isEmpty(x + star.Width() + STEP_SIZE, y - STEP_SIZE) && x + STEP_SIZE < m->GetWidth() - star.Width() && y - STEP_SIZE > 0)
			{
				x += STEP_SIZE;
				y -= STEP_SIZE;
			}
			// ���U
			else if (direction == 2 && m->isEmpty(x - STEP_SIZE, y + star.Height() + STEP_SIZE) && x - STEP_SIZE > 0)
			{
				x -= STEP_SIZE;
				y += STEP_SIZE;
			}
			// �k�U
			else if(direction == 3 && m->isEmpty(x + star.Width() + STEP_SIZE, y + star.Height() + STEP_SIZE) && x + STEP_SIZE < m->GetWidth() - star.Width())
			{
				x += STEP_SIZE;
				y += STEP_SIZE;
			}
			// �I�����H������V
			else if (direction == 0 || direction == 1)
				direction = rand() % 2 + 2;
			else if (direction == 2 || direction == 3)
				direction = rand() % 2;
		}
	}

	void LostAbility::OnShow(Map *m)
	{
		star.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		star.OnMove();
		star.OnShow();
	}
}