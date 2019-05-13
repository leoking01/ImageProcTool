// 004View.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "006View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C006View

IMPLEMENT_DYNCREATE(C006View, CFormView)

C006View::C006View()
	: CFormView(C006View::IDD)
{
	//{{AFX_DATA_INIT(C006View)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

C006View::~C006View()
{
}

void C006View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C006View)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C006View, CFormView)
	//{{AFX_MSG_MAP(C006View)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C006View diagnostics

#ifdef _DEBUG
void C006View::AssertValid() const
{
	CFormView::AssertValid();
}

void C006View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
CImageProcToolDoc   * C006View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcToolDoc)));
	return (CImageProcToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C006View message handlers

void C006View::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
}

void C006View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CFormView::OnLButtonUp(nFlags, point);
}
