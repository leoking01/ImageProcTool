// ImageProcPlatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcTool.h"
#include "ImageProcPlatDlg.h"
#include "afxdialogex.h"


// ImageProcPlatDlg 对话框

IMPLEMENT_DYNAMIC(ImageProcPlatDlg, CDialogEx)

ImageProcPlatDlg::ImageProcPlatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ImageProcPlatDlg::IDD, pParent)
{

}

ImageProcPlatDlg::~ImageProcPlatDlg()
{
}

void ImageProcPlatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageProcPlatDlg, CDialogEx)
	ON_COMMAND(ID_32773, &ImageProcPlatDlg::On32773_openImageFile)
	ON_COMMAND(ID_32774, &ImageProcPlatDlg::On32774_toGray)
	ON_UPDATE_COMMAND_UI(ID_32774, &ImageProcPlatDlg::OnUpdate32774_OnUpdate__On32774_toGray)
	ON_COMMAND(ID_32775, &ImageProcPlatDlg::On32775_toColor)
	ON_COMMAND(ID_32776, &ImageProcPlatDlg::On32776_saveImageToFile)
	ON_COMMAND(ID_32777, &ImageProcPlatDlg::On32777_onExit)

END_MESSAGE_MAP()


// ImageProcPlatDlg 消息处理程序

#include "string"
void ImageProcPlatDlg::On32773_openImageFile()
{
	// TODO: 在此添加命令处理程序代码
	fetchFileName(  this->nameOfImageFile  );
	src_const = imread(  nameOfImageFile );
	if( src_const.data  )
	{
		image_current = src_const.clone();
		DrawIplImage2MFC(  image_current,  IDC_STATIC  ) ;
	}
}


void ImageProcPlatDlg::On32774_toGray()
{
	// TODO: 在此添加命令处理程序代码
	if(! (this-> image_current.data ) )
	{
		AfxMessageBox( _T( "没有当前图像数据."));
		return ;
	}
	cv::Mat res;
	if( image_current.channels() == 3 )
	{
		cvtColor(  image_current,  res, CV_BGR2GRAY );
	}
	else
	{
		res = image_current.clone();
	}
	this->image_current = res;
	if( this->image_current.data  )
	{
		DrawIplImage2MFC(  this->image_current,  IDC_STATIC  ) ;
	}
}


void ImageProcPlatDlg::On32775_toColor()
{
	// TODO: 在此添加命令处理程序代码
	cv::Mat res;
	if( this->image_current.channels() == 1 )
	{
		cvtColor(  this->image_current,   res, CV_GRAY2BGR );
	}
	else
	{
		res = src_const.clone();
	}
	this->image_current = res;
	if( this->image_current.data  )
	{
		DrawIplImage2MFC(  this->image_current,  IDC_STATIC  ) ;
	}
}


void ImageProcPlatDlg::On32776_saveImageToFile()
{
	// TODO: 在此添加命令处理程序代码
	fetchFileName(  this->nameOfImageFileSave  );
	imwrite(  this->nameOfImageFileSave.c_str(),  image_current  );
}


void ImageProcPlatDlg::On32777_onExit()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnCancel();
}




//void CMainFrame::OnUpdate__On32774_toGray(CCmdUI* pCmdUI) //grays the menu item, as only one DialogWindow is allowed
//{
//	// TODO: Code f黵 die Befehlsbehandlungsroutine zum Aktualisieren der Benutzeroberfl鋍he hier einf黦en
//	if(CDialogWindow::IsCreated())
//		pCmdUI->Enable(FALSE);
//	else
//		pCmdUI->Enable(TRUE);
//}



void ImageProcPlatDlg::OnUpdate32774_OnUpdate__On32774_toGray(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
		if(   !( this->image_current.data  ) )
			pCmdUI->Enable(FALSE);
		else
			pCmdUI->Enable(TRUE);
}
