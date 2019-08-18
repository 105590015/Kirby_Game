#pragma once
#include "Map.h"

namespace game_framework {
	class Bullet
	{
	public:
		Bullet();
		int  GetX1();	             // 左上角 x 座標
		int  GetY1();	             // 左上角 y 座標
		void SetXY(int sx, int sy);  // 設定座標
		virtual int  GetX2() = 0;	 // 右下角 x 座標
		virtual int  GetY2() = 0;	 // 右下角 y 座標
		virtual void LoadBitmap() = 0;                    // 載入圖形
		virtual void OnMove(Map *m, bool direction) = 0;  // 移動
		virtual void OnShow(Map *m) = 0;                  // 將圖形貼到畫面
	protected:
		int x, y;
	};
}
