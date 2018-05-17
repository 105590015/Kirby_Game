#pragma once
#include"Enemy.h"
#include"Kirby.h"
#include"Map.h"

namespace game_framework {
	class Fire : public Enemy
	{
	public:
		Fire();

		void LoadBitmap();
		void OnShow(Map*, Kirby*);
		void OnMove(Map*, Kirby*);
		void Initialize(int, int);
		void Attack(Map*, Kirby*);
		int GetX2();
		int GetY2();

	private:

		bool IsAttacking;

		int counter;
		int StepSize;
		int tempX, tempY;
		int midX, midY;		
		CAnimation *index;
		CAnimation Sucked_L, Sucked_R, ATK, AttackRange, Walk_L, Walk_R, die;

	};

}