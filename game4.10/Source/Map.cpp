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

		ofstream output(Mapfile);

		for (int i = 0; i < mapSize_Y; i++) {
			for (int j = 0; j < mapSize_X; j++) {
				output << map[i][j] << " ";
			}
			output << endl;
		}

	}

	void Map::IsRclick(bool flag) {		//�]�w�k��O�_���U
		Rclick= flag;

		ofstream output(Mapfile);

		for (int i = 0; i < mapSize_Y; i++) {
			for (int j = 0; j < mapSize_X; j++) {
				output << map[i][j] << " ";
			}
			output << endl;
		}
	}

	int Map::GetWidth() {				//���o�I���e��
		return foreground.Width();
	}

	int Map::GetHeight() {				//���o�I������
		return foreground.Height();
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
		//const int X_POS = 320;
		//const int Y_POS = 240;
		//sx = X_POS;
		//sy = Y_POS;

		//ofstream set(Mapfile);			//�Ĥ@���إߦa�ϳ]�ߪ�l��
		//for (int i = 0; i < mapSize_Y; i++) {
		//	for (int j = 0; j < mapSize_X; j++) {
		//		set << 0 << " ";
		//	}
		//	set << endl;
		//}
		//set.close();

		ifstream file(Mapfile);			//�N��Ʀs�J�}�C
		for (int i = 0; i<mapSize_Y; i++)
		{
			for (int j = 0; j < mapSize_X; j++) {
				file >> map[i][j];
			}
		}
		file.close();
	}

	void Map::LoadBitmap(char* fore,COLORREF color,char* back,string file)
	{
		
		foreground.LoadBitmap(fore,color);
		background.LoadBitmap(back);
		Mapfile = file;
		mapSize_X = (foreground.Width() * 10 + 5) / 100;
		mapSize_Y = (foreground.Height() * 10 + 5) / 100;
		ball.LoadBitmap(".//RES//ball.bmp", RGB(0, 0, 0));
		ball_1.LoadBitmap(".//RES//ball_1.bmp", RGB(0, 0, 0));
		
	}
	
	void Map::OnMove(int x, int y)		//�a���H�H������
	{
		sx = x - SIZE_X / 2;			//���H���O���b�a�Ϥ���
		sy = y - SIZE_Y / 2;

		if (x <= SIZE_X / 2) {				//�]�w��H��������ɮɦa�ϲ��ʰ���
			sx = 0;
		}

		if (x >= foreground.Width() - SIZE_X / 2) {
			sx = foreground.Width() - SIZE_X;
		}

		if (y <= SIZE_Y / 2) {
			sy = 0;
		}

		if (y >= foreground.Height() - SIZE_Y / 2) {
			sy = foreground.Height() - SIZE_Y;
		}
	}

	void Map::OnShow()
	{
		background.SetTopLeft(0, 0);
		background.ShowBitmap();
		foreground.SetTopLeft(-sx, -sy); // ���w��(i, j)�o�@�檺�y��
		foreground.ShowBitmap();

		
		

		//for (int i = 0; i < mapSize_Y; i++) {
		//	for (int j = 0; j < mapSize_X; j++) {
		//		int x = j * 10 - sx; // ��X��(i, j)�o�@�檺 x �ù��y��
		//		int y = i * 10 - sy; // ��X��(i, j)�o�@�檺 y �ù��y��
		//		if (mx >= x && mx <= x + 20 && my >= y && my <= y + 20) { //�P�_�ƹ���m
		//			//if (Lclick) {				//���䬰�]�߻�ê��
		//			//	map[i][j] = 1;
		//			//}

		//			if (Lclick) {				//���䬰�]�߻�ê��
		//				map[i][j] = 2;
		//			}

		//			else if (Rclick) {			//�k�䬰������ê��
		//				map[i][j] = 0;
		//			}
		//		}
		//		switch (map[i][j]) {
		//			case 1:
		//				ball.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
		//				ball.ShowBitmap();
		//				break;
		//			case 2:
		//				ball_1.SetTopLeft(x, y);
		//				ball_1.ShowBitmap();
		//				break;
		//		}
		//	}
		//}
	}

	void Map::SetXY(int nx, int ny)
	{
		sx = nx;
		sy = ny;
	}

	bool Map::isEmpty(int x, int y) // (x, y) ���a�Ϫ��I�y��
	{
		int gx = x / 10; // �ഫ��X�b��y��(��ư��k)
		int gy = y / 10; // �ഫ��Y�b��y��(��ư��k)
		//map[x][y]����y���X�b����ơAx���Y�b
		return map[gy][gx] == 0; // ���] 0 �N��Ū�
	}

	bool Map::isEmpty_2(int x, int y) // (x, y) ���a�Ϫ��I�y��
	{
		int gx = x / 10; // �ഫ��X�b��y��(��ư��k)
		int gy = y / 10; // �ഫ��Y�b��y��(��ư��k)
		//map[x][y]����y���X�b����ơAx���Y�b
		return map[gy][gx] == 0 || map[gy][gx]==2; // ���] 0 �N��Ū�
	}
}