
// JOBDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
struct JCB
{
	CString name;          //��ҵ��
	int atime;         //��ҵ����ʱ��
	int stime;         //��ҵ����ʱ��
	int right;         //��ҵ����Ȩ
	int btime;         //��ҵ��ʼʱ��
	int ftime;         //��ҵ���ʱ��
	int total;         //��תʱ��
	double weight;     //��Ȩ��תʱ�䣨��תϵ����
	int fstate;        //��ҵ�Ƿ���ɣ�0Ϊ��1Ϊ�ǣ�
	double RP;         //��Ӧ�� 
};

// CJOBDlg �Ի���
class CJOBDlg : public CDialogEx
{
// ����
public:
	CJOBDlg(CWnd* pParent = NULL);	// ��׼���캯��
	struct JCB job[5];
// �Ի�������
	enum { IDD = IDD_JOB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
