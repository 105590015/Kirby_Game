#pragma once
#include "Map.h"
#include "Gas.h"
#include "Start.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 卡比的所有資料
	/////////////////////////////////////////////////////////////////////////////

	class Kirby
	{
	public:
		Kirby();
		int  GetX1();					  // 左上角 x 座標
		int  GetY1();				  	  // 左上角 y 座標
		int  GetX2();			          // 右下角 x 座標
		int  GetY2();			          // 右下角 y 座標
		void Initialize(int ,int);		  // 設定為初始值
		bool IsAlive();					  // 是否活著
		bool IsFly();                     // 是否在飛
		bool IsKick();                    // 是否踢擊
		bool IsSuck();                    // 是否吸怪
		void LoadBitmap();				  // 載入圖形
		void OnMove(Map *m);		      // 移動
		void OnShow(Map *m);			  // 將圖形貼到畫面
		void Hurted();                    // 受傷
		void Die(Map *m);			      // 死去
		void SetMovingDown(bool flag);    // 設定是否正在往下移動
		void SetMovingLeft(bool flag);	  // 設定是否正在往左移動
		void SetMovingRight(bool flag);   // 設定是否正在往右移動
		void SetMovingUp(bool flag);	  // 設定是否正在往上移動
		void SetSpace(bool flag);	      // 設定是否按下空白鍵
		void SetJump(bool flag);	      // 設定是否按下X鍵
		void SetAttack(bool flag);	      // 設定是否按下Z鍵
		void SetSuck(bool flag);	      // 設定是否吸怪
		void SetBig(bool flag);		      // 設定是否含滷蛋
		void SetRun(bool);				  // 設定是否按下C
		void SetXY(int nx, int ny);		  // 設定左上角的座標
	protected:	
		// 普通卡比
		CMovingBitmap originR, originL, exhaleR, exhaleL, jumpR, jumpL, downR, downL, landingR, landingL, downAttackR, downAttackL, GG;
		CAnimation goL, goR, flyR, prepareFlyR, flyL, prepareFlyL, hurtedL, hurtedR, runL, runR, suckR, suckL;
		// 含東西卡比
		CMovingBitmap bigOriginR, bigOriginL, bigJumpR, bigJumpL, bigLandingR, bigLandingL, threwR, threwL;
		CAnimation bigGoL, bigGoR, swallowR, swallowL;
		CMovingBitmap blood6, blood5, blood4, blood3, blood2, blood1, blood0;
		// 雷電卡比
		CMovingBitmap Spark_exhaleR, Spark_exhaleL, Spark_downR, Spark_downL, Spark_landingR, Spark_landingL;
		CAnimation Spark_originR, Spark_originL, Spark_goR, Spark_goL, Spark_jumpR, Spark_jumpL, Spark_downAttackR, Spark_downAttackL, Spark_flyR, Spark_prepareFlyR, Spark_flyL, Spark_prepareFlyL, Spark_runR, Spark_runL;

		Gas gas;
		Start start;
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
		bool isAlive;				// 是否活著
		bool isFly;                 // 是否在飛
		bool isRunning;				// 是否在跑
		bool isBig;                 // 是否含滷蛋
		bool isSwallow;             // 是否在吞怪
		bool rightOrLeft;           // 判斷左右
	private:
		int exhaleDelay;            // 吐氣的時間
		int jumpDistance;           // 跳躍的距離
		int kickDistance;           // 踢擊的距離
		int gasDistance;            // 氣體飛行距離
		int startDistance;          // 星星飛行距離
		bool bulletDirection;       // 吐出物體方向
		bool isInvincible;          // 是否無敵
		int InvincibleTime;         // 無敵時間
		void Attack(Map *m);        // 攻擊
		int hp;
	};
}