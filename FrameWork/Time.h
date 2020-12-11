#include "Include.h"

//��ŸŸ���� ����ϱ����� Ŭ����
class Time
{
public:
    Time();
    ~Time();
    void Reset();
    float Update();
    float GetDeltaTime();

private:
    LARGE_INTEGER m_CountTime;
    LARGE_INTEGER m_CurTime;
    LARGE_INTEGER m_PrevTime;
    double m_dDeltaTime;
    float m_fDeltaTime;

};

extern Time deltaTime;