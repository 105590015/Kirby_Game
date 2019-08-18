#pragma once

#include "KirbyType.h"

namespace game_framework {
	class Kirby_spark : public KirbyType
	{
	public:
		Kirby_spark() : KirbyType() { LoadBitmap(); };
		void OnShow(MovingType);
		bool ResetMove(MovingType);
		void LoadBitmap();
		void SetPoint(int x,int y,Map*);
		int GetHeight();
		int GetWidth();
	private:
		// ¹p¹q¥d¤ñ
		CMovingBitmap Spark_exhaleR, Spark_exhaleL;
		CAnimation Spark_originR, Spark_originL, Spark_downR, Spark_downL, Spark_goR, Spark_goL, Spark_jumpR, Spark_jumpL, Spark_landingR, Spark_landingL, Spark_downAttackR, Spark_downAttackL, Spark_flyR, Spark_prepareFlyR, Spark_flyL, Spark_prepareFlyL, Spark_runR, Spark_runL, Spark_attackR, Spark_attackL;
	};
}