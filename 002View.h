#if !defined(AFX_002VIEW_H__8C0B9C04_831E_43E0_9952_BD9B843AB074__INCLUDED_)
#define AFX_002VIEW_H__8C0B9C04_831E_43E0_9952_BD9B843AB074__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 002View.h : header file
//

#include "ImageProcToolDoc.h"

#include <afxcview.h>

/////////////////////////////////////////////////////////////////////////////
// C002View view

class C002View : public CListView
{
protected:
	C002View();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(C002View)

// Attributes
public:
	CImageProcToolDoc* GetDocument();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C002View)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~C002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(C002View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in 001View.cpp
inline CSpltDoc* C002View::GetDocument()
   { return (CSpltDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_002VIEW_H__8C0B9C04_831E_43E0_9952_BD9B843AB074__INCLUDED_)
