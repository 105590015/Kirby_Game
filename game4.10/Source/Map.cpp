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

	int Map::GetWidth() {
		return background.Width();
	}

	int Map::GetHeight() {
		return background.Height();
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
		const int X_POS = 320;
		const int Y_POS = 240;
		sx = X_POS;
		sy = Y_POS;
	}

	void Map::LoadBitmap(int pic)
	{
		background.LoadBitmap(pic);
	}

	void Map::OnMove(int x, int y)
	{
		sx = x - SIZE_X / 2;
		sy = y - SIZE_Y / 2;

		if (x <= SIZE_X / 2) {
			sx = 0;
		}

		if (x >= background.Width() - SIZE_X / 2) {
			sx = background.Width() - SIZE_X;
		}

		if (y <= SIZE_Y / 2) {
			sy = 0;
		}

		if (y >= background.Height() - SIZE_Y / 2) {
			sy = background.Height() - SIZE_Y;
		}
	}

	void Map::OnShow()
	{
		background.SetTopLeft(-sx, -sy); // ���w��(i, j)�o�@�檺�y��
		background.ShowBitmap();
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) ���a�Ϫ��I�y��
	{
		int gx = x / 20; // �ഫ��X�b��y��(��ư��k)
		int gy = y / 20; // �ഫ��Y�b��y��(��ư��k)
		//map[x][y]����y���X�b����ơAx���Y�b
		return map[gy][gx] == 0; // ���] 0 �N��Ū�
	}
}