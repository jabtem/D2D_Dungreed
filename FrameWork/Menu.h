#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
	Sprite menuimg;//로고
	Sprite menuimg1;//배경구름1
	Sprite menuimg2;//배경구름2

	Sprite PlayOn;
	Sprite PlayOff;

	Sprite ExitOn;
	Sprite ExitOff;

	RECT playRect;
	RECT exitRect;

	//배경좌표이동용 변수
	float mx;
	float mx2;
	POINT mouseP;
	bool cursorOnPlay;//마우스커서가 플레이버튼위치에 올라와있을경우
	bool cursorOnExit;//마우스커서가 종료버튼 위치에 올라와있을경우

public:
	Menu();
	~Menu();

	int count, alpha;
	int BGM;
	bool SoundOn;
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();
	void CheckPlayOn();
	void CheckExitOn();
	virtual void OnMessage(MSG* msg);

};

#endif