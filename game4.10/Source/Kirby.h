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
		bool IsKick();                  // �O�_����
		bool IsSuck();                  // �O�_�l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove(Map *m);		    // ����
		void OnShow(Map *m);			// �N�ϧζK��e��
		void Hurted();                  // ����
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetSpace(bool flag);	    // �]�w�O�_���U�ť���
		void SetJump(bool flag);	    // �]�w�O�_���UX��
		void SetAttack(bool flag);	    // �]�w�O�_���UZ��
		void SetSuck(bool flag);	    // �]�w�O�_�l��
		void SetRun(bool);				// �]�w�O�_���UC
		void SetXY(int nx, int ny);		// �]�w���W�����y��
	protected:	
		CMovingBitmap originR, originL, ExhaleRight, ExhaleLeft, JumpRight, JumpLeft, DownRight, DownLeft, LandingRight, LandingLeft, downAttackR, downAttackL;
		CAnimation GoLeft, GoRight, FlyRight, PrepareFlyRight, FlyLeft, PrepareFlyLeft, hurtedL, hurtedR, RunLeft, RunRight, suckRight, suckLeft;
		int x, y;					// ���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isSpace;			    // �O�_���U�ť���
		bool isJump;			    // �O�_���UX��
		bool isAttack;              // �O�_���UZ��
		bool isKick;                // �O�_�ϥν���
		bool isSuck;                // �O�_�ϥΧl��
		bool isHurted;              // �O�_�Q����
		bool is_alive;				// �O�_����
		bool isFly;                 // �O�_�b��
		bool isRunning;				// �O�_�b�]
		bool RightOrLeft;           // �P�_���k
	private:
		int ExhaleDelay;            // �R�𪺮ɶ�
		int JumpDistance;           // ���D���Z��
		int KickDistance;           // �������Z��
		int hp;
	};
}