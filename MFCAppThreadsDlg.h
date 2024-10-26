
// MFCAppThreadsDlg.h : header file
//

#pragma once


// CMFCAppThreadsDlg dialog
class CMFCAppThreadsDlg : public CDialogEx
{
// Construction
public:
	CMFCAppThreadsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPTHREADS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnKolo1();
	afx_msg void OnBnClickedBtnKolo2();
	afx_msg void OnBnClickedBtnKolo3();
	afx_msg void OnBnClickedBtnKolo4();

	/////////////////////
	CWinThread* pThread1;
	CWinThread* pThread2;
	CWinThread* pThread3;
	CWinThread* pThread4;

	BOOL bThread1_run = FALSE;
	BOOL bThread2_run = FALSE;
	BOOL bThread3_run = FALSE;
	BOOL bThread4_run = FALSE;

	CFont footer_font;
};
