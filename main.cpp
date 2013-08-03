#include"syozyo.h"
#include<time.h>
#include<string.h>
#include<stdlib.h>
	
int EdgeInput[4], Input[4] = {0,};
int gamepad, entry_flag[4], chara_select[4];
static int game_select = 0;
Cars car[4];

//�����͂�1��Ԃ�
int Entry_Flag()
{
	for(int i = 0; i < GetJoypadNum(); i++) {
		if( entry_flag[i] != 2 ) {
			return 0;
		}
	}
	return 1;
}

//��蕨��I��
void Car_Select() {
	for(int i = 0; i < GetJoypadNum(); i++) {
		if(chara_select[i] == 0) Car1(i);
		if(chara_select[i] == 1) Car2(i);
		if(chara_select[i] == 2) Car3(i);
		if(chara_select[i] == 3) Car4(i);
	}
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						 LPSTR lpCmdLine, int nCmdShow )
{
	// 640*480�̃E�C���h�E���[�h�ɕύX
	ChangeWindowMode( TRUE ) ;
	SetGraphMode( 800, 600, 32 );
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		 return -1;		// �G���[���N�����璼���ɏI��
	}
	
	//�`����ʂ𗠂ɂ���
	SetDrawScreen( DX_SCREEN_BACK );

	int White = GetColor(255, 255, 255);

	SetTransColor(255, 255, 255);

	init();
	Load();

	// �L�[���������܂Ń��[�v
	while( ProcessMessage() == 0 && ScreenFlip() == 0)
	{
		//��ʂ�������
		ClearDrawScreen();
	
		if( CheckHitKey( KEY_INPUT_ESCAPE ) == 1) break;


		int PadInput[4] = {GetJoypadInputState( DX_INPUT_PAD1 ), GetJoypadInputState( DX_INPUT_PAD2 ),
					GetJoypadInputState( DX_INPUT_PAD3 ), GetJoypadInputState( DX_INPUT_PAD4 )};
		for(int i = 0; i < 4; i++) {
			EdgeInput[i] = PadInput[i] & ~Input[i];
			Input[i] = PadInput[i];
		}

		switch( game_select) {
			case 0:			//���Ȃ����
				if( EdgeInput[0] & PAD_INPUT_2 )
					game_select = 1;
				break;
			case 1:			//
				DrawGameSelect();
				for( int i = 0; i < 4; i++) {
					if( EdgeInput[i] & PAD_INPUT_2 )
						entry_flag[i] = 1;
					if( EdgeInput[i] & PAD_INPUT_RIGHT ) {
						chara_select[i]++;
						chara_select[i] %= 4;
					}
					if( EdgeInput[i] & PAD_INPUT_LEFT ) {
						chara_select[i]--;
						if( chara_select[i] == -1)
							chara_select[i] = 3;
					}
					if( EdgeInput[i] & PAD_INPUT_9 )	
						entry_flag[i] = 2;
				}
				if( Entry_Flag() == 1 )
					game_select = 2;
				break;
			case 2:
				Car_Select();
				Draw();
			break;
			case 3:
				game_select = 0;
				break;
		}

	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;
	return 0 ;	
}

