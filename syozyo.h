#include "DxLib.h"

extern void Car1(int);
extern void Car2(int);
extern void Car3(int);
extern void Car4(int);
extern void Load();
//extern void Car_select();
extern void DrawGameSelect();
extern void Draw();
extern void init();
extern int Random();

#ifndef _SYOZYO_H_
#define _SYOZYO_H_

//main
typedef struct {
	float x;
	int y;
	int image;
}Cars;
extern Cars car[4];
extern int entry_flag[4];
extern int chara_select[4];

//cars
extern int Input[4];
extern int EdgeInput[4];
extern int car1key, car2key[8], car3key;
extern float px, pv;
extern int White;



//Load
extern int soitsu;

//Draw
extern int box;



#endif