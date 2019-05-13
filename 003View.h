#if !defined(AFX_003VIEW_H__8016A17A_97F1_494F_AB77_E041D4CEC3B7__INCLUDED_)
#define AFX_003VIEW_H__8016A17A_97F1_494F_AB77_E041D4CEC3B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 003View.h : header file
//

#include "ImageProcToolDoc.h"
#include <afxcview.h>

/////////////////////////////////////////////////////////////////////////////
// C003View view

class C003View : public CTreeView
{
protected:
	C003View();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(C003View)

// Attributes
public:
	CImageProcToolDoc* GetDocument();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C003View)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~C003View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(C003View)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in 001View.cpp
inline CSpltDoc* C003View::GetDocument()
   { return (CSpltDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_003VIEW_H__8016A17A_97F1_494F_AB77_E041D4CEC3B7__INCLUDED_)
