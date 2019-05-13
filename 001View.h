// 001View.h : interface of the C001View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_001VIEW_H__E59FEFE7_63B5_4F0D_9D5D_03FB71D31430__INCLUDED_)
#define AFX_001VIEW_H__E59FEFE7_63B5_4F0D_9D5D_03FB71D31430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImageProcToolDoc.h"

class C001View : public CEditView
{
protected: // create from serialization only
	C001View();
	DECLARE_DYNCREATE(C001View)

// Attributes
public:
	CImageProcToolDoc * GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C001View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~C001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(C001View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 001View.cpp
inline CSpltDoc* C001View::GetDocument()
   { return (CSpltDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_001VIEW_H__E59FEFE7_63B5_4F0D_9D5D_03FB71D31430__INCLUDED_)
