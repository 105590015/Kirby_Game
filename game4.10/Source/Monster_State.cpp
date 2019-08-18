#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Monster_State.h"
#include "NormalMonster.h"

namespace game_framework {
	void WalkRightState::HandleDraw(Map* m, Kirby* kirby, Enemy* enemy)
	{
		NormalMonster* normalMonster = dynamic_cast<NormalMonster*>(enemy);
		normalMonster->goRight.OnShow();
		normalMonster->goRight.OnMove();
		normalMonster->SetMonsterState(DecideNextState(m, kirby, enemy));
	}
	void WalkLeftState::HandleDraw(Map* m, Kirby* kirby, Enemy* enemy)
	{
		NormalMonster* normalMonster = dynamic_cast<NormalMonster*>(enemy);
		normalMonster->goLeft.OnShow();
		normalMonster->goLeft.OnMove();
		normalMonster->SetMonsterState(DecideNextState(m, kirby, enemy));
	}
	void IsSuckedState::HandleDraw(Map* m, Kirby* kirby, Enemy* enemy)
	{
		NormalMonster* normalMonster = dynamic_cast<NormalMonster*>(enemy);
		if (enemy->IsRight())
		{
			normalMonster->isSuckedR.ShowBitmap();
		}
		else
		{
			normalMonster->isSuckedL.ShowBitmap();
		}
		normalMonster->SetMonsterState(DecideNextState(m, kirby, enemy));
	}
	void DieState::HandleDraw(Map* m, Kirby* kirby, Enemy* enemy)
	{
		NormalMonster *normalMonster = dynamic_cast<NormalMonster*>(enemy);
		normalMonster->die.OnShow();
		normalMonster->die.OnMove();
		normalMonster->SetMonsterState(DecideNextState(m, kirby, enemy));

	}
	MonsterState* MonsterState::DecideNextState(Map* m, Kirby* kirby, Enemy* enemy)
	{
		NormalMonster* normalMonster = dynamic_cast<NormalMonster*>(enemy);
		MonsterState* result = nullptr;
		if (enemy->IsAlive())
		{
			if (!enemy->IsSucked() && !enemy->IsRight())
			{
				result = new WalkLeftState();
			}
			else if (!enemy->IsSucked() && enemy->IsRight())
			{
				result = new WalkRightState();
			}
			else if (enemy->IsSucked() && !((enemy->GetX1() - kirby->GetX1() >= -1) && (enemy->GetX1() - kirby->GetX1() <= 1)) || !((enemy->GetY1() - kirby->GetY1() >= -1) && (enemy->GetY1() - kirby->GetY1() <= 1)))
			{
				result = new IsSuckedState();
			}
		}
		else
		{
			if (!normalMonster->die.IsFinalBitmap() && !enemy->IsSucked())
			{
				result = new DieState();
			}
		}
		return result;
	}
}