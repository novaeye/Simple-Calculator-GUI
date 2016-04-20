
// SimpleCalculatorDlg.h : header file
//

#pragma once


// CSimpleCalculatorDlg dialog
class CSimpleCalculatorDlg : public CDialogEx
{
// Construction
public:
	CSimpleCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIMPLECALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support



// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_EchoText;
	CString expression;
public:
	afx_msg void OnBnClickedBtnSeven();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnCalculate();
	afx_msg void OnBnClickedBtnEight();
	afx_msg void OnBnClickedBtnZero();
	afx_msg void OnBnClickedBtnDecimal();
	afx_msg void OnBnClickedBtnOne();
	afx_msg void OnBnClickedBtnFive();
	afx_msg void OnBnClickedBtnSix();
	afx_msg void OnBnClickedBtnNine();
	afx_msg void OnBnClickedBtnDivide();
	afx_msg void OnBnClickedBtnMultiply();
	afx_msg void OnBnClickedBtnOpenparan();
	afx_msg void OnBnClickedBtnCloseparan();
	afx_msg void OnBnClickedBtnTwo();
	afx_msg void OnBnClickedBtnThree();
	afx_msg void OnStnClickedEchoText();
	afx_msg void OnBnClickedBtnFour();
	afx_msg void OnBnClickedBtnSubstract();
};
