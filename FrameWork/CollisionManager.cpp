#include "Include.h"

Collision collision;

Collision::Collision()
{
	isTBCol = false;
	isLRCol = false;
	trigger = false;
	triggercnt = 0;
}
Collision::~Collision()
{

}
void Collision::Coll_Character_Map(RECT p, RECT m)
{
	int PlayerY = character.Get_PlayerPosY();
	int PlayerX = character.Get_PlayerPosX();
	RECT p2;
	SetRect(&p2, p.left + 1, p.top + 1, p.right + 1, p.bottom + 1);
	if (IntersectRect(&rcTemp, &p, &m))
	{
		
		//SetRect(&rcTemp, 0, 0, rcTemp.right - rcTemp.left, rcTemp.bottom - rcTemp.top);
		//겹치는 사각형영역 길이를통해 좌표되돌려줌
		int tempW = rcTemp.right - rcTemp.left;
		int tempH = rcTemp.bottom - rcTemp.top;
	
		
		//위아래충돌
		//if (rcTemp.right > rcTemp.bottom)
		if (tempW>tempH)
		{
			trigger = false;
			isTBCol = true;
			triggercnt = 0;
			if (rcTemp.top==m.top/*&& !character.Get_jumpUp()*/)
			{
				//character.m_H = character.m_H;
				character.Set_PlayerPosY(PlayerY - tempH);
				if(!character.Get_jumpUp()&&character.Get_IsJump())
					character.Jump_Reset();
			}
			else if (rcTemp.bottom == m.bottom) {
				//isTDCol = true;
				character.Set_PlayerPosY(PlayerY + tempH);
				if (character.Get_jumpUp() && character.Get_IsJump())
					character.Jump_Reset();
			}
		}

		//좌우충돌
		else if(tempW < tempH)
		{
			if (rcTemp.left==m.left)
			{
				//character.m_W -= rcTemp.right;
				character.Set_PlayerPosX(PlayerX - tempW);
			}
			else if(rcTemp.right==m.right)
				//character.m_W += rcTemp.right;
				character.Set_PlayerPosX(PlayerX + tempW);
		}
		else
		{
			//character.Set_Gravity(9.8f);
			isTBCol = false;
		}
	}
	else
	{
		//isTBCol = false;
		//isLRCol = false;
	}

}


//단순 던전룸 이동역역에 충돌햇는지 유무만확인
void Collision::Coll_Character_MoveZone(RECT p, RECT z)
{
	RECT rcTemp2;//충돌여부확인용 임시렉트

	if (IntersectRect(&rcTemp2, &p, &z))
	{
		int tempW = rcTemp2.right - rcTemp2.left;
		int tempH = rcTemp2.bottom - rcTemp2.top;
		
		//좌우충돌만구분
		if (tempW < tempH)
		{
			isRoomChange = true;
			moveZone = z;
		}
		else
		{
			isRoomChange = false;
			
		}

	}

}
bool Collision::Line_Line(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {

	float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));


	intersectionX = x1 + (uA * (x2 - x1));//충돌교점 x좌표
	intersectionY = y1 + (uA * (y2 - y1));//충돌교점 y좌표

	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
		return true;
	}
	return false;
}
void Collision::Line_RECT(Line l, RECT _p) {

	int PlayerY = character.Get_PlayerPosY();//캐릭터의 실제 Y좌표를받아옴
	RECT p;//플레이어의 충돌영역을 받아올 RECT
	float height = _p.bottom - _p.top;//캐릭터 세로사이즈
	SetRect(&p, _p.left , _p.top +(height*0.6), _p.right , _p.bottom);//기존플레이어 rect의 절반만큼만할당

	//충돌여부만 구분(상하)
	bool top = Line_Line(l.x1, l.y1, l.x2, l.y2, p.left, p.top, p.right, p.top);
	bool bottom = Line_Line(l.x1, l.y1, l.x2, l.y2, p.left, p.bottom, p.right, p.bottom);


	//충돌한 교점까지 가져옴(좌우)
	bool left = Line_Line(l.x1, l.y1, l.x2, l.y2, p.left, p.top, p.left, p.bottom);
	//left_intersectionX = intersectionX;
	//left_intersectionY = intersectionY;

	//right_intersectionX = intersectionX;
	//right_intersectionY = intersectionY;
	

	if (left && !top && bottom && !trigger && !character.Get_jumpUp()) //사각형의 왼쪽면과아랫면 충돌 
	{
		isLineCol = true;
		character.Set_PlayerPosY(PlayerY - (p.bottom - intersectionY));
		//character.m_H -= (p.bottom - intersectionY);
		if (!character.Get_jumpUp() && character.Get_IsJump())
			character.Jump_Reset();
		//return true;
	}
	else if (left && !top && bottom && trigger) //트리거가 켜져있을시
	{
		isLineCol = false;
		triggercnt++;
		if (triggercnt > 5)
		{
			trigger = false;
			triggercnt = 0;
		}
	}
	bool right = Line_Line(l.x1, l.y1, l.x2, l.y2, p.right, p.top, p.right, p.bottom);
	if (right && !top && bottom && !trigger && !character.Get_jumpUp()) //사각형의 오른쪽면과 아랫면 충돌
	{
		isLineCol = true;
		character.Set_PlayerPosY(PlayerY - (p.bottom - intersectionY));
		if (!character.Get_jumpUp() && character.Get_IsJump())
			character.Jump_Reset();
	}
	else if (right && !top && bottom && trigger)
	{
		isLineCol = false;
		triggercnt++;
		if (triggercnt > 5)
		{
			trigger = false;
			triggercnt = 0;
		}
	}

	if ((right || left) && !top && !isTBCol && (l.y1 == l.y2) && !trigger&& !character.Get_jumpUp())//좌우면 동시충돌, 직선인경우
	{
		isLineCol = true;
		character.Set_PlayerPosY(PlayerY - (p.bottom - intersectionY));

		if (!character.Get_jumpUp() && character.Get_IsJump())
		{
			character.Jump_Reset();
		}

	}
	else if ((right || left) && (l.y1 == l.y2) && !top && trigger)
	{
		isLineCol = false;
		triggercnt++;
		if (triggercnt > 5)
		{
			trigger = false;
			triggercnt = 0;
		}

	}
	

	


	//return false;
}



bool& Collision::Get_TBCol()
{
	return isTBCol;
}

bool& Collision::Get_Trigger()
{
	return trigger;
}
bool Collision::Get_LineCol()
{
	return isLineCol;
}

bool Collision::Get_isRoomChange()
{
	return isRoomChange;
}

void Collision::Set_isRoomChange(bool _TF)
{
	isRoomChange = _TF;
}

RECT Collision::Get_MoveZone()
{
	return moveZone;
}