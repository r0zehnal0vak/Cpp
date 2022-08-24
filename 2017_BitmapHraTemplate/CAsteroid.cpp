#include "stdafx.h"
#include "CAsteroid.h"

void CAsteroid::LoadData(HDC dc)
{
	m_Btm.LoadBitmap("asteroid.bmp", dc);
	m_Btm.SetAnim(64, 64);
}

void CAsteroid::Display(HDC dc)
{
	m_Btm.DisplayTransparentAnim(dc, m_Pozice.x, m_Pozice.y, m_AnimPhase, m_AnimRow);
}

void CAsteroid::Move()
{
	m_Pozice.x -= 20;
	if (m_Pozice.x < -30) {		//pokaždé, co asteroid opustí obrazovku, objeví se na druhé stranì s novì generovaným y
		m_Pozice.x = 850;
		m_Pozice.y = rand() % 480 - 0;
	}

}

CPozice CAsteroid::GetPozice()
{
	return (m_Pozice);
}

CPozice CAsteroid::GetPoziceSZ()
{
	m_PoziceSZ.x = m_Pozice.x + 64;		// pozice + velikost obrázku --> levý horní roh + pravý horní roh
	m_PoziceSZ.y = m_Pozice.y + 64;
	return (m_PoziceSZ);
}

CAsteroid::CAsteroid(CPozice pozice)
{
	m_Pozice = pozice;
	m_Direction = 0;
	m_AnimRow = 0;
	m_AnimPhase = 0;
	m_TimeFrameInterval = 250;
	m_MaxAnimPhase = 2;
	m_LastTime = GetTickCount();
}

CAsteroid::CAsteroid(void)
{
}

CAsteroid::~CAsteroid(void)
{
}
