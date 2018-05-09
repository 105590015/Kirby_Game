#pragma once

namespace game_framework {
	class Bullet
	{
	public:
		Bullet();
		int  GetX1();	// ���W�� x �y��
		int  GetY1();	// ���W�� y �y��
		virtual int  GetX2();	// �k�U�� x �y��
		virtual int  GetY2();	// �k�U�� y �y��
		void SetXY(int sx, int sy);           // �]�w�y��
		bool IsAlive();
	protected:
		int x, y;
		bool isAlive;
	};
}
