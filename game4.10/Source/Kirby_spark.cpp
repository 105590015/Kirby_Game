#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby_spark.h"


void game_framework::Kirby_spark::OnShow(MovingType type)
{
	switch (type)
	{
	case game_framework::KirbyType::originR:
		Spark_originR.OnMove();
		Spark_originR.OnShow();
		break;
	case game_framework::KirbyType::originL:
		Spark_originL.OnMove();
		Spark_originL.OnShow();
		break;
	case game_framework::KirbyType::downR:
		Spark_downR.OnMove();
		Spark_downR.OnShow();
		break;
	case game_framework::KirbyType::downL:
		Spark_downL.OnMove();
		Spark_downL.OnShow();
		break;
	case game_framework::KirbyType::goR:
		Spark_goR.OnMove();
		Spark_goR.OnShow();
		break;
	case game_framework::KirbyType::goL:
		Spark_goL.OnMove();
		Spark_goL.OnShow();
		break;
	case game_framework::KirbyType::jumpR:
		Spark_jumpR.OnMove();
		Spark_jumpR.OnShow();
		break;
	case game_framework::KirbyType::jumpL:
		Spark_jumpL.OnMove();
		Spark_jumpL.OnShow();
		break;
	case game_framework::KirbyType::landingR:
		Spark_landingR.OnMove();
		Spark_landingR.OnShow();
		break;
	case game_framework::KirbyType::landingL:
		Spark_landingL.OnMove();
		Spark_landingL.OnShow();
		break;
	case game_framework::KirbyType::downAttackR:
		Spark_downAttackR.OnMove();
		Spark_downAttackR.OnShow();
		break;
	case game_framework::KirbyType::downAttackL:
		Spark_downAttackL.OnMove();
		Spark_downAttackL.OnShow();
		break;
	case game_framework::KirbyType::flyR:
		Spark_flyR.OnMove();
		Spark_flyR.OnShow();
		break;
	case game_framework::KirbyType::prepareFlyR:
		Spark_prepareFlyR.OnMove();
		Spark_prepareFlyR.OnShow();
		break;
	case game_framework::KirbyType::flyL:
		Spark_flyL.OnMove();
		Spark_flyL.OnShow();
		break;
	case game_framework::KirbyType::prepareFlyL:
		Spark_prepareFlyL.OnMove();
		Spark_prepareFlyL.OnShow();
		break;
	case game_framework::KirbyType::runR:
		Spark_runR.OnMove();
		Spark_runR.OnShow();
		break;
	case game_framework::KirbyType::runL:
		Spark_runL.OnMove();
		Spark_runL.OnShow();
		break;
	case game_framework::KirbyType::attackR:
		Spark_attackR.OnMove();
		Spark_attackR.OnShow();
		break;
	case game_framework::KirbyType::attackL:
		Spark_attackL.OnMove();
		Spark_attackL.OnShow();
		break;
	case game_framework::KirbyType::exhaleL:
		Spark_exhaleL.ShowBitmap();
		break;
	case game_framework::KirbyType::exhaleR:
		Spark_exhaleR.ShowBitmap();
		break;
	case KirbyType::suckL:
		Spark_attackL.SetDelayCount(5);
		Spark_attackL.OnMove();
		Spark_attackL.OnShow();
		break;
	case KirbyType::suckR:
		Spark_attackR.SetDelayCount(5);
		Spark_attackR.OnMove();
		Spark_attackR.OnShow();
		break;
	default:
		break;
	}
}

bool game_framework::Kirby_spark::ResetMove(MovingType type)
{
	switch (type)
	{
	case game_framework::KirbyType::prepareFlyR:
		if (Spark_prepareFlyR.IsFinalBitmap())
		{
			Spark_prepareFlyR.Reset();
			return true;
		}
	case game_framework::KirbyType::prepareFlyL:
		if (Spark_prepareFlyL.IsFinalBitmap())
		{
			Spark_prepareFlyL.Reset();
			return true;
		}
	default:
		break;
	}
	return false;
}

void game_framework::Kirby_spark::LoadBitmap()
{
	Spark_exhaleR.LoadBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_R_4.bmp", RGB(255, 255, 255));
	Spark_exhaleL.LoadBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_L_4.bmp", RGB(255, 255, 255));
	Spark_downR.AddBitmap(".\\RES\\SparkKirby\\Spark_Down_R.bmp", RGB(255, 255, 255));
	Spark_downR.AddBitmap(".\\RES\\SparkKirby\\Spark_Down_R_1.bmp", RGB(255, 255, 255));
	Spark_downR.AddBitmap(".\\RES\\SparkKirby\\Spark_Down_R_2.bmp", RGB(255, 255, 255));
	Spark_downL.AddBitmap(".\\RES\\SparkKirby\\Spark_Down_L.bmp", RGB(255, 255, 255));
	Spark_downL.AddBitmap(".\\RES\\SparkKirby\\Spark_Down_L_1.bmp", RGB(255, 255, 255));
	Spark_downL.AddBitmap(".\\RES\\SparkKirby\\Spark_Down_L_2.bmp", RGB(255, 255, 255));
	Spark_landingR.AddBitmap(".\\RES\\SparkKirby\\Spark_Landing_R.bmp", RGB(255, 255, 255));
	Spark_landingR.AddBitmap(".\\RES\\SparkKirby\\Spark_Landing_R_1.bmp", RGB(255, 255, 255));
	Spark_landingL.AddBitmap(".\\RES\\SparkKirby\\Spark_Landing_L.bmp", RGB(255, 255, 255));
	Spark_landingL.AddBitmap(".\\RES\\SparkKirby\\Spark_Landing_L_1.bmp", RGB(255, 255, 255));
	Spark_originR.AddBitmap(".\\RES\\SparkKirby\\Spark_stand_R_1.bmp", RGB(255, 255, 255));
	Spark_originR.AddBitmap(".\\RES\\SparkKirby\\Spark_stand_R_2.bmp", RGB(255, 255, 255));
	Spark_originR.AddBitmap(".\\RES\\SparkKirby\\Spark_stand_R_3.bmp", RGB(255, 255, 255));
	Spark_originL.AddBitmap(".\\RES\\SparkKirby\\Spark_stand_L_1.bmp", RGB(255, 255, 255));
	Spark_originL.AddBitmap(".\\RES\\SparkKirby\\Spark_stand_L_2.bmp", RGB(255, 255, 255));
	Spark_originL.AddBitmap(".\\RES\\SparkKirby\\Spark_stand_L_3.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_00.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_01.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_02.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_03.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_04.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_05.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_06.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_07.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_08.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_09.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_10.bmp", RGB(255, 255, 255));
	Spark_goR.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_R_11.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_00.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_01.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_02.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_03.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_04.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_05.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_06.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_07.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_08.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_09.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_10.bmp", RGB(255, 255, 255));
	Spark_goL.AddBitmap(".\\RES\\SparkKirby\\Spark_walk_L_11.bmp", RGB(255, 255, 255));
	Spark_jumpR.AddBitmap(".\\RES\\SparkKirby\\Spark_Jump_R_0.bmp", RGB(255, 255, 255));
	Spark_jumpR.AddBitmap(".\\RES\\SparkKirby\\Spark_Jump_R_1.bmp", RGB(255, 255, 255));
	Spark_jumpL.AddBitmap(".\\RES\\SparkKirby\\Spark_Jump_L_0.bmp", RGB(255, 255, 255));
	Spark_jumpL.AddBitmap(".\\RES\\SparkKirby\\Spark_Jump_L_1.bmp", RGB(255, 255, 255));
	Spark_downAttackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_R_0.bmp", RGB(255, 255, 255));
	Spark_downAttackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_R_1.bmp", RGB(255, 255, 255));
	Spark_downAttackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_R_2.bmp", RGB(255, 255, 255));
	Spark_downAttackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_R_3.bmp", RGB(255, 255, 255));
	Spark_downAttackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_L_0.bmp", RGB(255, 255, 255));
	Spark_downAttackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_L_1.bmp", RGB(255, 255, 255));
	Spark_downAttackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_L_2.bmp", RGB(255, 255, 255));
	Spark_downAttackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Kick_L_3.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_00.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_01.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_02.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_03.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_04.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_05.bmp", RGB(255, 255, 255));
	Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_06.bmp", RGB(255, 255, 255));
	Spark_prepareFlyR.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_R_0.bmp", RGB(255, 255, 255));
	Spark_prepareFlyR.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_R_1.bmp", RGB(255, 255, 255));
	Spark_prepareFlyR.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_R_2.bmp", RGB(255, 255, 255));
	Spark_prepareFlyR.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_R_3.bmp", RGB(255, 255, 255));
	Spark_prepareFlyR.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_R_4.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_00.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_01.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_02.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_03.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_04.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_05.bmp", RGB(255, 255, 255));
	Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_06.bmp", RGB(255, 255, 255));
	Spark_prepareFlyL.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_L_0.bmp", RGB(255, 255, 255));
	Spark_prepareFlyL.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_L_1.bmp", RGB(255, 255, 255));
	Spark_prepareFlyL.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_L_2.bmp", RGB(255, 255, 255));
	Spark_prepareFlyL.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_L_3.bmp", RGB(255, 255, 255));
	Spark_prepareFlyL.AddBitmap(".\\RES\\SparkKirby\\Spark_FlyPrepare_L_4.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_0.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_1.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_2.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_3.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_4.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_5.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_6.bmp", RGB(255, 255, 255));
	Spark_runR.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_R_7.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_0.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_1.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_2.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_3.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_4.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_5.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_6.bmp", RGB(255, 255, 255));
	Spark_runL.AddBitmap(".\\RES\\SparkKirby\\Spark_Run_L_7.bmp", RGB(255, 255, 255));
	Spark_attackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_R_1.bmp", RGB(255, 255, 255));
	Spark_attackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_R_2.bmp", RGB(255, 255, 255));
	Spark_attackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_R_3.bmp", RGB(255, 255, 255));
	Spark_attackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_R_4.bmp", RGB(255, 255, 255));
	Spark_attackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_R_5.bmp", RGB(255, 255, 255));
	Spark_attackR.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_R_6.bmp", RGB(255, 255, 255));
	Spark_attackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_L_1.bmp", RGB(255, 255, 255));
	Spark_attackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_L_2.bmp", RGB(255, 255, 255));
	Spark_attackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_L_3.bmp", RGB(255, 255, 255));
	Spark_attackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_L_4.bmp", RGB(255, 255, 255));
	Spark_attackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_L_5.bmp", RGB(255, 255, 255));
	Spark_attackL.AddBitmap(".\\RES\\SparkKirby\\Spark_Attack_L_6.bmp", RGB(255, 255, 255));
}

void game_framework::Kirby_spark::SetPoint(int x, int y, Map* m)
{
	Spark_exhaleR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_exhaleL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 20));
	Spark_downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 20));
	Spark_landingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_landingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_goR.SetTopLeft(m->ScreenX(x), m->ScreenY(y - 5));
	Spark_goL.SetTopLeft(m->ScreenX(x), m->ScreenY(y - 5));
	Spark_jumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_jumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_downAttackR.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y + 30));
	Spark_downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 30));
	Spark_flyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_prepareFlyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 5));
	Spark_flyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	Spark_prepareFlyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 5));
	Spark_runR.SetTopLeft(m->ScreenX(x - 20), m->ScreenY(y + 10));
	Spark_runL.SetTopLeft(m->ScreenX(x + 10), m->ScreenY(y + 10));
	Spark_attackR.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y - 20));
	Spark_attackL.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y - 20));
}

int game_framework::Kirby_spark::GetHeight()
{
	return Spark_originR.Height();
}

int game_framework::Kirby_spark::GetWidth()
{
	return Spark_originR.Width();
}
