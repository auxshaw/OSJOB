
// JOBDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JOB.h"
#include "JOBDlg.h"
#include "afxdialogex.h"
#include<Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CJOBDlg 对话框



CJOBDlg::CJOBDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJOBDlg::IDD, pParent)
	, a_atime(0)
	, a_stime(3)
	, b_atime(1)
	, c_atime(2)
	, d_atime(3)
	, e_atime(4)
	, b_stime(5)
	, c_stime(2)
	, d_stime(1)
	, e_stime(4)
	, avg_total(0)
	, avg_weight(0)
	, a_right(1)
	, b_right(1)
	, c_right(1)
	, d_right(1)
	, e_right(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJOBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_EDIT1, a_atime);
	DDV_MinMaxInt(pDX, a_atime, 0, 1024);
	DDX_Text(pDX, IDC_EDIT6, a_stime);
	DDV_MinMaxInt(pDX, a_stime, 1, 1024);
	DDX_Text(pDX, IDC_EDIT2, b_atime);
	DDV_MinMaxInt(pDX, b_atime, 0, 1024);
	DDX_Text(pDX, IDC_EDIT3, c_atime);
	DDV_MinMaxInt(pDX, c_atime, 0, 1024);
	DDX_Text(pDX, IDC_EDIT4, d_atime);
	DDV_MinMaxInt(pDX, d_atime, 0, 1024);
	DDX_Text(pDX, IDC_EDIT5, e_atime);
	DDV_MinMaxInt(pDX, e_atime, 0, 1024);
	DDX_Text(pDX, IDC_EDIT7, b_stime);
	DDV_MinMaxInt(pDX, b_stime, 1, 1024);
	DDX_Text(pDX, IDC_EDIT8, c_stime);
	DDV_MinMaxInt(pDX, c_stime, 1, 1024);
	DDX_Text(pDX, IDC_EDIT9, d_stime);
	DDV_MinMaxInt(pDX, d_stime, 1, 1024);
	DDX_Text(pDX, IDC_EDIT10, e_stime);
	DDV_MinMaxInt(pDX, e_stime, 1, 1024);
	DDX_Text(pDX, IDC_EDIT11, avg_total);
	DDX_Text(pDX, IDC_EDIT12, avg_weight);
	DDX_Text(pDX, IDC_EDIT13, a_right);
	DDV_MinMaxInt(pDX, a_right, 1, 1024);
	DDX_Text(pDX, IDC_EDIT14, b_right);
	DDV_MinMaxInt(pDX, b_right, 1, 1024);
	DDX_Text(pDX, IDC_EDIT15, c_right);
	DDV_MinMaxInt(pDX, c_right, 1, 1024);
	DDX_Text(pDX, IDC_EDIT16, d_right);
	DDV_MinMaxInt(pDX, d_right, 1, 1024);
	DDX_Text(pDX, IDC_EDIT17, e_right);
	DDV_MinMaxInt(pDX, e_right, 1, 1024);
}

BEGIN_MESSAGE_MAP(CJOBDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CJOBDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CJOBDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CJOBDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CJOBDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CJOBDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CJOBDlg 消息处理程序

BOOL CJOBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_list1.InsertColumn(0, TEXT("作业名"), LVCFMT_CENTER, 50);
	m_list1.InsertColumn(1, TEXT("到达时间"), LVCFMT_CENTER, 60);
	m_list1.InsertColumn(2, TEXT("服务时间"), LVCFMT_CENTER, 60);
	m_list1.InsertColumn(3, TEXT("优先权"), LVCFMT_CENTER, 50);
	m_list1.InsertColumn(4, TEXT("开始时间"), LVCFMT_CENTER, 60);
	m_list1.InsertColumn(5, TEXT("完成时间"), LVCFMT_CENTER, 60);
	m_list1.InsertColumn(6, TEXT("周转时间"), LVCFMT_CENTER, 60);
	m_list1.InsertColumn(7, TEXT("带权周转时间"), LVCFMT_CENTER, 90);
	a_right = 5;
	b_right = 4;
	c_right = 3;
	d_right = 2;
	e_right = 1;
	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CJOBDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CJOBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CJOBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//重置
void CJOBDlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	m_list1.DeleteAllItems();
	int cutime = 0;
	avg_total = 0;
	avg_weight = 0;
	UpdateData(FALSE);
}

//FCFS
void CJOBDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_list1.DeleteAllItems();
	if (!UpdateData(TRUE))return;
	int i, j;
	int cutime = 0;
	double alltotal=0;
	double allweight=0;
	avg_total=0;
	avg_weight=0;
	job[0].name = "A";
	job[1].name = "B";
	job[2].name = "C";
	job[3].name = "D";
	job[4].name = "E";
	job[0].atime = a_atime;
	job[1].atime = b_atime;
	job[2].atime = c_atime;
	job[3].atime = d_atime;
	job[4].atime = e_atime;
	job[0].stime = a_stime;
	job[1].stime = b_stime;
	job[2].stime = c_stime;
	job[3].stime = d_stime;
	job[4].stime = e_stime;
	for (i = 0; i < 5; i++){
		job[i].fstate = 0;
	}
	struct JCB tmp_rec;
	//按FCFS排序
	for (i = 0; i<4; i++)
	{
		for (j = i + 1; j<5; j++)
		if (job[i].atime>job[j].atime)
		{
			tmp_rec = job[j];
			job[j] = job[i];
			job[i] = tmp_rec;
		}
	}
	for (i = 0; i < 5; i++){
		if (cutime < job[i].atime){
			cutime = job[i].atime;
		}
		job[i].btime = cutime;
		cutime = job[i].btime + job[i].stime;
		job[i].ftime = cutime;
		job[i].total = job[i].ftime - job[i].atime;
		job[i].weight = (double)job[i].total / (double)job[i].stime;
		job[i].fstate = 1;
		alltotal = alltotal + (double)job[i].total;
		allweight = allweight + job[i].weight;
	}
	
	for (i = 0; i < 5; i++)
	{
		CString tmp_str;
		m_list1.InsertItem(i, job[i].name);
		tmp_str.Format(_T("%d"), job[i].atime);
		m_list1.SetItemText(i, 1, tmp_str);
		tmp_str.Format(_T("%d"), job[i].stime);
		m_list1.SetItemText(i, 2, tmp_str);
		tmp_str.Format(_T("%d"), job[i].btime);
		m_list1.SetItemText(i, 4, tmp_str);
		tmp_str.Format(_T("%d"), job[i].ftime);
		m_list1.SetItemText(i, 5, tmp_str);
		tmp_str.Format(_T("%d"), job[i].total);
		m_list1.SetItemText(i, 6, tmp_str);
		tmp_str.Format(_T("%lf"), job[i].weight);
		m_list1.SetItemText(i, 7, tmp_str);
//		Sleep(1000);
	}
	avg_total = alltotal / 5;
	avg_weight = allweight / 5;
	UpdateData(FALSE);
}


//SJF
void CJOBDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_list1.DeleteAllItems();
	if (!UpdateData(TRUE))return;
	int i, j, min, n, num;
	int cutime = 0;
	int tmp = 0;
	int c[5];
	i = j = num = 0;
	double alltotal = 0;
	double allweight = 0;
	avg_total = 0;
	avg_weight = 0;
	job[0].name = "A";
	job[1].name = "B";
	job[2].name = "C";
	job[3].name = "D";
	job[4].name = "E";
	job[0].atime = a_atime;
	job[1].atime = b_atime;
	job[2].atime = c_atime;
	job[3].atime = d_atime;
	job[4].atime = e_atime;
	job[0].stime = a_stime;
	job[1].stime = b_stime;
	job[2].stime = c_stime;
	job[3].stime = d_stime;
	job[4].stime = e_stime;
	for (i = 0; i < 5; i++){
	job[i].fstate = 0;
	}
	struct JCB tmp_rec;
	//按SJF排序
	while (j < 5)
	{
		while (tmp == 0)
		{
			for (n = 0; n<5; n++)
			if (job[n].atime <= cutime && job[n].fstate == 0){ tmp = 1; break; }
			if (tmp == 1)break;
			cutime++;
		}   //find time
		min = job[n].stime;
		num = n;
		/*for (n = 0; n < 5; n++){
			if (job[n].fstate == 0){
				min = job[n].stime;
				num = n;
				break;
			}
		}*/
		for (i = 0; i < 5; i++)
		{
			if (job[i].atime <= cutime&&job[i].fstate == 0)
			{
				if (job[i].stime < min){
					min = job[i].stime;
					num = i;
				}
			}
			
		}
		
		tmp = 0;
		if (j == 0){
			job[num].btime = cutime;
			job[num].ftime = job[num].stime + job[num].atime;
			job[num].total = job[num].ftime - job[num].atime;
			job[num].weight = (double)job[num].total / (double)job[num].stime;
			alltotal = alltotal + (double)job[num].total;
			allweight = allweight + job[num].weight;
			job[num].fstate = 1;
		}
		else{
			job[num].btime = job[c[j-1]].ftime;
			job[num].ftime = job[num].stime + job[num].btime;
			job[num].total = job[num].ftime - job[num].atime;
			job[num].weight = (double)job[num].total / (double)job[num].stime;
			alltotal = alltotal + (double)job[num].total;
			allweight = allweight + job[num].weight;
			job[num].fstate = 1;
		}
		cutime = job[num].ftime;
		c[j] = num;
		/*CString tmp_str;
		m_list1.InsertItem(j, job[num].name);
		tmp_str.Format(_T("%d"), job[num].atime);
		m_list1.SetItemText(j, 1, tmp_str);
		tmp_str.Format(_T("%d"), job[num].stime);
		m_list1.SetItemText(j, 2, tmp_str);

		tmp_str.Format(_T("%d"), job[num].btime);
		m_list1.SetItemText(j, 4, tmp_str);
		tmp_str.Format(_T("%d"), job[num].ftime);
		m_list1.SetItemText(j, 5, tmp_str);
		tmp_str.Format(_T("%d"), job[num].total);
		m_list1.SetItemText(j, 6, tmp_str);
		tmp_str.Format(_T("%lf"), job[num].weight);
		m_list1.SetItemText(j, 7, tmp_str);*/
		j++;
	}
	for (i = 0; i < 5; i++)
	{
		CString tmp_str;
		m_list1.InsertItem(i, job[i].name);
		tmp_str.Format(_T("%d"), job[i].atime);
		m_list1.SetItemText(i, 1, tmp_str);
		tmp_str.Format(_T("%d"), job[i].stime);
		m_list1.SetItemText(i, 2, tmp_str);
		tmp_str.Format(_T("%d"), job[i].btime);
		m_list1.SetItemText(i, 4, tmp_str);
		tmp_str.Format(_T("%d"), job[i].ftime);
		m_list1.SetItemText(i, 5, tmp_str);
		tmp_str.Format(_T("%d"), job[i].total);
		m_list1.SetItemText(i, 6, tmp_str);
		tmp_str.Format(_T("%lf"), job[i].weight);
		m_list1.SetItemText(i, 7, tmp_str);
	}
	avg_total = alltotal / 5;
	avg_weight = allweight / 5;
	UpdateData(FALSE);
}

//PSA
void CJOBDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_list1.DeleteAllItems();
	if (!UpdateData(TRUE))return;
	int i, j, min, n, num;
	int cutime = 0;
	int tmp = 0;
	int c[5];
	i = j = num = 0;
	double alltotal = 0;
	double allweight = 0;
	avg_total = 0;
	avg_weight = 0;
	job[0].name = "A";
	job[1].name = "B";
	job[2].name = "C";
	job[3].name = "D";
	job[4].name = "E";
	job[0].atime = a_atime;
	job[1].atime = b_atime;
	job[2].atime = c_atime;
	job[3].atime = d_atime;
	job[4].atime = e_atime;
	job[0].stime = a_stime;
	job[1].stime = b_stime;
	job[2].stime = c_stime;
	job[3].stime = d_stime;
	job[4].stime = e_stime;
	job[0].right = a_right;
	job[1].right = b_right;
	job[2].right = c_right;
	job[3].right = d_right;
	job[4].right = e_right;
	for (i = 0; i < 5; i++){
		job[i].fstate = 0;
	}
	struct JCB tmp_rec;
	//按PSA排序
	while (j < 5)
	{
		while (tmp == 0)
		{
			for (n = 0; n<5; n++)
			if (job[n].atime <= cutime && job[n].fstate == 0){ tmp = 1; break; }
			if (tmp == 1)break;
			cutime++;
		}   //find time
		min = job[n].right;
		num = n;
		
		for (i = 0; i < 5; i++)
		{
			if (job[i].atime <= cutime&&job[i].fstate == 0)
			{
				if (job[i].right < min){
					min = job[i].right;
					num = i;
				}
			}

		}

		tmp = 0;
		if (j == 0){
			job[num].btime = cutime;
			job[num].ftime = job[num].stime + job[num].atime;
			job[num].total = job[num].ftime - job[num].atime;
			job[num].weight = (double)job[num].total / (double)job[num].stime;
			alltotal = alltotal + (double)job[num].total;
			allweight = allweight + job[num].weight;
			job[num].fstate = 1;
		}
		else{
			job[num].btime = job[c[j - 1]].ftime;
			job[num].ftime = job[num].stime + job[num].btime;
			job[num].total = job[num].ftime - job[num].atime;
			job[num].weight = (double)job[num].total / (double)job[num].stime;
			alltotal = alltotal + (double)job[num].total;
			allweight = allweight + job[num].weight;
			job[num].fstate = 1;
		}
		cutime = job[num].ftime;
		c[j] = num;
		
		j++;
	}
	for (i = 0; i < 5; i++)
	{
		CString tmp_str;
		m_list1.InsertItem(i, job[i].name);
		tmp_str.Format(_T("%d"), job[i].atime);
		m_list1.SetItemText(i, 1, tmp_str);
		tmp_str.Format(_T("%d"), job[i].stime);
		m_list1.SetItemText(i, 2, tmp_str);
		tmp_str.Format(_T("%d"), job[i].right);
		m_list1.SetItemText(i, 3, tmp_str);
		tmp_str.Format(_T("%d"), job[i].btime);
		m_list1.SetItemText(i, 4, tmp_str);
		tmp_str.Format(_T("%d"), job[i].ftime);
		m_list1.SetItemText(i, 5, tmp_str);
		tmp_str.Format(_T("%d"), job[i].total);
		m_list1.SetItemText(i, 6, tmp_str);
		tmp_str.Format(_T("%lf"), job[i].weight);
		m_list1.SetItemText(i, 7, tmp_str);
	}
	avg_total = alltotal / 5;
	avg_weight = allweight / 5;
	UpdateData(FALSE);
}

//HRRN
void CJOBDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	m_list1.DeleteAllItems();
	if (!UpdateData(TRUE))return;
	int i, j, max, n, num;
	int cutime = 0;
	int tmp = 0;
	int c[5];
	i = j = num = 0;
	double alltotal = 0;
	double allweight = 0;
	avg_total = 0;
	avg_weight = 0;
	job[0].name = "A";
	job[1].name = "B";
	job[2].name = "C";
	job[3].name = "D";
	job[4].name = "E";
	job[0].atime = a_atime;
	job[1].atime = b_atime;
	job[2].atime = c_atime;
	job[3].atime = d_atime;
	job[4].atime = e_atime;
	job[0].stime = a_stime;
	job[1].stime = b_stime;
	job[2].stime = c_stime;
	job[3].stime = d_stime;
	job[4].stime = e_stime;
	for (i = 0; i < 5; i++){
		job[i].fstate = 0;
	}
	struct JCB tmp_rec;
	//按HRRN排序
	while (j < 5)
	{
		while (tmp == 0)
		{
			for (n = 0; n<5; n++)
			if (job[n].atime <= cutime && job[n].fstate == 0){ tmp = 1; break; }
			if (tmp == 1)break;
			cutime++;
		}   //find time
		for (i = 0; i < 5; i++){
			job[i].RP = (double)(job[i].stime + cutime - job[i].atime) / (double)job[i].stime;
		}
		max = job[n].RP;
		num = n;

		for (i = 0; i < 5; i++)
		{
			if (job[i].atime <= cutime&&job[i].fstate == 0)
			{
				if (job[i].RP > max){
					max = job[i].RP;
					num = i;
				}
			}

		}

		tmp = 0;
		if (j == 0){
			job[num].btime = cutime;
			job[num].ftime = job[num].stime + job[num].atime;
			job[num].total = job[num].ftime - job[num].atime;
			job[num].weight = (double)job[num].total / (double)job[num].stime;
			alltotal = alltotal + (double)job[num].total;
			allweight = allweight + job[num].weight;
			job[num].fstate = 1;
		}
		else{
			job[num].btime = job[c[j - 1]].ftime;
			job[num].ftime = job[num].stime + job[num].btime;
			job[num].total = job[num].ftime - job[num].atime;
			job[num].weight = (double)job[num].total / (double)job[num].stime;
			alltotal = alltotal + (double)job[num].total;
			allweight = allweight + job[num].weight;
			job[num].fstate = 1;
		}
		cutime = job[num].ftime;
		c[j] = num;	
		j++;
	}
	for (i = 0; i < 5; i++)
	{
		CString tmp_str;
		m_list1.InsertItem(i, job[i].name);
		tmp_str.Format(_T("%d"), job[i].atime);
		m_list1.SetItemText(i, 1, tmp_str);
		tmp_str.Format(_T("%d"), job[i].stime);
		m_list1.SetItemText(i, 2, tmp_str);
		/*tmp_str.Format(_T("%d"), job[i].right);
		m_list1.SetItemText(i, 3, tmp_str);*/
		tmp_str.Format(_T("%d"), job[i].btime);
		m_list1.SetItemText(i, 4, tmp_str);
		tmp_str.Format(_T("%d"), job[i].ftime);
		m_list1.SetItemText(i, 5, tmp_str);
		tmp_str.Format(_T("%d"), job[i].total);
		m_list1.SetItemText(i, 6, tmp_str);
		tmp_str.Format(_T("%lf"), job[i].weight);
		m_list1.SetItemText(i, 7, tmp_str);
	}
	avg_total = alltotal / 5;
	avg_weight = allweight / 5;
	UpdateData(FALSE);
}
