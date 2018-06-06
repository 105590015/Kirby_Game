#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby.h"

namespace game_framework {
	Kirby::Kirby()
	{
	}

	int Kirby::GetX1()
	{
		return x;
	}

	int Kirby::GetY1()
	{
		return y;
	}

	int Kirby::GetX2()
	{
		return x + width;
	}

	int Kirby::GetY2()
	{
		return y + height;
	}

	int Kirby::GetType()
	{
		return type;
	}

	int Kirby::GetHeight()
	{
		return height;
	}

	int Kirby::GetWidth()
	{
		return width;
	}

	void Kirby::Initialize(int px, int py)
	{
		const int X_POS = px;
		const int Y_POS = py;
		x = X_POS;
		y = Y_POS;
		hp = 6;
		jumpDistance = 120;
		kickDistance = 100;
		exhaleDelay = 10;
		gasDistance = starDistance = 0;
		InvincibleTime = 0;
		type = 0;
		eat = -1;
		velocity = 2;
		count = 0;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isExhale = isJump = isAttack = isKick = isFly = isHurted = isSuck = isBig = isSwallow = isRunning = isInvincible = isLanding = false;
		isAlive = rightOrLeft = true;
		blood0.SetTopLeft(SIZE_X / 2 - blood0.Width() / 2, SIZE_Y - blood0.Height());
		blood1.SetTopLeft(SIZE_X / 2 - blood1.Width() / 2, SIZE_Y - blood1.Height());
		blood2.SetTopLeft(SIZE_X / 2 - blood2.Width() / 2, SIZE_Y - blood2.Height());
		blood3.SetTopLeft(SIZE_X / 2 - blood3.Width() / 2, SIZE_Y - blood3.Height());
		blood4.SetTopLeft(SIZE_X / 2 - blood4.Width() / 2, SIZE_Y - blood4.Height());
		blood5.SetTopLeft(SIZE_X / 2 - blood5.Width() / 2, SIZE_Y - blood5.Height());
		blood6.SetTopLeft(SIZE_X / 2 - blood6.Width() / 2, SIZE_Y - blood6.Height());
	}

	bool Kirby::IsAlive()
	{
		return isAlive;
	}

	bool Kirby::IsFly()
	{
		return isFly;
	}

	bool Kirby::IsKick()
	{
		return isKick;
	}

	bool Kirby::IsSuck()
	{
		return isSuck;
	}

	bool Kirby::IsAttack()
	{
		return isAttack;
	}

	bool Kirby::IsRight()
	{
		return rightOrLeft;
	}

	bool Kirby::IsDown()
	{
		return isMovingDown;
	}

	bool Kirby::IsBig()
	{
		return isBig;
	}

	bool Kirby::IsMove()
	{
		return isMovingLeft || isMovingRight;
	}

	void Kirby::LoadBitmap()
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
		// 雷電卡比
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
		// 火焰卡比
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

		blood0.LoadBitmap(".\\RES\\Blood_0.bmp", RGB(255, 255, 255));
		blood1.LoadBitmap(".\\RES\\Blood_1.bmp", RGB(255, 255, 255));
		blood2.LoadBitmap(".\\RES\\Blood_2.bmp", RGB(255, 255, 255));
		blood3.LoadBitmap(".\\RES\\Blood_3.bmp", RGB(255, 255, 255));
		blood4.LoadBitmap(".\\RES\\Blood_4.bmp", RGB(255, 255, 255));
		blood5.LoadBitmap(".\\RES\\Blood_5.bmp", RGB(255, 255, 255));
		blood6.LoadBitmap(".\\RES\\Blood_6.bmp", RGB(255, 255, 255));

		gas.LoadBitmap();
		star.LoadBitmap();
		lost.LoadBitmap();
	}

	void Kirby::OnMove(Map *m)
	{	
		//被攻擊且不是在空中也沒超出邊界時
		if (isHurted)
		{
			isFly = false;
			if (m->isEmpty(GetX2() - width / 2, GetY2() + 1))
				y++;
			if (rightOrLeft && m->isEmpty(GetX1() - STEP_SIZE, GetY1() + height / 2) && x - STEP_SIZE >= 0)
				x -= STEP_SIZE;
			else if (!rightOrLeft && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - height / 2) && x + STEP_SIZE <= m->GetWidth() - width)
				x += STEP_SIZE;
		}
		else
		{
			if (isMovingLeft && !isSuck && !isSwallow && !isAttack)
			{
				rightOrLeft = false;        //設定面向左邊
				// 上坡
				if (m->isSlope(GetX1() - 1, GetY2()) && !isMovingDown && (isFly || !isMovingUp)) {
					if (isRunning && !isFly)
					{
						x -= STEP_SIZE * 2;
						y -= STEP_SIZE * 2;
					}
					else
					{
						x -= STEP_SIZE;
						y -= STEP_SIZE;
					}
				}
				//先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
				//為了防止變身後卡比變高導致牆壁失效，將判斷撞牆的點設在Y2-10
				else if (m->isEmpty(GetX1() - STEP_SIZE, GetY2() - 10) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x <= 0) //邊界
						x = 0;
					else if (isRunning && !isFly && !m->isEmpty(GetX1() + width / 2, GetY2() + 1))
						x -= STEP_SIZE * 2;
					else
						x -= STEP_SIZE;
				}
			}
			else if (isMovingRight && !isSuck && !isSwallow && !isAttack)
			{
				rightOrLeft = true;          //設定面向右邊
				// 上坡
				if (m->isSlope(GetX2() - 1, GetY2()) && !isMovingDown && (isFly || !isMovingUp)) {
					if (isRunning && !isFly)
					{
						x += STEP_SIZE * 2;
						y -= STEP_SIZE * 2;
					}
					else
					{
						x += STEP_SIZE;
						y -= STEP_SIZE;
					}
				}
				//先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
				//為了防止變身後卡比變高導致牆壁失效，將判斷撞牆的點設在Y2-10
				else if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - 10) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x >= m->GetWidth() - width)  //邊界
						x = m->GetWidth() - width;
					else if (isRunning && !isFly && !m->isEmpty(GetX2() - width / 2, GetY2() + 1))
						x += STEP_SIZE * 2;
					else
						x += STEP_SIZE;
				}
			}
			if (isMovingUp && !isBig)
			{
				if (isFly && m->isEmpty_2(GetX1() + flyR.Width() / 2, GetY1() - STEP_SIZE))  //判斷飛行中上面是否可走
				{
					if (y <= 0)  //邊界
						y = 0;
					else
						y -= STEP_SIZE;
				}
			}
			if (isJump && !isSuck)
			{
				if (jumpDistance == 120)
					CAudio::Instance()->Play(jump);
				jumpDistance -= 5;
				if (m->isEmpty_2(GetX1() + width / 2, GetY1() - 5) && y - 5 > 0)  //會不會撞到頭
					y -= 5;
				if (jumpDistance == 0 || y - 5 <= 0)
				{
					jumpDistance = 120;
					isJump = false;
				}
			}
		}

		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() , GetY2() + 1) && m->isEmpty(GetX1(), GetY2() + 1))  //地吸引力
		{
			count++;
			isLanding = true;
			if (isFly)
				y += 1;	
			else
			{
				y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				if (velocity < 5 && count == 30)
				{
					velocity++; // 受重力影響，下次的下降速度增加
					count = 0;
				}
			}
		}
		else if (!isFly && m->isEmpty(x, y + height + 1) && m->isEmpty(x + width, y + height + 1))  // 當y座標還沒碰到地板
			y += 1;
		else
		{
			if (isLanding == true && !isFly && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				CAudio::Instance()->Play(landing);
				isLanding = false;
			}
			velocity = 2; // 重設重力加速度
			count = 0;
		}
	}

	void Kirby::OnShow(Map *m)
	{
		if (type == 0)
		{
			if (isBig)
			{
				height = bigOriginR.Height();
				width = bigOriginR.Width();
			}
			else
			{
				height = originR.Height();
				width = originR.Width();
			}
		}
		else if (type == 1)
		{
			height = Spark_originR.Height();
			width = Spark_originR.Width();
		}
		else if (type == 2)
		{
			height = fire_originR.Height();
			width = fire_originR.Width();
		}

		if (hp == 6) blood6.ShowBitmap();
		else if (hp == 5) blood5.ShowBitmap();
		else if (hp == 4) blood4.ShowBitmap();
		else if (hp == 3) blood3.ShowBitmap();
		else if (hp == 2) blood2.ShowBitmap();
		else if (hp == 1) blood1.ShowBitmap();
		else blood0.ShowBitmap();

		if (InvincibleTime != 0) InvincibleTime--;
		else isInvincible = false;

		if (type == 0) ShowKirby(m);
		else if (type == 1) ShowSparkKirby(m);
		else if (type == 2) ShowFireKirby(m);

		if (lost.IsAlive())
		{
			lost.OnMove(m, x, y, isSuck);
			lost.OnShow(m);
		}
	}

	void Kirby::Hurted(Map *m)
	{
		if (type != 0)
		{
			lost.Initialize(type, x, y);
			type = 0;
		}

		if (!isInvincible)
		{
			hp--;
			isInvincible = true;
			InvincibleTime = 60;
			if(hp>0)
				CAudio::Instance()->Play(hurted);
		}

		if (hp > 0)
			isHurted = true;
		else
		{
			CAudio::Instance()->Play(die);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND);
			isAlive = false;
		}
	}

	void Kirby::Die(Map *m)
	{
		GG.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		GG.ShowBitmap();
		y -= 3;
	}

	void Kirby::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Kirby::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Kirby::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Kirby::SetMovingUp(bool flag)
	{
		if (isBig)
			isMovingUp = false;
		else
			isMovingUp = flag;
	}

	void Kirby::SetJump(bool flag)
	{
		isJump = flag;
	}

	void Kirby::SetAttack(bool flag)
	{
		isAttack = flag;
	}

	void Kirby::SetSuck(bool flag)
	{
		isSuck = flag;
	}

	void Kirby::SetBig(bool flag)
	{
		isBig = flag;
	}

	void Kirby::SetRun(bool flag) {
		isRunning = flag;
	}

	void Kirby::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Kirby::SetEat(int t)
	{
		eat = t;
	}

	Gas* Kirby::GetGas()
	{
		return &gas;
	}

	Star* Kirby::GetStar()
	{
		return &star;
	}

	void Kirby::Attack(Map *m)
	{
		//------空氣彈------
		if (isFly && isAttack)
		{	
			gas.SetXY(x, y);
			gas.SetAlive(true);
			gasDistance = 176;
			bulletDirection = rightOrLeft;
		}
		if (gasDistance != 0)
		{
			gasDistance -= STEP_SIZE * 2;
			gas.OnMove(m, bulletDirection);
			gas.OnShow(m);
		}
		else
			gas.SetAlive(false);

		//------星星------
		if (isBig && isAttack && !isSuck)
		{
			star.SetXY(x, y);
			star.SetAlive(true);
			starDistance = 376;
			bulletDirection = rightOrLeft;
		}
		if (starDistance != 0)
		{
			starDistance -= STEP_SIZE * 2;
			star.OnMove(m, bulletDirection);
			star.OnShow(m);
		}
		else
			star.SetAlive(false);

		//------踢擊------
		if (!isFly && !isBig && (isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - width / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			isAttack = false;
			kickDistance -= 5;
			if (rightOrLeft && m->isEmpty(GetX2() + 5, GetY2() - 5) && x + 5 <= m->GetWidth() - downAttackR.Width())  //右邊會不會踢牆(y-5是補償卡比大小)
				x += 5;
			else if (!rightOrLeft && m->isEmpty(GetX1() - 5, GetY2() - 5) && x - 5 >= 0)  //左邊會不會踢牆(y-5是補償卡比大小)
				x -= 5;
			//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
			if (kickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - width / 2, GetY2() + 1))
			{
				kickDistance = 100;
				isKick = false;
			}
		}
	}

	void Kirby::Spark_Attack(Map *m)
	{
		//放電在怪物那邊偵測

		//------空氣彈------
		if (isFly && isAttack)
		{
			gas.SetXY(x, y + 40);
			gas.SetAlive(true);
			gasDistance = 176;
			bulletDirection = rightOrLeft;
		}
		if (gasDistance != 0)
		{
			gasDistance -= STEP_SIZE * 2;
			gas.OnMove(m, bulletDirection);
			gas.OnShow(m);
		}
		else
			gas.SetAlive(false);

		//------踢擊------
		if (!isFly && !isBig && (isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - width / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			isAttack = false;
			kickDistance -= 5;
			if (rightOrLeft && m->isEmpty(GetX2() + 5, GetY2() - 5) && x + 5 <= m->GetWidth() - Spark_downAttackR.Width() + 40)  //右邊會不會踢牆(y-5是補償卡比大小)(+40是消除動畫補償)
				x += 5;
			else if (!rightOrLeft && m->isEmpty(GetX1() - 5, GetY2() - 5) && x - 5 >= 0)  //左邊會不會踢牆(y-5是補償卡比大小)
				x -= 5;
			//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
			if (kickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - width / 2, GetY2() + 1))
			{
				kickDistance = 100;
				isKick = false;
			}
		}
	}

	void Kirby::Fire_Attack(Map *m)
	{
		//放火在怪物那邊偵測

		//------空氣彈------
		if (isFly && isAttack)
		{
			gas.SetXY(x, y + 40);
			gas.SetAlive(true);
			gasDistance = 176;
			bulletDirection = rightOrLeft;
		}
		if (gasDistance != 0)
		{
			gasDistance -= STEP_SIZE * 2;
			gas.OnMove(m, bulletDirection);
			gas.OnShow(m);
		}
		else
			gas.SetAlive(false);

		//------踢擊------
		if (!isFly && !isBig && (isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - width / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			isAttack = false;
			kickDistance -= 5;
			if (rightOrLeft && m->isEmpty(GetX2() + 5, GetY2() - 5) && x + 5 <= m->GetWidth() - fire_downAttackR.Width() + 30)  //右邊會不會踢牆(y-5是補償卡比大小)(+40是消除動畫補償)
				x += 5;
			else if (!rightOrLeft && m->isEmpty(GetX1() - 5, GetY2() - 5) && x - 5 >= 0)  //左邊會不會踢牆(y-5是補償卡比大小)
				x -= 5;
			//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
			if (kickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - width / 2, GetY2() + 1))
			{
				kickDistance = 100;
				isKick = false;
			}
		}
	}

	void Kirby::Transform()
	{
		if (eat == 1)
		{
			type = 1;
			y -= 40;
		}
		else if (eat == 2)
		{
			type = 2;
			y -= 40;
		}
	}

	void Kirby::ShowKirby(Map *m)
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

		Attack(m);

		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			prepareFlyR.Reset();
			prepareFlyL.Reset();
		}

		if (isHurted)   // 被攻擊
		{
			isBig = false;
			if (rightOrLeft)
			{
				hurtedR.OnMove();
				hurtedR.OnShow();
			}
			else
			{
				hurtedL.OnMove();
				hurtedL.OnShow();
			}
			if (hurtedL.IsFinalBitmap() || hurtedR.IsFinalBitmap())
			{
				isHurted = false;
				hurtedL.Reset();
				hurtedR.Reset();
			}
		}
		else if (isBig)
		{
			if(isSuck)
				isAttack = false;
			if (isJump)   //跳躍
			{
				if (rightOrLeft)
					bigJumpR.ShowBitmap();
				else
					bigJumpL.ShowBitmap();
			}
			else if (isAttack || (starDistance < 376 && starDistance > 356))  //吐怪
			{
				if (rightOrLeft)
					threwR.ShowBitmap();
				else
					threwL.ShowBitmap();
				if (starDistance <= 360)
					isBig = false;
			}
			else if (isSwallow || (isMovingDown && !m->isEmpty(GetX1() + width / 2, GetY2() + 1)))   //吞食
			{
				isSwallow = true;
				if (rightOrLeft)
				{
					swallowR.OnMove();
					swallowR.OnShow();
				}
				else
				{
					swallowL.OnMove();
					swallowL.OnShow();
				}
				if (swallowR.IsFinalBitmap() || swallowL.IsFinalBitmap())
				{
					isSwallow = false;
					isBig = false;
					Transform();
					swallowR.Reset();
					swallowL.Reset();
				}
			}
			//自由落體
			//兩腳地都必須空，且不是走在斜坡，才會顯示降落的圖
			else if (!isFly && m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				if (rightOrLeft)
					bigLandingR.ShowBitmap();
				else
					bigLandingL.ShowBitmap();
			}
			else if (isMovingLeft)   //向左走
			{
				if (isRunning)
					bigGoL.SetDelayCount(2);
				else
					bigGoL.SetDelayCount(10);
				bigGoL.OnShow();
				bigGoL.OnMove();
			}
			else if (isMovingRight)   //向右走
			{
				if (isRunning)
					bigGoR.SetDelayCount(2);
				else
					bigGoR.SetDelayCount(10);
				bigGoR.OnShow();
				bigGoR.OnMove();
			}
			else if (rightOrLeft)   //面相右
				bigOriginR.ShowBitmap();
			else if (!rightOrLeft)  //面相左
				bigOriginL.ShowBitmap();
		}
		else
		{
			if (isAttack && !isFly && !isMovingDown && (starDistance < 276 || !star.IsAlive()))  //吸怪
			{
				isSuck = true;
				if (rightOrLeft)
				{
					suckR.OnMove();
					suckR.OnShow();
				}
				else
				{
					suckL.OnMove();
					suckL.OnShow();
				}
				if (lost.IsAlive() && (lost.GetX() - x >= -2) && (lost.GetX() - x <= 2) && (lost.GetY() - y >= -2) && (lost.GetY() - y <= 2))
				{
					lost.SetAlive(false);
					SetBig(true);
					SetEat(lost.type);
				}
			}
			else if (isJump)   //跳躍
			{
				if (rightOrLeft)
					jumpR.ShowBitmap();
				else
					jumpL.ShowBitmap();
			}
			else if ((isAttack || isExhale) && isFly)   //吐氣
			{
				isExhale = true;
				exhaleDelay--;
				if (rightOrLeft)
					exhaleR.ShowBitmap();
				else
					exhaleL.ShowBitmap();
				if (exhaleDelay == 0)
				{
					exhaleDelay = 10;
					prepareFlyR.Reset();
					prepareFlyL.Reset();
					isFly = false;
					isExhale = false;
				}
				SetEat(-1);
			}
			else if (isMovingUp)
			{
				if (prepareFlyR.IsFinalBitmap() || prepareFlyL.IsFinalBitmap())   //飛行前吸氣
				{
					isFly = true;
					if (rightOrLeft)
					{
						if (flyR.GetCurrentBitmapNumber() == 1)
							CAudio::Instance()->Play(fly);
						flyR.OnShow();
						flyR.OnMove();
					}
					else
					{
						if (flyL.GetCurrentBitmapNumber() == 1)
							CAudio::Instance()->Play(fly);
						flyL.OnShow();
						flyL.OnMove();
					}
				}
				else
				{
					if (rightOrLeft)
					{
						prepareFlyR.OnShow();
						prepareFlyR.OnMove();
					}
					else
					{
						prepareFlyL.OnShow();
						prepareFlyL.OnMove();
					}
				}
			}
			else if (isFly)  //飛行
			{
				if (rightOrLeft)
				{
					if (flyR.GetCurrentBitmapNumber() == 1)
						CAudio::Instance()->Play(fly);
					flyR.OnShow();
					flyR.OnMove();
				}
				else
				{
					if (flyL.GetCurrentBitmapNumber() == 1)
						CAudio::Instance()->Play(fly);
					flyL.OnShow();
					flyL.OnMove();
				}
			}
			//自由落體
			//兩腳地都必須空，且不是走在斜坡，才會顯示降落的圖
			else if (!isFly && m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				if (rightOrLeft)
					landingR.ShowBitmap();
				else
					landingL.ShowBitmap();
			}
			else if (isKick && !isFly)   //踢擊
			{
				if (rightOrLeft)
					downAttackR.ShowBitmap();
				else
					downAttackL.ShowBitmap();
			}
			else if (isMovingDown && !m->isEmpty(GetX1() + width / 2, GetY2() + 1))   //縮小
			{
				if (rightOrLeft)
					downR.ShowBitmap();
				else
					downL.ShowBitmap();
			}
			else if (!isFly && isRunning && (isMovingLeft || isMovingRight))  //跑
			{
				if (!rightOrLeft)
				{
					runL.OnShow();
					runL.OnMove();
				}
				else
				{
					runR.OnShow();
					runR.OnMove();
				}
			}
			else if (!isFly && isMovingLeft)   //一般向左走
			{
				goL.OnShow();
				goL.OnMove();
			}
			else if (!isFly && isMovingRight)   //一般向右走
			{
				goR.OnShow();
				goR.OnMove();
			}
			else if (rightOrLeft)   //面相右
				originR.ShowBitmap();
			else if (!rightOrLeft)  //面相左
				originL.ShowBitmap();
		}
	}

	void Kirby::ShowSparkKirby(Map *m)
	{
		// 雷電卡比圖片.動畫定位及大小補償
		Spark_exhaleR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_exhaleL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y+20));
		Spark_downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y+20));
		Spark_landingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_landingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_goR.SetTopLeft(m->ScreenX(x), m->ScreenY(y-5));
		Spark_goL.SetTopLeft(m->ScreenX(x), m->ScreenY(y-5));
		Spark_jumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_jumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_downAttackR.SetTopLeft(m->ScreenX(x-40), m->ScreenY(y+30));
		Spark_downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y+30));
		Spark_flyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_prepareFlyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y+5));
		Spark_flyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_prepareFlyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y+5));
		Spark_runR.SetTopLeft(m->ScreenX(x-20), m->ScreenY(y+10));
		Spark_runL.SetTopLeft(m->ScreenX(x+10), m->ScreenY(y+10));
		Spark_attackR.SetTopLeft(m->ScreenX(x-40), m->ScreenY(y-20));
		Spark_attackL.SetTopLeft(m->ScreenX(x-40), m->ScreenY(y-20));
		hurtedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		hurtedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_Attack(m);

		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			Spark_prepareFlyR.Reset();
			Spark_prepareFlyL.Reset();
		}

		if (isHurted)   // 被攻擊
		{
			y += 40;  //還原補償的高度
			if (rightOrLeft)
			{
				hurtedR.OnMove();
				hurtedR.OnShow();
			}
			else
			{
				hurtedL.OnMove();
				hurtedL.OnShow();
			}
			if (hurtedL.IsFinalBitmap() || hurtedR.IsFinalBitmap())
			{
				isHurted = false;
				hurtedL.Reset();
				hurtedR.Reset();
			}
		}
		else
		{
			if (isAttack && !isFly && !isMovingDown)  //放電
			{
				if (rightOrLeft)
				{
					Spark_attackR.SetDelayCount(5);
					Spark_attackR.OnMove();
					Spark_attackR.OnShow();
				}
				else
				{
					Spark_attackL.SetDelayCount(5);
					Spark_attackL.OnMove();
					Spark_attackL.OnShow();
				}
			}
			else if (isJump)   //跳躍
			{
				if (rightOrLeft)
				{
					Spark_jumpR.OnMove();
					Spark_jumpR.OnShow();
				}
				else
				{
					Spark_jumpL.OnMove();
					Spark_jumpL.OnShow();
				}
			}
			else if ((isAttack || isExhale) && isFly)   //吐氣
			{
				isExhale = true;
				exhaleDelay--;
				if (rightOrLeft)
					Spark_exhaleR.ShowBitmap();
				else
					Spark_exhaleL.ShowBitmap();
				if (exhaleDelay == 0)
				{
					exhaleDelay = 10;
					Spark_prepareFlyR.Reset();
					Spark_prepareFlyL.Reset();
					isFly = false;
					isExhale = false;
				}
			}
			else if (isMovingUp)
			{
				if (Spark_prepareFlyR.IsFinalBitmap() || Spark_prepareFlyL.IsFinalBitmap())   //飛行前吸氣
				{
					isFly = true;
					if (rightOrLeft)
					{
						if (Spark_flyR.GetCurrentBitmapNumber() == 3)
							CAudio::Instance()->Play(fly);
						Spark_flyR.OnShow();
						Spark_flyR.OnMove();
					}
					else
					{
						if (Spark_flyL.GetCurrentBitmapNumber() == 3)
							CAudio::Instance()->Play(fly);
						Spark_flyL.OnShow();
						Spark_flyL.OnMove();
					}
				}
				else
				{
					if (rightOrLeft)
					{
						Spark_prepareFlyR.OnShow();
						Spark_prepareFlyR.OnMove();
					}
					else
					{
						Spark_prepareFlyL.OnShow();
						Spark_prepareFlyL.OnMove();
					}
				}
			}
			else if (isFly)  //飛行
			{
				if (rightOrLeft)
				{
					if (Spark_flyR.GetCurrentBitmapNumber() == 3)
						CAudio::Instance()->Play(fly);
					Spark_flyR.OnShow();
					Spark_flyR.OnMove();
				}
				else
				{
					if (Spark_flyL.GetCurrentBitmapNumber() == 3)
						CAudio::Instance()->Play(fly);
					Spark_flyL.OnShow();
					Spark_flyL.OnMove();
				}
			}
			//自由落體
			//兩腳地都必須空，且不是走在斜坡，才會顯示降落的圖
			else if (!isFly && m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				if (rightOrLeft)
				{
					Spark_landingR.OnShow();
					Spark_landingR.OnMove();
				}
				else
				{
					Spark_landingL.OnShow();
					Spark_landingL.OnMove();
				}
			}
			else if (isKick && !isFly)   //踢擊
			{
				if (rightOrLeft)
				{
					Spark_downAttackR.OnMove();
					Spark_downAttackR.OnShow();
				}
				else
				{
					Spark_downAttackL.OnMove();
					Spark_downAttackL.OnShow();
				}
			}
			else if (isMovingDown && !m->isEmpty(GetX1() + width / 2, GetY1() + height + 1))   //縮小
			{
				if (rightOrLeft)
				{
					Spark_downR.OnShow();
					Spark_downR.OnMove();
				}
				else
				{
					Spark_downL.OnShow();
					Spark_downL.OnMove();
				}
			}
			else if (!isFly && isRunning && (isMovingLeft || isMovingRight))  //跑
			{
				if (!rightOrLeft)
				{
					Spark_runL.OnShow();
					Spark_runL.OnMove();
				}
				else
				{
					Spark_runR.OnShow();
					Spark_runR.OnMove();
				}
			}
			else if (!isFly && isMovingLeft)   //一般向左走
			{
				Spark_goL.OnShow();
				Spark_goL.OnMove();
			}
			else if (!isFly && isMovingRight)   //一般向右走
			{
				Spark_goR.OnShow();
				Spark_goR.OnMove();
			}
			else if (rightOrLeft)   //面相右
			{
				Spark_originR.OnMove();
				Spark_originR.OnShow();
			}
			else if (!rightOrLeft)  //面相左
			{
				Spark_originL.OnMove();
				Spark_originL.OnShow();
			}
		}
	}

	void Kirby::ShowFireKirby(Map *m)
	{
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
		Fire_Attack(m);
		attack1.SetDelayCount(5);
		attack2.SetDelayCount(5);
		attack3.SetDelayCount(5);
		
		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			fire_prepareFlyR.Reset();
			fire_prepareFlyL.Reset();
		}

		if (isHurted)   // 被攻擊
		{
			y += 40;  //還原補償的高度
			if (rightOrLeft)
			{
				hurtedR.OnMove();
				hurtedR.OnShow();
			}
			else
			{
				hurtedL.OnMove();
				hurtedL.OnShow();
			}
			if (hurtedL.IsFinalBitmap() || hurtedR.IsFinalBitmap())
			{
				isHurted = false;
				hurtedL.Reset();
				hurtedR.Reset();
			}
		}
		else
		{
			if (isAttack && !isFly && !isMovingDown)  //放火
			{
				if (rightOrLeft)
				{
					fire_attackR.OnShow();
					fire_attackR.OnMove();
					attack1.SetTopLeft(m->ScreenX(x + 63), m->ScreenY(y + 30));
					attack2.SetTopLeft(m->ScreenX(x + 83), m->ScreenY(y + 10));
					attack3.SetTopLeft(m->ScreenX(x + 133), m->ScreenY(y + 10));
				}
				else
				{
					fire_attackL.OnShow();
					fire_attackL.OnMove();
					attack1.SetTopLeft(m->ScreenX(x - 52), m->ScreenY(y + 30));
					attack2.SetTopLeft(m->ScreenX(x - 72), m->ScreenY(y + 10));
					attack3.SetTopLeft(m->ScreenX(x - 122), m->ScreenY(y + 10));
				}
				attack1.OnMove();
				attack1.OnShow();
				attack2.OnMove();
				attack2.OnShow();
				attack3.OnMove();
				attack3.OnShow();
			}
			else if (isJump)   //跳躍
			{
				if (rightOrLeft)
				{
					fire_jumpR.OnMove();
					fire_jumpR.OnShow();
				}
				else
				{
					fire_jumpL.OnMove();
					fire_jumpL.OnShow();
				}
			}
			else if ((isAttack || isExhale) && isFly)   //吐氣
			{
				isExhale = true;
				exhaleDelay--;
				if (rightOrLeft)
					fire_exhaleR.ShowBitmap();
				else
					fire_exhaleL.ShowBitmap();
				if (exhaleDelay == 0)
				{
					exhaleDelay = 10;
					fire_prepareFlyR.Reset();
					fire_prepareFlyL.Reset();
					isFly = false;
					isExhale = false;
				}
			}
			else if (isMovingUp)
			{
				if (fire_prepareFlyR.IsFinalBitmap() || fire_prepareFlyL.IsFinalBitmap())   //飛行前吸氣
				{
					isFly = true;
					if (rightOrLeft)
					{
						if (fire_flyR.GetCurrentBitmapNumber() == 3)
							CAudio::Instance()->Play(fly);
						fire_flyR.OnShow();
						fire_flyR.OnMove();
					}
					else
					{
						if (fire_flyL.GetCurrentBitmapNumber() == 3)
							CAudio::Instance()->Play(fly);
						fire_flyL.OnShow();
						fire_flyL.OnMove();
					}
				}
				else
				{
					if (rightOrLeft)
					{
						fire_prepareFlyR.OnShow();
						fire_prepareFlyR.OnMove();
					}
					else
					{
						fire_prepareFlyL.OnShow();
						fire_prepareFlyL.OnMove();
					}
				}
			}
			else if (isFly)  //飛行
			{
				if (rightOrLeft)
				{
					if (fire_flyR.GetCurrentBitmapNumber() == 3)
						CAudio::Instance()->Play(fly);
					fire_flyR.OnShow();
					fire_flyR.OnMove();
				}
				else
				{
					if (fire_flyL.GetCurrentBitmapNumber() == 3)
						CAudio::Instance()->Play(fly);
					fire_flyL.OnShow();
					fire_flyL.OnMove();
				}
			}
			//自由落體
			//兩腳地都必須空，且不是走在斜坡，才會顯示降落的圖
			else if (!isFly && m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				if (rightOrLeft)
				{
					fire_landingR.OnShow();
					fire_landingR.OnMove();
				}
				else
				{
					fire_landingL.OnShow();
					fire_landingL.OnMove();
				}
			}
			else if (isKick && !isFly)   //踢擊
			{
				if (rightOrLeft)
				{
					fire_downAttackR.OnMove();
					fire_downAttackR.OnShow();
				}
				else
				{
					fire_downAttackL.OnMove();
					fire_downAttackL.OnShow();
				}
			}
			else if (isMovingDown && !m->isEmpty(GetX1() + width / 2, GetY1() + height + 1))   //縮小
			{
				if (rightOrLeft)
				{
					fire_downR.OnShow();
					fire_downR.OnMove();
				}
				else
				{
					fire_downL.OnShow();
					fire_downL.OnMove();
				}
			}
			else if (!isFly && isRunning && (isMovingLeft || isMovingRight))  //跑
			{
				if (!rightOrLeft)
				{
					fire_runL.OnShow();
					fire_runL.OnMove();
				}
				else
				{
					fire_runR.OnShow();
					fire_runR.OnMove();
				}
			}
			else if (!isFly && isMovingLeft)   //一般向左走
			{
				fire_goL.OnShow();
				fire_goL.OnMove();
			}
			else if (!isFly && isMovingRight)   //一般向右走
			{
				fire_goR.OnShow();
				fire_goR.OnMove();
			}
			else if (rightOrLeft)   //面相右
			{
				fire_originR.OnMove();
				fire_originR.OnShow();
			}
			else if (!rightOrLeft)  //面相左
			{
				fire_originL.OnMove();
				fire_originL.OnShow();
			}
		}
	}
}