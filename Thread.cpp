#include "pch.h"
#include "Thread.h"

UINT ThreadFunction(LPVOID param) {
	// inicjalizacja liczb randomowych podstaw¹ czasu
	srand(time(0));

	thread_param* tp = (thread_param*)param;

	CMFCAppThreadsDlg* dialog = (CMFCAppThreadsDlg*)tp->dialog;
	CWnd* cwnd = dialog->GetDlgItem(tp->id_static);
	CDC* dc = cwnd->GetDC();

	CRect rc;
	cwnd->GetClientRect(&rc);

	// odstêp obiektu od granic pola, w którym jest rysowany (GroupBox)
	int padding = 5;

	int window_height = rc.bottom;
	int window_width = rc.right;

	int object_speed_x = tp->speed_x;
	int object_speed_y = tp->speed_y;

	int object_height = tp->size_object, object_width = tp->size_object;

	int object_pos_x = (rand() % 10 + padding) * 10, object_pos_y = (rand() % 20 + padding) * 10;

	// kolor t³a okna dialogowego, u¿ywane do usuwania np. poprzednich pozycji obiektu
	COLORREF dialog_bg_color = RGB(240, 240, 240);

	// rysujê obwód pola gdzie porusza siê obiekt (GroupBox)
	dc->SelectObject(GetStockObject(DC_BRUSH));
	dc->SetDCBrushColor(dialog_bg_color);
	dc->Rectangle(rc);

	// kontur figur
	dc->SelectObject(GetStockObject(DC_PEN));
	dc->SetDCPenColor(dialog_bg_color);

	dc->SelectObject(GetStockObject(DC_BRUSH));

	COLORREF object_color = tp->color;

	// kolor tekstu i przeŸroczyste t³o
	dc->SetTextColor(object_color);
	dc->SetBkMode(TRANSPARENT);

	// font dla tekstu etykiety ("Ko³o ...")
	CFont myFont;
	myFont.CreateFont(80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Tahoma"));
	dc->SelectObject(&myFont);

	// pozycja etykiety
	RECT rc_text = { rc.right / 3, rc.bottom / 2 };

	while (tp->bThread_run) {
		// "wymazujemy" poprzedni¹ pozycjê obiektu
		dc->SetDCBrushColor(dialog_bg_color);
		dc->Ellipse(object_pos_x, object_pos_y, object_pos_x + object_height, object_pos_y + object_width);

		object_pos_x += object_speed_x;
		object_pos_y += object_speed_y;

		// czy obiekt jest poza krawêdzi¹ x < 0
		if (object_pos_x < padding)
		{
			object_speed_x *= -1;
			object_pos_x = 0 + padding;
		}
		else if ((object_pos_x + object_width) > window_width)
		{
			object_speed_x *= -1;
			object_pos_x = window_width - object_width - padding;
		}

		// czy obiekt jest poza krawêdzi¹ y < 0
		if (object_pos_y < padding)
		{
			object_speed_y *= -1;
			object_pos_y = 0 + padding;
		}
		else if ((object_pos_y + object_height) > window_height)
		{
			object_speed_y *= -1;
			object_pos_y = window_height - object_height - padding;
		}

		dc->SetDCBrushColor(object_color);
		dc->Ellipse(object_pos_x, object_pos_y, object_pos_x + object_height, object_pos_y + object_width);

		// wyœwietlamy opis
		dc->DrawText(tp->strLabel, &rc_text, DT_NOCLIP);
		Sleep(50);
	}

	// "wymazujemy" poprzedni¹ pozycjê
	dc->SetDCBrushColor(dialog_bg_color);
	dc->Ellipse(object_pos_x, object_pos_y, object_pos_x + object_height, object_pos_y + object_width);

	// rysujê obwód pola gdzie porusza siê obiekt (GroupBox)
	dc->SelectObject(GetStockObject(DC_BRUSH));
	dc->SetDCBrushColor(dialog_bg_color);
	dc->Rectangle(rc);

	AfxEndThread(0, TRUE);
	return 0;
}