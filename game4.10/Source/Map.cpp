#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Map
	/////////////////////////////////////////////////////////////////////////////
	Map::Map()
	{
		Initialize();
	}

	int  Map::ScreenX(int x)
	{
		return x-sx;
	}

	int  Map::ScreenY(int y)
	{
		return y-sy;
	}

	void Map::Initialize()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map[i][j] = 0;
			}
		}
		map[5][5] = 10;
		const int X_POS = 280;
		const int Y_POS = 400;
		sx = X_POS;
		sy = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void Map::LoadBitmap()
	{
		background.LoadBitmap(IDB_MAP);
	}

	void Map::OnMove()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{

			}
		}
		const int STEP_SIZE = 2;
		if (isMovingLeft)
			sx -= STEP_SIZE;
		if (isMovingRight)
			sx += STEP_SIZE;
		if (isMovingUp)
			sy -= STEP_SIZE;
		if (isMovingDown)
			sy += STEP_SIZE;
	}

	void Map::OnShow()
	{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int x = i * 80 - sx; // ��X��(i, j)�o�@�檺 x �ù��y��
				int y = j * 80 - sy; // ��X��(i, j)�o�@�檺 y �ù��y��
				switch (map[i][j]/10) {
				case 1:
					background.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					background.ShowBitmap();
				}
			}
		}
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) ���a�Ϫ��I�y��
	{
		int gx = x / 160; // �ഫ����y��(��ư��k)
		int gy = y / 120; // �ഫ����y��(��ư��k)
		return map[gx][gy] == 0; // ���] 0 �N��Ū�
	}

	void Map::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Map::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Map::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Map::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
}