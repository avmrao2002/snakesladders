; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetChessView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetChess.h"
LastPage=0

ClassCount=18
Class1=CNetChessApp
Class2=CNetChessDoc
Class3=CNetChessView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CServerSocket
Class7=CClientSocket
Resource2=IDR_SHELL_MENU
Class8=COptions
Class9=CServerInfoDlg
Class10=CMessageSend
Class11=CHistoryDlg
Class12=CMyColorDialog
Class13=CPickPieceDlg
Class14=CPropertiesDlg
Class15=CAcceptDlg
Class16=CLostPieceDlg
Class17=CDemo
Resource3=IDD_ABOUTBOX
Class18=CGameType
Resource4=IDD_DIALOG_GAMETYPE

[CLS:CNetChessApp]
Type=0
HeaderFile=NetChess.h
ImplementationFile=NetChess.cpp
Filter=N

[CLS:CNetChessDoc]
Type=0
HeaderFile=NetChessDoc.h
ImplementationFile=NetChessDoc.cpp
Filter=N

[CLS:CNetChessView]
Type=0
HeaderFile=NetChessView.h
ImplementationFile=NetChessView.cpp
Filter=C
LastObject=ID_EDIT_PLAYER2COLOR
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=AFX_ID_PREVIEW_CLOSE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=NetChess.cpp
ImplementationFile=NetChess.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_EDIT_GAMETYPE
Command4=ID_EDIT_PLAYER1COLOR
Command5=ID_EDIT_PLAYER2COLOR
Command6=ID_VIEW_HIDE
Command7=ID_APP_ABOUT
Command8=ID_HELP_HOWTOPLAY
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_VIEW_HIDE
Command2=ID_FILE_NEW
CommandCount=2

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_VIEW_HIDE
Command3=ID_APP_ABOUT
Command4=AFX_ID_PREVIEW_CLOSE
Command5=AFX_ID_PREVIEW_CLOSE
Command6=AFX_ID_PREVIEW_CLOSE
Command7=AFX_ID_PREVIEW_CLOSE
Command8=AFX_ID_PREVIEW_CLOSE
Command9=AFX_ID_PREVIEW_CLOSE
Command10=AFX_ID_PREVIEW_CLOSE
Command11=AFX_ID_PREVIEW_CLOSE
Command12=AFX_ID_PREVIEW_CLOSE
Command13=AFX_ID_PREVIEW_CLOSE
Command14=AFX_ID_PREVIEW_CLOSE
Command15=AFX_ID_PREVIEW_CLOSE
Command16=AFX_ID_PREVIEW_CLOSE
Command17=AFX_ID_PREVIEW_CLOSE
Command18=AFX_ID_PREVIEW_CLOSE
Command19=AFX_ID_PREVIEW_CLOSE
CommandCount=19

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CServerSocket
VirtualFilter=q

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=q

[CLS:COptions]
Type=0
HeaderFile=Options.h
ImplementationFile=Options.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATIC_PIECE_TYPE3
VirtualFilter=dWC

[CLS:CServerInfoDlg]
Type=0
HeaderFile=ServerInfoDlg.h
ImplementationFile=ServerInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[CLS:CMessageSend]
Type=0
HeaderFile=MessageSend.h
ImplementationFile=MessageSend.cpp
BaseClass=CDialog
Filter=D
LastObject=CMessageSend
VirtualFilter=dWC

[CLS:CHistoryDlg]
Type=0
HeaderFile=HistoryDlg.h
ImplementationFile=HistoryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHistoryDlg

[CLS:CMyColorDialog]
Type=0
HeaderFile=MyColorDialog.h
ImplementationFile=MyColorDialog.cpp
BaseClass=CColorDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyColorDialog

[CLS:CPickPieceDlg]
Type=0
HeaderFile=PickPieceDlg.h
ImplementationFile=PickPieceDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPickPieceDlg
VirtualFilter=dWC

[MNU:IDR_SHELL_MENU]
Type=1
Class=?
Command1=ID_SHELL_CLOSE
Command2=ID_SHELL_VIEW
CommandCount=2

[CLS:CPropertiesDlg]
Type=0
HeaderFile=PropertiesDlg.h
ImplementationFile=PropertiesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[CLS:CAcceptDlg]
Type=0
HeaderFile=AcceptDlg.h
ImplementationFile=AcceptDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAcceptDlg

[CLS:CLostPieceDlg]
Type=0
HeaderFile=LostPieceDlg.h
ImplementationFile=LostPieceDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[CLS:CDemo]
Type=0
HeaderFile=Demo.h
ImplementationFile=Demo.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[DLG:IDD_DIALOG_GAMETYPE]
Type=1
Class=CGameType
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_HC,button,1342177289
Control4=IDC_RADIO_HH,button,1342177289
Control5=IDC_EDIT_PLAYER1NAME,edit,1350631552
Control6=IDC_EDIT_PLAYER2NAME,edit,1484849280
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_RADIO_HHM,button,1342177289

[CLS:CGameType]
Type=0
HeaderFile=GameType.h
ImplementationFile=GameType.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

