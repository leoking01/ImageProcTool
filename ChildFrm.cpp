
// ChildFrm.cpp : CChildFrame 类的实现
//

#include "stdafx.h"
#include "ImageProcTool.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO: 在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}

//BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
//{
//	return m_wndSplitter.Create(this,
//		2, 2,			// TODO: 调整行数和列数
//		CSize(10, 10),	// TODO: 调整最小窗格大小
//		pContext);
//}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 消息处理程序





BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	BOOL ret=m_wndSplitter.CreateStatic(this,3,2);
	if(!ret)
	{
		TRACE("SplitCreate Failed...\n");
		return ret;
	}

	//计算窗口尺寸
	CRect rt;
	GetClientRect(&rt);
	CSize czPane(rt.Width()/2, rt.Height()/3);


	//创建接收数据显示窗口
	pContext->m_pCurrentFrame=this;
	ret=m_wndSplitter.CreateView(
		0,0,
		RUNTIME_CLASS(C001View),
		czPane,
		pContext);
	if(!ret)
	{
		TRACE("SplitCreateView Failed(1)...\n");
		return ret;
	}

	//创建发送数据显示窗口
	pContext->m_pCurrentFrame=this;
	ret=m_wndSplitter.CreateView(
		0,1,
		RUNTIME_CLASS(C002View),
		czPane,
		pContext);
	if(!ret)
	{
		TRACE("Split CreateView Failed(2)...\n");
		return ret;
	}

	//创建调试数据显示窗口
	pContext->m_pCurrentFrame=this;
	ret=m_wndSplitter.CreateView(
		1,0,
		RUNTIME_CLASS(C003View),
		czPane,
		pContext);
	//
	pContext->m_pCurrentFrame=this;
	ret=m_wndSplitter.CreateView(
		1,1,
		RUNTIME_CLASS(C004View),
		czPane,
		pContext);

	//
	pContext->m_pCurrentFrame=this;
	ret=m_wndSplitter.CreateView(
		2,0,
		RUNTIME_CLASS(C005View),
		czPane,
		pContext);
	//
	pContext->m_pCurrentFrame=this;
	ret=m_wndSplitter.CreateView(
		2,1,
		RUNTIME_CLASS(C006View),
		//RUNTIME_CLASS(C007View),
		czPane,
		pContext);
	if(!ret)
	{
		TRACE("Split CreateView Failed(3)...\n");
		return ret;
	}


	//初始化窗口
	m_wndSplitter.RecalcLayout();	
	m_wndSplitter.SetActivePane(1,0);
	return ret;
}



