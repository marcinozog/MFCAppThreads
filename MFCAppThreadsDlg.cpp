
// MFCAppThreadsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCAppThreads.h"
#include "MFCAppThreadsDlg.h"
#include "afxdialogex.h"

#include "Thread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

thread_param tp1;
thread_param tp2;
thread_param tp3;
thread_param tp4;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAppThreadsDlg dialog



CMFCAppThreadsDlg::CMFCAppThreadsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPTHREADS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppThreadsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCAppThreadsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_KOLO_1, &CMFCAppThreadsDlg::OnBnClickedBtnKolo1)
	ON_BN_CLICKED(IDC_BTN_KOLO_2, &CMFCAppThreadsDlg::OnBnClickedBtnKolo2)
	ON_BN_CLICKED(IDC_BTN_KOLO_3, &CMFCAppThreadsDlg::OnBnClickedBtnKolo3)
	ON_BN_CLICKED(IDC_BTN_KOLO_4, &CMFCAppThreadsDlg::OnBnClickedBtnKolo4)
END_MESSAGE_MAP()


// CMFCAppThreadsDlg message handlers

BOOL CMFCAppThreadsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Font dla stopki
	footer_font.CreateFont(46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Tahoma"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCAppThreadsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCAppThreadsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// wyœwietlamy tekst stopki
		CPaintDC dc(this);
		CRect rect = { 10, 1050, 0, 0 };
		dc.SetTextColor(RGB(255, 0, 0));
		dc.SetBkMode(TRANSPARENT);
		dc.SelectObject(&footer_font);
		dc.DrawText(L"Aplikacja wielow¹tkowa - Marcin O¿óg, nr albumu 26065 - WSZ Edukacja 2024", rect, DT_NOCLIP);

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCAppThreadsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCAppThreadsDlg::OnBnClickedBtnKolo1()
{
	CWnd* btnKolo1 = this->GetDlgItem(IDC_BTN_KOLO_1);

	tp1.dialog = this;
	tp1.id_static = IDC_STATIC1;
	tp1.speed_x = 10;
	tp1.speed_y = 30;
	tp1.size_object = 50;
	tp1.strLabel = "Ko³o 1";
	tp1.color = RGB(255, 0, 0);

	if (tp1.bThread_run == FALSE) {
		tp1.bThread_run = TRUE;
		AfxBeginThread(ThreadFunction, &tp1);
		btnKolo1->SetWindowText(L"Stop ko³o 1");
	}
	else {
		tp1.bThread_run = FALSE;
		btnKolo1->SetWindowText(L"Start ko³o 1");
	}
}

void CMFCAppThreadsDlg::OnBnClickedBtnKolo2()
{
	CWnd* btnKolo2 = this->GetDlgItem(IDC_BTN_KOLO_2);

	tp2.dialog = this;
	tp2.id_static = IDC_STATIC2;
	tp2.speed_x = 50;
	tp2.speed_y = 40;
	tp2.size_object = 30;
	tp2.strLabel = "Ko³o 2";
	tp2.color = RGB(0, 155, 0);

	if (tp2.bThread_run == FALSE) {
		tp2.bThread_run = TRUE;
		AfxBeginThread(ThreadFunction, &tp2);
		btnKolo2->SetWindowText(L"Stop ko³o 2");
	}
	else {
		tp2.bThread_run = FALSE;
		btnKolo2->SetWindowText(L"Start ko³o 2");
	}
}

void CMFCAppThreadsDlg::OnBnClickedBtnKolo3()
{
	CWnd* btnKolo3 = this->GetDlgItem(IDC_BTN_KOLO_3);

	tp3.dialog = this;
	tp3.id_static = IDC_STATIC3;
	tp3.speed_x = 80;
	tp3.speed_y = 30;
	tp3.size_object = 100;
	tp3.strLabel = "Ko³o 3";
	tp3.color = RGB(0, 0, 255);

	if (tp3.bThread_run == FALSE) {
		tp3.bThread_run = TRUE;
		AfxBeginThread(ThreadFunction, &tp3);
		btnKolo3->SetWindowText(L"Stop ko³o 3");
	}
	else {
		tp3.bThread_run = FALSE;
		btnKolo3->SetWindowText(L"Start ko³o 3");
	}
}

void CMFCAppThreadsDlg::OnBnClickedBtnKolo4()
{
	CWnd* btnKolo4 = this->GetDlgItem(IDC_BTN_KOLO_4);

	tp4.dialog = this;
	tp4.id_static = IDC_STATIC4;
	tp4.speed_x = 20;
	tp4.speed_y = 100;
	tp4.size_object = 70;
	tp4.strLabel = "Ko³o 4";
	tp4.color = RGB(0, 0, 0);

	if (tp4.bThread_run == FALSE) {
		tp4.bThread_run = TRUE;
		AfxBeginThread(ThreadFunction, &tp4);
		btnKolo4->SetWindowText(L"Stop ko³o 4");
	}
	else {
		tp4.bThread_run = FALSE;
		btnKolo4->SetWindowText(L"Start ko³o 4");
	}
}
