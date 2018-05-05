#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 地圖物件的行為
	/////////////////////////////////////////////////////////////////////////////

	class Map
	{
	public:
		Map();
		int  GetWidth();                    //取得背景寬度
		int  GetHeight();                   //取得背景高度
		int  ScreenX(int x);				// 螢幕 x 座標
		int  ScreenY(int y);				// 螢幕 y 座標
		void Initialize();					// 設定為初始值
		void LoadBitmap(char*,COLORREF,char*,string);		// 載入圖形
		void OnMove(int,int);               // 地圖移動
		void OnShow();						// 將圖形貼到畫面
		void SetXY(int nx, int ny);	        // 設定螢幕畫面左上角的座標
		bool isEmpty(int x, int y);         // 判斷碰壁;
		bool isEmpty_2(int x, int y);         // 判斷碰壁;
		void SetMouse(int ,int);			//設定滑鼠座標
		void IsLclick(bool);				//設定左鍵按下
		void IsRclick(bool);				//設定右鍵按下
	protected:
		CMovingBitmap background;			// 地圖
		CMovingBitmap foreground;
		CMovingBitmap ball,ball_1;					//顯示地形圖

	private:
		bool Lclick=false, Rclick=false;    //滑鼠左鍵與右鍵是否按下 預設為否
		int mx, my;							//滑鼠座標
		int sx, sy;							// 左上角座標
		int mapSize_X, mapSize_Y;			//地圖所切的格數
		int map[1000][1000];
		string Mapfile;
		
	};


}