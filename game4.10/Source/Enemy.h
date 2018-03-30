#pragma once
#include "Map.h"
namespace game_framework {

	class Enemy
	{
	public:
		Enemy(int ox, int oy);
		bool IsAlive();					// 是否活著
		void SetXY(int nx, int ny);		// 設定左上角的座標
		virtual void OnShow(Map *m);    // 顯示
		virtual void OnMove(Map *m);    // 移動
		virtual void Attack();          // 攻擊
		virtual void hurted();          // 被攻擊
		virtual bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// 是否碰到參數範圍的矩形
	protected:
		int x, y;					// 左上角座標
		bool is_alive;				// 是否活著
		bool RightOrLeft;           // 判斷左右
	private:
		int hp;
	};
}