// GameType.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "GameType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameType dialog


CGameType::CGameType(CWnd* pParent /*=NULL*/)
	: CDialog(CGameType::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameType)
	m_player1name = _T("Human");
	m_player2name = _T("Computer");
	//}}AFX_DATA_INIT
	m_gameType = HUMAN_COMPUTER;
}


void CGameType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameType)
	DDX_Text(pDX, IDC_EDIT_PLAYER1NAME, m_player1name);
	DDV_MaxChars(pDX, m_player1name, 10);
	DDX_Text(pDX, IDC_EDIT_PLAYER2NAME, m_player2name);
	DDV_MaxChars(pDX, m_player2name, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGameType, CDialog)
	//{{AFX_MSG_MAP(CGameType)
	ON_BN_CLICKED(IDC_RADIO_COMPUTER, OnRadioComputer)
	ON_BN_CLICKED(IDC_RADIO_HC, OnRadioHc)
	ON_BN_CLICKED(IDC_RADIO_HH, OnRadioHh)
	ON_BN_CLICKED(IDC_RADIO_SINGLE, OnRadioSingle)
	ON_BN_CLICKED(IDC_RADIO_HHM, OnRadioHhm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameType message handlers

void CGameType::OnRadioComputer() 
{
	// TODO: Add your control notification handler code here
	m_gameType = SINGLE_PLAY_COMPUTER;
	CWnd* wnd = GetDlgItem(IDC_EDIT_PLAYER1NAME);
	wnd->EnableWindow(FALSE);
	wnd = GetDlgItem(IDC_EDIT_PLAYER2NAME);
	wnd->EnableWindow(FALSE);
	m_player1name = "Computer";
	m_player2name = "Computer";
	UpdateData(FALSE);
}

void CGameType::OnRadioHc() 
{
	// TODO: Add your control notification handler code here
	m_gameType = HUMAN_COMPUTER;
	CWnd* wnd = GetDlgItem(IDC_EDIT_PLAYER1NAME);
	wnd->EnableWindow(TRUE);
	wnd = GetDlgItem(IDC_EDIT_PLAYER2NAME);
	wnd->EnableWindow(FALSE);
	m_player1name = "Human";
	m_player2name = "Computer";
	UpdateData(FALSE);
}

void CGameType::OnRadioHh() 
{
	// TODO: Add your control notification handler code here
	m_gameType = HUMAN_HAMAN_COMPUTER;
	CWnd* wnd = GetDlgItem(IDC_EDIT_PLAYER1NAME);
	wnd->EnableWindow(TRUE);
	wnd = GetDlgItem(IDC_EDIT_PLAYER2NAME);
	wnd->EnableWindow(TRUE);
	m_player1name = "Human1";
	m_player2name = "Human2";
	UpdateData(FALSE);
}

void CGameType::OnRadioSingle() 
{
	// TODO: Add your control notification handler code here
	m_gameType = SINGLE_PLAY_HUMAN;
	CWnd* wnd = GetDlgItem(IDC_EDIT_PLAYER1NAME);
	wnd->EnableWindow(TRUE);
	wnd = GetDlgItem(IDC_EDIT_PLAYER2NAME);
	wnd->EnableWindow(FALSE);
	m_player1name = "Human1";
	UpdateData(FALSE);
}

void CGameType::OnRadioHhm() 
{
	// TODO: Add your control notification handler code here
	m_gameType = HUMAN_HAMAN_MANUAL;
	CWnd* wnd = GetDlgItem(IDC_EDIT_PLAYER1NAME);
	wnd->EnableWindow(TRUE);
	wnd = GetDlgItem(IDC_EDIT_PLAYER2NAME);
	wnd->EnableWindow(TRUE);
	m_player1name = "Human1";
	m_player2name = "Human2";
	UpdateData(FALSE);
}

BOOL CGameType::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CButton *btn; 
	 
	switch(m_gameType)
	{
		case HUMAN_COMPUTER:
			 btn = (CButton*)GetDlgItem(IDC_RADIO_HC);
			break;
		case HUMAN_HAMAN_MANUAL:
			btn = (CButton*)GetDlgItem(IDC_RADIO_HHM);
			break;
		case HUMAN_HAMAN_COMPUTER:			
			btn = (CButton*)GetDlgItem(IDC_RADIO_HH);
			break;
		case SINGLE_PLAY_HUMAN:			
			btn = (CButton*)GetDlgItem(IDC_RADIO_SINGLE);
			break;
		case SINGLE_PLAY_COMPUTER:			
			btn = (CButton*)GetDlgItem(IDC_RADIO_COMPUTER);
			break;

	}	 
	btn->SetCheck(TRUE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
