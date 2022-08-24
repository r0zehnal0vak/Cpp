#include "StdAfx.h"
#include "Scene.h"

CScene::CScene(void)
{
	n = 0;
}

CScene::~CScene(void)
{
}

void CScene::Init(HDC hdc) {


	CCfgFile cfgfile; //dekoder konfiguracniho souboru sceny

	if (cfgfile.LoadFile("scena1.cfg")>=0) { //nacteme konfiguracni soubor sceny
		// konfiguracni soubor muze byt rozdelen na sekce (oddeleny slozenymi zavorkami {})
		// obsahuje vzdy klicove slovo a hodnotu (string nebo cislo) oddelene symbolem rovna se =

		//**** toto je priklad jak nacitat data z konfiguracniho souboru
		int pocet_objektu = cfgfile.GetIntValue(0, "pocet_objektu"); // nacte ze sekce 0 (prvni sekce v souboru) hodnotu klicoveho slova pocet_objektu
		char nazev_objektu[255];
		cfgfile.GetStrValue(0,"nazev_objektu",nazev_objektu); //nacte string ze sekce 0 pod klicem nazev objektu
	}
	m_Background.LoadData(hdc); //Pozadí
	m_xwing.LoadData(hdc);		//x-wing
	if (m_Asteroidy.OtestujKolize(&m_xwing) == 0) {
		m_Asteroidy.Load(hdc);		//Asteroidy
	}
}

void CScene::Render(HDC hdc) {
	m_Background.Display(hdc);
	m_xwing.Display(hdc);
	n = m_Asteroidy.OtestujKolize(&m_xwing);
	if (n == 0) {
		m_Asteroidy.Show(hdc);	//vrátí 0 --> pokud nevrátí 1 ani 2, generují se asteroidy...
		m_Asteroidy.GenerujAsteroid(5, hdc);
	}
	else if (n == 1) {		//vrátí 1 --> prohra, 0 životù
		m_Lives.GameOver(hdc);
		m_Lives.GameOverDisplay(hdc);
	}
	else if (n == 2) {		//vrátí 2 --> výhra, hráè pøežil stanovenou dobu
		m_Victory.VictoryData(hdc);
		m_Victory.VictoryDisplay(hdc);
		n + 1;
		if (n == 3) Sleep(1000);
	}
}

void CScene::UserInput(WPARAM wParam) { 
		switch (wParam) {
		case VK_UP: m_xwing.SetDirUp(); dir = 3; break;
		case VK_DOWN:  m_xwing.SetDirDown(); dir = 4; break;
		}
}

void CScene::Move() {
	if (m_Asteroidy.OtestujKolize(&m_xwing) == 0) {
		m_xwing.Move();
		m_Asteroidy.Move();
	}
}

