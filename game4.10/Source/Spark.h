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
		int GetX2();
		int GetY2();

	private:
		bool IsRising;
		int velocity;
		int init_velocity;
		int floor;
		CAnimation *index;
		CAnimation Jump_L, Jump_R, Sucked_L, Sucked_R,Attack,Stand_L,Stand_R;

	};


}
