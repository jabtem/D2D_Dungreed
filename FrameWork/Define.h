#define SCREEN_WITH 1366		// ȭ�� ���� �ȼ�ũ��
#define SCREEN_HEIGHT 768	// ȭ�� ���� �ȼ�ũ��

#define FRAME 2000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// ����Ÿ ���̽�
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "zxcv1234"
#define DB_NAME "D3D_Project"
#define CHOP(x) x[strlen(x) - 1] = ' '
#define CHARACTER_WIDTH 60
#define CHARACTER_HEIGHT 80

//��
#define TOWN_MAXRANGE 6300
#define TOWN_MINRANGE 100
#define MAP_MAXHEIGHT 384

//�ٴ� �Ѽ�Ʈ ����
#define GroundLength 1662

//�ӵ�
#define SPEED 1 //��ü�ӵ� ���� ������

#define _USE_MATH_DEFINES



typedef struct _Position
{
	float x1, x2;
	float y1, y2;
}Position;

typedef struct _Line
{
	float x1, x2;
	float y1, y2;
}Line;

typedef struct _ssWsalsh
{
	bool Up;
	bool Down;
}ssWslash;