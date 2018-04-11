#pragma once
#include "Map.h"
#include "Kirby.h"
namespace game_framework {

	class Enemy
	{
	public:
		Enemy();
		int GetX1();                                  // ���W�� x �y��
		int GetY1();                                  // ���W�� y �y��
		bool IsAlive();
		bool IsSucked();
		void hurted(Kirby* kirby);                    // �Q����
		virtual int GetX2();                          // �k�U�� x �y��
		virtual int GetY2();                          // �k�U�� y �y��
		virtual void OnShow(Map *m, Kirby *kirby);    // ���
		virtual void OnMove(Map *m, Kirby* kirby);    // ����
		virtual void Attack(Kirby* kirby);            // ����
	protected:
		int x, y, hp;				// ���W���y��.��q
		bool is_alive;				// �O�_����
		bool is_sucked;             // �O�_�Q�l
		bool RightOrLeft;           // �P�_���k
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};
}