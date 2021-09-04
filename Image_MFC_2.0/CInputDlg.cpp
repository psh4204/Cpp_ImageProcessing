// CInputDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImagePSH.h"
#include "afxdialogex.h"
#include "CInputDlg.h"


// CInputDlg 대화 상자

IMPLEMENT_DYNAMIC(CInputDlg, CDialog)

CInputDlg::CInputDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_INPUT1, pParent)
	, m_input1(0)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VALUE1, m_input1);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
END_MESSAGE_MAP()


// CInputDlg 메시지 처리기
