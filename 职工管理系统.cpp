 #define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;


int main()
{
	//实例化管理者对象
	WorkerManager workermanager;
	int choice = 0;//存贮用户的选择
	while (true)
	{
		workermanager.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			workermanager.ExitSystem();
			break;
		case 1://添加职工
			workermanager.Add_Emp();
			break;
		case 2://显示职工
			workermanager.Show_Emp();
			break;
		case 3://删除职工
			workermanager.Del_Emp();
			break;
		case 4://修改职工
			workermanager.Mod_Emp();
			break;
		case 5://查找职工
			workermanager.Find_Emp();
			break;
		case 6://排序职工
			workermanager.Sort_Emp();
			break;
		case 7://清空文档
			workermanager.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	
	system("pause");
	return 0;
}