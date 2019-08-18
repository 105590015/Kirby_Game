#pragma once
#include "Enemy.h"
#include "Map.h"
#include "Kirby.h"

namespace game_framework {

	class NormalMonster:public Enemy
	{
	public:
		NormalMonster();
		void Initialize(int ox, int oy);	    // �]�w����l��
		int GetX2();
		int GetY2();
		void LoadBitmap();
		void OnShow(Map *m, Kirby *kirby);      // ���
		void OnMove(Map *m, Kirby *kirby);      // ����
		void Attack(Map *m, Kirby* kirby);      // ����
		friend class MonsterState;
		friend class WalkLeftState;
		friend class WalkRightState;
		friend class IsSuckedState;
		friend class DieState;
		void SetMonsterState(MonsterState *state) {monsterState = state;}; //�]�w�Ǫ����A
	protected:
		CMovingBitmap isSuckedR, isSuckedL;
		CAnimation goLeft, goRight, die;

	private:
		int count, velocity;
		MonsterState *monsterState;
	};
}