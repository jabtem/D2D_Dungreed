#pragma once
//입력한 배열숫자만큼 이차원배열생성
class TileNum
{
public:
	//TileNum();
	TileNum(int, int);
	~TileNum();
	void Reset();//초기화
	void SetData();//값세팅
	int Get_itemX(int);
	int Get_itemY(int);

private:
	POINT* arr;
	int length;
	int width;//넘버링할 이미지의 가로칸수
	int countX;
	int countY;


};
