#if !defined(AFX_005VIEW_H__42258922_9B9A_4BD2_BDE2_95C1C35ADD0B__INCLUDED_)
#define AFX_005VIEW_H__42258922_9B9A_4BD2_BDE2_95C1C35ADD0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 005View.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// C005View view

class C005View : public CEditView
{
protected:
	C005View();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(C005View)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C005View)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~C005View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(C005View)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_005VIEW_H__42258922_9B9A_4BD2_BDE2_95C1C35ADD0B__INCLUDED_)
