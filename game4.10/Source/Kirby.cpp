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
		if (type == 0)
			return x + originR.Width();
		else
			return x + Spark_originR.Width();
	}

	int Kirby::GetY2()
	{
		if (type == 0)
			return y + originR.Height();
		else
			return y + Spark_originR.Height();
	}

	void Kirby::Initialize(int px, int py)  //設定在腳色在螢幕的初始位置
	{
		const int X_POS = px;
		const int Y_POS = py;
		x = X_POS;
		y = Y_POS;
		hp = 6;
		jumpDistance = 120;
		kickDistance = 100;
		exhaleDelay = 10;
		gasDistance = startDistance = 0;
		InvincibleTime = 0;
		type = 0;
		eat = -1;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isSpace = isJump = isAttack = isKick = isFly = isHurted = isSuck = isBig = isSwallow = isRunning = isInvincible = false;
		isAlive = rightOrLeft = true;
		gas.LoadBitmap();
		start.LoadBitmap();
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
		Spark_downR.LoadBitmap(".\\RES\\SparkKirby\\Spark_Down_R.bmp", RGB(255, 255, 255));
		Spark_downL.LoadBitmap(".\\RES\\SparkKirby\\Spark_Down_L.bmp", RGB(255, 255, 255));
		Spark_landingR.LoadBitmap(".\\RES\\SparkKirby\\Spark_Landing_R.bmp", RGB(255, 255, 255));
		Spark_landingL.LoadBitmap(".\\RES\\SparkKirby\\Spark_Landing_L.bmp", RGB(255, 255, 255));
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
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_07.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_08.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_09.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_10.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_11.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_12.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_13.bmp", RGB(255, 255, 255));
		Spark_flyR.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_R_14.bmp", RGB(255, 255, 255));
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
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_07.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_08.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_09.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_10.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_11.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_12.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_13.bmp", RGB(255, 255, 255));
		Spark_flyL.AddBitmap(".\\RES\\SparkKirby\\Spark_Fly_L_14.bmp", RGB(255, 255, 255));
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

		blood0.LoadBitmap(".\\RES\\Blood_0.bmp", RGB(255, 255, 255));
		blood1.LoadBitmap(".\\RES\\Blood_1.bmp", RGB(255, 255, 255));
		blood2.LoadBitmap(".\\RES\\Blood_2.bmp", RGB(255, 255, 255));
		blood3.LoadBitmap(".\\RES\\Blood_3.bmp", RGB(255, 255, 255));
		blood4.LoadBitmap(".\\RES\\Blood_4.bmp", RGB(255, 255, 255));
		blood5.LoadBitmap(".\\RES\\Blood_5.bmp", RGB(255, 255, 255));
		blood6.LoadBitmap(".\\RES\\Blood_6.bmp", RGB(255, 255, 255));
	}

	void Kirby::OnMove(Map *m)
	{
		// 設定身材
		if (type == 0)
		{
			height = originR.Height();
			width = originR.Width();
		}
		else if(type==1)
		{
			height = Spark_originR.Height();
			width = Spark_originR.Width();
		}
		//被攻擊且不是在空中也沒超出邊界時
		if (isHurted)
		{
			isFly = false;
			if (m->isEmpty(GetX2() - width / 2, GetY2() + 1))
				y++;
			if (rightOrLeft && m->isEmpty(GetX1() - STEP_SIZE, GetY1() + hurtedR.Height() / 2) && x - STEP_SIZE >= 0)
				x -= STEP_SIZE;
			else if (!rightOrLeft && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - hurtedL.Height() / 2) && x + STEP_SIZE <= m->GetWidth() - width)
				x += STEP_SIZE;
		}
		else
		{
			if (isMovingLeft && !isSuck && !isSwallow)
			{
				rightOrLeft = false;        //設定面向左邊
				//先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
				if (m->isEmpty(GetX1() - STEP_SIZE, GetY1() + height / 2) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x <= 0) //邊界
						x = 0;
					else if (isRunning && !isFly && !m->isEmpty(GetX2() - width / 2, GetY2() + 1))
						x -= STEP_SIZE * 2;
					else
						x -= STEP_SIZE;
				}
			}
			else if (isMovingRight && !isSuck && !isSwallow)
			{
				rightOrLeft = true;          //設定面向右邊
				//先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
				if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - height / 2) && !isMovingDown && (isFly || !isMovingUp))
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
				jumpDistance -= 5;
				if (m->isEmpty_2(GetX1() + width / 2, GetY1() - 5))  //會不會撞到頭
					y -= 5;
				if (jumpDistance == 0)
				{
					jumpDistance = 120;
					isJump = false;
				}
			}
		}
		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() - width / 2, GetY2() + 1))  //地吸引力
		{
			if (isFly)
				y += 1;
			else
			{
				if (y >= m->GetHeight() - height)
					y = m->GetHeight() - height;
				else
					y += STEP_SIZE;
			}
		}
	}

	void Kirby::OnShow(Map *m)
	{
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
	}

	void Kirby::Hurted()
	{
		if (!isInvincible)
		{
			hp--;
			isInvincible = true;
			InvincibleTime = 45;
		}

		if (hp > 0)
			isHurted = true;
		else
			isAlive = false;
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

	void Kirby::SetSpace(bool flag)
	{
		isSpace = flag;
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

	void Kirby::Attack(Map *m)
	{
		//------空氣彈------
		if (isFly && isSpace)
		{
			gas.SetXY(x, y);
			gasDistance = 176;
			bulletDirection = rightOrLeft;
		}
		if (gasDistance != 0)
		{
			gasDistance -= STEP_SIZE * 2;
			gas.OnMove(m, bulletDirection);
			gas.OnShow(m);
		}

		//------星星------
		if (isBig && isAttack && !isSuck)
		{
			start.SetXY(x, y);
			startDistance = 376;
			bulletDirection = rightOrLeft;
		}
		if (startDistance != 0)
		{
			startDistance -= STEP_SIZE * 2;
			start.OnMove(m, bulletDirection);
			start.OnShow(m);
		}

		//------踢擊------
		if (!isFly && !isBig && (isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			kickDistance -= 5;
			if (rightOrLeft && m->isEmpty(GetX2() + 5, GetY2() - 5) && x + 5 <= m->GetWidth() - downAttackR.Width())  //右邊會不會踢牆(y-2是補償圖檔大小的差異)
				x += 5;
			else if (!rightOrLeft && m->isEmpty(GetX1() - 5, GetY2() - 5) && x - 5 >= 0)  //左邊會不會踢牆(y-2是補償圖檔大小的差異)
				x -= 5;
			//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
			if (kickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))
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
			y -= 40; // 卡比身高補償
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
			if (isSuck)
				isAttack = false;
			if (isJump)   //跳躍
			{
				if (rightOrLeft)
					bigJumpR.ShowBitmap();
				else
					bigJumpL.ShowBitmap();
			}
			else if (isAttack)  //吐怪
			{
				if (rightOrLeft)
					threwR.ShowBitmap();
				else
					threwL.ShowBitmap();
				if (!isSuck)
					isBig = false;
			}
			else if (isSwallow || (isMovingDown && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1)))   //吞食
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
			else if (m->isEmpty(GetX2() - bigOriginR.Width() / 2, GetY2() + 1))  //自由落體
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
			if (isAttack && !isFly && !isMovingDown)  //吸怪
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
			}
			else if (isJump)   //跳躍
			{
				if (rightOrLeft)
					jumpR.ShowBitmap();
				else
					jumpL.ShowBitmap();
			}
			else if (isSpace && isFly)   //吐氣
			{
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
					isSpace = false;
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
						flyR.OnShow();
						flyR.OnMove();
					}
					else
					{
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
					flyR.OnShow();
					flyR.OnMove();
				}
				else
				{
					flyL.OnShow();
					flyL.OnMove();
				}
			}
			else if (!isFly && m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))  //自由落體
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
			else if (isMovingDown && !m->isEmpty(GetX2() - originR.Width() / 2, GetY2() + 1))   //縮小
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
		Spark_exhaleR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_exhaleL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_downR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_downL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_landingR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_landingL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_originR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_originL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_goR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_goL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_jumpR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_jumpL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_downAttackR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_downAttackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_flyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_prepareFlyR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_flyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_prepareFlyL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_runR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_runL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_attackR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		Spark_attackL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		hurtedL.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		hurtedR.SetTopLeft(m->ScreenX(x), m->ScreenY(y));

		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			Spark_prepareFlyR.Reset();
			Spark_prepareFlyL.Reset();
		}

		if (isHurted)   // 被攻擊
		{
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
					Spark_attackR.OnMove();
					Spark_attackR.OnShow();
				}
				else
				{
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
			else if (isSpace && isFly)   //吐氣
			{
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
					isSpace = false;
				}
			}
			else if (isMovingUp)
			{
				if (Spark_prepareFlyR.IsFinalBitmap() || Spark_prepareFlyL.IsFinalBitmap())   //飛行前吸氣
				{
					isFly = true;
					if (rightOrLeft)
					{
						Spark_flyR.OnShow();
						Spark_flyR.OnMove();
					}
					else
					{
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
					Spark_flyR.OnShow();
					Spark_flyR.OnMove();
				}
				else
				{
					Spark_flyL.OnShow();
					Spark_flyL.OnMove();
				}
			}
			else if (!isFly && m->isEmpty(GetX1() + Spark_originR.Width() / 2, GetY1() + Spark_originR.Height() + 1))  //自由落體
			{
				if (rightOrLeft)
					Spark_landingR.ShowBitmap();
				else
					Spark_landingL.ShowBitmap();
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
			else if (isMovingDown && !m->isEmpty(GetX1() + Spark_originR.Width() / 2, GetY1() + Spark_originR.Height() + 1))   //縮小
			{
				if (rightOrLeft)
					Spark_downR.ShowBitmap();
				else
					Spark_downL.ShowBitmap();
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
}