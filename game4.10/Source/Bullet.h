#pragma once

namespace game_framework {
	class Bullet
	{
	public:
		Bullet();
		int  GetX1();	// 左上角 x 座標
		int  GetY1();	// 左上角 y 座標
		virtual int  GetX2();	// 右下角 x 座標
		virtual int  GetY2();	// 右下角 y 座標
		void SetXY(int sx, int sy);           // 設定座標
		bool IsAlive();
	protected:
		int x, y;
		bool isAlive;
	};
}
