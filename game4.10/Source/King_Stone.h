#pragma once
#include"Enemy.h"
#include"Kirby.h"
#include"Map.h"

namespace game_framework {
	class Stone : public Enemy
	{
	public:
		Stone();
		void LoadBitmap();
		void Init(int sx, int sy);
		void OnShow(Map*, Kirby*);
		void OnMove(Map*, Kirby*);
		void Attack(Map*, Kirby*);
		void SetAlive(bool flag);
		int GetX2();
		int GetY2();

	private:
		CAnimation stone;
	};

}
