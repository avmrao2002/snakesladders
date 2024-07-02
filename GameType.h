#if !defined(AFX_GAMETYPE_H__CB383091_189D_45F6_92E5_B57AC91C61DB__INCLUDED_)
#define AFX_GAMETYPE_H__CB383091_189D_45F6_92E5_B57AC91C61DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameType dialog

class CGameType : public CDialog
{
// Construction
public:
	CGameType(CWnd* pParent = NULL);   // standard constructor
	int m_gameType;
// Dialog Data
	//{{AFX_DATA(CGameType)
	enum { IDD = IDD_DIALOG_GAMETYPE };
	CString	m_player1name;
	CString	m_player2name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameType)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameType)
	afx_msg void OnRadioComputer();
	afx_msg void OnRadioHc();
	afx_msg void OnRadioHh();
	afx_msg void OnRadioSingle();
	afx_msg void OnRadioHhm();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMETYPE_H__CB383091_189D_45F6_92E5_B57AC91C61DB__INCLUDED_)
