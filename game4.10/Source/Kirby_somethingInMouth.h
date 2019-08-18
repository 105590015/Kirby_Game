#pragma once

#include "KirbyType.h"

namespace game_framework {
	class Kirby_somethingInMouth : public KirbyType
	{
	public:
		Kirby_somethingInMouth() : KirbyType() { LoadBitmap(); };
		void OnShow(MovingType);
		bool ResetMove(MovingType);
		void LoadBitmap();
		void SetPoint(int, int, Map*);
		int GetHeight();
		int GetWidth();
	private:
		// 含東西卡比
		CMovingBitmap bigOriginR, bigOriginL, bigJumpR, bigJumpL, bigLandingR, bigLandingL, threwR, threwL;
		CAnimation bigGoL, bigGoR, swallowR, swallowL;
	};
}
