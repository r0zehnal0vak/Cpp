#include "stdafx.h"
#include "CLives.h"

void CLives::LoadData(HDC dc)
{
	m_Btm.LoadBitmap("lives.bmp", dc); //naèteme bitmapu
	m_Btm.SetAnim(29, 11);
}

void CLives::Display(HDC dc)
{
	m_Btm.DisplayTransparentAnimScale(dc, 700, 10, m_AnimPhase, m_AnimRow, 2.0);
}

void CLives::GetLives(int lives)
{
	m_Lives = lives;					//vezmeme poèet životù z asteroidù
	if (m_Lives == 2) m_AnimRow = 1;
	if (m_Lives == 1) m_AnimRow = 2;
	if (m_Lives == 0) m_AnimRow = 3;
}

void CLives::GameOver(HDC dc)
{
	m_Btm.LoadBitmap("GameOver2.bmp", dc); //naèteme bitmapu
	m_Btm.SetAnim(512, 256);
}

void CLives::GameOverDisplay(HDC dc)
{
	m_Btm.DisplayTransparentAnimScale(dc, 130, 110, 0, 0, 1);
}

CLives::CLives(void)
{
	m_AnimRow = 0;
	m_AnimPhase = 0;
}

CLives::~CLives(void)
{
}
