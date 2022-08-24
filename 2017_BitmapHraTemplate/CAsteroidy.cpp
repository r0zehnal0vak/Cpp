#include "stdafx.h"
#include "CAsteroidy.h"

void CAsteroidy::Move()
{
	for (int i = 0; i < m_Asteroid.size(); i++) m_Asteroid[i]->Move();
}

void CAsteroidy::Load(HDC dc)
{
}

void CAsteroidy::Show(HDC dc)
{
	for (int i = 0; i < m_Asteroid.size(); i++) {							
		m_Asteroid[i]->Display(dc);
	}
	lives.LoadData(dc);
	lives.Display(dc);
	victory.LoadData(dc);
	victory.Display(dc);
}

void CAsteroidy::GenerujAsteroid(int pocet, HDC dc)
{
	m_Number++;
	victory.GetNumber(m_Number);
	int maxpoc;
	maxpoc = m_Asteroid.size();
	for (int i = 0; i < pocet; i++) {
		if (maxpoc < 5) {			//vygeneruje pouze 5 asteroidù, pokud se jeden znièí vytvoøí se nový do poètu
			int x = rand() % 100;
			if (x == 1) CreateAsteroid(800, rand() % 600, dc); 
		}
	}
}

void CAsteroidy::CreateAsteroid(int x, int y, HDC dc)
{
	m_Pozice.x = x;
	m_Pozice.y = y;
	CAsteroid* asteroid;
	asteroid = new CAsteroid(m_Pozice);
	asteroid->LoadData(dc);
	m_Asteroid.push_back(asteroid);
}

int CAsteroidy::OtestujKolize(Cxwing* xwing)
{
	for (int i = 0; i < m_Asteroid.size(); i++) {
		if (xwing->GetPozice() <= m_Asteroid[i]->GetPozice() && xwing->GetPoziceSZ() >= m_Asteroid[i]->GetPozice() ||       //Pokud se Asteroid støetne s X-wingem, tak odeèteme životy a smažeme asteroid
			m_Asteroid[i]->GetPozice() <= xwing->GetPozice() && m_Asteroid[i]->GetPoziceSZ() >= xwing->GetPozice()) {
			m_Asteroid.erase(m_Asteroid.begin() + i);
			m_Lives--;
			lives.GetLives(m_Lives);
		}
	}
	//více výstupù funkce, na rozlišení výhry(1) a prohry(2)
	if (m_Lives <= 0) return 1;
	if (m_Number >= 2000) return 2;
	else return 0;
}

CAsteroidy::CAsteroidy(void)
{
	m_Lives = 3;
	m_Number = 0;
}

CAsteroidy::~CAsteroidy(void)
{
}
