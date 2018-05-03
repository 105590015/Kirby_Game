#pragma once
#include "Map.h"
#include "Gas.h"
#include "Start.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �d�񪺩Ҧ����
	/////////////////////////////////////////////////////////////////////////////

	class Kirby
	{
	public:
		Kirby();
		int  GetX1();					  // ���W�� x �y��
		int  GetY1();				  	  // ���W�� y �y��
		int  GetX2();			          // �k�U�� x �y��
		int  GetY2();			          // �k�U�� y �y��
		void Initialize(int ,int);		  // �]�w����l��
		bool IsAlive();					  // �O�_����
		bool IsFly();                     // �O�_�b��
		bool IsKick();                    // �O�_����
		bool IsSuck();                    // �O�_�l��
		void LoadBitmap();				  // ���J�ϧ�
		void OnMove(Map *m);		      // ����
		void OnShow(Map *m);			  // �N�ϧζK��e��
		void Hurted();                    // ����
		void Die(Map *m);			      // ���h
		void SetMovingDown(bool flag);    // �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	  // �]�w�O�_���b��������
		void SetMovingRight(bool flag);   // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	  // �]�w�O�_���b���W����
		void SetSpace(bool flag);	      // �]�w�O�_���U�ť���
		void SetJump(bool flag);	      // �]�w�O�_���UX��
		void SetAttack(bool flag);	      // �]�w�O�_���UZ��
		void SetSuck(bool flag);	      // �]�w�O�_�l��
		void SetBig(bool flag);		      // �]�w�O�_�t���J
		void SetRun(bool);				  // �]�w�O�_���UC
		void SetXY(int nx, int ny);		  // �]�w���W�����y��
	protected:	
		// ���q�d��
		CMovingBitmap originR, originL, exhaleR, exhaleL, jumpR, jumpL, downR, downL, landingR, landingL, downAttackR, downAttackL, GG;
		CAnimation goL, goR, flyR, prepareFlyR, flyL, prepareFlyL, hurtedL, hurtedR, runL, runR, suckR, suckL;
		// �t�F��d��
		CMovingBitmap bigOriginR, bigOriginL, bigJumpR, bigJumpL, bigLandingR, bigLandingL, threwR, threwL;
		CAnimation bigGoL, bigGoR, swallowR, swallowL;
		CMovingBitmap blood6, blood5, blood4, blood3, blood2, blood1, blood0;
		// �p�q�d��
		CMovingBitmap Spark_exhaleR, Spark_exhaleL, Spark_downR, Spark_downL, Spark_landingR, Spark_landingL;
		CAnimation Spark_originR, Spark_originL, Spark_goR, Spark_goL, Spark_jumpR, Spark_jumpL, Spark_downAttackR, Spark_downAttackL, Spark_flyR, Spark_prepareFlyR, Spark_flyL, Spark_prepareFlyL, Spark_runR, Spark_runL;

		Gas gas;
		Start start;
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
		bool isAlive;				// �O�_����
		bool isFly;                 // �O�_�b��
		bool isRunning;				// �O�_�b�]
		bool isBig;                 // �O�_�t���J
		bool isSwallow;             // �O�_�b�]��
		bool rightOrLeft;           // �P�_���k
	private:
		int exhaleDelay;            // �R�𪺮ɶ�
		int jumpDistance;           // ���D���Z��
		int kickDistance;           // �������Z��
		int gasDistance;            // ���魸��Z��
		int startDistance;          // �P�P����Z��
		bool bulletDirection;       // �R�X�����V
		bool isInvincible;          // �O�_�L��
		int InvincibleTime;         // �L�Įɶ�
		void Attack(Map *m);        // ����
		int hp;
	};
}