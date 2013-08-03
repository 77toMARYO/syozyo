#include "syozyo.h"
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int car1key, car2key[8], car3key, car4key;		//入力するキー
float px, pv;
int up_flag = 1, move_flag = 1;
int White = GetColor(255, 255, 255);


int Random( void )
{
	return rand() % 8 + 1;
}


void KeySwitch( int *count, int EdgeInput, int Key )
{
	switch(Key) {
			case 1:
				if( EdgeInput & PAD_INPUT_1 ) *count += 1;
				break;
			
			case 2:
				if( EdgeInput & PAD_INPUT_2 ) *count += 1;
				break;
			
			case 3:
				if( EdgeInput & PAD_INPUT_3 ) *count += 1;
				break;
			
			case 4:
				if( EdgeInput & PAD_INPUT_4 ) *count += 1;
				break;
			
			case 5:
				if( EdgeInput & PAD_INPUT_5 ) *count += 1;
				break;
			
			case 6:
				if( EdgeInput & PAD_INPUT_6 ) *count += 1;
				break;
			
			case 7:
				if( EdgeInput & PAD_INPUT_7 ) *count += 1;
				break;
			
			case 8:
				if( EdgeInput & PAD_INPUT_8 ) *count += 1;
				break;

		}
}

char *KeyReturn( int car2key )
{
	if(car2key == 1)
		return "△";
	if(car2key == 2)
		return "○";
	if(car2key == 3)
		return "×";
	if(car2key == 4)
		return "□";
	if(car2key == 5)
		return "L2";
	if(car2key == 6)
		return "R2";
	if(car2key == 7)
		return "L1";
	if(car2key == 8)
		return "R1";
}

// 「○」5回連打で進む
void Car1(int select)
{
	static int count = 0;
	if(count == 5) {
		car1key = Random();
		car[select].x += 10;
		count = 0;
	}
	DrawFormatString( 0, car[select].y, White, "%s", KeyReturn(car1key) ); 
	KeySwitch( &count, EdgeInput[select], car1key );
}





//8つのコマンドを押し終えると進む
void Car2(int select)
{

	static int count = 0;

	//8回入力し終えると初期化して進む
	if(count == 8) {
		for(int i = 0; i < 8; i++)  
			car2key[i] = Random();
		car[select].x += 50;
		count = 0;
	}

	for(int i = 0; i < 8; i++)
		DrawFormatString( i * 16, car[i].y, White, "%s", KeyReturn(car2key[i]) ); 
	DrawBox( 0, 340, count * 16, 340 + 16, White , TRUE );
	
	if(count < 8) {
		int _count = count;
		KeySwitch( &count, EdgeInput[select], car2key[count] );
		if(	count == _count && EdgeInput[select] != 0) {
			count = 0;
			for(int i = 0; i < 8; i++)  
				car2key[i] = Random();
		}
	}
}


//1つのコマンドを押すと進む
void Car3(int select) 
{
	int go_flag = 0;
	DrawFormatString( 0, car[select].y, White, "%s", KeyReturn(car3key) );
	KeySwitch( &go_flag, EdgeInput[select], car3key );
	if( go_flag ==  1) {
		car3key = Random();
		car[select].x += 5;
	}

}

void MoveLine()
{
	if(up_flag == 1) {
		px += 0.2;
		if(px >= 31 && px <= 50) px += 1.0;
		if(px >= 51) up_flag = 0;
	}
	if(up_flag == 0){
		px -= 1.0;	
		if(px <= 1) up_flag = 1;
	}
}

//任意の長さを進む
void Car4(int select)
{
	int go_flag = 0;
	static int wait_time = 0;
	static float goal_x;
	
	if(wait_time == 0 && move_flag == 1) KeySwitch( &go_flag, EdgeInput[select], 2 );
	if(wait_time > 0) wait_time -= 1;

	if( move_flag == 1) MoveLine();
	else {
		car[select].x += 0.2;
		if( goal_x < car[select].x ) {
			move_flag = 1;
			px = 0;
			wait_time = 120;
		}
	}
	if( go_flag == 1 ) {
		move_flag = 0;
		goal_x = car[select].x + px;
	}
}
