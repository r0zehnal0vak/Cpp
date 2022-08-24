#include "stdafx.h"
#include "Cxwing.h"

void Cxwing::LoadData(HDC dc)
{
    m_Btm.LoadBitmap("xwing2.bmp", dc);
    m_Btm.SetAnim(64, 64);
}

void Cxwing::Display(HDC dc)
{
    m_Btm.DisplayTransparentAnim(dc, m_Pozice.x, m_Pozice.y, m_AnimPhase, m_AnimRow);
}

void Cxwing::Move()
{
	//Se x-wingem se budeme pohybovat jen nahoru a dolù
		if (m_Direction == _UP) {
			m_Pozice.y -= 10;
			if (m_Pozice.y <= -40) m_Pozice.y = 550;
		}
		if (m_Direction == _DOWN) {
			m_Pozice.y += 10;
			if (m_Pozice.y >= 550) m_Pozice.y = -20;
		}
}


bool Cxwing::CheckHit(CPozice enemy_pozice, CPozice enemy_poziceSZ)
{
    return false;
}

CPozice Cxwing::GetPozice()
{
	return (m_Pozice);
}

CPozice Cxwing::GetPoziceSZ()
{
	m_PoziceSZ.x = m_Pozice.x + 55;
	m_PoziceSZ.y = m_Pozice.y + 55;
	return (m_PoziceSZ);
}

Cxwing::Cxwing(void)
{
	m_Direction = 1;
	m_AnimRow = 0;
	m_Pozice.x = 50; m_Pozice.y = 50;
	m_AnimPhase = 0;
	m_TimeFrameInterval = 250;
	m_MaxAnimPhase = 2;
	m_LastTime = GetTickCount();
}

Cxwing::~Cxwing(void)
{
}
