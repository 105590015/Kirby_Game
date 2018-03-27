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
		const int X_POS = -320;
		const int Y_POS = -240;
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

	}

	void Map::OnShow()
	{
		background.SetTopLeft(sx, sy); // 指定第(i, j)這一格的座標
		background.ShowBitmap();
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) 為地圖的點座標
	{
		int gx = x / 64; // 轉換為X軸格座標(整數除法)
		int gy = y / 48; // 轉換為Y軸格座標(整數除法)
		//map[x][y]中的y表示X軸的格數，x表示Y軸
		return map[gy][gx] == 0; // 假設 0 代表空的
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