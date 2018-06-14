#pragma once
#include"Enemy.h"
#include "Map.h"


namespace game_framework {
	class Spark :public Enemy
	{
	public:
		Spark ();
		void LoadBitmap();
		void OnShow(Map*,Kirby*);
		void OnMove(Map*,Kirby*);
		void Initialize(int ,int);
		void Attack(Map*, Kirby*);
		int GetX2();
		int GetY2();

	private:
		bool IsRising;
		bool IsAttacking;
		int velocity;
		int init_velocity;
		int counter;
		int StepSize;
		int tempX, tempY;
		int midX, midY;
		CAnimation *index;
		CAnimation Jump_L, Jump_R, Sucked_L, Sucked_R,ATK,AttackRange,Stand_L,Stand_R,die;
		bool HitSpark(int tx1, int ty1, int tx2, int ty2);
	};


}
