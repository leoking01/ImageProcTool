#pragma once



// C004View 窗体视图

class C004View : public CFormView
{
	DECLARE_DYNCREATE(C004View)

protected:
	C004View();           // 动态创建所使用的受保护的构造函数
	virtual ~C004View();

public:
	enum { IDD = IDD_VISIONPLATFORM_FORM };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


