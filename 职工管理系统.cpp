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
	//ʵ���������߶���
	WorkerManager workermanager;
	int choice = 0;//�����û���ѡ��
	while (true)
	{
		workermanager.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			workermanager.ExitSystem();
			break;
		case 1://���ְ��
			workermanager.Add_Emp();
			break;
		case 2://��ʾְ��
			workermanager.Show_Emp();
			break;
		case 3://ɾ��ְ��
			workermanager.Del_Emp();
			break;
		case 4://�޸�ְ��
			workermanager.Mod_Emp();
			break;
		case 5://����ְ��
			workermanager.Find_Emp();
			break;
		case 6://����ְ��
			workermanager.Sort_Emp();
			break;
		case 7://����ĵ�
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