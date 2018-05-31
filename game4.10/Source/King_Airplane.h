#pragma once
#include "Enemy.h"
#include "Kirby.h"
#include "Map.h"
#include "King_Bomb.h"

namespace game_framework {
	class King_Airplane : public Enemy
	{
	public:
		King_Airplane();
		void LoadBitmap();
		void OnShow(Map* m, Kirby* kirby);
		void OnMove(Map* m, Kirby* kirby);
		void Initialize(int sx, int sy);
		void Attack(Map* m, Kirby* kirby);
		int GetX2();
		int GetY2();
	private:
		int counter;  //計算丟炸彈時機
		int UporDown; //控制飛上還飛下
		CMovingBitmap downL, downR, dieL, dieR;
		CAnimation goLeft, goRight;
		King_Bomb bomb1, bomb2, bomb3;
	};
}