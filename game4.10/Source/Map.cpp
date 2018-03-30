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
		background.SetTopLeft(-sx, -sy); // 指定第(i, j)這一格的座標
		background.ShowBitmap();
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) 為地圖的點座標
	{
		int gx = x / 20; // 轉換為X軸格座標(整數除法)
		int gy = y / 20; // 轉換為Y軸格座標(整數除法)
		//map[x][y]中的y表示X軸的格數，x表示Y軸
		return map[gy][gx] == 0; // 假設 0 代表空的
	}
}