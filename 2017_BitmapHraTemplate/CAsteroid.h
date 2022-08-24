#pragma once
#include "bitmapa.h"
#include "CPozice.h"
class CAsteroid
{
	CBitmapa m_Btm; // bitmapa s animacemi (dlazdicemi)
	int m_Direction; // smer, kterym se drak pohybuje
	int m_AnimPhase; // cislo animacni faze - index faze(dlazdice) v bitmape 
	int m_AnimRow; // cislo radku v bitmape pro animacni fazi
	int m_MaxAnimPhase; // maximalni index animacni faze (dlazdice) v bitmape  
	DWORD m_TimeFrameInterval; // interval v ms kdy se bude menit animacni faze
	DWORD m_LastTime; // posledni cas, kdy se menila animacni faze

	CPozice m_Pozice;
	CPozice m_PoziceSZ;
public:
	void LoadData(HDC dc);
	void Display(HDC dc);
	void Move();

	CPozice GetPozice();
	CPozice GetPoziceSZ();

	CAsteroid(CPozice pozice);
	CAsteroid(void);
	~CAsteroid(void);
};

