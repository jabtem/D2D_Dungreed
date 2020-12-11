#include "Include.h"


Time deltaTime;

Time::Time()
{
    Reset();
}
Time::~Time()
{

}

void Time::Reset()
{
    QueryPerformanceFrequency(&m_CountTime);
    QueryPerformanceCounter(&m_CurTime);
    QueryPerformanceCounter(&m_PrevTime);
}

float Time::Update()
{
    QueryPerformanceCounter(&m_CurTime);

    // delta time = current time - previous time
    m_dDeltaTime = (static_cast<double>(m_CurTime.QuadPart) - static_cast<double>(m_PrevTime.QuadPart)) / static_cast<double>(m_CountTime.QuadPart);

    m_fDeltaTime = static_cast<float>(m_dDeltaTime);
    m_PrevTime = m_CurTime;

    return m_fDeltaTime;
}

float Time::GetDeltaTime()
{
    return m_fDeltaTime;
}