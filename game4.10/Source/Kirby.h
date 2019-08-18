#pragma once
#include "Map.h"
#include "Gas.h"
#include "Star.h"
#include "LostAbility.h"
#include "KirbyType.h"
#include "Kirby_normal.h"
#include "Kirby_spark.h"
#include "Kirby_fire.h"
#include "Kirby_somethingInMouth.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �d�񪺩Ҧ����
	/////////////////////////////////////////////////////////////////////////////
	class Kirby
	{
	public:
		Kirby();
		~Kirby();
		int  GetX1();					  // ���W�� x �y��
		int  GetY1();				  	  // ���W�� y �y��
		int  GetX2();			          // �k�U�� x �y��
		int  GetY2();			          // �k�U�� y �y��
		int  GetType();                   // ���o��e���A
		int  GetHeight();                 // ���o����
		int  GetWidth();                  // ���o�e��
		void Initialize(int ,int);		  // �]�w����l��
		bool IsAlive();					  // �O�_����
		bool IsFly();                     // �O�_�b��
		bool IsKick();                    // �O�_����
		bool IsSuck();                    // �O�_�l��
		bool IsAttack();                  // �O�_��Z��
		bool IsRight();                   // �����V
		bool IsDown();                    // �O�_�Y�p
		bool IsBig();                     // �O�_�O�j����
		bool IsMove();                    // �O�_�b����
		void LoadBitmap();				  // ���J�ϧ�
		void OnMove(Map *m);		      // ����
		void OnShow(Map *m);			  // �N�ϧζK��e��
		void Hurted(Map *m);              // ����
		void Die(Map *m);			      // ���h
		void SetMovingDown(bool flag);    // �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	  // �]�w�O�_���b��������
		void SetMovingRight(bool flag);   // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	  // �]�w�O�_���b���W����
		void SetJump(bool flag);	      // �]�w�O�_���UX��
		void SetAttack(bool flag);	      // �]�w�O�_���UZ��
		void SetSuck(bool flag);	      // �]�w�O�_�l��
		void SetBig(bool flag);		      // �]�w�O�_�t���J
		void SetRun(bool);				  // �]�w�O�_���UC
		void SetXY(int nx, int ny);		  // �]�w���W�����y��
		void SetEat(int t);		          // �]�w�Y�F����Ǫ�
		void Restore();                   // �K��:��^�캡
		Bullet* GetBullet();
		void DeleteBullet();
	protected:	
		CMovingBitmap blood6, blood5, blood4, blood3, blood2, blood1, blood0;
		CMovingBitmap GG;

		Bullet* bullet;
		LostAbility lost;
		int x, y;					// ���W���y��
		int flyCount;               // ����Ϥ���ܭp��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isExhale;			    // �O�_�R��
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
		bool isLanding;             // �O�_������
		bool rightOrLeft;           // �P�_���k
	private:
		void ShowKirby(Map *m);     // ��ܴ��q�d��
		int exhaleDelay;            // �R�𪺮ɶ�
		int jumpDistance;           // ���D���Z��
		int kickDistance;           // �������Z��
		int bulletDistance;			// �R�X���魸��Z��
		bool bulletDirection;       // �R�X�����V
		bool isInvincible;          // �O�_�L��
		int InvincibleTime;         // �L�Įɶ�
		void Attack(Map *m);        // ���q�d�����
		void Transform();           // �ܨ�
		int hp;                     // ��q
		int type;                   // ���A
		int eat;                    // �Y�F����
		int velocity;               // ���O�[�t��
		int count;                  // �p�ƬO�_�@��
		int height;                 // �O����U������
		int width;                  // �O����U���e��

		Kirby_normal* kirby_normal;
		Kirby_fire* kirby_fire;
		Kirby_spark* kirby_spark;
		Kirby_somethingInMouth* kirby_somethingInMouth;
		KirbyType* kirbyType;

		enum COPY_AUDIO_ID {		// �w�q�U�ح��Ī��s��
			AUDIO_BACKGROUND,       // 0
			jump,                   // 1
			landing,                // 2
			kick,                   // 3
			die,                    // 4
			fly,                    // 5
			hurted,                 // 6
			run,                    // 7
			suck,                   // 8
			gasSound,               // 9
			starSound,              // 10
			swallow,                // 11
			spark,                  // 12
			fire,                   // 13
			stone,                  // 14
			start,                  // 15
			enemyDie,               // 16
			lostAbility,            // 17
			ending                  // 18
		};
	};
}