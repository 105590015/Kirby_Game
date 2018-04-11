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
		void Initialize(int ,int);		// �]�w����l��
		bool IsAlive();					// �O�_����
		bool IsFly();                   // �O�_�b��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove(Map *m);		    // ����
		void OnShow(Map *m);			// �N�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetSpace(bool flag);	    // �]�w�O�_���U�ť���
		void SetJump(bool flag);	    // �]�w�O�_���UX��
		void SetAttack(bool flag);	    // �]�w�O�_���UZ��
		void SetRun(bool);				//�]�w�O�_���UC
		void SetXY(int nx, int ny);		// �]�w���W�����y��
	protected:	
		CMovingBitmap originR, originL, ExhaleRight, ExhaleLeft, JumpRight, JumpLeft, DownRight, DownLeft, LandingRight, LandingLeft, downAttackR, downAttackL;
		CAnimation GoLeft, GoRight, FlyRight, PrepareFlyRight, FlyLeft, PrepareFlyLeft,RunLeft,RunRight;
		int x, y;					// ���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isSpace;			    // �O�_���U�ť���
		bool isJump;			    // �O�_���UX��
		bool isAttack;              // �O�_���UZ��
		bool isKick;                 // �O�_�ϥν���
		bool is_alive;				// �O�_����
		bool isFly;                 // �O�_�b��
		bool isRunning;				// �O�_�b�]
		bool RightOrLeft;           // �P�_���k
	private:
		int flyDelay;               // ����e���l��ɶ�
		int JumpDelay;              // ���D���ɶ�
		int ExhaleDelay;            // �R�𪺮ɶ�
		int KickDistance;           // �������Z��
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};
}