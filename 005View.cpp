// 005View.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "005View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C005View

IMPLEMENT_DYNCREATE(C005View, CEditView)

C005View::C005View()
{
}

C005View::~C005View()
{
}


BEGIN_MESSAGE_MAP(C005View, CEditView)
	//{{AFX_MSG_MAP(C005View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C005View drawing

void C005View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// C005View diagnostics

#ifdef _DEBUG
void C005View::AssertValid() const
{
	CEditView::AssertValid();
}

void C005View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C005View message handlers
