#include"syozyo.h"

void DrawGameSelect()
{
	DrawFormatString( 0, 20, White, "%d", GetJoypadNum() );
	DrawFormatString( 100, 20, White, "%d", entry_flag[0]);
	DrawFormatString( 120, 20, White, "%d", entry_flag[1]);
	if(entry_flag[0] == 1 || entry_flag[0] == 2) {
		DrawBox( 0, 30, 350, 250, GetColor(255, 0, 0), TRUE );
		DrawFormatString( 0, 30, White, "%d", chara_select[0] );
	}
	if(entry_flag[1] == 1 || entry_flag[1] == 2) {
		DrawBox( 450, 30, 750, 250, GetColor(0, 0, 255), TRUE );
		DrawFormatString( 450, 30, White, "%d", chara_select[1] );
	}
	if(entry_flag[2] == 1 || entry_flag[2] == 2) {
		DrawBox( 0, 30 + 250, 350, 550, GetColor(0, 255, 0), TRUE );
		DrawFormatString( 0, 30 + 250, White, "%d", chara_select[2] );
	}
	if(entry_flag[3] == 1 || entry_flag[3] == 2) {
		DrawBox( 450, 30 + 250, 750, 550, GetColor(255, 255, 0), TRUE );
		DrawFormatString( 450, 30 + 250, White, "%d", chara_select[3] );
	}

}

void DrawCar1()
{
	
	DrawBox(car[0].x, car[0].y, car[0].x+32-1, car[0].y+32-1, GetColor(255, 0, 0), TRUE);
	DrawLine(car[3].x + 32, car[3].y + 32 - 1, car[3].x + 32 + px, car[3].y + 32 - 1, GetColor( 255, 255, 255 ));
	DrawFormatString( 0, car[3].y, White, "%.1f", car[3].x );
	DrawFormatString( 48, car[3].y, White, "%.1f", px);
	DrawFormatString( 96, car[3].y, White, "%.0f", pv);
}


void DrawCar2()
{
	DrawBox(car[1].x, car[1].y, car[1].x+32-1, car[1].y+32-1, GetColor(255, 0, 0), TRUE);
}


void DrawCar3()
{
	DrawBox(car[2].x, car[2].y, car[2].x+32-1, car[2].y+32-1, GetColor(255, 0, 0), TRUE);
}

void DrawCar4()
{
	DrawBox(car[3].x, car[3].y, car[3].x+32-1, car[3].y+32-1, GetColor(255, 0, 0), TRUE);
}
