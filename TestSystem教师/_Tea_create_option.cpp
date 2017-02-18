// _Tea_create_option.cpp : implementation file
//

#include "stdafx.h"
#include "testsystem.h"
#include "_Tea_create_option.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// _Tea_create_option dialog

extern ADO ado;
const int MAX=1000;
_Tea_create_option::_Tea_create_option(CWnd* pParent /*=NULL*/)
	: CDialog(_Tea_create_option::IDD, pParent)
{
	//{{AFX_DATA_INIT(_Tea_create_option)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void _Tea_create_option::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(_Tea_create_option)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(_Tea_create_option, CDialog)
	//{{AFX_MSG_MAP(_Tea_create_option)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _Tea_create_option message handlers
//////////////////////////////////////
bool judge(int* a,int n,int x)//判断数组中是否存在，第三个参数为数组实际长度，第二个为判断值
{
	for(int i=0;i<x;i++)
	{
		if(n==a[i])
			return false;
	}
	return true;
}
//////////////////////////////////////
void _Tea_create_option::OnButton1() //生成试卷
{
	/*
	0.准备工作：数据定义及有效性检测
	1.抽题算法实现
	*/
	//RADIO控件有效性
	CString table;//表名
	CString type;//试卷编号
	CString error;//错误提示

	//如果选择A卷
	if(((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()==1)
	{
		table="TestA";
		type="A";
		error="A卷已经存在...";
	}

	//如果选择B卷
	else if(((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()==1)
	{
		table="TestB";
		type="B";
		error="B卷已经存在...";
	}

	//否则报错
	else
	{
		AfxMessageBox("请选择试卷编号...");
		return ;
	}

	//EDIT控件有效性
	CString t;//记录考试时间
	GetDlgItem(IDC_EDIT1)->GetWindowText(t);
	//如果未填
	if(t=="")
	{
		AfxMessageBox("请输入考试时间...");
		return ;
	}

	// TODO: Add your control notification handler code here


	/*1.定义用来存储题目编号的两个数组
	  2.分别生成【选择题库总记录数】，【判断题库总记录数】个不重复的随机数存入数组
	  3.连接表
	  4.for根据数组中编号依次取出Bank_cho与Bank_jud中的题目
	  5.连接表
	  6.依次将题目录入TestA与TestB表中
	  */

	//1
	CString A_cho,B_cho,C_cho,D_cho,question_cho,answer_cho;//记录
	CString question_jud,answer_jud;//记录
	
	int i,num_cho[MAX],num_jud[MAX];
	CString	sql="select* from Bank_cho";
	ado.OpenRecordset(sql,1);
	int cho_max=ado.GetRecordCount(ado.m_pRst);//【选择题库总记录数】

	/*
	char aaa[5];
	itoa(cho_max,aaa,10);
	AfxMessageBox((CString)aaa);
	*/
	sql="select* from Bank_jud";
	ado.OpenRecordset(sql,1);
	int jud_max=ado.GetRecordCount(ado.m_pRst);//【判断题库总记录数】
	
	//2
	srand((unsigned)time(NULL));//用系统时间设置随机函数种子
	for(i=0;i<30;)
	{
		int x=rand()%cho_max+1;	
		
			
		if(judge(num_cho,x,i))//选择题数组，生成数字，当前下标
		{	
			num_cho[i]=x;
			i++;
		}
	}

	for(i=0;i<40;)
	{
		int x=rand()%jud_max+1;
		if(judge(num_jud,x,i))
		{
			num_jud[i]=x;
			i++;
		}
	}
	
	//3
	//试卷题目编号（一定）
	CString temp_C[30]={"1","2","3","4","5","6","7","8","9","10",
					"11","12","13","14","15","16","17","18","19","20",
					"21","22","23","24","25","26","27","28","29","30"};
	CString temp_J[40]={"31","32","33","34","35","36","37","38","39","40",
					"41","42","43","44","45","46","47","48","49","50",
					"51","52","53","54","55","56","57","58","59","60",
					"61","62","63","64","65","66","67","68","69","70"};

	 //4
	try
	{	
		
		for(i=0;i<30;i++)
		{
			/*调试用
			char xxxx[5];
			itoa(num_cho[i],xxxx,10);
			CString x=(CString)xxxx;
			AfxMessageBox(x);
			*/
			//CString A_cho,B_cho,C_cho,D_cho,question_cho,answer_cho;
			
			//sql.Format("select* from Bank_cho where 编号='%d'",num_cho[i]);//锁定编号为num_cho[i]的记录
		
			sql="select* from Bank_cho";
			ado.OpenRecordset(sql,1);//打开记录集
			for(int j=0;j<num_cho[i]-1;j++)
			{
				ado.m_pRst->MoveNext();				
			}
			
			question_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("题目");//获取题目
			A_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("A");//获取A
			B_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("B");//获取B
			C_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("C");//获取C
			D_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("D");//获取D
			answer_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("答案");//获取答案
			
			sql.Format("select* from %s",table);//锁定表TestA
			ado.OpenRecordset(sql,1);//打开记录集
			ado.m_pRst->AddNew();//添加新记录
			ado.m_pRst->PutCollect("编号",(_variant_t)temp_C[i]);//将temp[i]设置为编号
			ado.m_pRst->PutCollect("题型",(_variant_t)"选择题");//添加题型
			ado.m_pRst->PutCollect("题目",(_variant_t)question_cho);//添加题目
			ado.m_pRst->PutCollect("A",(_variant_t)A_cho);//添加A
			ado.m_pRst->PutCollect("B",(_variant_t)B_cho);//添加B
			ado.m_pRst->PutCollect("C",(_variant_t)C_cho);//添加C
			ado.m_pRst->PutCollect("D",(_variant_t)D_cho);//添加D
			ado.m_pRst->PutCollect("答案",(_variant_t)answer_cho);//添加答案
			ado.m_pRst->Update();

		}
	}
	//catch(_com_error e)
	catch(...)
	{
		AfxMessageBox(error);
		//AfxMessageBox(e.Description());
		return ;
	}
	try
	{
		for(i=0;i<40;i++)
		{
			//CString question_jud,answer_jud;
			//sql.Format("select* from Bank_jud where 编号='%d'",num_jud[i]);
			
			sql="select* from Bank_jud";
			ado.OpenRecordset(sql,1);
			for(int j=0;j<num_jud[i]-1;j++)
			{
				ado.m_pRst->MoveNext();				
			}
			
			question_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("题目");
			answer_cho=(LPSTR)(_bstr_t)ado.m_pRst->GetCollect("答案");
			sql.Format("select* from %s",table);
			ado.OpenRecordset(sql,1);
			ado.m_pRst->AddNew();
			ado.m_pRst->PutCollect("编号",(_variant_t)temp_J[i]);
			ado.m_pRst->PutCollect("题型",(_variant_t)"判断题");
			ado.m_pRst->PutCollect("题目",(_variant_t)question_cho);
			ado.m_pRst->PutCollect("答案",(_variant_t)answer_cho);
			ado.m_pRst->Update();
		}
		sql.Format("select* from Test_option where 试卷编号='%s'",type);
		ado.OpenRecordset(sql,1);
		ado.m_pRst->PutCollect("考试时间",(_variant_t)t);
		ado.m_pRst->Update();
		AfxMessageBox("试卷已生成...");
	}
	//catch(_com_error e)
	catch(...)
	{
		AfxMessageBox("000");
		//AfxMessageBox(e.Description());
	}
}
