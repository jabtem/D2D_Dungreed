#include "include.h"

Character character;
Character::Character()
{
	m_W = 0;//�ʱ�X��ǥ
	m_H = 1200;//�ʱ� Y��ǥ
	next_Idle = 0;
	next_Move = 0;
	state = Idle;
	direction = Right;
	curWeapon = Ssw;//�ʱ�⺻��� ���ҵ�μ���

	gravity = 10.0f;//������ �ƴҶ� ���ð������� �߷°�
	//ch_gravity = 9.8f;
	//����
	jumpPower = 70.0f;
	jumpTime = 0.0f;
	isJump = false;
	jumpUp = false;//������ �ö󰡰�������

	//�뽬
	dashTime = 0.0f;
	dashPower = 20.0f;
	isDash = false;

	isLeftMove = false;
	isRightMove = false;
	characterHide = false;
}
Character::~Character()
{
}

void Character::Init()
{
	posY = m_H;//������ y��ǥ
	char FileName[256];
	sprintf_s(FileName, "./resources/images/costumes/base/player_idle_X4.png");
	Ch_Idle.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/costumes/base/player_run_X4.png");
	Ch_Move.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/costumes/base/player_jump_X4.png");
	Ch_Jump.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Character::Update()
{
	cameraX = camera.Get_CameraX();//ī�޶��� X��
	cameraY = camera.Get_CameraY();//ī�޶��� Y��

	if (mouse.Get_isRclick())//��Ŭ���� ������ ���콺��������ǥ�޾ƿ�������
	{
		mouseP = mouse.Get_MousePoint();
		prePlayerX = PlayerX;
		prePlayerY = PlayerY;
		mouse.Set_isRclick(false);
		isDash = true;
		posY = m_H;//�뽬�� ĳ����y��ǥ(�������)
		posX = m_W;//�뽬�� ĳ����x��ǥ(�������)
	}

	//angle1 = weapon.Get_Angle1();//�����ʱ���
	//angle2 = weapon.Get_Angle2();//���ʱ���




	if (mouse.Get_MousePoint().x + cameraX < (Ch_Rect.left + CHARACTER_WIDTH * 0.5))//ĳ���� �߽���ġ�������� ���콺�����Ͱ� �����϶� 
		direction = Left;
	else if (mouse.Get_MousePoint().x + cameraX >= (Ch_Rect.left + CHARACTER_WIDTH * 0.5))//ĳ���� �߽���ġ�������� ���콺�����Ͱ� �������϶�
		direction = Right;

	if (KeyDown(VK_SPACE)&& !isJump&&!key.Get_isSDown())//�ϴ������� �����ϱ��� ���Ǽ���
	{
		isJump = true;
		
		posY = m_H;//������ ĳ����y��ǥ(�������)
	}
	if (isJump)
	{
		Jumping();
	}

	if (GetTickCount64() - curTime > 70)
	{

		next_Idle += 60;
		if (next_Idle - 300 >= 0)
		{
			next_Idle -= 300;
		}
		next_Move += 68;
		if (next_Move - 544 >= 0)
		{
			next_Move -= 544;
		}

		curTime = GetTickCount64();
	}
	//if(!collision.Get_TBCol())
	if(!isJump&&!isDash)
		m_H += gravity;

	if (isDash)//��Ŭ���� �뽬�ϵ��� ����
	{
		Dash();
	}
	PlayerX = m_W - cameraX;//ȭ�鿵�������� �÷��̾��� X��ǥ(��ũ����ǥ)
	PlayerY = m_H - cameraY;//ȭ�鿵�������� �÷��̾��� Y��ǥ(��ũ����ǥ)
}

void Character::Draw()
{
	if(collision.Get_TBCol())
		dv_font.DrawString("Rectcol :  True", 400, 0);
	else
		dv_font.DrawString("Rectcol :  False", 400, 0);

	if(collision.Get_Trigger())
		dv_font.DrawString("Trigger :  True", 400, 50);
	else
		dv_font.DrawString("Trigger :  False", 400, 50);

	if (collision.Get_LineCol())
		dv_font.DrawString("LineCol :  True", 400, 100);
	else
		dv_font.DrawString("LineCol :  False", 400, 100);

	if(camera.Get_Llimit())
		dv_font.DrawString("Left Limit :  True", 700, 0);
	else
		dv_font.DrawString("Left Limit :  False", 700, 0);

	if (camera.Get_Rlimit())
		dv_font.DrawString("Right Limit :  True", 700, 50);
	else
		dv_font.DrawString("Right Limit :  False", 700, 50);

	if (mouse.Get_Lclick())
		dv_font.DrawString("Lclick :  True", 700, 200);
	else
		dv_font.DrawString("Lclick  :  False", 700, 200);

	if (mouse.Get_isLclick())
		dv_font.DrawString("isLclick :  True", 700, 250);
	else
		dv_font.DrawString("isLclick  :  False", 700, 250);


	TCHAR sztext[100];
	sprintf_s(sztext, __TEXT("m_H : %d"), m_H);
	dv_font.DrawString(sztext, 500, 150);

	TCHAR sztext2[100];
	sprintf_s(sztext2, __TEXT("m_W : %d"), m_W);
	dv_font.DrawString(sztext2, 700, 150);

	TCHAR sztext3[100];
	sprintf_s(sztext3, __TEXT("camX : %d"), camera.Get_CameraX());
	dv_font.DrawString(sztext3, 900, 150);

	TCHAR sztext10[100];
	sprintf_s(sztext10, __TEXT("camY : %d"), camera.Get_CameraY());
	dv_font.DrawString(sztext10, 900, 200);


	TCHAR sztext11[100];
	sprintf_s(sztext11, __TEXT("nomx : %f"), nomx);
	dv_font.DrawString(sztext11, 1100, 100);

	TCHAR sztext12[100];
	sprintf_s(sztext12, __TEXT("nomy : %f"), nomy);
	dv_font.DrawString(sztext12, 1100, 200);




	if (Gmanager.m_GameStart == true) {
		//SetRect(&Ch_Rect, m_W - camera.Get_CameraX(), m_H, m_W - camera.Get_CameraX() + 60, m_H + 80);
		SetRect(&Ch_Rect, m_W , m_H-80, m_W  + 60, m_H);
		if (!characterHide)
		{
			switch (state)
			{
			case Idle:
				if (direction == Right) {
					Ch_Idle.RenderDraw(PlayerX, PlayerY - 80, next_Idle, 0, next_Idle + 60, 80, 0, 1.0, 1.0);
				}
				else if (direction == Left)
					Ch_Idle.RenderDraw(PlayerX + 60, PlayerY - 80, next_Idle, 0, next_Idle + 60, 80, 0, -1.0, 1.0);
				break;
			case Move:
				if (direction == Right) {
					Ch_Move.RenderDraw(PlayerX, PlayerY - 80, next_Move, 0, next_Move + 68, 80, 0, 1.0, 1.0);
				}
				else if (direction == Left)
					Ch_Move.RenderDraw(PlayerX + 68, PlayerY - 80, next_Move, 0, next_Move + 68, 80, 0, -1.0, 1.0);
				break;
			case Jump:
				if (direction == Right)
					Ch_Jump.Render(PlayerX, PlayerY - 80, 0, 1.0, 1.0);
				else if (direction == Left)
					Ch_Jump.Render(PlayerX + 68, PlayerY - 80, 0, -1.0, 1.0);

				break;
			};
		}
	}
}

void Character::Reset()
{
	characterHide = false;
	m_W = 0;
	m_H = 400;
}
void Character::Set_Sate(int _state)//ĳ���� ����
{
	state = _state;
}


void Character::Set_Direction(int _direction)//���� ����
{
	direction = _direction;
}

void Character::Jumping()
{
	if (jumpTime > 6)
		jumpUp = false;
	else {
		jumpUp = true;
		collision.Get_TBCol() = false;
	}
		
	int height = (jumpTime * jumpTime * (-gravity) / 2) + (jumpTime * jumpPower);

	m_H = posY - height;

	jumpTime += deltaTime.GetDeltaTime()*15;


	//if (jumpPower >= 80.0f)
	//{
	//	jumpPower = 80.0f;
	//}

	//if (height<0.0f&&collision.Get_TDCol())
	//{
	//	//m_H = posY;
	//	//state = Idle;
	//	Jump_Reset();
	//	state = Idle;
	//}

}

//���� ���������� ����
bool& Character::Get_IsJump()
{
	return isJump;
}
//������ �ö󰡰��ִ��� ���������ִ��� ����
bool& Character::Get_jumpUp()
{
	return jumpUp;
}
void Character::Jump_Reset()
{
	jumpTime = 0.0f;
	isJump = false;
	jumpPower = 70.0f;;
	state = Idle;

}
void Character::Set_Gravity(float _gravity)
{
	ch_gravity = _gravity;
}

double Character::Get_CameraY()
{
	return cameraY;
}

RECT Character::Get_ChRECT()
{
	return Ch_Rect;
}
int Character::Get_Direction()
{
	return direction;
}

bool Character::MoveStop()
{
	RECT cam = camera.Get_CameraRect();

	if (Ch_Rect.left <= cam.left &&isLeftMove)//ĳ���Ͱ� ī�޶� ���ʳ�������
		return true;
	else if (Ch_Rect.right >= cam.right&&isRightMove)//ĳ���Ͱ� ī�޶� �����ʳ��� ����
		return true;
	else
		return false;
}

int Character::Get_PlayerPosX()
{
	return m_W;
}

int Character::Get_PlayerPosY()
{
	return m_H;
}

void Character::Set_PlayerPosX(int x)
{
	m_W = x;
}

void Character::Set_PlayerPosY(int y)
{
	m_H = y;
}
int Character::Get_PlayerX()
{
	return PlayerX;
}
int Character::Get_PlayerY()
{
	return PlayerY;
}
//���⺯�汸�������� ���� �������(�̻����)
int Character::Get_Curweapon()
{
	return curWeapon;
}

//�����̵�
void Character::MoveLeft()
{
	
	isLeftMove = true;
	isRightMove = false;
	if(!MoveStop())
		m_W -= 5 * SPEED;
}

//�������̵�
void Character::MoveRight()
{

	isLeftMove = false;
	isRightMove = true;
	if (!MoveStop())
		m_W += 5 * SPEED;
}
void Character::Set_CharacterHide(bool _TF)
{
	characterHide = _TF;
}
bool Character::Get_CharacterHide()
{
	return characterHide;
}

void Character::Dash()
{
	D3DXVECTOR2 dir(mouseP.x - (prePlayerX + CHARACTER_WIDTH * 0.5), mouseP.y - (prePlayerY - CHARACTER_HEIGHT * 0.5));//�뽬�ҹ���
	D3DXVECTOR2 normalDir;
	D3DXVec2Normalize(&normalDir, &dir);

	nomx = normalDir.x;
	nomy = normalDir.y;

	int disX = mouseP.x - (prePlayerX + CHARACTER_WIDTH * 0.5);
	int disY = mouseP.y - (prePlayerY - CHARACTER_HEIGHT * 0.5);

	int width = normalDir.x * dashTime * dashTime * dashPower;
	int height = normalDir.y * dashTime * dashTime * dashPower;

	m_W = posX + width;
	m_H = posY + height;

	dashTime += deltaTime.GetDeltaTime()*25;
	if (dashTime > 5)
	{
		isDash = false;
		dashTime = 0;
	}
}