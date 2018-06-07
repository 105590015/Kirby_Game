#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include <fstream> 


namespace game_framework {
	Map::Map()
	{
	}

	void Map::SetMouse(int x, int y) {  //設定滑鼠座標
		mx = x;
		my = y;
	}

	void Map::IsLclick(bool flag) {		//設定左鍵是否按下
		Lclick= flag;

		ofstream output(Mapfile);

		for (int i = 0; i < mapSize_Y; i++) {
			for (int j = 0; j < mapSize_X; j++) {
				output << map[i][j] << " ";
			}
			output << endl;
		}
		output.close();
	}

	void Map::IsRclick(bool flag) {		//設定右鍵是否按下
		Rclick= flag;

		ofstream output(Mapfile);

		for (int i = 0; i < mapSize_Y; i++) {
			for (int j = 0; j < mapSize_X; j++) {
				output << map[i][j] << " ";
			}
			output << endl;
		}
		output.close();
	}

	int Map::GetWidth() {				//取得背景寬度
		return foreground.Width();
	}

	int Map::GetHeight() {				//取得背景長度
		return foreground.Height();
	}

	int  Map::ScreenX(int x)			//回傳人物在螢幕上座標	
	{
		return x-sx;
	}

	int  Map::ScreenY(int y)			//同上
	{
		return y-sy;
	}

	void Map::Initialize()
	{
		//const int X_POS = 320;
		//const int Y_POS = 240;
		//sx = X_POS;
		//sy = Y_POS;

		
		ifstream file(Mapfile);			//將資料存入陣列
		for (int i = 0; i<mapSize_Y; i++)
		{
			for (int j = 0; j < mapSize_X; j++) {
				file >> map[i][j];
			}
		}
		file.close();
	}

	void Map::LoadBitmap(char* fore,COLORREF color,char* back,string file)
	{
		
		foreground.LoadBitmap(fore,color);
		background.LoadBitmap(back);
		Mapfile = file;
		mapSize_X = (foreground.Width() * 10 + 5) / 100;
		mapSize_Y = (foreground.Height() * 10 + 5) / 100;
		ball_1.LoadBitmap(".//RES//ball_1.bmp", RGB(0, 0, 0));
		ball_2.LoadBitmap(".//RES//ball_2.bmp", RGB(0, 0, 0));
		ball_3.LoadBitmap(".//RES//ball_3.bmp", RGB(0, 0, 0));
		
	}
	
	void Map::OnMove(int x, int y)		//地圖隨人物移動
	{
		sx = x - SIZE_X / 2;			//讓人物保持在地圖中間
		sy = y - SIZE_Y / 2;

		if (x <= SIZE_X / 2) {				//設定當人物接近邊界時地圖移動停止
			sx = 0;
		}

		if (x >= foreground.Width() - SIZE_X / 2) {
			sx = foreground.Width() - SIZE_X;
		}

		if (y <= SIZE_Y / 2) {
			sy = 0;
		}

		if (y >= foreground.Height() - SIZE_Y / 2) {
			sy = foreground.Height() - SIZE_Y;
		}
	}

	void Map::OnShow()
	{
		background.SetTopLeft(0, 0);
		background.ShowBitmap();
		foreground.SetTopLeft(-sx, -sy); // 指定第(i, j)這一格的座標
		foreground.ShowBitmap();

		
		//ofstream set(Mapfile);			//第一次建立地圖設立初始值
		//for (int i = 0; i < mapSize_Y; i++) {
		//	for (int j = 0; j < mapSize_X; j++) {
		//		set << 0 << " ";
		//	}
		//	set << endl;
		//}
		//set.close();

		for (int i = 0; i < mapSize_Y; i++) {
			for (int j = 0; j < mapSize_X; j++) {
				int x = j * 10 - sx; // 算出第(i, j)這一格的 x 螢幕座標
				int y = i * 10 - sy; // 算出第(i, j)這一格的 y 螢幕座標
				if (mx >= x && mx <= x + 10 && my >= y && my <= y + 10) { //判斷滑鼠位置
					//if (Lclick) {				//左鍵為設立障礙物
					//	map[i][j] = 1;
					//}

					//if (Lclick) {				//左鍵為設立可穿透的障礙物
					//	map[i][j] = 2;
					//} 

					//if (Lclick) {				//左鍵為設立斜坡
					//	map[i][j] = 3;
					//}

					//if (Rclick) {			//右鍵為取消障礙物
					//	map[i][j] = 0;
					//}
				}
				switch (map[i][j]) {
					case 1:
						ball_1.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
						ball_1.ShowBitmap();
						break;
					case 2:
						ball_2.SetTopLeft(x, y);
						ball_2.ShowBitmap();
						break;

					case 3:
						ball_3.SetTopLeft(x, y);
						ball_3.ShowBitmap();
						break;

				}
			}
		}
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) 為地圖的點座標
	{
		int gx = x / 10; // 轉換為X軸格座標(整數除法)
		int gy = y / 10; // 轉換為Y軸格座標(整數除法)
		//map[x][y]中的y表示X軸的格數，x表示Y軸
		return map[gy][gx] == 0; // 假設 0 代表空的
	}

	bool Map::isEmpty_2(int x, int y) // (x, y) 為地圖的點座標
	{
		int gx = x / 10; // 轉換為X軸格座標(整數除法)
		int gy = y / 10; // 轉換為Y軸格座標(整數除法)
		//map[x][y]中的y表示X軸的格數，x表示Y軸
		return map[gy][gx] == 0 || map[gy][gx]==2; // 假設 0 代表空的2代表可穿越
	}

	bool Map::isSlope(int x, int y) {
		int gx = x / 10; // 轉換為X軸格座標(整數除法)
		int gy = y / 10; // 轉換為Y軸格座標(整數除法)
						 //map[x][y]中的y表示X軸的格數，x表示Y軸
		return map[gy][gx] == 3 ;// 假設 3 代表斜坡
	}
}