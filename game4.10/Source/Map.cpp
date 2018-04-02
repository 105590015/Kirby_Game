#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include <fstream> 


namespace game_framework {
	Map::Map()
	{
	}

	void Map::SetMouse(int x, int y) {  //�]�w�ƹ��y��
		mx = x;
		my = y;
	}

	void Map::IsLclick(bool flag) {		//�]�w����O�_���U
		Lclick= flag;
	}

	void Map::IsRclick(bool flag) {		//�]�w�k��O�_���U
		Rclick= flag;
	}

	int Map::GetWidth() {				//���o�I���e��
		return background.Width();
	}

	int Map::GetHeight() {				//���o�I������
		return background.Height();
	}

	int  Map::ScreenX(int x)			//�^�ǤH���b�ù��W�y��	
	{
		return x-sx;
	}

	int  Map::ScreenY(int y)			//�P�W
	{
		return y-sy;
	}

	void Map::Initialize()
	{
		const int X_POS = 320;
		const int Y_POS = 240;
		sx = X_POS;
		sy = Y_POS;
	}

	void Map::LoadBitmap(int pic)
	{
		background.LoadBitmap(pic);
		ball.LoadBitmap(IDB_BALL, RGB(0, 0, 0));
	}

	void Map::OnMove(int x, int y)		//�a���H�H������
	{
		sx = x - SIZE_X / 2;			//���H���O���b�a�Ϥ���
		sy = y - SIZE_Y / 2;

		if (x <= SIZE_X / 2) {				//�]�w��H��������ɮɦa�ϲ��ʰ���
			sx = 0;
		}

		if (x >= background.Width() - SIZE_X / 2) {
			sx = background.Width() - SIZE_X;
		}

		if (y <= SIZE_Y / 2) {
			sy = 0;
		}

		if (y >= background.Height() - SIZE_Y / 2) {
			sy = background.Height() - SIZE_Y;
		}
	}

	void Map::OnShow()
	{
		

		background.SetTopLeft(-sx, -sy); // ���w��(i, j)�o�@�檺�y��
		background.ShowBitmap();

		ifstream file("map.txt");			//�N��Ʀs�J�}�C

		for (int i = 0; i<48; i++)
		{
			for (int j = 0; j < 64; j++) {
				file >> map[i][j];
			}			
		}
		file.close();

		ofstream output("map.txt");
		
		for (int i = 0; i < 48; i++) {
			for (int j = 0; j < 64; j++) {
				int x = j * 20 - sx; // ��X��(i, j)�o�@�檺 x �ù��y��
				int y = i * 20 - sy; // ��X��(i, j)�o�@�檺 y �ù��y��

				if (mx >= x && mx <= x + 20 && my >= y && my <= y + 20) { //�P�_�ƹ���m
					if (Lclick) {				//���䬰�]�߻�ê��
						map[i][j] = 1;
					}

					else if (Rclick) {			//�k�䬰������ê��
						map[i][j] = 0;
					}
				}

				output << map[i][j] << " ";		//�N���ܿ�X


				switch (map[i][j]) {
				case 1:
					ball.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					ball.ShowBitmap();
					break;

				}


			}
			output << endl;
			}
		
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) ���a�Ϫ��I�y��
	{
		int gx = x / 20; // �ഫ��X�b��y��(��ư��k)
		int gy = y / 20; // �ഫ��Y�b��y��(��ư��k)
		//map[x][y]����y���X�b����ơAx���Y�b
		return map[gy][gx] == 0; // ���] 0 �N��Ū�
	}
}