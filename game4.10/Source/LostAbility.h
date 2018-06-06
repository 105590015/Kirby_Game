#pragma once
#include "Map.h"

namespace game_framework {
	class LostAbility
	{
	public:
		LostAbility();
		int  type;                                          // ����
		int  GetX();                                        
		int  GetY();
		bool IsAlive();
		void SetAlive(bool flag);
		void Initialize(int t, int sx, int sy);             // ��l��
		void LoadBitmap();                                  // ���J�ϧ�
		void OnMove(Map *m, int kx, int ky, bool isSuck);   // ����
		void OnShow(Map *m);                                // �N�ϧζK��e��
	protected:
		int x, y;
		int direction;   // �üu����V
		int time;        // ��ܮɶ�
		bool isAlive;
		CAnimation star;
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
			lostAbility             // 17
		};
	};
}