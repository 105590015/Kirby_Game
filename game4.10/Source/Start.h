#pragma once
#include "Bullet.h"
#include "Map.h"
namespace game_framework {
	class Start : public Bullet
	{
	public:
		Start();
		int  GetX2();	                      // 右下角 x 座標
		int  GetY2();	                      // 右下角 y 座標
		void LoadBitmap();				      // 載入圖形
		void OnMove(Map *m, bool direction);  // 移動
		void OnShow(Map *m);                  // 將圖形貼到畫面
	protected:
		CAnimation start;
	};
}