#pragma once
#include "Map.h"
#include "Kirby.h"
#include "Enemy.h"

namespace game_framework {
	class MonsterState
	{
	public:
		MonsterState* DecideNextState(Map* m, Kirby* kirby, Enemy* enemy);
		virtual void HandleDraw(Map* m, Kirby* kirby, Enemy* enemy) = 0;
	};

	class WalkRightState : public MonsterState
	{
	public:
		void HandleDraw(Map *m, Kirby *kirby, Enemy *enemy);
	};

	class WalkLeftState : public MonsterState
	{
	public:
		void HandleDraw(Map *m, Kirby *kirby, Enemy *enemy);
	};

	class IsSuckedState : public MonsterState
	{
	public:
		void HandleDraw(Map *m, Kirby *kirby, Enemy *enemy);
	};

	class DieState : public MonsterState
	{
	public:
		void HandleDraw(Map *m, Kirby *kirby, Enemy *enemy);
	};
}
