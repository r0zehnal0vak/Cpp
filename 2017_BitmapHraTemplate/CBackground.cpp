#include "stdafx.h"
#include "CBackground.h"

void CBackground::LoadData(HDC dc)
{
	m_Btm.LoadBitmap("background3.bmp", dc); //naèteme bitmapu
	m_Btm.SetAnim(800, 600);
}

void CBackground::Display(HDC dc)
{
	m_Btm.DisplayTransparentAnimScale(dc, -50, -168, m_AnimPhase, m_AnimRow, 1.2);
}

CBackground::CBackground(void)
{
	m_AnimRow = 0;
	m_AnimPhase = 0;
}

CBackground::~CBackground(void)
{
}
