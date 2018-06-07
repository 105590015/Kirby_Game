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
		int  GetX();
		int  GetY();
		int  GetNextX();
		int  GetNextY();
		int  GetX2();
		int  GetY2();
		void Initialize(int x,int y,int Num,int,Door* );					// �]�w����l��
		void LoadBitmap();			// ���J�ϧ�
		void OnMove();               // �a�ϲ���
		void OnShow(Map *);						// �N�ϧζK��e��
		void SetEnter(bool flag);	// �]�w�O�_���i�J�ǰe��
		bool IsEnter(Kirby*);
		Door GetNextDoor();


	protected:
		CAnimation door;			// �a��
		CAnimation Gate;
	private:
		bool Enter=false;    //�O�_�b�����W �w�]���_
		int x, y;							// ���W���y��
		int mapNum;				//�O�������ǰe��X���a��
		int map;				//�{�b�Ҧb�a��
		Door* NextDoor;
	};


}