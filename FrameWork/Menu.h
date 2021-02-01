#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
	Sprite menuimg;//�ΰ�
	Sprite menuimg1;//��汸��1
	Sprite menuimg2;//��汸��2

	Sprite PlayOn;
	Sprite PlayOff;

	Sprite ExitOn;
	Sprite ExitOff;

	RECT playRect;
	RECT exitRect;

	//�����ǥ�̵��� ����
	float mx;
	float mx2;
	POINT mouseP;
	bool cursorOnPlay;//���콺Ŀ���� �÷��̹�ư��ġ�� �ö���������
	bool cursorOnExit;//���콺Ŀ���� �����ư ��ġ�� �ö���������

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