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
		int counter;  //�p��ᬵ�u�ɾ�
		int UporDown; //����W�٭��U
		CMovingBitmap downL, downR, dieL, dieR;
		CAnimation goLeft, goRight;
		King_Bomb bomb1, bomb2, bomb3;
	};
}