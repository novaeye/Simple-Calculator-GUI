
// SimpleCalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleCalculator.h"
#include "SimpleCalculatorDlg.h"
#include "afxdialogex.h"
#include "calculate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSimpleCalculatorDlg dialog



CSimpleCalculatorDlg::CSimpleCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimpleCalculatorDlg::IDD, pParent)
	, m_EchoText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ECHO_TEXT, m_EchoText);
}

BEGIN_MESSAGE_MAP(CSimpleCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEVEN, &CSimpleCalculatorDlg::OnBnClickedBtnSeven)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CSimpleCalculatorDlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_BACK, &CSimpleCalculatorDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_ADD, &CSimpleCalculatorDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_CALCULATE, &CSimpleCalculatorDlg::OnBnClickedBtnCalculate)
	ON_BN_CLICKED(IDC_BTN_EIGHT, &CSimpleCalculatorDlg::OnBnClickedBtnEight)
	ON_BN_CLICKED(IDC_BTN_ZERO, &CSimpleCalculatorDlg::OnBnClickedBtnZero)
	ON_BN_CLICKED(IDC_BTN_DECIMAL, &CSimpleCalculatorDlg::OnBnClickedBtnDecimal)
	ON_BN_CLICKED(IDC_BTN_ONE, &CSimpleCalculatorDlg::OnBnClickedBtnOne)
	ON_BN_CLICKED(IDC_BTN_FIVE, &CSimpleCalculatorDlg::OnBnClickedBtnFive)
	ON_BN_CLICKED(IDC_BTN_SIX, &CSimpleCalculatorDlg::OnBnClickedBtnSix)
	ON_BN_CLICKED(IDC_BTN_NINE, &CSimpleCalculatorDlg::OnBnClickedBtnNine)
	ON_BN_CLICKED(IDC_BTN_DIVIDE, &CSimpleCalculatorDlg::OnBnClickedBtnDivide)
	ON_BN_CLICKED(IDC_BTN_MULTIPLY, &CSimpleCalculatorDlg::OnBnClickedBtnMultiply)
	ON_BN_CLICKED(IDC_BTN_OPENPARAN, &CSimpleCalculatorDlg::OnBnClickedBtnOpenparan)
	ON_BN_CLICKED(IDC_BTN_CLOSEPARAN, &CSimpleCalculatorDlg::OnBnClickedBtnCloseparan)
	ON_BN_CLICKED(IDC_BTN_TWO, &CSimpleCalculatorDlg::OnBnClickedBtnTwo)
	ON_BN_CLICKED(IDC_BTN_THREE, &CSimpleCalculatorDlg::OnBnClickedBtnThree)
	ON_BN_CLICKED(IDC_BTN_FOUR, &CSimpleCalculatorDlg::OnBnClickedBtnFour)
	ON_BN_CLICKED(IDC_BTN_SUBSTRACT, &CSimpleCalculatorDlg::OnBnClickedBtnSubstract)
END_MESSAGE_MAP()


// CSimpleCalculatorDlg message handlers

BOOL CSimpleCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	expression = "";

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimpleCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimpleCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimpleCalculatorDlg::OnBnClickedBtnSeven()
{
		expression += "7";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);

}


void CSimpleCalculatorDlg::OnBnClickedBtnClear()
{
	expression = "";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnBack()
{
	int i = expression.GetLength()-1;
	expression.Delete(i);
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnAdd()
{
	expression += "+";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}



void CSimpleCalculatorDlg::OnBnClickedBtnCalculate()
{
	Calculator c;
	int x;
	double d = c.toPostfix(expression, x);
	if (x == 1)
	{
		m_EchoText.Format(_T("%.8g"), d);
		expression = "";
		//CString str;
		//str.Format(_T("%.8g"), d);
		//expression = str;
		UpdateData(FALSE);
	}
	else if (x == 0)
	{
		m_EchoText.Format(_T("%s"), CString("Invalid input"));
		expression = "";
		UpdateData(FALSE);
	}
	else if (x == -1)
	{
		m_EchoText.Format(_T("%s"), CString("Cannot divide by zero"));
		expression = "";
		UpdateData(FALSE);
	}
	else if (x == 2)
	{
		m_EchoText.Format(_T("%s"), CString("Too lengthy expression!!!"));
		expression = "";
		UpdateData(FALSE);
	}
	else if (x == 3)
	{
		m_EchoText.Format(_T("%s"), CString("You have entered a too lengthy number!!!"));
		expression = "";
		UpdateData(FALSE);
	}
}


void CSimpleCalculatorDlg::OnBnClickedBtnEight()
{	
		expression += "8";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnZero()
{
		expression += "0";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnDecimal()
{
		expression += ".";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnOne()
{
		expression += "1";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnFive()
{
		expression += "5";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnSix()
{
		expression += "6";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnNine()
{
		expression += "9";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnDivide()
{
	expression += "/";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnMultiply()
{
	expression += "*";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnOpenparan()
{
	expression += "(";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnCloseparan()
{
	expression += ")";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnTwo()
{
		expression += "2";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);

}


void CSimpleCalculatorDlg::OnBnClickedBtnThree()
{
		expression += "3";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnFour()
{
		expression += "4";
		m_EchoText.Format(_T("%s"), expression);
		UpdateData(FALSE);
}


void CSimpleCalculatorDlg::OnBnClickedBtnSubstract()
{
	expression += "-";
	m_EchoText.Format(_T("%s"), expression);
	UpdateData(FALSE);
}
