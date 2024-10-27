#pragma once
#include "MFCAppThreadsDlg.h"

struct thread_param
{
	CMFCAppThreadsDlg* dialog;
	// czy w¹tek jest aktywny
	BOOL bThread_run;
	// id obiektu, po którym rysujemy
	int id_static;
	// uchwyt okna, po którym rysujemy
	CWnd* cwnd;
	// o ile pixeli przesuwa siê obiekt przy ka¿dym kroku
	int speed_x, speed_y;
	// rozmiar rysowanego obiektu 
	int size_object;
	// tekst w oknie w¹tku
	CString strLabel;
	// kolor obiektu
	COLORREF color;
};

UINT ThreadFunction(LPVOID param);