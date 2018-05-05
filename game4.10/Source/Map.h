#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �a�Ϫ��󪺦欰
	/////////////////////////////////////////////////////////////////////////////

	class Map
	{
	public:
		Map();
		int  GetWidth();                    //���o�I���e��
		int  GetHeight();                   //���o�I������
		int  ScreenX(int x);				// �ù� x �y��
		int  ScreenY(int y);				// �ù� y �y��
		void Initialize();					// �]�w����l��
		void LoadBitmap(char*,COLORREF,char*,string);		// ���J�ϧ�
		void OnMove(int,int);               // �a�ϲ���
		void OnShow();						// �N�ϧζK��e��
		void SetXY(int nx, int ny);	        // �]�w�ù��e�����W�����y��
		bool isEmpty(int x, int y);         // �P�_�I��;
		bool isEmpty_2(int x, int y);         // �P�_�I��;
		void SetMouse(int ,int);			//�]�w�ƹ��y��
		void IsLclick(bool);				//�]�w������U
		void IsRclick(bool);				//�]�w�k����U
	protected:
		CMovingBitmap background;			// �a��
		CMovingBitmap foreground;
		CMovingBitmap ball,ball_1;					//��ܦa�ι�

	private:
		bool Lclick=false, Rclick=false;    //�ƹ�����P�k��O�_���U �w�]���_
		int mx, my;							//�ƹ��y��
		int sx, sy;							// ���W���y��
		int mapSize_X, mapSize_Y;			//�a�ϩҤ������
		int map[1000][1000];
		string Mapfile;
		
	};


}