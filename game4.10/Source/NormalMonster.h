#pragma once
#include "Enemy.h"
#include "Map.h"
#include "Kirby.h"
namespace game_framework {

	class NormalMonster:public Enemy
	{
	public:
		NormalMonster();
		void Initialize(int ox, int oy, int sx, int ex, bool direction);		// �]�w����l��
		int GetX2();
		int GetY2();
		void LoadBitmap();
		void OnShow(Map *m, Kirby *kirby);      // ���
		void OnMove(Map *m, Kirby *kirby);      // ����
		void Attack(Map *m, Kirby* kirby);      // ����
	protected:
		CMovingBitmap isSuckedR, isSuckedL;
		CAnimation goLeft, goRight, die;
	private:
		int startX, endX;
		int count, velocity;
	};
}