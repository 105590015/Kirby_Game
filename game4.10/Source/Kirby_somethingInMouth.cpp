#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby_somethingInMouth.h"

void game_framework::Kirby_somethingInMouth::OnShow(MovingType movingType)
{
	switch (movingType)
	{
	case KirbyType::originR:
		bigOriginR.ShowBitmap();
		break;
	case KirbyType::originL:
		bigOriginL.ShowBitmap();
		break;
	case KirbyType::goR:
		bigGoR.SetDelayCount(10);
		bigGoR.OnMove();
		bigGoR.OnShow();
		break;
	case KirbyType::goL:
		bigGoL.SetDelayCount(10);
		bigGoL.OnMove();
		bigGoL.OnShow();
		break;
	case KirbyType::jumpR:
		bigJumpR.ShowBitmap();
		break;
	case KirbyType::jumpL:
		bigJumpL.ShowBitmap();
		break;
	case KirbyType::landingR:
		bigLandingR.ShowBitmap();
		break;
	case KirbyType::landingL:
		bigLandingL.ShowBitmap();
		break;
	case KirbyType::runR:
		bigGoR.SetDelayCount(2);
		bigGoR.OnMove();
		bigGoR.OnShow();
		break;
	case KirbyType::runL:
		bigGoL.SetDelayCount(2);
		bigGoL.OnMove();
		bigGoL.OnShow();
		break;
	case KirbyType::attackR:
		break;
	case KirbyType::attackL:
		break;
	case KirbyType::threwR:
		threwR.ShowBitmap();
		break;
	case KirbyType::threwL:
		threwL.ShowBitmap();
		break;
	case KirbyType::swallowR:
		swallowR.OnMove();
		swallowR.OnShow();
		break;
	case KirbyType::swallowL:
		swallowL.OnMove();
		swallowL.OnShow();
		break;
	default:
		break;
	}
}

bool game_framework::Kirby_somethingInMouth::ResetMove(MovingType type)
{
	switch (type)
	{
	case game_framework::KirbyType::swallowR:
		if (swallowR.IsFinalBitmap())
		{
			swallowR.Reset();
			return true;
		}
	case game_framework::KirbyType::swallowL:
		if (swallowL.IsFinalBitmap())
		{
			swallowL.Reset();
			return true;
		}
	default:
		break;
	}
	return false;
}

void game_framework::Kirby_somethingInMouth::LoadBitmap()
{
	// 含東西的卡比
	bigOriginR.LoadBitmap(".\\RES\\Kirby\\BKB_R_0.bmp", RGB(255, 255, 255));
	bigOriginL.LoadBitmap(".\\RES\\Kirby\\BKB_L_0.bmp", RGB(255, 255, 255));
	bigJumpR.LoadBitmap(".\\RES\\Kirby\\BKB_Jump_R.bmp", RGB(255, 255, 255));
	bigJumpL.LoadBitmap(".\\RES\\Kirby\\BKB_Jump_L.bmp", RGB(255, 255, 255));
	bigLandingR.LoadBitmap(".\\RES\\Kirby\\BKB_Landing_R.bmp", RGB(255, 255, 255));
	bigLandingL.LoadBitmap(".\\RES\\Kirby\\BKB_Landing_L.bmp", RGB(255, 255, 255));
	threwR.LoadBitmap(".\\RES\\Kirby\\BKB_Threw_R.bmp", RGB(255, 255, 255));
	threwL.LoadBitmap(".\\RES\\Kirby\\BKB_Threw_L.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_1.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_2.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_3.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_4.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_5.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_6.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_7.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_8.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_9.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_10.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_11.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_12.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_13.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_14.bmp", RGB(255, 255, 255));
	bigGoR.AddBitmap(".\\RES\\Kirby\\BKB_R_15.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_1.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_2.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_3.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_4.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_5.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_6.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_7.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_8.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_9.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_10.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_11.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_12.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_13.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_14.bmp", RGB(255, 255, 255));
	bigGoL.AddBitmap(".\\RES\\Kirby\\BKB_L_15.bmp", RGB(255, 255, 255));
	swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_1.bmp", RGB(255, 255, 255));
	swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_2.bmp", RGB(255, 255, 255));
	swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_3.bmp", RGB(255, 255, 255));
	swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_4.bmp", RGB(255, 255, 255));
	swallowR.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_R_5.bmp", RGB(255, 255, 255));
	swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_1.bmp", RGB(255, 255, 255));
	swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_2.bmp", RGB(255, 255, 255));
	swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_3.bmp", RGB(255, 255, 255));
	swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_4.bmp", RGB(255, 255, 255));
	swallowL.AddBitmap(".\\RES\\Kirby\\BKB_Swallow_L_5.bmp", RGB(255, 255, 255));
}

void game_framework::Kirby_somethingInMouth::SetPoint(int x, int y, Map* m)
{
	bigOriginR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigOriginL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigJumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigJumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigLandingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigLandingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	threwR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	threwL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigGoL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	bigGoR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	swallowR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
	swallowL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
}

int game_framework::Kirby_somethingInMouth::GetHeight()
{
	return bigOriginR.Height();
}

int game_framework::Kirby_somethingInMouth::GetWidth()
{
	return bigOriginR.Width();
}
