#pragma once

#include "KirbyType.h"

namespace game_framework {
	class Kirby_fire : public KirbyType
	{
	public:
		Kirby_fire() : KirbyType() { LoadBitmap(); };
		void OnShow(MovingType);
		void LoadBitmap();
		bool ResetMove(MovingType);
		void SetPoint(int x, int y, Map* m);
		int GetHeight();
		int GetWidth();
	private:
		// ¤õµK¥d¤ñ
		CMovingBitmap fire_exhaleR, fire_exhaleL;
		CAnimation fire_originR, fire_originL, fire_downR, fire_downL, fire_goR, fire_goL, fire_jumpR, fire_jumpL, fire_landingR, fire_landingL, fire_downAttackR, fire_downAttackL, fire_flyR, fire_prepareFlyR, fire_flyL, fire_prepareFlyL, fire_runR, fire_runL, fire_attackR, fire_attackL, attack1, attack2, attack3;
		bool IsAttackR = true;
		Map* _m;
		int _x, _y;
	};
}