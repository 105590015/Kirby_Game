#pragma once
#include "Map.h"
namespace game_framework {

	class Enemy
	{
	public:
		Enemy(int ox, int oy);
		bool IsAlive();					// �O�_����
		void SetXY(int nx, int ny);		// �]�w���W�����y��
		virtual void OnShow(Map *m);    // ���
		virtual void OnMove(Map *m);    // ����
		virtual void Attack();          // ����
		virtual void hurted();          // �Q����
		virtual bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	protected:
		int x, y;					// ���W���y��
		bool is_alive;				// �O�_����
		bool RightOrLeft;           // �P�_���k
	private:
		int hp;
	};
}