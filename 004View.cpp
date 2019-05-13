// C004View.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "004View.h"


// C004View

IMPLEMENT_DYNCREATE(C004View, CFormView)

C004View::C004View()
	: CFormView(C004View::IDD)
{

}

C004View::~C004View()
{
}

void C004View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C004View, CFormView)
END_MESSAGE_MAP()


// C004View 诊断

#ifdef _DEBUG
void C004View::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void C004View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// C004View 消息处理程序
