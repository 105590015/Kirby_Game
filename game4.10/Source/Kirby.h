#pragma once
#include "Map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �d�񪺩Ҧ����
	/////////////////////////////////////////////////////////////////////////////

	class Kirby
	{
	public:
		Kirby();
		int  GetX1();					// ���W�� x �y��
		int  GetY1();					// ���W�� y �y��
		int  GetX2();					// �k�U�� x �y��
		int  GetY2();					// �k�U�� y �y��
		void Initialize();				// �]�w����l��
		bool IsAlive();					// �O�_����
		bool IsFly();
		void LoadBitmap();				// ���J�ϧ�
		void OnMove(Map *m);					// ����
		void OnShow(Map *m);					// �N�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetSpace(bool flag);	    // �]�w�O�_���U�ť���
		void SetJump(bool flag);	    // �]�w�O�_���UX��
		void SetXY(int nx, int ny);		// �]�w���W�����y��
	protected:	
		CMovingBitmap originR, originL, ExhaleRight, ExhaleLeft, JumpRight, JumpLeft, DownRight, DownLeft;		//�d�񤣰�.�R��.���D.�ۤU����
		CAnimation GoLeft, GoRight, FlyRight, PrepareFlyRight, FlyLeft, PrepareFlyLeft;	// �d��.�k��.����.�w�ƭ��檺�ʵe
		int x, y;					// ���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isSpace;			    // �O�_���U�ť���
		bool isJump;			    // �O�_���UX��
		bool is_alive;				// �O�_����
		bool isFly;                 // �O�_�b��
		bool RightOrLeft;           // �P�_���k
	private:
		int flyDelay;               // ����e���l��ɶ�
		int JumpDelay;              // ���D���ɶ�
		int ExhaleDelay;            // �R�𪺮ɶ�
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};
}