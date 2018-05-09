#pragma once
#include "Map.h"

namespace game_framework {
	class LostAbility
	{
	public:
		LostAbility();
		int  type;                                          // 種類
		int  GetX();                                        
		int  GetY();
		bool IsAlive();
		void SetAlive(bool flag);
		void Initialize(int t, int sx, int sy);             // 初始化
		void LoadBitmap();                                  // 載入圖形
		void OnMove(Map *m, int kx, int ky, bool isSuck);   // 移動
		void OnShow(Map *m);                                // 將圖形貼到畫面
	protected:
		int x, y;
		int direction;   // 亂彈的方向
		int time;        // 顯示時間
		bool isAlive;
		CAnimation star;
	};
}