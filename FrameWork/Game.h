#ifndef __Game_H__
#define __Game_H__

class Game : public Chap
{
	int MapState;//ÇöÀç ¸ÊÀÌ ¹«½¼¸ÊÀÎÁö ±¸ºĞ
public:
	Game();
	~Game();

	DWORD GameTime;
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

	void Set_MapState(int);
};
#endif