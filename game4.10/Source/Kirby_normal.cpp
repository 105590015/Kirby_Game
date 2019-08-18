#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby_normal.h"

void game_framework::Kirby_normal::OnShow(MovingType movingType)
{
	switch (movingType)
	{
	case KirbyType::originR:
		originR.ShowBitmap();
		break;
	case KirbyType::originL:
		originL.ShowBitmap();
		break;
	case KirbyType::downR:
		downR.ShowBitmap();
		break;
	case KirbyType::downL:
		downL.ShowBitmap();
		break;
	case KirbyType::goR:
		goR.OnMove();
		goR.OnShow();
		break;
	case KirbyType::goL:
		goL.OnMove();
		goL.OnShow();
		break;
	case KirbyType::jumpR:
		jumpR.ShowBitmap();
		break;
	case KirbyType::jumpL:
		jumpL.ShowBitmap();
		break;
	case KirbyType::landingR:
		landingR.ShowBitmap();
		break;
	case KirbyType::landingL:
		landingL.ShowBitmap();
		break;
	case KirbyType::downAttackR:
		downAttackR.ShowBitmap();
		break;
	case KirbyType::downAttackL:
		downAttackL.ShowBitmap();
		break;
	case KirbyType::flyR:
		flyR.OnMove();
		flyR.OnShow();
		break;
	case KirbyType::prepareFlyR:
		prepareFlyR.OnMove();
		prepareFlyR.OnShow();
		break;
	case KirbyType::flyL:
		flyL.OnMove();
		flyL.OnShow();
		break;
	case KirbyType::prepareFlyL:
		prepareFlyL.OnMove();
		prepareFlyL.OnShow();
		break;
	case KirbyType::runR:
		runR.OnMove();
		runR.OnShow();
		break;
	case KirbyType::runL:
		runL.OnMove();
		runL.OnShow();
		break;
	case KirbyType::attackR:
		break;
	case KirbyType::attackL:
		break;
	case KirbyType::hurtedL:
		hurtedL.OnMove();
		hurtedL.OnShow();
		break;
	case KirbyType::hurtedR:
		hurtedR.OnMove();
		hurtedR.OnShow();
		break;
	case KirbyType::suckR:
		suckR.OnMove();
		suckR.OnShow();
		break;
	case KirbyType::suckL:
		suckL.OnMove();
		suckL.OnShow();
		break;
	case KirbyType::exhaleL:
		exhaleL.ShowBitmap();
		break;
	case KirbyType::exhaleR:
		exhaleR.ShowBitmap();
		break;
	default:
		break;
	}
}

bool game_framework::Kirby_normal::ResetMove(MovingType type)
{
	switch (type)
	{
	case game_framework::KirbyType::prepareFlyR:
		if (prepareFlyR.IsFinalBitmap())
		{
			prepareFlyR.Reset();
			return true;
		}
	case game_framework::KirbyType::prepareFlyL:
		if (prepareFlyL.IsFinalBitmap())
		{
			prepareFlyL.Reset();
			return true;
		}
	case game_framework::KirbyType::hurtedL:
		if (hurtedL.IsFinalBitmap() )
		{
			hurtedL.Reset();
			return true;
		}
		break;
	case game_framework::KirbyType::hurtedR:
		if (hurtedR.IsFinalBitmap())
		{
			hurtedR.Reset();
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

void game_framework::Kirby_normal::LoadBitmap()
{
	originR.LoadBitmap(".\\RES\\Kirby\\KB_R_0.bmp", RGB(255, 255, 255));
	originL.LoadBitmap(".\\RES\\Kirby\\KB_L_0.bmp", RGB(255, 255, 255));
	exhaleR.LoadBitmap(".\\RES\\Kirby\\KB_Exhale_R.bmp", RGB(255, 255, 255));
	exhaleL.LoadBitmap(".\\RES\\Kirby\\KB_Exhale_L.bmp", RGB(255, 255, 255));
	jumpR.LoadBitmap(".\\RES\\Kirby\\KB_Jump_R.bmp", RGB(255, 255, 255));
	jumpL.LoadBitmap(".\\RES\\Kirby\\KB_Jump_L.bmp", RGB(255, 255, 255));
	downR.LoadBitmap(".\\RES\\Kirby\\KB_Down_R.bmp", RGB(255, 255, 255));
	downL.LoadBitmap(".\\RES\\Kirby\\KB_Down_L.bmp", RGB(255, 255, 255));
	landingL.LoadBitmap(".\\RES\\Kirby\\KB_Landing_L.bmp", RGB(255, 255, 255));
	landingR.LoadBitmap(".\\RES\\Kirby\\KB_Landing_R.bmp", RGB(255, 255, 255));
	downAttackL.LoadBitmap(".\\RES\\Kirby\\KB_DownAttack_L.bmp", RGB(255, 255, 255));
	downAttackR.LoadBitmap(".\\RES\\Kirby\\KB_DownAttack_R.bmp", RGB(255, 255, 255));
	GG.LoadBitmap(".\\RES\\Kirby\\Die.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_1.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_2.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_3.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_4.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_5.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_6.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_7.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_8.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_9.bmp", RGB(255, 255, 255));
	goL.AddBitmap(".\\RES\\Kirby\\KB_L_10.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_1.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_2.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_3.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_4.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_5.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_6.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_7.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_8.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_9.bmp", RGB(255, 255, 255));
	goR.AddBitmap(".\\RES\\Kirby\\KB_R_10.bmp", RGB(255, 255, 255));
	prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_1.bmp", RGB(255, 255, 255));
	prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_2.bmp", RGB(255, 255, 255));
	prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_3.bmp", RGB(255, 255, 255));
	prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_4.bmp", RGB(255, 255, 255));
	prepareFlyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_5.bmp", RGB(255, 255, 255));
	flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_6.bmp", RGB(255, 255, 255));
	flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_7.bmp", RGB(255, 255, 255));
	flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_8.bmp", RGB(255, 255, 255));
	flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_9.bmp", RGB(255, 255, 255));
	flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_10.bmp", RGB(255, 255, 255));
	flyR.AddBitmap(".\\RES\\Kirby\\KB_U_R_11.bmp", RGB(255, 255, 255));
	prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_1.bmp", RGB(255, 255, 255));
	prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_2.bmp", RGB(255, 255, 255));
	prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_3.bmp", RGB(255, 255, 255));
	prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_4.bmp", RGB(255, 255, 255));
	prepareFlyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_5.bmp", RGB(255, 255, 255));
	flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_6.bmp", RGB(255, 255, 255));
	flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_7.bmp", RGB(255, 255, 255));
	flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_8.bmp", RGB(255, 255, 255));
	flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_9.bmp", RGB(255, 255, 255));
	flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_10.bmp", RGB(255, 255, 255));
	flyL.AddBitmap(".\\RES\\Kirby\\KB_U_L_11.bmp", RGB(255, 255, 255));
	hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_1.bmp", RGB(255, 255, 255));
	hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_2.bmp", RGB(255, 255, 255));
	hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_3.bmp", RGB(255, 255, 255));
	hurtedL.AddBitmap(".\\RES\\Kirby\\KB_Hurted_L_4.bmp", RGB(255, 255, 255));
	hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_1.bmp", RGB(255, 255, 255));
	hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_2.bmp", RGB(255, 255, 255));
	hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_3.bmp", RGB(255, 255, 255));
	hurtedR.AddBitmap(".\\RES\\Kirby\\KB_Hurted_R_4.bmp", RGB(255, 255, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_0.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_1.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_2.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_3.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_4.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_5.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_6.bmp", RGB(207, 176, 255));
	runL.AddBitmap(".\\RES\\Kirby\\RUN_L_7.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_0.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_1.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_2.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_3.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_4.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_5.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_6.bmp", RGB(207, 176, 255));
	runR.AddBitmap(".\\RES\\Kirby\\RUN_R_7.bmp", RGB(207, 176, 255));
	suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_1.bmp", RGB(255, 255, 255));
	suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_2.bmp", RGB(255, 255, 255));
	suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_3.bmp", RGB(255, 255, 255));
	suckL.AddBitmap(".\\RES\\Kirby\\KB_Suck_L_4.bmp", RGB(255, 255, 255));
	suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_1.bmp", RGB(255, 255, 255));
	suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_2.bmp", RGB(255, 255, 255));
	suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_3.bmp", RGB(255, 255, 255));
	suckR.AddBitmap(".\\RES\\Kirby\\KB_Suck_R_4.bmp", RGB(255, 255, 255));
}

void game_framework::Kirby_normal::SetPoint(int x,int y,Map* m)
{
	originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	goL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	goR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	prepareFlyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	prepareFlyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	flyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	flyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	exhaleR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	exhaleL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	jumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	jumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	landingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	landingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	downAttackR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	hurtedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	hurtedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	runR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	runL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	suckL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	suckR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
}

int game_framework::Kirby_normal::GetHeight()
{
	return originR.Height();
}

int game_framework::Kirby_normal::GetWidth()
{
	return originR.Width();
}
