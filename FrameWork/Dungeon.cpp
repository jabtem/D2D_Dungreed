#include "Include.h"
Dungeon dungeon;
Dungeon::Dungeon()
{
	tile = new TileNum(100, 10);
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
	sprintf_s(FileName, "./resources/images/Map/tileAtlas3.png");//한칸에 64,64씩자를수있다
	DungeonAtlas.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Dungeon::Update()
{
	cameraX = camera.Get_CameraX();
	cameraY = camera.Get_CameraY();
}

void Dungeon::Draw()
{
	DrawRoom0();
}

//Room0 렌더
void Dungeon::DrawRoom0()
{
	arrSize size = roominfo->Get_Size(0);
	for (int row = 0; row < size.row;row++)
		for (int col = 0; col < size.col;col++)
			DrawTile(col, row, roominfo->Get_Room0(row,col));

}
//타일맵 그리는함수
void Dungeon::DrawTile(float x, float y, int _tileInfo)
{
	DungeonAtlas.RenderDraw(x * TILE_SIZE, y * TILE_SIZE,
		tile->Get_itemX(_tileInfo) * TILE_SIZE, tile->Get_itemY(_tileInfo) * TILE_SIZE,
		(tile->Get_itemX(_tileInfo) + 1) * TILE_SIZE, (tile->Get_itemY(_tileInfo) + 1) * TILE_SIZE,
		0, 1, 1);
}