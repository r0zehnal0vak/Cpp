#pragma once

#include "stdafx.h"
#include "CBackground.h"
#include "cfgfile.h"
#include "Cxwing.h"
#include "CAsteroidy.h"
#include "CLives.h"
#include "CVictory.h"

class CScene
{
	//vytvorime nase hlavni objekty
	CBackground m_Background; //BACKGROUND
	Cxwing m_xwing;
	CAsteroidy m_Asteroidy;
	CLives m_Lives;
	CVictory m_Victory;

	int dir;
public:
	int n;
	void Init(HDC hdc);
	void Render(HDC hdc);
	void UserInput(WPARAM wParam);
	void Move();
	CScene(void);
	~CScene(void);
};
