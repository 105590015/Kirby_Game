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
		void Initialize();				// 設定為初始值
		bool IsAlive();					// 是否活著
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動
		void OnShow();					// 將圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetSpace(bool flag);	    // 設定是否按下空白鍵
		void SetXY(int nx, int ny);		// 設定左上角的座標
	protected:	
		CMovingBitmap originR, originL;		//卡比不動的圖
		CAnimation GoLeft, GoRight, FlyRight, PrepareFlyRight, FlyLeft, PrepareFlyLeft;	// 卡比左.右走.飛行.預備飛行的動畫
		int x, y;					// 左上角座標
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isSpace;			    // 是否按下空白鍵
		bool is_alive;				// 是否活著
		bool isFly;                 // 是否在飛
		bool RightOrLeft;           // 判斷左右
	private:
		int flyDelay;               // 飛行前的吸氣時間
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// 是否碰到參數範圍的矩形
	};
}