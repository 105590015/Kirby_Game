#pragma once
#include "Enemy.h"
#include "Kirby.h"
#include "Map.h"
#include "King_Stone.h"

namespace game_framework {
	class Tree : public Enemy
	{
	public:
		Tree();

		void LoadBitmap();
		void OnShow(Map*, Kirby*);
		void OnMove(Map*, Kirby*);
		void Initialize(int, int);
		void Attack(Map*, Kirby*);
		void StoneAttack(Map*, Kirby*);
		bool IsAlive();
		int GetX2();
		int GetY2();

	private:

		bool IsAttacking;

		int counter;
		CAnimation *index;
		CAnimation normal, mad, hurted, die;
		Stone stone[12];
	};

}