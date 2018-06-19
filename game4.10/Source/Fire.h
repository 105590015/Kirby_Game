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
		CAnimation *index;
		CAnimation originR, originL, Sucked_L, Sucked_R, Attack_R, Attack_L, Walk_L, Walk_R, attack, die;
		bool HitFire(int tx1, int ty1, int tx2, int ty2);
	};

}