#include <graphics.h>
#include <time.h>
#include <Windows.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include "main.h"
using namespace std;
#define PI acos(-1)
#define WIDTH 1800
#define HEIGHT 900

#define BLOCK_XY 30		//С����߳�
#define BLOCK_JJ 2		//С����֮��ļ��
COLORREF SNACK_COLOR_MAX = COLORREF RGB(255, 0,  0);		//��ͷ��ɫ
COLORREF SNACK_COLOR_MIN = COLORREF RGB(50, 50, 200);		//��β��ɫ
COLORREF BK_COLOR = COLORREF RGB(100, 100, 100);			//��ϷΧǽ��ɫ
float SNACK_XY_MAX = 0;			//�����ֵ
float SNACK_XY_MIN = 10;		//����ϸֵ
int GAMETIME = 250;				//��Ϸ�ٶ�
int LIZITIME = 0;				//���������ٶ�
#define LIZINUM 100				//��������
int CAMERA_X = 0;				//���x����,0Ϊ��Ļ�м�
int CAMERA_Y = 0;				//���y����,0Ϊ��Ļ�м�
#define SHAKE 120				//����Ч����֡��
int WINDOW_SHAKE = 0;			//��¼�����˶��ٴ�

const int BLOCK_WIDTH = WIDTH / (BLOCK_XY + BLOCK_JJ);	 //С����x������
const int BLOCK_HEIGHT = HEIGHT / (BLOCK_XY + BLOCK_JJ); //С����y������

const int PYI_X = WIDTH - BLOCK_WIDTH * (BLOCK_XY + BLOCK_JJ);  //x���ϵ�ƫ��������Ϊ�ֱ��ʺͷ��񾭳���������
const int PYI_Y = HEIGHT - BLOCK_HEIGHT * (BLOCK_XY + BLOCK_JJ);//y���ϵ�ƫ��������Ϊ�ֱ��ʺͷ��񾭳���������
const float G = 0.002f;			//����
const float MC = 0.999f;		//Ħ����
float jd = 0;
DWORD t1, t2;
DWORD t3, t4;

struct snack {
	int dx = 1, dy = 0;  //����
	int snack_map[BLOCK_WIDTH * BLOCK_HEIGHT] = { 2,1,0 };  //��ʼ��������,�����һ����ͷ��
	int snack_len = 3;   //�ߵĳ���
}Snack;

struct lizi{
	float x = 0, y = 0;    //����λ��
	int sjx[6] = { -BLOCK_XY / 4, -BLOCK_XY / 4, BLOCK_XY / 4, -BLOCK_XY / 4, -BLOCK_XY / 4, BLOCK_XY  / 4};
	float dx, dy;  //�����ٶ�
	float jd = 0;  //���ӽǶ�
	float djd = 0; //������ת�Ľ��ٶ�

	int life = 100; //����
	int d_life = 0; //��ǰ����

	COLORREF RGB;//������ɫ
}Lizi[LIZINUM];

void initlizi(int x, int y) {   //x,yΪҪ��ʾ��λ��
	for (int i = 0; i < LIZINUM; i++) {
		Lizi[i].x = rand() % BLOCK_XY + x;
		Lizi[i].y = rand() % BLOCK_XY + y;
		//Lizi[i].dx = cos(double(i)) * (rand() % 10) * (float)Snack.dx;
		//Lizi[i].dy = sin(double(i)) * (rand() % 10) * (float)Snack.dy;     //��סҪ���㸡������ö�����  ".0f"  �ӼӼӼӼӼӼӼӼӼӣ�����������
		BYTE r = rand() % 255, g = rand() % 255, b = rand() % 255;
		Lizi[i].RGB = COLORREF RGB(r,g,b);
		Lizi[i].dx = (float)i / 4.0f * (rand() % 20 - 10) / 50.0f; //* (float)Snack.dx;
		Lizi[i].dy = (float)i / 4.0f * (rand() % 20 - 10) / 50.0f; //* (float)Snack.dy;
		
		Lizi[i].jd = rand() % 100 + 100;
		Lizi[i].djd = (rand() % 100 + 100) / 10000.0f;
	}
}

void drawlizi() {
	for (int i = 0; i < LIZINUM; i++) {
		setfillcolor(Lizi[i].RGB); setlinecolor(Lizi[i].RGB);
		Lizi[i].x += Lizi[i].dx;
		Lizi[i].y += Lizi[i].dy;

		Lizi[i].dx *= MC;
		Lizi[i].dy *= MC;
		Lizi[i].dy = Lizi[i].dy + G;

		Lizi[i].jd = Lizi[i].jd + Lizi[i].djd;
		jd = Lizi[i].jd;

		int ss[6] = {
		Lizi[i].sjx[0] * cos(jd) - Lizi[i].sjx[1] * sin(jd), Lizi[i].sjx[1] * cos(jd) + Lizi[i].sjx[0] * sin(jd),
		Lizi[i].sjx[2] * cos(jd) - Lizi[i].sjx[3] * sin(jd), Lizi[i].sjx[3] * cos(jd) + Lizi[i].sjx[2] * sin(jd),
		Lizi[i].sjx[4] * cos(jd) - Lizi[i].sjx[5] * sin(jd), Lizi[i].sjx[5] * cos(jd) + Lizi[i].sjx[4] * sin(jd),
		};

		int s[6] = {
			ss[0] + Lizi[i].x + CAMERA_X, ss[1] + Lizi[i].y + CAMERA_Y,
			ss[2] + Lizi[i].x + CAMERA_X, ss[3] + Lizi[i].y + CAMERA_Y,
			ss[4] + Lizi[i].x + CAMERA_X, ss[5] + Lizi[i].y + CAMERA_Y
		};
		fillpolygon((POINT*)s, 3);
	
	}



}

struct food {
	int food_x, food_y;   //ʳ������
	int z = -30;		  //ʳ��֡������ʼ
	int jz = 20;		  //ʳ��֡��������
	int zmp = -30;		  //ʳ�ﵱǰ֡
	int p = 0;			  //֡�����Ƿ����
}Food;

int maptox(int map) {     //map����תx����
	return (map % BLOCK_WIDTH);
}
int maptoy(int map) {     //map����תy����
	return (map / BLOCK_WIDTH);
}
int xytomap(int x, int y) { //xy����תmap
	return (y * BLOCK_WIDTH + x);
}
void gamewindowshake() {
	if (WINDOW_SHAKE < SHAKE) {
		int x = rand() % 30 - 15;
		int y = rand() % 30 - 15;
		CAMERA_X = x;
		CAMERA_Y = y;
		WINDOW_SHAKE++;
	}
	else {
		CAMERA_X = 0;
		CAMERA_Y = 0;
	}
}
void gamedrawpixal(int x, int y, COLORREF COLOR, float xy) {
	int py_x = PYI_X / 2;
	int py_y = PYI_Y / 2;
	float xy2 = xy / 2;
	setfillcolor(COLOR); setlinecolor(COLOR);
	fillrectangle(x * BLOCK_XY + x * BLOCK_JJ + xy2 + py_x + CAMERA_X, y * BLOCK_XY + y * BLOCK_JJ + xy2 + py_y + CAMERA_Y,
		BLOCK_XY + x * BLOCK_XY + x * BLOCK_JJ - xy2 + py_x + CAMERA_X, BLOCK_XY + y * BLOCK_XY + y * BLOCK_JJ - xy2 + py_y + CAMERA_Y);
};
void drawsnack() {
	int rp = (GetRValue(SNACK_COLOR_MAX) - GetRValue(SNACK_COLOR_MIN)) / (Snack.snack_len - 1);
	int gp = (GetGValue(SNACK_COLOR_MAX) - GetGValue(SNACK_COLOR_MIN)) / (Snack.snack_len - 1);
	int bp = (GetBValue(SNACK_COLOR_MAX) - GetBValue(SNACK_COLOR_MIN)) / (Snack.snack_len - 1);

	float pp = (SNACK_XY_MAX - SNACK_XY_MIN) / (Snack.snack_len - 1);

	gamedrawpixal(maptox(Snack.snack_map[0]), maptoy(Snack.snack_map[0]),
		SNACK_COLOR_MAX, SNACK_XY_MAX);

	for (int i = 1; i < Snack.snack_len - 1; i++){
		gamedrawpixal(maptox(Snack.snack_map[i]),maptoy(Snack.snack_map[i]),
			COLORREF RGB(GetRValue(SNACK_COLOR_MAX) - (rp * i), GetGValue(SNACK_COLOR_MAX) - (gp * i), GetBValue(SNACK_COLOR_MAX) - (bp * i)), SNACK_XY_MAX - (pp * i));
	}

	gamedrawpixal(maptox(Snack.snack_map[Snack.snack_len - 1]), maptoy(Snack.snack_map[Snack.snack_len - 1]),
		SNACK_COLOR_MIN, SNACK_XY_MIN);
}
void foodinit() {
LOOP:
	Food.food_x = rand() % BLOCK_WIDTH;
	Food.food_y = rand() % BLOCK_HEIGHT;
	for (int i = 0; i < Snack.snack_len; i++){
		if ((maptox(Snack.snack_map[i]) == Food.food_x) && (maptoy(Snack.snack_map[i]) == Food.food_y))
			goto LOOP;
	}
	Food.p = 0;

}
void gameinit() {
	Snack.dx = 1;
	Snack.dy = 0;
	Snack.snack_map[0] = 2;
	Snack.snack_map[1] = 1;
	Snack.snack_map[2] = 0;
	Snack.snack_len = 3;
}
void gameover() {
	settextcolor(WHITE);
	settextstyle(90,50, _T("Consolas"));
	RECT r = { 0, 0, WIDTH ,HEIGHT };
	while (1) {
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 13) {
				gameinit();
				foodinit();
				break;
			}
		}
		cleardevice();
		drawbk();
		drawfood();
		drawsnack();
		gamewindowshake();
		WINDOW_SHAKE = 0;
		drawtext(_T("Game Over!!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		FlushBatchDraw();
	}
}
void drawfood() {
	if (!Food.p) {
		if (Food.zmp > Food.jz) {
			Food.zmp = Food.z;
			Food.p = !Food.p;
		}
		float p = (Food.zmp * Food.zmp) / 10 - 100;
		gamedrawpixal(Food.food_x, Food.food_y, COLORREF RGB(255, 255, 255), p);
		//Sleep(100);
		Food.zmp++;
	}else{
		gamedrawpixal(Food.food_x, Food.food_y, COLORREF RGB(255, 255, 255), 0);
	}
}
void drawbk() {
	setfillcolor(BK_COLOR); setlinecolor(BK_COLOR);
	fillrectangle(0 + CAMERA_X, 0 + CAMERA_Y, PYI_X / 2 + CAMERA_X, HEIGHT + CAMERA_Y);
	fillrectangle((WIDTH - PYI_X / 2) + CAMERA_X, 0 + CAMERA_Y, WIDTH + CAMERA_X, HEIGHT + CAMERA_Y);
	fillrectangle(0 + CAMERA_X, 0 + CAMERA_Y, WIDTH + CAMERA_X, PYI_Y / 2 + CAMERA_Y);
	fillrectangle(0 + CAMERA_X, HEIGHT + CAMERA_Y, WIDTH + CAMERA_X, (HEIGHT - PYI_Y / 2) + CAMERA_Y);
}
void gamepause() {
	settextcolor(WHITE);
	settextstyle(90, 50, _T("Consolas"));
	RECT r = { 0, 0, WIDTH ,HEIGHT };
	drawtext(_T("Pause!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	FlushBatchDraw();			//�������������Ļ
	while (1) {
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 32) {
				break;
			}
		}
		FlushBatchDraw();			//�������������Ļ
	}
}
void gameupdata() {
	char ch;
	if (_kbhit()) {
		ch = _getch();   //up 119  down 115  left 97  right 100  \n 13  " " 32  e 101
		//printf("%d\n",ch);
		switch (ch){
		case 119:
			if (!(Snack.dx == 0 && Snack.dy == 1)) {
				Snack.dx = 0;
				Snack.dy = -1;
			}
			break;
		case 115:
			if (!(Snack.dx == 0 && Snack.dy == -1)) {
				Snack.dx = 0;
				Snack.dy = 1;
			}
			break;
		case 97:
			if (!(Snack.dx == 1 && Snack.dy == 0)) {
				Snack.dx = -1;
				Snack.dy = 0;
			}
			break;
		case 100:
			if (!(Snack.dx == -1 && Snack.dy == 0)) {
				Snack.dx = 1;
				Snack.dy = 0;
			}
			break;
		case 32:
			gamepause(); //��Ϸ��ͣ
			break;
		case 13:
			jiasu();
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < Snack.snack_len; i++) {
		Snack.snack_map[Snack.snack_len - i] = Snack.snack_map[Snack.snack_len - i - 1];
	}
	//ǽ����ײ���
	if (maptox(Snack.snack_map[1]) + Snack.dx >= BLOCK_WIDTH || maptox(Snack.snack_map[1]) + Snack.dx < 0) {
		gameover();
	}
	if (maptoy(Snack.snack_map[1]) + Snack.dy >= BLOCK_HEIGHT || maptoy(Snack.snack_map[1]) + Snack.dy < 0) {
		gameover();
	}
	Snack.snack_map[0] = xytomap(maptox(Snack.snack_map[1]) + Snack.dx, maptoy(Snack.snack_map[1]) + Snack.dy);
	//ʳ����ײ���
	if (maptox(Snack.snack_map[0]) == Food.food_x && maptoy(Snack.snack_map[0]) == Food.food_y) {
		WINDOW_SHAKE = 0;
		initlizi(Food.food_x * (BLOCK_XY + BLOCK_JJ), Food.food_y * (BLOCK_XY + BLOCK_JJ));
		foodinit();
		Snack.snack_len++;
	}
	//������ײ���
	for (int i = 1; i < Snack.snack_len + 1; i++){
		if (maptox(Snack.snack_map[0]) == maptox(Snack.snack_map[i])
			&& maptoy(Snack.snack_map[0]) == maptoy(Snack.snack_map[i])) {
			gameover();
		}
	}

}
void jiasu() {
	int snack_xy = Snack.snack_map[0]; //�Ȱѵ�ǰ����λ�ô��
	bool food = 0;
	int from = 0; //��ʾʳ�ﵽ�ߵľ���

	while (!((maptox(Snack.snack_map[0]) + Snack.dx >= BLOCK_WIDTH || maptox(Snack.snack_map[0]) + Snack.dx < 0) ||
		   (maptoy(Snack.snack_map[0]) + Snack.dy >= BLOCK_HEIGHT || maptoy(Snack.snack_map[0]) + Snack.dy < 0))
		   )
	{   //ֻҪ��ײ��ǽ��һֱѭ��

		//�����һ����ʳ��
		if (maptox(Snack.snack_map[0]) + Snack.dx == Food.food_x && maptoy(Snack.snack_map[0]) + Snack.dy == Food.food_y) {
			food = 1;   //��food��1��ʾ̽�⵽ʳ��
			break;
		}
		//��ͷǰ��
		Snack.snack_map[0] = xytomap(maptox(Snack.snack_map[0]) + Snack.dx, maptoy(Snack.snack_map[0]) + Snack.dy);
		from++;
	}

	if (food) {  //���̽�⵽ʳ��Ͱ�������ǰ��
		Snack.snack_map[0] = snack_xy;
		for (int i = 0; i < from - 1; i++){
			cleardevice();
			drawlizi();
			drawfood();			//��ʳ��
			gameupdata();
			drawsnack();		//����
			drawbk();			//��ǽ��
			FlushBatchDraw();			//�������������Ļ
			Sleep(3);
		}

	}else {  //���û��̽�⵽ʳ�������ͷ�ع�
		Snack.snack_map[0] = snack_xy;
	}
}

int main() {
	
	srand((unsigned)time(NULL));	//���������
	initgraph(WIDTH, HEIGHT);		//������ͼ����
	BeginBatchDraw();				//��ʼ������ͼ
	t1 = t2 = GetTickCount();		//��ȡ���Կ���ʱ��
	foodinit();
	t3 = t4 = GetTickCount();
	
	while (1) {
		cleardevice();


		drawlizi();
		drawfood();			//��ʳ��
		drawsnack();		//����
		gamewindowshake();  //��Ļ����
		
		if (t2 - t1 > GAMETIME) {		//ʹ��Ϸ�Ƕ�����ʱ
			gameupdata();
			t1 = t2;	
		}
		
		drawbk();			//��ǽ��
		FlushBatchDraw();			//�������������Ļ
		t2 = GetTickCount();
	}
}