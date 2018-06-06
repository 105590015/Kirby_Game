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
	private:
		enum COPY_AUDIO_ID {		// 定義各種音效的編號
			AUDIO_BACKGROUND,       // 0
			jump,                   // 1
			landing,                // 2
			kick,                   // 3
			die,                    // 4
			fly,                    // 5
			hurted,                 // 6
			run,                    // 7
			suck,                   // 8
			gasSound,               // 9
			starSound,              // 10
			swallow,                // 11
			spark,                  // 12
			fire,                   // 13
			stone,                  // 14
			start,                  // 15
			enemyDie,               // 16
			lostAbility             // 17
		};
	};
}