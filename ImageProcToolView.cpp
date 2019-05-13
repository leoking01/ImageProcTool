
// ImageProcToolView.cpp : CImageProcToolView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CImageProcToolView ����/����

CImageProcToolView::CImageProcToolView()
	: CFormView(CImageProcToolView::IDD)
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CImageProcToolView ���

#ifdef _DEBUG
void CImageProcToolView::AssertValid() const
{
	CFormView::AssertValid();
}

void CImageProcToolView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CImageProcToolDoc* CImageProcToolView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcToolDoc)));
	return (CImageProcToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcToolView ��Ϣ�������
