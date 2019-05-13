// 001View.cpp : implementation of the C001View class
//

#include "stdafx.h"
#include "ImageProcTool.h"

#include "ImageProcToolDoc.h"
#include "001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C001View

IMPLEMENT_DYNCREATE(C001View, CEditView)

BEGIN_MESSAGE_MAP(C001View, CEditView)
	//{{AFX_MSG_MAP(C001View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C001View construction/destruction

C001View::C001View()
{
	// TODO: add construction code here

}

C001View::~C001View()
{
}

BOOL C001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CEditView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// C001View drawing

void C001View::OnDraw(CDC* pDC)
{
	CImageProcToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// C001View printing

BOOL C001View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void C001View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void C001View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// C001View diagnostics

#ifdef _DEBUG
void C001View::AssertValid() const
{
	CEditView::AssertValid();
}

void C001View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CImageProcToolDoc* C001View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcToolDoc)));
	return (CImageProcToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// C001View message handlers
