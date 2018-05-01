#pragma once
#include"Enemy.h"

namespace game_framework {
	class Spark :public Enemy
	{
	public:
		Spark ();
		void LoadBitmap();
		void OnShow();
		void OnMone();
		void Initialize();
		int GetX2();
		int GetY2();

	private:
		CAnimation *index;
		CAnimation Jump_L, Jump_R, Sucked_L, Sucked_R,Attack;

	};


}
