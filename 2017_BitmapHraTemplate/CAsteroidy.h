#pragma once
#include <vector>
#include "CAsteroid.h"
#include"Cxwing.h"
#include "CLives.h"
#include "CVictory.h"
using namespace std;
class CAsteroidy
{
	vector <CAsteroid*> m_Asteroid;

	CPozice m_Pozice;
	CLives lives;
	CVictory victory;

	int m_Lives;
	int m_Number;
	int m_Pocet;
public:
	void Move();
	void Load(HDC dc);
	void Show(HDC dc);
	void GenerujAsteroid(int pocet, HDC dc);
	void CreateAsteroid(int x, int y, HDC dc);
	int OtestujKolize(Cxwing* xwing);

	CAsteroidy(void);
	~CAsteroidy(void);
};

