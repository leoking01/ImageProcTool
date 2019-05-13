
// ChildFrm.h : CChildFrame 类的接口
//

#pragma once

#include "001view.h"
#include "002view.h"
#include "003view.h"
#include "006view.h"
#include "005view.h"
#include "007view.h"
#include "004View.h"


//#include "ImageProcTool.h"



class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// 特性
protected:
	CSplitterWndEx m_wndSplitter;
public:

// 操作
public:

// 重写
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

//public:
//	CSplitterWnd    m_wndSplitter;
//

};
