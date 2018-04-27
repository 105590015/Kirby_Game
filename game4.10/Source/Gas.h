#pragma once
#include "Bullet.h"
#include "Map.h"
namespace game_framework {
	class Gas : public Bullet
	{
	public:
		Gas();
		int  GetX2();	                      // �k�U�� x �y��
		int  GetY2();	                      // �k�U�� y �y��
		void LoadBitmap();                    // ���J�ϧ�
		void OnMove(Map *m, bool direction);  // ����
		void OnShow(Map *m);                  // �N�ϧζK��e��
	protected:
		CMovingBitmap gas;
	};
}