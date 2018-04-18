#pragma once
#include "Map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 卡比的所有資料
	/////////////////////////////////////////////////////////////////////////////

	class Kirby
	{
	public:
		Kirby();
		int  GetX1();					// 左上角 x 座標
		int  GetY1();					// 左上角 y 座標
		int  GetX2();					// 右下角 x 座標
		int  GetY2();					// 右下角 y 座標
		void Initialize(int ,int);		// 設定為初始值
		bool IsAlive();					// 是否活著
		bool IsFly();                   // 是否在飛
		bool IsKick();                  // 是否踢擊
		bool IsSuck();                  // 是否吸怪
		void LoadBitmap();				// 載入圖形
		void OnMove(Map *m);		    // 移動
		void OnShow(Map *m);			// 將圖形貼到畫面
		void Hurted();                  // 受傷
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetSpace(bool flag);	    // 設定是否按下空白鍵
		void SetJump(bool flag);	    // 設定是否按下X鍵
		void SetAttack(bool flag);	    // 設定是否按下Z鍵
		void SetSuck(bool flag);	    // 設定是否吸怪
		void SetRun(bool);				// 設定是否按下C
		void SetXY(int nx, int ny);		// 設定左上角的座標
	protected:	
		CMovingBitmap originR, originL, ExhaleRight, ExhaleLeft, JumpRight, JumpLeft, DownRight, DownLeft, LandingRight, LandingLeft, downAttackR, downAttackL;
		CAnimation GoLeft, GoRight, FlyRight, PrepareFlyRight, FlyLeft, PrepareFlyLeft, hurtedL, hurtedR, RunLeft, RunRight, suckRight, suckLeft;
		int x, y;					// 左上角座標
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isSpace;			    // 是否按下空白鍵
		bool isJump;			    // 是否按下X鍵
		bool isAttack;              // 是否按下Z鍵
		bool isKick;                // 是否使用踢擊
		bool isSuck;                // 是否使用吸怪
		bool isHurted;              // 是否被攻擊
		bool is_alive;				// 是否活著
		bool isFly;                 // 是否在飛
		bool isRunning;				// 是否在跑
		bool RightOrLeft;           // 判斷左右
	private:
		int ExhaleDelay;            // 吐氣的時間
		int JumpDistance;           // 跳躍的距離
		int KickDistance;           // 踢擊的距離
		int hp;
	};
}