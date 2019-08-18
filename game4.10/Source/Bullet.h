#pragma once
#include "Map.h"

namespace game_framework {
	class Bullet
	{
	public:
		Bullet();
		int  GetX1();	             // ���W�� x �y��
		int  GetY1();	             // ���W�� y �y��
		void SetXY(int sx, int sy);  // �]�w�y��
		virtual int  GetX2() = 0;	 // �k�U�� x �y��
		virtual int  GetY2() = 0;	 // �k�U�� y �y��
		virtual void LoadBitmap() = 0;                    // ���J�ϧ�
		virtual void OnMove(Map *m, bool direction) = 0;  // ����
		virtual void OnShow(Map *m) = 0;                  // �N�ϧζK��e��
	protected:
		int x, y;
	};
}
