#include "syozyo.h"
#include<time.h>
void init()
{
	entry_flag[0] = entry_flag[1] = entry_flag[2] = entry_flag[3] = 0;
	chara_select[0] = chara_select[1] = chara_select[2]	= chara_select[3] = 0;
	srand((unsigned int)time(NULL));
	car[0].x = car[1].x = car[2].x = car[3].x = 150;
	car[0].y = 120;
	car[1].y = 240;
	car[2].y = 360;
	car[3].y = 480;

	px = 10;

	car1key = Random();
	for(int i = 0; i < 8; i++)
		car2key[i] = Random();
	car3key = Random();
}


