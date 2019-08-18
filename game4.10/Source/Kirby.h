#pragma once
#include "Map.h"
#include "Gas.h"
#include "Star.h"
#include "LostAbility.h"
#include "KirbyType.h"
#include "Kirby_normal.h"
#include "Kirby_spark.h"
#include "Kirby_fire.h"
#include "Kirby_somethingInMouth.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 卡比的所有資料
	/////////////////////////////////////////////////////////////////////////////
	class Kirby
	{
	public:
		Kirby();
		~Kirby();
		int  GetX1();					  // 左上角 x 座標
		int  GetY1();				  	  // 左上角 y 座標
		int  GetX2();			          // 右下角 x 座標
		int  GetY2();			          // 右下角 y 座標
		int  GetType();                   // 取得當前型態
		int  GetHeight();                 // 取得身高
		int  GetWidth();                  // 取得寬度
		void Initialize(int ,int);		  // 設定為初始值
		bool IsAlive();					  // 是否活著
		bool IsFly();                     // 是否在飛
		bool IsKick();                    // 是否踢擊
		bool IsSuck();                    // 是否吸怪
		bool IsAttack();                  // 是否按Z鍵
		bool IsRight();                   // 面對方向
		bool IsDown();                    // 是否縮小
		bool IsBig();                     // 是否是大隻的
		bool IsMove();                    // 是否在移動
		void LoadBitmap();				  // 載入圖形
		void OnMove(Map *m);		      // 移動
		void OnShow(Map *m);			  // 將圖形貼到畫面
		void Hurted(Map *m);              // 受傷
		void Die(Map *m);			      // 死去
		void SetMovingDown(bool flag);    // 設定是否正在往下移動
		void SetMovingLeft(bool flag);	  // 設定是否正在往左移動
		void SetMovingRight(bool flag);   // 設定是否正在往右移動
		void SetMovingUp(bool flag);	  // 設定是否正在往上移動
		void SetJump(bool flag);	      // 設定是否按下X鍵
		void SetAttack(bool flag);	      // 設定是否按下Z鍵
		void SetSuck(bool flag);	      // 設定是否吸怪
		void SetBig(bool flag);		      // 設定是否含滷蛋
		void SetRun(bool);				  // 設定是否按下C
		void SetXY(int nx, int ny);		  // 設定左上角的座標
		void SetEat(int t);		          // 設定吃了什麼怪物
		void Restore();                   // 密技:血回到滿
		Bullet* GetBullet();
		void DeleteBullet();
	protected:	
		CMovingBitmap blood6, blood5, blood4, blood3, blood2, blood1, blood0;
		CMovingBitmap GG;

		Bullet* bullet;
		LostAbility lost;
		int x, y;					// 左上角座標
		int flyCount;               // 飛行圖片顯示計數
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isExhale;			    // 是否吐氣
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
		bool isLanding;             // 是否降落中
		bool rightOrLeft;           // 判斷左右
	private:
		void ShowKirby(Map *m);     // 顯示普通卡比
		int exhaleDelay;            // 吐氣的時間
		int jumpDistance;           // 跳躍的距離
		int kickDistance;           // 踢擊的距離
		int bulletDistance;			// 吐出物體飛行距離
		bool bulletDirection;       // 吐出物體方向
		bool isInvincible;          // 是否無敵
		int InvincibleTime;         // 無敵時間
		void Attack(Map *m);        // 普通卡比攻擊
		void Transform();           // 變身
		int hp;                     // 血量
		int type;                   // 型態
		int eat;                    // 吃了什麼
		int velocity;               // 重力加速度
		int count;                  // 計數是否一秒
		int height;                 // 記錄當下的身高
		int width;                  // 記錄當下的寬度

		Kirby_normal* kirby_normal;
		Kirby_fire* kirby_fire;
		Kirby_spark* kirby_spark;
		Kirby_somethingInMouth* kirby_somethingInMouth;
		KirbyType* kirbyType;

		enum COPY_AUDIO_ID {		// 定義各種音效的編號
			AUDIO_BACKGROUND,       // 0
			jump,                   // 1
			landing,                // 2
			kick,                   // 3
			die,                    // 4
			fly,                    // 5
			hurted,                 // 6
			run,                    // 7
			suck,                   // 8
			gasSound,               // 9
			starSound,              // 10
			swallow,                // 11
			spark,                  // 12
			fire,                   // 13
			stone,                  // 14
			start,                  // 15
			enemyDie,               // 16
			lostAbility,            // 17
			ending                  // 18
		};
	};
}