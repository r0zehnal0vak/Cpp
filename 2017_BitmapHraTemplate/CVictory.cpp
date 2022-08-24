#include "stdafx.h"
#include "CVictory.h"

void CVictory::LoadData(HDC dc)
{
	m_Btm.LoadBitmap("clock.bmp", dc);
	m_Btm.SetAnim(64, 64);
}

void CVictory::Display(HDC dc)
{
	m_Btm.DisplayTransparentAnimScale(dc, 650, 10, m_AnimPhase, m_AnimRow, 0.5);
}

void CVictory::GetNumber(int num)
{
	number = num;
	if (number < 500) m_AnimRow = 0;			
	if (number >= 500 && number < 1000) m_AnimRow = 1;
	if (number >= 1000 && number < 1500) m_AnimRow = 2;
	if (number >= 1500 && number < 2000) m_AnimRow = 3;
	if (number >= 2000) m_AnimRow = 0;					//zkruba 1,5 minuty
}

void CVictory::VictoryData(HDC dc)
{
	m_Btm.LoadBitmap("Victory.bmp", dc); //naèteme bitmapu
	m_Btm.SetAnim(512, 256);
}

void CVictory::VictoryDisplay(HDC dc)
{
	m_Btm.DisplayTransparentAnimScale(dc, 130, 110, 0, 0, 1);
}

CVictory::CVictory(void)
{
	m_AnimPhase = 0;
	m_MaxAnimPhase = 0;
	m_AnimRow = 0;
	number = 0;
	m_TimeFrameInterval = 250;
	m_LastTime = GetTickCount();
}

CVictory::~CVictory(void)
{
}