#pragma once
#include"Enemy.h"
#include"Kirby.h"
#include"Map.h"

namespace game_framework {
	class King_Bomb : public Enemy
	{
	public:
		King_Bomb();
		void LoadBitmap();
		void Init(int sx, int sy);
		void OnShow(Map* m, Kirby* kirby);
		void OnMove(Map* m, Kirby* kirby);
		void Attack(Map* m, Kirby* kirby);
		void FireAttack(Map* m, Kirby* kirby);
		int GetX2();
		int GetY2();
	private:
		int counter;
		CMovingBitmap bomb;
		CAnimation fire;
	};

}