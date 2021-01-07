#include "Include.h"
Dungeon dungeon;
Dungeon::Dungeon()
{
	tile = new TileNum(100, 10);
	SetRect(&RoomZero_World, 0, 0, 1408, 768);//����0������ �����
	roominfo = new RoomData;
	cameraX = 0;
	cameraY = 0;
}

Dungeon::~Dungeon()
{
	delete tile;
	delete roominfo;
}
void Dungeon::init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/Map/tileAtlas3.png");//��ĭ�� 64,64���ڸ����ִ�
	DungeonAtlas.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Dungeon::Update()
{
	cameraX = camera.Get_CameraX();
	cameraY = camera.Get_CameraY();
	//0�����������϶� 0������ �浹����
	camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomZero_World);


	int rectsize = sizeof(wall) / sizeof(RECT);//RECT �迭 ũ��
	for (int i = 0;i < rectsize;++i)
		collision.Coll_Character_Map(character.Get_ChRECT(), wall[i]);
}

void Dungeon::Draw()
{
	//�浹��
	SetRect(&wall[0], 0, 630, 1408, 768);
	SetRect(&wall[1], 0, 0, 128, 768);
	SetRect(&wall[2], 1280, 0, 1408, 384);
	DrawRoom0();
}

//Room0 ����
void Dungeon::DrawRoom0()
{
	arrSize size = roominfo->Get_Size(0);
	for (int row = 0; row < size.row;row++)
		for (int col = 0; col < size.col;col++)
			DrawTile(col, row, roominfo->Get_Room0(row,col));

}
//Ÿ�ϸ� �׸����Լ�
void Dungeon::DrawTile(float x, float y, int _tileInfo)
{
	DungeonAtlas.RenderDraw(x * TILE_SIZE- cameraX, y * TILE_SIZE- cameraY,
		tile->Get_itemX(_tileInfo) * TILE_SIZE, tile->Get_itemY(_tileInfo) * TILE_SIZE,
		(tile->Get_itemX(_tileInfo) + 1) * TILE_SIZE, (tile->Get_itemY(_tileInfo) + 1) * TILE_SIZE,
		0, 1, 1);
}