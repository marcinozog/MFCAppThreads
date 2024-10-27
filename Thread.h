#pragma once
#include "MFCAppThreadsDlg.h"

struct thread_param
{
	CMFCAppThreadsDlg* dialog;
	// czy w�tek jest aktywny
	BOOL bThread_run;
	// id obiektu, po kt�rym rysujemy
	int id_static;
	// uchwyt okna, po kt�rym rysujemy
	CWnd* cwnd;
	// o ile pixeli przesuwa si� obiekt przy ka�dym kroku
	int speed_x, speed_y;
	// rozmiar rysowanego obiektu 
	int size_object;
	// tekst w oknie w�tku
	CString strLabel;
	// kolor obiektu
	COLORREF color;
};

UINT ThreadFunction(LPVOID param);