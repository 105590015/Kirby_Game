#pragma once

#include "Map.h"

namespace game_framework{
class KirbyType
{
	public:
	enum MovingType
	{
		originR,
		originL,
		downR,
		downL,
		goR,
		goL,
		jumpR,
		jumpL,
		landingR,
		landingL,
		downAttackR,
		downAttackL,
		flyR,
		prepareFlyR,
		flyL,
		prepareFlyL,
		runR,
		runL,
		attackR,
		attackL,
		hurtedL,
		hurtedR,
		suckR,
		suckL,
		exhaleR,
		exhaleL,
		threwR,
		threwL,
		swallowR,
		swallowL
	};
		KirbyType();
		virtual void OnShow(MovingType) = 0;
		virtual bool ResetMove(MovingType) = 0; //�P�_�O�_�F�쭫�s������A�p�G�O�^��true
		virtual void LoadBitmap() = 0;
		virtual void SetPoint(int, int, Map*);
		virtual int GetHeight() = 0;
		virtual int GetWidth() = 0;
	private:

	};
}