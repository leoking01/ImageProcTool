// 003View.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "003View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C003View

IMPLEMENT_DYNCREATE(C003View, CTreeView)

C003View::C003View()
{
}

C003View::~C003View()
{
}


BEGIN_MESSAGE_MAP(C003View, CTreeView)
	//{{AFX_MSG_MAP(C003View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C003View drawing

void C003View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// C003View diagnostics

#ifdef _DEBUG
void C003View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C003View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
CImageProcToolDoc* C003View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcToolDoc)));
	return (CImageProcToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C003View message handlers

BOOL C003View::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CTreeView::PreCreateWindow(cs);
}

void C003View::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl* pctlTree=&GetTreeCtrl();
	HTREEITEM	hRoot=NULL,
				hCurr=NULL,
				hChild=NULL;
#define  XXX
#ifdef  XXX
	hRoot=pctlTree->InsertItem( CString("root1" )  );
	hCurr=pctlTree->InsertItem(  CString("111111" )  ,hRoot);
	hChild=pctlTree->InsertItem(CString("111111-1" )  ,hCurr);
	hChild=pctlTree->InsertItem(CString("111111-2" )  ,hCurr);
	hChild=pctlTree->InsertItem(CString("111111-3" )  ,hCurr);
	hCurr=pctlTree->InsertItem(CString("222222" )  ,hRoot);
	hChild=pctlTree->InsertItem(CString("222222-1" )  ,hCurr);
	hChild=pctlTree->InsertItem(CString("222222-2" )  ,hCurr);
	hChild=pctlTree->InsertItem(CString("222222-3" )  ,hCurr);
#endif
}
