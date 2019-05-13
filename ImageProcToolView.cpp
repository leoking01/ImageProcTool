
// ImageProcToolView.cpp : CImageProcToolView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ImageProcTool.h"
#endif

#include "ImageProcToolDoc.h"
#include "ImageProcToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcToolView

IMPLEMENT_DYNCREATE(CImageProcToolView, CFormView)

BEGIN_MESSAGE_MAP(CImageProcToolView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CImageProcToolView 构造/析构

CImageProcToolView::CImageProcToolView()
	: CFormView(CImageProcToolView::IDD)
{
	// TODO: 在此处添加构造代码

}

CImageProcToolView::~CImageProcToolView()
{
}

void CImageProcToolView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CImageProcToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CImageProcToolView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();

}

void CImageProcToolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcToolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcToolView 诊断

#ifdef _DEBUG
void CImageProcToolView::AssertValid() const
{
	CFormView::AssertValid();
}

void CImageProcToolView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CImageProcToolDoc* CImageProcToolView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcToolDoc)));
	return (CImageProcToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcToolView 消息处理程序
