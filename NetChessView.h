// NetChessView.h : interface of the CNetChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
#define AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChessBoard.h"
#include "GameType.h"

class CNetChessView : public CView
{
	//int m_snakes[12][12],m_ladders[11][8];
	int i;
	int m_diceBitmapId;
	COLORREF m_player1color;
	COLORREF m_player2color;
	CRect m_diceRect;
	int m_diceClickedFlag;
	int m_firstPlayerPos,m_secondPlayerPos;
	int m_gameType;
	long m_blackTime, m_whiteTime,m_startTime;
	CRect m_applyButtonRect;
	int m_sendButtonClickedFlag;
	COLOR_TYPE  m_pieceSide;
	bool m_mouseMoveFlag;
	CRect m_moveRect;
	CPoint m_point;
	int m_SpecialAction;		
	int m_player_turn;	
	int m_squareWidth;
	CRect m_movedFromRect;
	CRect m_movedToRect; 
	CGameType m_gameTypeDlg;
protected: // create from serialization only
	CNetChessView();
	DECLARE_DYNCREATE(CNetChessView)
	 

// Attributes
public:
	bool m_timerFlag;	 

	void DrawBoard();
	CNetChessDoc* GetDocument();			
	bool CheckValidMove(int,int);
	void KillTimerEvent();	
	void Initialize();
	int GetBitmapId(int piece_id);
	void SetPieceSide(COLOR_TYPE piecetype);
	COLOR_TYPE GetPlayerSide();
	CChessBoard cb[10][10];	
 
	CRect GetBoardRect(int id);
	void checkMovement(int &player);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNetChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNetChessView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFileNew();
	afx_msg void OnHelpHowtoplay();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEditGametype();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEditPlayer1color();
	afx_msg void OnEditPlayer2color();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	LRESULT OnMessageColorData(WPARAM wParam,LPARAM lParam);
	void OnLButtonDownAction(UINT nFlags, CPoint point);
	void OnLButtonUpAction(UINT nFlags, CPoint point);
	void OnMouseMoveAction(UINT nFlags, CPoint point);
	void OnFileNewAction();
	CString GetHistoryString();
	void SetShellIconData(char* data, int id);
	bool CheckCheckState(int piecetype, int piececolor,int x,int y);
	bool CheckKingMove(int fromx, int fromy, int tox, int toy);
	void SetMoveHistory();
	void GetMoveHistory();

};

#ifndef _DEBUG  // debug version in NetChessView.cpp
inline CNetChessDoc* CNetChessView::GetDocument()
   { return (CNetChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
