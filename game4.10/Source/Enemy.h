#pragma once
#include "Map.h"
#include "Kirby.h"
namespace game_framework {

	class Enemy
	{
	public:
		Enemy();
		int GetX1();                                  // 左上角 x 座標
		int GetY1();                                  // 左上角 y 座標
		void Hurted(Kirby* kirby);                    // 被攻擊
		void Sucked(Kirby* kirby);                    // 被吸
		void SetAlive(bool flag);                     // 設定死活
		bool IsAlive();                               // 是否活著
		virtual int GetX2();                          // 右下角 x 座標
		virtual int GetY2();                          // 右下角 y 座標
		virtual void OnShow(Map *m, Kirby *kirby);    // 顯示
		virtual void OnMove(Map *m, Kirby* kirby);    // 移動
		virtual void LoadBitmap();                    // 讀圖
		virtual void Attack(Kirby* kirby);            // 攻擊
	protected:
		int x, y, hp;				// 左上角座標.血量
		bool is_alive;				// 是否活著
		bool is_sucked;             // 是否被吸
		bool RightOrLeft;           // 判斷左右
		bool Ishurted;              // 受傷與否
		bool IsKing;                // 是不是王
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);   // 是否碰到參數範圍的矩形
		double ComputeDistance(int tx1, int ty1);                // 計算距離
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
			lostAbility,            // 17
			ending                  // 18
		};
	};
}