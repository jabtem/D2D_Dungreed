#define SCREEN_WITH 1366		// 화면 가로 픽셀크기
#define SCREEN_HEIGHT 768	// 화면 세로 픽셀크기

#define FRAME 2000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// 데이타 베이스
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "zxcv1234"
#define DB_NAME "D3D_Project"
#define CHOP(x) x[strlen(x) - 1] = ' '
#define CHARACTER_WIDTH 60
#define CHARACTER_HEIGHT 80

//맵
#define TOWN_MAXRANGE 6300
#define TOWN_MINRANGE 100
#define MAP_MAXHEIGHT 384

//바닥 한세트 넓이
#define GroundLength 1662

//속도
#define SPEED 1 //전체속도 배율 조정용

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