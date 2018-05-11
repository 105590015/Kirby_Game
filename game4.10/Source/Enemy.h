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
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);   // 是否碰到參數範圍的矩形
		double ComputeDistance(int tx1, int ty1);                   // 計算距離
	};
}