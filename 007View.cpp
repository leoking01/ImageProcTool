// 007View.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "007View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C007View

IMPLEMENT_DYNCREATE(C007View, CListView)

C007View::C007View()
{
}

C007View::~C007View()
{
}


BEGIN_MESSAGE_MAP(C007View, CListView)
	//{{AFX_MSG_MAP(C007View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C007View drawing

void C007View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// C007View diagnostics

#ifdef _DEBUG
void C007View::AssertValid() const
{
	CListView::AssertValid();
}

void C007View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C007View message handlers
