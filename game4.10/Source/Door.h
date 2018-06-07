#pragma once
#include"Map.h"
#include"Kirby.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 地圖物件的行為
	/////////////////////////////////////////////////////////////////////////////

	class Door
	{
	public:
		Door();
		int  GetMapNum();
		int  GetWidth();                    //取得背景寬度
		int  GetHeight();                   //取得背景高度
		int  GetX();
		int  GetY();
		int  GetNextX();
		int  GetNextY();
		int  GetX2();
		int  GetY2();
		void Initialize(int x,int y,int Num,int,Door* );					// 設定為初始值
		void LoadBitmap();			// 載入圖形
		void OnMove();               // 地圖移動
		void OnShow(Map *);						// 將圖形貼到畫面
		void SetEnter(bool flag);	// 設定是否正進入傳送門
		bool IsEnter(Kirby*);
		Door GetNextDoor();


	protected:
		CAnimation door;			// 地圖
		CAnimation Gate;
	private:
		bool Enter=false;    //是否在門按上 預設為否
		int x, y;							// 左上角座標
		int mapNum;				//記錄此門傳送到幾號地圖
		int map;				//現在所在地圖
		Door* NextDoor;
	};


}