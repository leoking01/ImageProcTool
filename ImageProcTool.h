
// ImageProcTool.h : ImageProcTool Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CImageProcToolApp:
// �йش����ʵ�֣������ ImageProcTool.cpp
//

class CImageProcToolApp : public CWinAppEx
{
public:
	CImageProcToolApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	
	afx_msg void On32771_lanchImageProcessingPlat();
	afx_msg void On32772_lanchImageProcessingPlatTool();
	afx_msg void On32778_studyGA();
};

extern CImageProcToolApp theApp;
