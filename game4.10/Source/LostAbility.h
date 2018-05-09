#pragma once
#include "Map.h"

namespace game_framework {
	class LostAbility
	{
	public:
		LostAbility();
		int  type;                                          // ����
		int  GetX();                                        
		int  GetY();
		bool IsAlive();
		void SetAlive(bool flag);
		void Initialize(int t, int sx, int sy);             // ��l��
		void LoadBitmap();                                  // ���J�ϧ�
		void OnMove(Map *m, int kx, int ky, bool isSuck);   // ����
		void OnShow(Map *m);                                // �N�ϧζK��e��
	protected:
		int x, y;
		int direction;   // �üu����V
		int time;        // ��ܮɶ�
		bool isAlive;
		CAnimation star;
	};
}