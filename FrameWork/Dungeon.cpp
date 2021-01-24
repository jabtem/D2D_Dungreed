#include "Include.h"
Dungeon dungeon;
Dungeon::Dungeon()
{
	tile = new TileNum(100, 10);
	SetRect(&RoomZero_World, 0, 0, 1408, 768);//����0������ �����
	SetRect(&RoomOne_World, 0, 0, 1600, 768);
	SetRect(&RoomTwo_World, 0, 0, 1600, 768);
	roominfo = new RoomData;
	cameraX = 0;
	cameraY = 0;
	curRoomNum = 0;//���� �������� 0���̱⶧��
	col = false;
	isDungeonBGMON = false;
}
//������ ������ �̵��� ��� �Ų������Ұ��ΰ�? (���� �߿����)
//�׽�Ʈ��� ���� ������1�� ����βٹ̱�
//������ �����ٹ̱�
//������1�� �ϼ��� �����ϰ� ���� 2�������� �߰�(AI�� �ϴ� �ִ��� �����ϰ�)
Dungeon::~Dungeon()
{
	delete tile;
	delete roominfo;
}
void Dungeon::init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/Map/tileAtlas3.png");//��ĭ�� 64,64 �ȼ����߶� Ÿ�ϸ����λ��
	DungeonAtlas.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Dungeon::Update()
{
	if (!isDungeonBGMON)
	{
		int DBGM = sound.Get_BGM(DUNGEONBGM);//BGM���Ϻҷ���
		//sound.BGReset();
		//sound.BGPlay(DBGM);
		sound.BGMChange(DBGM);
		isDungeonBGMON = true;
	}

	cameraX = camera.Get_CameraX();
	cameraY = camera.Get_CameraY();

	//�����溰�� ī�޶���
	if(curRoomNum == 0)
		camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomZero_World);
	else if(curRoomNum == 1)
	{
		camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomOne_World);
	}
	else if(curRoomNum == 2)
	{
		camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomTwo_World);
	}

	//���̵� ����
	//��Ʈ�� �����뿡 ���������ְ� �������� �浹�� �Ͼ�� ��������� �浹���Ͼ���Ŀ����� ������� �̵����� ������ǥ�� ��Ե���������
	//�ٸ��� �̵������� �浹������ �ʱ�ȭ������������ �����濡�� ������ �浹�� �״�� �Ͼ���� �浹������ ���̵����� �ʱ�ȭ�ϵ��� ����
	int rectsize = sizeof(wall) / sizeof(RECT);//RECT �迭 ũ��
	for (int i = 0;i < rectsize;++i)
		collision.Coll_Character_Map(character.Get_ChRECT(), wall[i]);

	int rectsize2 = sizeof(moveZone) / sizeof(RECT);//RECT �迭 ũ��
	for (int i = 0;i < rectsize2;++i)
	{
		collision.Coll_Character_MoveZone(character.Get_ChRECT(), moveZone[i]);
	}


	//���̵�
	if (collision.Get_isRoomChange())
	{
		//�̵����� ��Ұ� ������ȣ������ ����
		switch (curRoomNum)
		{
		case 0:
			preRoomNum = curRoomNum;//���� ��ѹ��� ������ѹ��� ����
			curRoomNum = 1;
			character.Reset(128, 630);
			camera.Cam_Reset();//ī�޶� ��ǥ�ʱ�ȭ
			collision.Set_isRoomChange(false);
			resetRect();
			break;
		case 1:
			preRoomNum = curRoomNum;//���� ��ѹ��� ������ѹ��� ����
			//�浹������ left�� movezon0�ϰ�� ������ 1�̸� ������
			if (collision.Get_MoveZone().left == moveZone[0].left)
			{
				curRoomNum = 0;
				character.Reset(64*20, 630);

			}
			else if(collision.Get_MoveZone().left == moveZone[1].left)
			{
				curRoomNum = 2;
				character.Reset(128, 630);
			}
			camera.Cam_Reset();//ī�޶� ��ǥ�ʱ�ȭ
			collision.Set_isRoomChange(false);
			resetRect();
			break;
		}

	}

}

void Dungeon::Draw()
{
	switch (curRoomNum)
	{
	case 0:
		//0���� ����
		SetRect(&wall[0], 0, 630, 1408, 768);
		SetRect(&wall[1], 0, 0, 128, 768);
		SetRect(&wall[2], 1280, 0, 1408, 384);
		SetRect(&moveZone[0], 1344+32, 384, 1408, 640);//�̵�����
		DrawRoom(0);//���� 0���� �׸�
		break;
	case 1:
		//�ٴ�
		SetRect(&wall[0], 0, 630, 1600, 768);
		//�޺�
		SetRect(&wall[1], 0, 0, 128, 64*6);
		//õ��
		SetRect(&wall[2], 0, 0, 64 * 25, 64 * 2);
		//������
		SetRect(&wall[3], 64*23, 0, 64 * 25, 64 * 6);
		SetRect(&moveZone[0], 0, 64 * 6, 32, 640);//�̵�����
		SetRect(&moveZone[1], 64*24+32, 64 * 6, 64*25, 640);//�̵�����
		
		DrawRoom(1);//���� 1���� �׸�
		monster.Draw();
		break;
	case 2:
		//�ٴ�
		SetRect(&wall[0], 0, 630, 1600, 768);
		DrawRoom(2);//���� 1���� �׸�
		break;
	}
	//0���� �浹��

}

//������ ����
void Dungeon::DrawRoom(int roomNum)
{
	arrSize size = roominfo->Get_Size(roomNum);
	for (int row = 0; row < size.row;row++)
		for (int col = 0; col < size.col;col++)
			DrawTile(col, row, roominfo->Get_Room(row,col, roomNum));

}
//Ÿ�ϸ� �׸����Լ�
void Dungeon::DrawTile(float x, float y, int _tileInfo)
{
	DungeonAtlas.RenderDraw(x * TILE_SIZE- cameraX, y * TILE_SIZE- cameraY,
		tile->Get_itemX(_tileInfo) * TILE_SIZE, tile->Get_itemY(_tileInfo) * TILE_SIZE,
		(tile->Get_itemX(_tileInfo) + 1) * TILE_SIZE, (tile->Get_itemY(_tileInfo) + 1) * TILE_SIZE,
		0, 1, 1);
}

void Dungeon::resetRect()
{
	//���̵��� �浹���� �ʱ�ȭ
	int rectsize = sizeof(wall) / sizeof(RECT);//RECT �迭 ũ��
	RECT reset = { 0,0,0,0 };
	for (int i = 0;i < rectsize;++i)
		wall[i] = reset;

	//���̵��� �̵����� �ʱ�ȭ 
	int rectsize2 = sizeof(moveZone) / sizeof(RECT);//RECT �迭 ũ��
	for (int i = 0;i < rectsize2;++i)
		moveZone[i] = reset;
}