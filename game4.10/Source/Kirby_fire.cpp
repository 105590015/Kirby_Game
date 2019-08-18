#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby_fire.h"

void game_framework::Kirby_fire::OnShow(MovingType type)
{
	switch (type)
	{
	case game_framework::KirbyType::originR:
		fire_originR.OnMove();
		fire_originR.OnShow();
		break;
	case game_framework::KirbyType::originL:
		fire_originL.OnMove();
		fire_originL.OnShow();
		break;
	case game_framework::KirbyType::downR:
		fire_downR.OnMove();
		fire_downR.OnShow();
		break;
	case game_framework::KirbyType::downL:
		fire_downL.OnMove();
		fire_downL.OnShow();
		break;
	case game_framework::KirbyType::goR:
		fire_goR.OnMove();
		fire_goR.OnShow();
		break;
	case game_framework::KirbyType::goL:
		fire_goL.OnMove();
		fire_goL.OnShow();
		break;
	case game_framework::KirbyType::jumpR:
		fire_jumpR.OnMove();
		fire_jumpR.OnShow();
		break;
	case game_framework::KirbyType::jumpL:
		fire_jumpL.OnMove();
		fire_jumpL.OnShow();
		break;
	case game_framework::KirbyType::landingR:
		fire_landingR.OnMove();
		fire_landingR.OnShow();
		break;
	case game_framework::KirbyType::landingL:
		fire_landingL.OnMove();
		fire_landingL.OnShow();
		break;
	case game_framework::KirbyType::downAttackR:
		fire_downAttackR.OnMove();
		fire_downAttackR.OnShow();
		break;
	case game_framework::KirbyType::downAttackL:
		fire_downAttackL.OnMove();
		fire_downAttackL.OnShow();
		break;
	case game_framework::KirbyType::flyR:
		fire_flyR.OnMove();
		fire_flyR.OnShow();
		break;
	case game_framework::KirbyType::prepareFlyR:
		fire_prepareFlyR.OnMove();
		fire_prepareFlyR.OnShow();
		break;
	case game_framework::KirbyType::flyL:
		fire_flyL.OnMove();
		fire_flyL.OnShow();
		break;
	case game_framework::KirbyType::prepareFlyL:
		fire_prepareFlyL.OnMove();
		fire_prepareFlyL.OnShow();
		break;
	case game_framework::KirbyType::runR:
		fire_runR.OnMove();
		fire_runR.OnShow();
		break;
	case game_framework::KirbyType::runL:
		fire_runL.OnMove();
		fire_runL.OnShow();
		break;
	case game_framework::KirbyType::attackR:
		fire_attackR.OnMove();
		fire_attackR.OnShow();
		break;
	case game_framework::KirbyType::attackL:
		fire_attackL.OnMove();
		fire_attackL.OnShow();
		break;
	case game_framework::KirbyType::exhaleL:
		fire_exhaleL.ShowBitmap();
		break;
	case game_framework::KirbyType::exhaleR:
		fire_exhaleR.ShowBitmap();
		break;
	case KirbyType::suckR:
		fire_attackR.OnShow();
		fire_attackR.OnMove();
		attack1.SetTopLeft(_m->ScreenX(_x + 63), _m->ScreenY(_y + 30));
		attack2.SetTopLeft(_m->ScreenX(_x + 83), _m->ScreenY(_y + 10));
		attack3.SetTopLeft(_m->ScreenX(_x + 133), _m->ScreenY(_y + 10));
		attack1.OnMove();
		attack1.OnShow();
		attack2.OnMove();
		attack2.OnShow();
		attack3.OnMove();
		attack3.OnShow();
		break;
	case KirbyType::suckL:
		fire_attackL.OnShow();
		fire_attackL.OnMove();
		attack1.SetTopLeft(_m->ScreenX(_x - 52), _m->ScreenY(_y + 30));
		attack2.SetTopLeft(_m->ScreenX(_x - 72), _m->ScreenY(_y + 10));
		attack3.SetTopLeft(_m->ScreenX(_x - 122), _m->ScreenY(_y + 10));
		attack1.OnMove();
		attack1.OnShow();
		attack2.OnMove();
		attack2.OnShow();
		attack3.OnMove();
		attack3.OnShow();
		break;
	default:
		break;
	}
}

void game_framework::Kirby_fire::LoadBitmap()
{
	// ¤õµK¥d¤ñ
	fire_exhaleR.LoadBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_R_4.bmp", RGB(255, 255, 255));
	fire_exhaleL.LoadBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_L_4.bmp", RGB(255, 255, 255));
	fire_originR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Stand_R_1.bmp", RGB(255, 255, 255));
	fire_originR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Stand_R_2.bmp", RGB(255, 255, 255));
	fire_originR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Stand_R_3.bmp", RGB(255, 255, 255));
	fire_originL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Stand_L_1.bmp", RGB(255, 255, 255));
	fire_originL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Stand_L_2.bmp", RGB(255, 255, 255));
	fire_originL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Stand_L_3.bmp", RGB(255, 255, 255));
	fire_downR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Down_R_0.bmp", RGB(255, 255, 255));
	fire_downR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Down_R_1.bmp", RGB(255, 255, 255));
	fire_downR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Down_R_2.bmp", RGB(255, 255, 255));
	fire_downL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Down_L_0.bmp", RGB(255, 255, 255));
	fire_downL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Down_L_1.bmp", RGB(255, 255, 255));
	fire_downL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Down_L_2.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_0.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_1.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_2.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_3.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_4.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_5.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_6.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_7.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_8.bmp", RGB(255, 255, 255));
	fire_goR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_R_9.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_0.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_1.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_2.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_3.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_4.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_5.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_6.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_7.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_8.bmp", RGB(255, 255, 255));
	fire_goL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Walk_L_9.bmp", RGB(255, 255, 255));
	fire_jumpR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Jump_R_0.bmp", RGB(255, 255, 255));
	fire_jumpR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Jump_R_1.bmp", RGB(255, 255, 255));
	fire_jumpL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Jump_L_0.bmp", RGB(255, 255, 255));
	fire_jumpL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Jump_L_1.bmp", RGB(255, 255, 255));
	fire_landingR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Landing_R_0.bmp", RGB(255, 255, 255));
	fire_landingR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Landing_R_1.bmp", RGB(255, 255, 255));
	fire_landingL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Landing_L_0.bmp", RGB(255, 255, 255));
	fire_landingL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Landing_L_1.bmp", RGB(255, 255, 255));
	fire_downAttackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_R_0.bmp", RGB(255, 255, 255));
	fire_downAttackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_R_1.bmp", RGB(255, 255, 255));
	fire_downAttackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_R_2.bmp", RGB(255, 255, 255));
	fire_downAttackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_R_3.bmp", RGB(255, 255, 255));
	fire_downAttackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_L_0.bmp", RGB(255, 255, 255));
	fire_downAttackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_L_1.bmp", RGB(255, 255, 255));
	fire_downAttackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_L_2.bmp", RGB(255, 255, 255));
	fire_downAttackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Kick_L_3.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_0.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_1.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_2.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_3.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_4.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_5.bmp", RGB(255, 255, 255));
	fire_flyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_R_6.bmp", RGB(255, 255, 255));
	fire_prepareFlyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_R_0.bmp", RGB(255, 255, 255));
	fire_prepareFlyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_R_1.bmp", RGB(255, 255, 255));
	fire_prepareFlyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_R_2.bmp", RGB(255, 255, 255));
	fire_prepareFlyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_R_3.bmp", RGB(255, 255, 255));
	fire_prepareFlyR.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_R_4.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_0.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_1.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_2.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_3.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_4.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_5.bmp", RGB(255, 255, 255));
	fire_flyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Fly_L_6.bmp", RGB(255, 255, 255));
	fire_prepareFlyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_L_0.bmp", RGB(255, 255, 255));
	fire_prepareFlyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_L_1.bmp", RGB(255, 255, 255));
	fire_prepareFlyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_L_2.bmp", RGB(255, 255, 255));
	fire_prepareFlyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_L_3.bmp", RGB(255, 255, 255));
	fire_prepareFlyL.AddBitmap(".\\RES\\FireKirby\\FireKirby_FlyPrepare_L_4.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_0.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_1.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_2.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_3.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_4.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_5.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_6.bmp", RGB(255, 255, 255));
	fire_runR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_R_7.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_0.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_1.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_2.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_3.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_4.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_5.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_6.bmp", RGB(255, 255, 255));
	fire_runL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Run_L_7.bmp", RGB(255, 255, 255));
	fire_attackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_R_0.bmp", RGB(255, 255, 255));
	fire_attackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_R_1.bmp", RGB(255, 255, 255));
	fire_attackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_R_2.bmp", RGB(255, 255, 255));
	fire_attackR.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_R_3.bmp", RGB(255, 255, 255));
	fire_attackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_L_0.bmp", RGB(255, 255, 255));
	fire_attackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_L_1.bmp", RGB(255, 255, 255));
	fire_attackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_L_2.bmp", RGB(255, 255, 255));
	fire_attackL.AddBitmap(".\\RES\\FireKirby\\FireKirby_Attack_L_3.bmp", RGB(255, 255, 255));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_0.bmp", RGB(0, 0, 115));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_1.bmp", RGB(0, 0, 115));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_2.bmp", RGB(0, 0, 115));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_3.bmp", RGB(0, 0, 115));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_4.bmp", RGB(0, 0, 115));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_5.bmp", RGB(0, 0, 115));
	attack1.AddBitmap(".\\RES\\FireKirby\\attack1_6.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_0.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_1.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_2.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_3.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_4.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_5.bmp", RGB(0, 0, 115));
	attack2.AddBitmap(".\\RES\\FireKirby\\attack2_6.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_0.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_1.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_2.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_3.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_4.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_5.bmp", RGB(0, 0, 115));
	attack3.AddBitmap(".\\RES\\FireKirby\\attack3_6.bmp", RGB(0, 0, 115));
}

bool game_framework::Kirby_fire::ResetMove(MovingType type)
{
	switch (type)
	{
	case game_framework::KirbyType::prepareFlyR:
		if (fire_prepareFlyR.IsFinalBitmap())
		{
			fire_prepareFlyR.Reset();
			return true;
		}
	case game_framework::KirbyType::prepareFlyL:
		if (fire_prepareFlyL.IsFinalBitmap())
		{
			fire_prepareFlyL.Reset();
			return true;
		}
	default:
		break;
	}
	return false;
}

void game_framework::Kirby_fire::SetPoint(int x, int y, Map* m)
{
	_m = m;
	_x = x;
	_y = y;
	fire_exhaleR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_exhaleL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 20));
	fire_downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 20));
	fire_goR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_goL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_jumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_jumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_landingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_landingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_downAttackR.SetTopLeft(m->ScreenX(x - 30), m->ScreenY(y + 28));
	fire_downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 28));
	fire_flyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_prepareFlyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_flyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_prepareFlyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	fire_runR.SetTopLeft(m->ScreenX(x - 35), m->ScreenY(y + 5));
	fire_runL.SetTopLeft(m->ScreenX(x), m->ScreenY(y + 5));
	fire_attackR.SetTopLeft(m->ScreenX(x - 15), m->ScreenY(y + 10));
	fire_attackL.SetTopLeft(m->ScreenX(x + 10), m->ScreenY(y + 10));

	attack1.SetDelayCount(5);
	attack2.SetDelayCount(5);
	attack3.SetDelayCount(5);
}

int game_framework::Kirby_fire::GetHeight()
{
	return fire_originR.Height();
}

int game_framework::Kirby_fire::GetWidth()
{
	return fire_originR.Width();
}
