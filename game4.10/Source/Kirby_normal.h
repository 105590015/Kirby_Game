#pragma once

#include "KirbyType.h"

namespace game_framework {
	class Kirby_normal : public KirbyType
	{
	public:
		Kirby_normal() : KirbyType() { LoadBitmap(); };
		void OnShow(MovingType);
		bool ResetMove(MovingType);
		void LoadBitmap();
		void SetPoint(int, int, Map*);
		int GetHeight();
		int GetWidth();
	private:
		// ´¶³q¥d¤ñ
		CMovingBitmap originR, originL, exhaleR, exhaleL, jumpR, jumpL, downR, downL, landingR, landingL, downAttackR, downAttackL, GG;
		CAnimation goL, goR, flyR, prepareFlyR, flyL, prepareFlyL, hurtedL, hurtedR, runL, runR, suckR, suckL;
	};
}