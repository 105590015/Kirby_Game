#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �a�Ϫ��󪺦欰
	/////////////////////////////////////////////////////////////////////////////

	class Door
	{
	public:
		Door();
		int  GetWidth();                    //���o�I���e��
		int  GetHeight();                   //���o�I������
		void Initialize();					// �]�w����l��
		void LoadBitmap();			// ���J�ϧ�
		void OnMove();               // �a�ϲ���
		void OnShow();						// �N�ϧζK��e��
		void SetMouse(int, int);			//�]�w�ƹ��y��
		void IsLclick(bool);				//�]�w������U
		void IsRclick(bool);				//�]�w�k����U
	protected:
		CAnimation door;			// �a��

	private:
		bool Lclick = false, Rclick = false;    //�ƹ�����P�k��O�_���U �w�]���_
		int mx, my;							//�ƹ��y��
		int x, y;							// ���W���y��
	};


}