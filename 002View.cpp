// 002View.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "002View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C002View

IMPLEMENT_DYNCREATE(C002View, CListView)

C002View::C002View()
{
}

C002View::~C002View()
{
}


BEGIN_MESSAGE_MAP(C002View, CListView)
	//{{AFX_MSG_MAP(C002View)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C002View drawing

void C002View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// C002View diagnostics

#ifdef _DEBUG
void C002View::AssertValid() const
{
	CListView::AssertValid();
}

void C002View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
CImageProcToolDoc* C002View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcToolDoc)));
	return (CImageProcToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C002View message handlers

BOOL C002View::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |=	LVS_REPORT |
				LVS_SHOWSELALWAYS | 
				LVS_SINGLESEL;
	return CListView::PreCreateWindow(cs);
}

void C002View::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	CListCtrl* pctlList=&GetListCtrl();

	LVCOLUMN	lvc={0};
	char buf[128]={0};
	lvc.pszText=   LPWSTR ( (char*)buf  ); 

	lvc.mask=LVCF_FMT|LVCF_TEXT|LVCF_SUBITEM|LVCF_WIDTH;

	lvc.fmt=LVCFMT_LEFT;
	lvc.iSubItem=0;
	lvc.cx=50;
	lstrcpyn( LPWSTR (buf), CString("left") ,sizeof(buf));
	pctlList->InsertColumn(lvc.iSubItem,&lvc);

	lvc.fmt=LVCFMT_CENTER;
	lvc.iSubItem++;
	lvc.cx=100;
	lstrcpyn(   LPWSTR (buf), CString("center"),sizeof(buf));
	pctlList->InsertColumn(lvc.iSubItem,&lvc);
	
	lvc.fmt=LVCFMT_RIGHT;
	lvc.iSubItem++;
	lvc.cx=150;
	lstrcpyn(  LPWSTR (buf), CString("right"),sizeof(buf));
	pctlList->InsertColumn(lvc.iSubItem,&lvc);

	LVITEM	lvi={0};
	lvi.mask=LVIF_TEXT;
	lvi.pszText=  LPWSTR( (char*)buf );

	lvi.iItem=0;
	lvi.iSubItem=0;
	lstrcpyn(   LPWSTR (buf), CString("left-1"),sizeof(buf));
	pctlList->InsertItem(&lvi);

	lvi.iSubItem++;
	lstrcpyn(  LPWSTR (buf) ,CString("center-1" ),sizeof(buf));
	pctlList->SetItem(&lvi);

	lvi.iSubItem++;
	lstrcpyn(   LPWSTR (buf)  ,CString("right-1"),sizeof(buf));
	pctlList->SetItem(&lvi);

	lvi.iItem++;
	lvi.iSubItem=0;
	lstrcpyn(   LPWSTR (buf)  , CString("left-2" ),sizeof(buf));
	pctlList->InsertItem(&lvi);

	lvi.iSubItem++;
	lstrcpyn(   LPWSTR (buf) ,CString("center-2"),sizeof(buf));
	pctlList->SetItem(&lvi);

	lvi.iSubItem++;
	lstrcpyn(   LPWSTR (buf), CString("right-2"),sizeof(buf));
	pctlList->SetItem(&lvi);
}

int C002View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	DWORD dwStyle = SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)dwStyle);
	
	return 0;
}
