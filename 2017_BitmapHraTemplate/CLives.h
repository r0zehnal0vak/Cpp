#pragma once
#include "Bitmapa.h"
#include "CPozice.h"

class CLives
{
	CBitmapa m_Btm; // bitmapa s animacemi (dlazdicemi)
	int m_AnimPhase; // cislo animacni faze - index faze(dlazdice) v bitmape 
	int m_AnimRow; // cislo radku v bitmape pro animacni fazi

	CPozice m_Pozice;

public:
	int m_Lives;
	void LoadData(HDC dc);
	void Display(HDC dc);
	void GetLives(int lives);
	void GameOver(HDC dc);
	void GameOverDisplay(HDC dc);

	CLives(void);
	~CLives(void);
};

