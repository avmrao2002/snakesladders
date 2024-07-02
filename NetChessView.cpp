// NetChessView.cpp : implementation of the CNetChessView class
//

#include "stdafx.h"
#include "NetChess.h"
#include "GameType.h"
#include "ChessBoard.h"

#include "MainFrm.h"


#include "NetChessDoc.h"
#include "NetChessView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetChessView
int m_snakes[12][12] = {
		{98,84,85,76,65,56,55,46,35,27,13,0},
		{95,86,75,66,56,45,37,0,0,0,0,0},
		{92,89,72,69,51,0,0,0,0,0,0,0},
		{83,78,63,58,43,39,22,0,0,0,0,0},
		{64,57,44,38,24,0,0,0,0,0,0,0},
		{68,53,47,34,27,14,15,5,4,3,2,0},
		{69,52,49,32,33,0,0,0,0,0,0,0},
		{59,42,39,22,20,19,2,18,0,0,0,0},
		{52,50,31,30,11,0,0,0,0,0},
		{44,43,38,22,0,0,0,0,0,0,0,0},
		{46,36,25,16,15,0,0,0,0,0,0,0},
		{48,33,32,29,12,9,0,0,0,0,0,0}
		};
int m_ladders[11][8] = {
		{8,14,26,0,0,0,0,0},
		{19,23,38,0,0,0,0,0},
		{28,33,48,53,0,0,0,0},
		{21,40,41,60,61,79,82,0},
		{36,45,57,0,0,0,0,0},
		{43,58,63,77,0,0,0,0},
		{50,51,70,71,90,91,0,0},
		{54,67,73,88,0,0,0,0},
		{62,78,84,96,0,0,0,0},
		{66,74,87,0,0,0,0,0},
		{80,81,99,0,0,0,0,0}
		};
void writeMessage(char *str,...);
int checkExisting(int n, int *arr, int rand)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == rand)
			return 1;
	}
	return 0;
}

int getExisting(int n,int* arr, int* data)
{	 
	int foundFlag = 0; 	 	 
	for(int i=0;i<n;i++)
	{		 
		if(data[i] == 0) continue;
 		for(int j =0;j<n;j++)
		{
 			if(arr[j]==0)
			{
			 			 
				return data[i];
			}
				
			if(arr[j] == data[i])
			{				 
				foundFlag = 1;
				break;
			}
		}
		if(foundFlag == 0)
		{	 			 
			return data[i];
		}
	}
 	return -1;
}
void getRandom(int num,int arr[100])
{
	int i;
	srand( (unsigned)time( NULL ) );
	int data[100];
	for(i=0;i<100;i++)
	{
		data[i] = i+1;
	}

	for(i=0;i<100;i++)
	{
		arr[i]=0;
	}
	int trycount = 0;
	for(i=0;i<num;i++)
	{
			 
			int rnd = (rand() % ((num)+1));
 			if( rnd == 0 || checkExisting(num,arr,rnd) == 1)
			{//try once again
				if(trycount==1000)
				{
					int retdata = getExisting(num,arr,data);
					if(retdata < 0)
					{
						return;
					}
					else
					{
						trycount = 0;
						arr[i] = retdata;
					}
				}
				else
				{
					trycount++;
					i--;
				}
				 
			}
			else
			{
				trycount=0;
				arr[i] = rnd;
			}
	} 
}

IMPLEMENT_DYNCREATE(CNetChessView, CView)

BEGIN_MESSAGE_MAP(CNetChessView, CView)
	//{{AFX_MSG_MAP(CNetChessView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EDIT_GAMETYPE, OnEditGametype)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_EDIT_PLAYER1COLOR, OnEditPlayer1color)
	ON_COMMAND(ID_EDIT_PLAYER2COLOR, OnEditPlayer2color)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(ID_MY_MESSAGE_COLORDATA,OnMessageColorData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetChessView construction/destruction

CNetChessView::CNetChessView()
{
	// TODO: add construction code here
	m_player1color = RGB(255,0,0);
	m_player2color = RGB(0,0,255);

	Initialize();	 
}

CNetChessView::~CNetChessView()
{
}

BOOL CNetChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView drawing

void CNetChessView::OnDraw(CDC* pDC)
{
	CNetChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	DrawBoard(); 
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView printing

BOOL CNetChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNetChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNetChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView diagnostics

#ifdef _DEBUG
void CNetChessView::AssertValid() const
{
	CView::AssertValid();
}

void CNetChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNetChessDoc* CNetChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNetChessDoc)));
	return (CNetChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNetChessView message handlers



void CNetChessView::DrawBoard()
{
	CClientDC dc(this);
	CBitmap localbmp;
	//localbmp.LoadBitmap(IDB_BITMAP1_ORG);
	//dc.SelectObject(&localbmp); 

	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	//CBitmap localbmp;
	//BITMAP bp={0,1000,490,3000,1,24,0x00000000};
	//localbmp.CreateBitmapIndirect(&bp);
	localbmp.LoadBitmap(IDB_BITMAP_ORG);
	ldc.SelectObject(&localbmp); 
	COLORREF cr(RGB(20,140,17));	 
	CBrush br(cr);
	ldc.SetBkColor(cr);
	CRect rect1;
	GetClientRect(&rect1);
	ldc.FillRect(&rect1,&br);
	//BITMAP bp;
	//localbmp.GetBitmap(&bp);
	

	CDC ldcpic;
	ldcpic.CreateCompatibleDC(&ldcpic);
	CBitmap localbmp2;
	localbmp2.LoadBitmap(IDB_BITMAP_BASE);
	ldcpic.SelectObject(&localbmp2); 
	BITMAP bmp;
	localbmp2.GetBitmap(&bmp);
	//ldc.SetStretchBltMode(HALFTONE);
	//POINT pt;
	//SetBrushOrgEx(ldc.GetSafeHdc(),0,0,&pt);
	CRect rect;
	GetClientRect(&rect);
	//ldc.StretchBlt(rect.left,rect.top,400,400,&ldcpic,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	 //for high resolution 
	ldc.StretchBlt(rect.left,rect.top,490,490,&ldcpic,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	/*CRect rect1(0,0,rect.right,rect.bottom);*/
	
	CBrush brush(cr);
	ldc.SelectObject(brush);
	/*//CRect rect1;
	//GetClientRect(&rect1);
 
	ldc.FillRect(&rect1,&brush);*/

/*	ldc.TextOut(500,397,"Player Turn:");
	if(m_player_turn == true)
	{
		ldc.TextOut(510,420,m_gameTypeDlg.m_player1name);
	}
	else
	{
		ldc.TextOut(510,420,m_gameTypeDlg.m_player2name);
	}
	if(m_gameTypeDlg.m_gameType != SINGLE_PLAY_COMPUTER)
	{
		ldc.TextOut(495,360,"Click dice to roll");
	}
	
*/
	if(m_gameTypeDlg.m_gameType != SINGLE_PLAY_COMPUTER)
	{
		ldc.TextOut(495,200,"Click dice to roll");
	}
	
	ldc.TextOut(500,220,"Player Turn:");
	if(m_player_turn == PLAYER1_TURN)
	{
		ldc.TextOut(510,250,m_gameTypeDlg.m_player1name);
	}
	else
	{
		ldc.TextOut(510,250,m_gameTypeDlg.m_player2name);
	}
		
	CDC ldc1;
	CBitmap localbmp1;

	localbmp1.LoadBitmap(IDB_BITMAP_DICE + m_diceBitmapId);
	ldc1.CreateCompatibleDC(&ldc);
	ldc1.SelectObject(&localbmp1); 
	ldc.BitBlt(510,300,50,50,&ldc1,0,0,SRCCOPY);
    //ldc.BitBlt(500,450,50,50,&ldc1,0,0,SRCCOPY);
	ldc.TextOut(500,17,"First Player:");
	ldc.TextOut(510,40,m_gameTypeDlg.m_player1name);

	if(m_gameTypeDlg.m_gameType == HUMAN_HAMAN_MANUAL || 
		m_gameTypeDlg.m_gameType == HUMAN_HAMAN_COMPUTER ||
		m_gameTypeDlg.m_gameType == HUMAN_COMPUTER)
	{
		ldc.TextOut(500,87,"Second Player:");
		ldc.TextOut(510,110,m_gameTypeDlg.m_player2name);
	}
	  
	rect = GetBoardRect(m_firstPlayerPos);
	if(m_firstPlayerPos == m_secondPlayerPos)
	{
		rect.left -=13;		
		rect.right -=13;		
	}
	//CRect rect1(rect.left,rect.top,rect.right,rect.bottom);
	//dc.Ellipse(rect1);
	CRgn rgn;						 
	rgn.CreateEllipticRgn(rect.left+13, rect.top+13, rect.right-13, rect.bottom-13);	
	CRgn rgn1;						 
	rgn1.CreateEllipticRgn(530,60, 550,75);		 
	//COLORREF redcr(RGB(255,0,0));
	CBrush redbrush;
	//redbrush.CreateSolidBrush(redcr);
	redbrush.CreateSolidBrush(m_player1color);
	//CBrush brush1(redcr);
	CBrush brush1(m_player1color);
	ldc.SelectObject(&brush1);

	ldc.FillRgn(&rgn,&brush1);
	ldc.FillRgn(&rgn1,&brush1);

	//draw apply button
	if(m_sendButtonClickedFlag == 1)
	{
		ldc.SelectObject(brush);
	//	ldc.SetBkColor(bluecr);
	}
	else
	{
		ldc.SelectObject(brush1);
	//	ldc.SetBkColor(redbluecr);
	}
	//ldc.RoundRect(500,430,560,455,10,10);
	CPoint pt(10,10);
	ldc.RoundRect(m_applyButtonRect,pt);
	ldc.TextOut(510,435,"Apply");


	if(m_gameTypeDlg.m_gameType == HUMAN_HAMAN_MANUAL || 
		m_gameTypeDlg.m_gameType == HUMAN_HAMAN_COMPUTER ||
		m_gameTypeDlg.m_gameType == HUMAN_COMPUTER)
	{

		rect = GetBoardRect(m_secondPlayerPos);
		if(m_firstPlayerPos == m_secondPlayerPos)
		{
			rect.left +=13;		
			rect.right +=13;		
		}
		//CRect rect2(rect.left, rect.top, rect.right, rect.bottom);
		//dc.Ellipse(rect2);
		CRgn rgn1;						 
		rgn1.CreateEllipticRgn(rect.left+13, rect.top+13, rect.right-13, rect.bottom-13);	
		CRgn rgn2;						 
		rgn2.CreateEllipticRgn(530,130, 550,145);	
		//COLORREF bluecr(RGB(0,0,255));
		//CBrush bluebrush;
		//redbrush.CreateSolidBrush(bluecr);
		//CBrush brush2(bluecr);
		CBrush brush2(m_player2color);
		ldc.SelectObject(&brush2);
		ldc.FillRgn(&rgn1,&brush2);
		ldc.FillRgn(&rgn2,&brush2);
	}
	dc.BitBlt(0,0,600,700,&ldc,0,0,SRCCOPY);  
}
void CNetChessView::Initialize()
{
	m_mouseMoveFlag = false;
	m_moveRect =0;	
	m_player_turn = PLAYER1_TURN;

	m_timerFlag = false;
	m_squareWidth = 45;
	m_pieceSide = WHITE;
	m_blackTime = m_whiteTime = 0;
	m_startTime = time(0);
	m_movedFromRect.left = -1;
	m_movedToRect.left = -1;
	m_diceBitmapId = 0;
	m_diceClickedFlag = 0;
	//CRect rect(500,450,550,500);
    CRect rect(510,300,560,350);
	m_diceRect = rect;		 
	CRect rect1(500,430,560,455);
	m_applyButtonRect = rect1;
	m_firstPlayerPos = m_secondPlayerPos = 1;
	m_sendButtonClickedFlag = 0;				
	CString str;
	str.Format("0:0:0");	 
//	((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(3,str);
//	((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(5,str);
	m_player_turn = PLAYER1_TURN;

}
int CNetChessView::GetBitmapId(int piece_id)
{

	return -1;
}
void CNetChessView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();	 
	m_firstPlayerPos = m_secondPlayerPos = 1;
	int xstart = 10;
	int ystart = 10;
	int x,y=ystart;
	int count = 100;
	int flag = 0;
	for ( int i = 0; i < 10; i++)
	{
		x = xstart;
		for( int j = 0; j < 10; j++)
		{
			CRect rect(x,y, x+ m_squareWidth, y+m_squareWidth);

			cb[i][j].SetRect(rect);
			cb[i][j].SetPieceType(BLANK);			 
			if(flag == 0)
			{
				cb[i][j].SetPieceData(count--,NONE,BLANK,PIECE_NOT_MOVING);
			}
			else
			{
				cb[i][j].SetPieceData(count++,NONE,BLANK,PIECE_NOT_MOVING);
			}
			 
			x += m_squareWidth;
		}
		if(flag == 0)
		{
			flag = 1;
			count-=9;
		}
		else
		{
			flag = 0;
			count-=11;
		}
		y += m_squareWidth;
	}
/*	for(i=0;i<10;i++)
	for(int j=0;j<10;j++)
	{
		writeMessage("data is %d ",cb[i][j].GetPieceId());
	}*/

	
	SetTimer(PIECE_SIDE_TIMER_EVENT_ID,1000,NULL);
	 
}

void CNetChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	OnLButtonDownAction(nFlags,point);	 
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OnLButtonUpAction(nFlags,point);	 
	CView::OnLButtonUp(nFlags, point);
}

void CNetChessView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	 
	OnMouseMoveAction(nFlags,point);
	CView::OnMouseMove(nFlags, point);
}

void CNetChessView::SetShellIconData(char* data, int id)
{
	NOTIFYICONDATA nicondata;					
	nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(id,&nicondata);
}

LRESULT CNetChessView::OnMessageColorData(WPARAM wParam,LPARAM lParam)
{	 
	DrawBoard();
	return 0;
}

CString CNetChessView::GetHistoryString()
{
	return "";
}

bool CNetChessView::CheckValidMove(int x,int y)
{	
	return true;
}
 
void CNetChessView::OnLButtonDownAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_mouseMoveFlag == true)
		return;
	m_mouseMoveFlag = true;
	SetShellIconData("Snakes & Ladders by AVM RAO",NIM_DELETE);				 	 
	if(m_gameTypeDlg.m_gameType == SINGLE_PLAY_COMPUTER)		
	{
		return;
	}
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
	/*if(m_player_turn == false)
		return;*/
	/*for(int i = 0; i < 8; i++)
	{
		for( int j = 0; j < 8; j++)
		{
			CRgn rgn;
			CRect rect = cb[i][j].GetRect();
			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if(rgn.PtInRegion(point))
			{
				writeMessage("check king move%d %d",i,j);
				if(m_pieceSide == cb[i][j].GetPieceColor())
				{		 				 
					writeMessage("check king move%d %d",i,j);
					m_point.x = i; m_point.y = j;
					cb[i][j].SetPieceState(PIECE_MOVING);
			 		m_mouseMoveFlag = true;
					 
					return;	 
				}
			}
		}
	}*/
	if(m_applyButtonRect.PtInRect(point) && m_diceClickedFlag == 1)
	{
		writeMessage("point inthe apply button rect");
		if(m_player_turn == PLAYER1_TURN)
		{
			writeMessage("player 1 turn");
			m_firstPlayerPos += m_diceBitmapId;
			if(m_firstPlayerPos > 100)
			{
				m_firstPlayerPos -= m_diceBitmapId;
			}
			else if(m_firstPlayerPos == 100)
			{
				DrawBoard();
				AfxMessageBox(m_gameTypeDlg.m_player1name + " won the game");			 
				OnFileNew();
			}
			m_diceBitmapId =0;
			checkMovement(m_firstPlayerPos);
			m_player_turn = PLAYER2_TURN;
			DrawBoard();
			writeMessage("now player 2 turn");
			if(m_gameTypeDlg.m_gameType == HUMAN_COMPUTER)
			{
				writeMessage("OH, game with computer");
				int arr[100];
				getRandom(6,arr); 
				m_diceBitmapId = arr[4];		
				DrawBoard();
				Sleep(1000);
				m_secondPlayerPos += m_diceBitmapId;
				if(m_secondPlayerPos > 100)
				{
					m_secondPlayerPos -= m_diceBitmapId;
				}
				else if(m_secondPlayerPos == 100)
				{
					DrawBoard();
					AfxMessageBox(m_gameTypeDlg.m_player2name + " won the game");				 
					OnFileNew();
				}
				checkMovement(m_secondPlayerPos);

				writeMessage("the new random rumber is %d",m_diceBitmapId);
				m_player_turn = PLAYER1_TURN;
				m_diceBitmapId =0;
				DrawBoard();				
				writeMessage("now player 1 turn");
			}
		}
		else
		{
			writeMessage("player 2 turn");
			m_secondPlayerPos += m_diceBitmapId;
			if(m_secondPlayerPos > 100)
			{
				m_secondPlayerPos -= m_diceBitmapId;
			}
			else if(m_secondPlayerPos == 100)
			{
				DrawBoard();
				AfxMessageBox(m_gameTypeDlg.m_player2name + " won the game");				 
				OnFileNew();
			}
			checkMovement(m_secondPlayerPos);

			writeMessage("the new random rumber is %d",m_diceBitmapId);
			m_player_turn = PLAYER1_TURN;
			m_diceBitmapId =0;
			DrawBoard();
			writeMessage("now player 1 turn");
		}
		m_diceClickedFlag = 0;
		m_mouseMoveFlag = false;
		return;
	}
	CRgn rgn;
	rgn.CreateEllipticRgn(m_diceRect.left, m_diceRect.top, m_diceRect.right, m_diceRect.bottom);
	if(rgn.PtInRegion(point) && m_diceClickedFlag == 0 && m_gameTypeDlg.m_gameType != HUMAN_HAMAN_MANUAL)
	{
		int arr[100];
		getRandom(6,arr);
		m_diceBitmapId = arr[4];		
		writeMessage("the dice value is %d",m_diceBitmapId);
		m_diceClickedFlag = 1;
		//m_player_turn = false;
	}
	/*CRgn rgn;
	rgn.CreateEllipticRgn(m_diceRect.left, m_diceRect.top, m_diceRect.right, m_diceRect.bottom);
	if(rgn.PtInRegion(point))
	{
		m_moveRect =0;
		CRgn rgn;
		rgn.CreateEllipticRgn(m_diceRect.left, m_diceRect.top, m_diceRect.right, m_diceRect.bottom);
		if(rgn.PtInRegion(point))
		{
			int arr[100];
			getRandom(6,arr);
			m_diceBitmapId = arr[4];
			m_firstPlayerPos += m_diceBitmapId;
			if(m_firstPlayerPos > 100)
			{
				m_firstPlayerPos -= m_diceBitmapId;
			}
			else if(m_firstPlayerPos == 100)
			{
				DrawBoard();
				AfxMessageBox(m_gameTypeDlg.m_player1name + " won the game");			 
				OnFileNew();
			}
			checkMovement(m_firstPlayerPos);
			DrawBoard();
			m_player_turn = false;
			 
			
			Sleep(1000);
			if(m_gameTypeDlg.m_gameType == HUMAN_COMPUTER)
			{
				getRandom(6,arr); 
				m_diceBitmapId = arr[4];		
				DrawBoard();
				Sleep(1000);
				m_secondPlayerPos += m_diceBitmapId;
				if(m_secondPlayerPos > 100)
				{
					m_secondPlayerPos -= m_diceBitmapId;
				}
				else if(m_secondPlayerPos == 100)
				{
					DrawBoard();
					AfxMessageBox(m_gameTypeDlg.m_player2name + " won the game");				 
					OnFileNew();
				}
				checkMovement(m_secondPlayerPos);

				writeMessage("the new random rumber is %d",m_diceBitmapId);
				m_player_turn = true;
				DrawBoard();
			}
			else
			{
				m_player_turn = true;;
			}
		}
		m_mouseMoveFlag = false;
		m_point.x = m_point.y = -1;
		DrawBoard();	 
	}	*/
	m_mouseMoveFlag = false;
	m_point.x = m_point.y = -1;
	DrawBoard();	 
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUpAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_mouseMoveFlag == false)
	{	 
		return;
	}	 
	 
}

void CNetChessView::OnMouseMoveAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
}


void CNetChessView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
		
	CView::OnRButtonDown(nFlags, point);
}

void CNetChessView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	DrawBoard();
	CView::OnPrint(pDC, pInfo);
}

void CNetChessView::OnTimer(UINT nIDEvent) 
{
	static int state=1;	 
	switch(nIDEvent)
	{
		case SHELL_ICON_TIMER_EVENT_ID:
			{				
				NOTIFYICONDATA nicondata;
				char data[64] = "Snakes & Ladders by AVM RAO";
				 
				nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
				nicondata.uID = 10;
				nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
				nicondata.cbSize = sizeof(nicondata);
				nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
				nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
				strcpy(nicondata.szTip,data);				
				if(state == 1)
				{
					nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
					Shell_NotifyIcon(NIM_MODIFY,&nicondata);
					state = 0;
				}
				else
				{
					nicondata.hIcon = AfxGetApp()->LoadIcon(IDI_ICON_MAINFRAME_OPPOSITE);
					state = 1;
					Shell_NotifyIcon(NIM_MODIFY,&nicondata);
				}
			}
			break;
		
		default:
			break;
		 
	}
	CView::OnTimer(nIDEvent);
}
void CNetChessView::KillTimerEvent()
{	 
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
}

void CNetChessView::OnFileNew() 
{
	m_blackTime = m_whiteTime = 0;
	m_startTime = time(0);	 
//	m_gameTypeDlg.DoModal();
	OnFileNewAction();  	
}
void CNetChessView::OnFileNewAction()
{
	Initialize();
	OnInitialUpdate();	
	DrawBoard();
}

void CNetChessView::OnHelpHowtoplay() 
{
	CString helpMsg;
	helpMsg = "Snakes and Ladders, as the name suggest, one has to reach HOME from START by crossing SNAKES and going through LADDERS\n"
		"Click on the dice to roll and play\n"
		"You can play three types of Snakes and Ladders\n"
		"1-Play with Computer\n"
		"2-Play with your friend - with computer dice(click on dice and then click on appply for each turn\n"
		"3-Play with your friend - with manual dice entry(press 1 to 6 on the keyboard and click apply for each turn\n"
		"\nOther features are:-----\n"		
		"\"View->Hide\" - will hide the current board and an icon will be placed in the system tray. "
		"\"Edit->GameType\" - Select the game type, by default the game play type is bewteen Human and computer\n"
		"On clicking on icon, the hidden board will be displayed\n\n"		
		"Enjoy the game!!!";  
		AfxMessageBox(helpMsg);
	// TODO: Add your command handler code here*/ 
	//::WinHelp(this->GetSafeHwnd(),"NetChess.hlp",HELP_CONTENTS,0);	 
	
}
void CNetChessView::SetPieceSide(COLOR_TYPE pieceside)
{
	m_pieceSide = pieceside;
	/*if(m_pieceSide == WHITE)
	{
		m_player_turn = true;
	
		//((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(1,"WHITE");				 
	}
	else
	{
		m_player_turn = false;	
	//((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(1,"BLACK");				 
	}*/
	m_blackTime = m_whiteTime = 0;
	m_startTime = time(0);
	DrawBoard();
}

COLOR_TYPE CNetChessView::GetPlayerSide()
{
	return m_pieceSide;
}




void CNetChessView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	 
	CView::OnRButtonUp(nFlags, point);
}



void CNetChessView::SetMoveHistory()
{
}

CRect CNetChessView::GetBoardRect(int id)
{
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	{
		if(cb[i][j].GetPieceId() == id)
		{
			return cb[i][j].GetRect();
		}
	}
	CRect rect(0,0,0,0);
	return rect;
}

void CNetChessView::GetMoveHistory()
{	
	

}
void CNetChessView::checkMovement(int &playerpos)
{
	for(int i=0;i<12;i++)
	{
		if(m_snakes[i][0] == playerpos)
		{
			for(int j=0;j<12;j++)
			{
				if(m_snakes[i][j] == 0)
					return;
				playerpos = m_snakes[i][j];
				DrawBoard();
				Sleep(500);
				MSG msg;
				while(PeekMessage(&msg,this->GetSafeHwnd(),WM_LBUTTONDOWN,WM_LBUTTONDOWN,PM_REMOVE)!=0);
			}			
		}
	}
	for(i=0;i<11;i++)
	{
		if(m_ladders[i][0] == playerpos)
		{
			for(int j=0;j<8;j++)
			{
				if(m_ladders[i][j] == 0)
					return;
				playerpos = m_ladders[i][j];
				DrawBoard();
				Sleep(500);
				MSG msg;								
				while(PeekMessage(&msg,this->GetSafeHwnd(),WM_LBUTTONDOWN,WM_LBUTTONDOWN,PM_REMOVE)!=0);
			}			
			return;
		}
	}
}

void writeMessage(char *str,...)
{
#ifdef _DEBUG
	char arr[9999];
	 va_list va;     
     va_start(va,str);
     vsprintf(arr,str,va);       
	 FILE* fp=fopen(".\\data.dat","a+");
	 fprintf(fp,"%s\n",arr);
	 fclose(fp);
#endif
}


void CNetChessView::OnEditGametype() 
{
	// TODO: Add your command handler code here
	m_gameTypeDlg.DoModal();
	DrawBoard();
}

void CNetChessView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default	
	if(nChar >='1' && nChar <='6' && m_gameTypeDlg.m_gameType == HUMAN_HAMAN_MANUAL && m_diceClickedFlag == 0)
	{
		writeMessage("dice manual entry");
		m_diceClickedFlag = 1;
		m_mouseMoveFlag = false;
		m_diceBitmapId = nChar-'1'+1;		
		DrawBoard();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CNetChessView::OnEditPlayer1color() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_player1color= dlg.GetColor();
	}
	DrawBoard();
}

void CNetChessView::OnEditPlayer2color() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_player2color= dlg.GetColor();
	}
	DrawBoard();
}
