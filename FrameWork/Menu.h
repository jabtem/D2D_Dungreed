#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
	Sprite menuimg;
	Sprite menuimg1;
	Sprite menuimg2;
	float mx;
	float mx2;

public:
	Menu();
	~Menu();

	int count, alpha;


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif