namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 地圖物件的行為
	/////////////////////////////////////////////////////////////////////////////

	class Map
	{
	public:
		Map();
		int  ScreenX(int x);				// 螢幕 x 座標
		int  ScreenY(int y);				// 螢幕 y 座標
		void Initialize();					// 設定為初始值
		void LoadBitmap();					// 載入圖形
		void OnMove();                      // 地圖移動
		void OnShow();						// 將圖形貼到畫面
		void SetXY(int nx, int ny);	        // 設定螢幕畫面左上角的座標
		bool isEmpty(int x, int y);         // 判斷碰壁;
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
	protected:
		CMovingBitmap background;			// 地圖
		CMovingBitmap foreground;
	private:
		int sx, sy;							// 左上角座標
		int map[10][10];
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
	};
}