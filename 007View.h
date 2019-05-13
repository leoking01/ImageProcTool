#if !defined(AFX_007VIEW_H__0865C322_DA15_4A84_BA6E_B56A1A0A9D65__INCLUDED_)
#define AFX_007VIEW_H__0865C322_DA15_4A84_BA6E_B56A1A0A9D65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 007View.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// C007View view
#include <afxcview.h>
class C007View : public CListView
{
protected:
	C007View();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(C007View)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C007View)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~C007View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(C007View)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_007VIEW_H__0865C322_DA15_4A84_BA6E_B56A1A0A9D65__INCLUDED_)
