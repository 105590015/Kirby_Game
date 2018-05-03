#pragma once
#include"Enemy.h"
#include "Map.h"


namespace game_framework {
	class Spark :public Enemy
	{
	public:
		Spark ();
		void LoadBitmap();
		void OnShow(Map*);
		void OnMove(Map*,Kirby*);
		void Initialize(int ,int);
		void Attack(Kirby*);
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
		double i = 1.0;
		void Jump(Kirby*);
		CAnimation *index;
		CAnimation Jump_L, Jump_R, Sucked_L, Sucked_R,ATK,AttackRange,Stand_L,Stand_R;

	};


}
