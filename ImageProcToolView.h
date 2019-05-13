
// ImageProcToolView.h : CImageProcToolView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CImageProcToolView : public CFormView
{
protected: // �������л�����
	CImageProcToolView();
	DECLARE_DYNCREATE(CImageProcToolView)

public:
	enum{ IDD = IDD_VISIONPLATFORM_FORM };

// ����
public:
	CImageProcToolDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CImageProcToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ImageProcToolView.cpp �еĵ��԰汾
inline CImageProcToolDoc* CImageProcToolView::GetDocument() const
   { return reinterpret_cast<CImageProcToolDoc*>(m_pDocument); }
#endif

