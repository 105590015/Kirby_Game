#pragma once
#include "Map.h"
#include "Kirby.h"
namespace game_framework {

	class Enemy
	{
	public:
		Enemy();
		int GetX1();                                  // ���W�� x �y��
		int GetY1();                                  // ���W�� y �y��
		void Hurted(Kirby* kirby);                    // �Q����
		void Sucked(Kirby* kirby);                    // �Q�l
		void SetAlive(bool flag);                     // �]�w����
		bool IsAlive();                               // �O�_����
		virtual int GetX2();                          // �k�U�� x �y��
		virtual int GetY2();                          // �k�U�� y �y��
		virtual void OnShow(Map *m, Kirby *kirby);    // ���
		virtual void OnMove(Map *m, Kirby* kirby);    // ����
		virtual void LoadBitmap();                    // Ū��
		virtual void Attack(Kirby* kirby);            // ����
	protected:
		int x, y, hp;				// ���W���y��.��q
		bool is_alive;				// �O�_����
		bool is_sucked;             // �O�_�Q�l
		bool RightOrLeft;           // �P�_���k
		bool Ishurted;              // ���˻P�_
		bool IsKing;                // �O���O��
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);   // �O�_�I��Ѽƽd�򪺯x��
		double ComputeDistance(int tx1, int ty1);                // �p��Z��
	private:
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