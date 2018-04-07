#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 地圖物件的行為
	/////////////////////////////////////////////////////////////////////////////

	class Door
	{
	public:
		Door();
		int  GetWidth();                    //取得背景寬度
		int  GetHeight();                   //取得背景高度
		void Initialize();					// 設定為初始值
		void LoadBitmap();			// 載入圖形
		void OnMove();               // 地圖移動
		void OnShow();						// 將圖形貼到畫面
		void SetMouse(int, int);			//設定滑鼠座標
		void IsLclick(bool);				//設定左鍵按下
		void IsRclick(bool);				//設定右鍵按下
	protected:
		CAnimation door;			// 地圖

	private:
		bool Lclick = false, Rclick = false;    //滑鼠左鍵與右鍵是否按下 預設為否
		int mx, my;							//滑鼠座標
		int x, y;							// 左上角座標
	};


}