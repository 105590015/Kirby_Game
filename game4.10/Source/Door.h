#pragma once
#include"Map.h"
#include"Kirby.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �a�Ϫ��󪺦欰
	/////////////////////////////////////////////////////////////////////////////

	class Door
	{
	public:
		Door();
		int  GetMapNum();
		int  GetWidth();                    //���o�I���e��
		int  GetHeight();                   //���o�I������
		void Initialize(int x,int y,int Num);					// �]�w����l��
		void LoadBitmap();			// ���J�ϧ�
		void OnMove();               // �a�ϲ���
		void OnShow(Map *);						// �N�ϧζK��e��
		void SetEnter(bool flag);	// �]�w�O�_���i�J�ǰe��
		void SetTopLeft(int, int);
		bool IsEnter(Kirby*);

	protected:
		CAnimation door;			// �a��

	private:
		bool Enter=false;    //�ƹ�����P�k��O�_���U �w�]���_
		int x, y;							// ���W���y��
		int mapNum;				//�O�������ǰe��X���a��
	};


}