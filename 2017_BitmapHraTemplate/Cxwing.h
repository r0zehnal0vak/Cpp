#pragma once
#include "bitmapa.h"
#include "CPozice.h"
#include <vector>
#include "Windows.h"
using namespace std;

#define _UP 1
#define _DOWN 0
class Cxwing
{
	CBitmapa m_Btm; // bitmapa s animacemi (dlazdicemi)
	int m_Direction; // smer, kterym se drak pohybuje
	int m_AnimPhase; // cislo animacni faze - index faze(dlazdice) v bitmape 
	int m_AnimRow; // cislo radku v bitmape pro animacni fazi
	int m_MaxAnimPhase; // maximalni index animacni faze (dlazdice) v bitmape  
	DWORD m_TimeFrameInterval; // interval v ms kdy se bude menit animacni faze
	DWORD m_LastTime; // posledni cas, kdy se menila animacni faze

	int lives;;
	CPozice m_Pozice;
	CPozice m_PoziceSZ;
public:
	void LoadData(HDC dc);
	void Display(HDC dc);
	void Move();
	void SetDirUp() { m_Direction = _UP; m_AnimRow = 0; };
	void SetDirDown() { m_Direction = _DOWN; m_AnimRow = 0; };


	bool CheckHit(CPozice enemy_pozice, CPozice enemy_poziceSZ);
	CPozice GetPozice();
	CPozice GetPoziceSZ();


	Cxwing(void);
	~Cxwing(void);
};

