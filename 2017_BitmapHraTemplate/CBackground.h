#pragma once
#include "Bitmapa.h"
#include "CPozice.h"

class CBackground
{
	CBitmapa m_Btm; // bitmapa s animacemi (dlazdicemi)
	int m_AnimPhase; // cislo animacni faze - index faze(dlazdice) v bitmape 
	int m_AnimRow; // cislo radku v bitmape pro animacni fazi

	CPozice m_Pozice;
public:
	void LoadData(HDC dc);
	void Display(HDC dc);
	CBackground(void);
	~CBackground(void);
};

