// _Stu.cpp : implementation file
//

#include "stdafx.h"
#include "TestSystem.h"
#include "_Stu.h"
#include "_Stu_test1.h"
#include "_Stu_test2.h"
#include "_Stu_mark.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Stu dialog

extern ADO ado;
extern bool finish;
extern CString score;
extern int hour,second,minute;
extern bool statu;
extern CString _account;
_Stu::_Stu(CWnd* pParent /*=NULL*/)
	: CDialog(_Stu::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Stu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Stu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Stu)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
	CString sql;
	sql.Format("select* from Stu where 学号='%s'",_account);
	ado.OpenRecordset(sql,1);

	CString name;			//姓名
	CString academy;		//学院
	CString clas;			//班级
	CString time="00:00:00";//时间
	
	_account=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("学号");
	name=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("姓名");
	clas=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("班级");
	academy=(LPCSTR)(_bstr_t)ado.m_pRst->GetCollect("学院");

	GetDlgItem(IDC_STATIC1)->SetWindowText(_account);
	GetDlgItem(IDC_STATIC2)->SetWindowText(name);
	GetDlgItem(IDC_STATIC3)->SetWindowText(clas);
	GetDlgItem(IDC_STATIC4)->SetWindowText(academy);
	GetDlgItem(IDC_STATIC5)->SetWindowText(score);
	GetDlgItem(IDC_STATIC6)->SetWindowText(time);
}


BEGIN_MESSAGE_MAP(_Stu, CDialog)
	//{{AFX_MSG_MAP(_Stu)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Stu message handlers

void _Stu::OnButton7()//选择题按钮
{
	// TODO: Add your control notification handler code here
	if(start==0)
	{
		AfxMessageBox("请先点击“开始答题”进行抽题...");
		return ;
	}
	else if(statu==1)
	{
		//已交卷，不处理
		return ;
	}
	_Stu_test1 Dlg;
	Dlg.DoModal();
}

void _Stu::OnButton8()//判断题按钮
{
	// TODO: Add your control notification handler code here
	if(start==0)
	{
		AfxMessageBox("请先点击“开始答题”进行抽题...");
		return ;
	}
	else if(statu==1)
	{
		//已交卷，不处理
		return ;
	}
	_Stu_test2 Dlg;
	Dlg.DoModal();
}

void _Stu::OnButton1()//提交试卷
{
	// TODO: Add your control notification handler code here
	if(!statu)
	{
		if(finish)
		{
			MessageBox("是否确认交卷？",MB_OK,MB_ICONWARNING);
		}
		else
		{
			AfxMessageBox("存在未完成的题目，是否交卷...");
		}
		statu=1;
		_Stu_mark Dlg;
		Dlg.DoModal();
		KillTimer(1);//杀掉计时器
		GetDlgItem(IDC_STATIC6)->SetWindowText("00:00:00");//重置计时器
		GetDlgItem(IDC_STATIC5)->SetWindowText(score);//刷新分数
	}
	else
		AfxMessageBox("考试已结束...");
}

void _Stu::OnButton3() //退出按钮
{
	// TODO: Add your control notification handler code here
	EndDialog(0);	
}

void _Stu::OnButton2() //开始答题
{
	/*
	1.特殊情况处理
	2.正常情况处理
	*/

	//特殊情况处理
	//判断是否交卷
	if(statu==1)
	{
		//已交卷，不处理
		return ;
	}
	//判断是否开始
	if(start==1)
	{
		//已经开始，不处理
		AfxMessageBox("考试已经开始，请答题...");
		return ;
	}
	

	//正常情况
	/*
		0.标记状态
		1.利用随机数随机抽取试卷
		2.
	*/

	//表示试卷状态为开始答题
	start=1;

	//生成随机数，0->A，1->B
	srand((unsigned)time(NULL));
	int x=rand()%2;

	//随机抽取试卷
	CString sql;
	CString prompt;//提示

	if(x==0)
	{
		CString temp;//储存考试时间
		sql="select* from Test_option where 试卷编号='A'";
		//筛选所有字段，从Test_option表中，要求记录中字段“试卷编号”的值为“A”
		ado.OpenRecordset(sql,1);
		temp=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("考试时间");
		minute=atoi(temp);//将时间从CString转换为integer
		hour=minute/60;
		minute%=60;

		sql="select* from TestA";
		prompt="抽题成功（A），开始答题...";
	}
	else
	{
		CString temp;
		sql="select* from Test_option where 试卷编号='B'";
		ado.OpenRecordset(sql,1);
		temp=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("考试时间");
		minute=atoi(temp);
		hour=minute/60;
		minute%=60;

		sql="select* from TestB";
		prompt="抽题成功（B），开始答题...";
	}

	
	ado.OpenRecordset(sql,1);//打开记录集
	MessageBox(prompt,MB_OK,MB_ICONEXCLAMATION);//弹出提示信息
	SetTimer(1,1000,NULL);//设置计时器控件
}

void _Stu::OnTimer(UINT nIDEvent)//计时器函数
{
	// TODO: Add your message handler code here and/or call default

	//实现倒计时
	second--;
	if(second<0)
	{
		minute--;
		if(minute<0)
		{
			hour--;
			if(hour<0)
			{
				AfxMessageBox("答题时间到...");
				KillTimer(nIDEvent);
			}
			minute=59;
		}
		second=59;
	}



	//显示倒计时
	char hou[5],minut[5],secon[5],judg[5],choos[5];
	
	itoa(second,secon,10);
	itoa(hour,hou,10);
	itoa(minute,minut,10);
	itoa(choose_num,choos,10);//将用于记录选择题总进度的全局integer变量转化为CString
	itoa(judge_num,judg,10);//将用于记录判断题总进度的全局integer变量转化为CString
	
	CString time;
	CString judge;
	CString choose;

	time.Format("%s:%s:%s",(CString)hou,(CString)minut,(CString)secon);
	choose.Format("%s/30",choos);	
	judge.Format("%s/40",judg);

	GetDlgItem(IDC_STATIC6)->SetWindowText(time);
	GetDlgItem(IDC_Stu_static1)->SetWindowText(choose);
	GetDlgItem(IDC_Stu_static2)->SetWindowText(judge);

	//判断是否完成所有题目
	if(choose_num==30&&judge_num==40)
		finish=1;

}
