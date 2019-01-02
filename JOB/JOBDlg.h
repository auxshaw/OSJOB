
// JOBDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
struct JCB
{
	CString name;          //作业名
	int atime;         //作业到达时间
	int stime;         //作业服务时间
	int right;         //作业优先权
	int btime;         //作业开始时间
	int ftime;         //作业完成时间
	int total;         //周转时间
	double weight;     //带权周转时间（周转系数）
	int fstate;        //作业是否完成（0为否，1为是）
	double RP;         //响应比 
};

// CJOBDlg 对话框
class CJOBDlg : public CDialogEx
{
// 构造
public:
	CJOBDlg(CWnd* pParent = NULL);	// 标准构造函数
	struct JCB job[5];
// 对话框数据
	enum { IDD = IDD_JOB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list1;
	int a_atime;
	int a_stime;
	int b_atime;
	int c_atime;
	int d_atime;
	int e_atime;
	int b_stime;
	int c_stime;
	int d_stime;
	int e_stime;
	double avg_total;
	double avg_weight;
	afx_msg void OnBnClickedButton1();
	int a_right;
	int b_right;
	int c_right;
	int d_right;
	int e_right;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
