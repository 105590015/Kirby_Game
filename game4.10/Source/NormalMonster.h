#pragma once
#include "Enemy.h"
#include "Map.h"
#include "Kirby.h"

namespace game_framework {

	class NormalMonster:public Enemy
	{
	public:
		NormalMonster();
		void Initialize(int ox, int oy);	    // 設定為初始值
		int GetX2();
		int GetY2();
		void LoadBitmap();
		void OnShow(Map *m, Kirby *kirby);      // 顯示
		void OnMove(Map *m, Kirby *kirby);      // 移動
		void Attack(Map *m, Kirby* kirby);      // 攻擊
		friend class MonsterState;
		friend class WalkLeftState;
		friend class WalkRightState;
		friend class IsSuckedState;
		friend class DieState;
		void SetMonsterState(MonsterState *state) {monsterState = state;}; //設定怪物狀態
	protected:
		CMovingBitmap isSuckedR, isSuckedL;
		CAnimation goLeft, goRight, die;

	private:
		int count, velocity;
		MonsterState *monsterState;
	};
}