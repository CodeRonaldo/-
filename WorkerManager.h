#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流
#include<fstream>
#define FILENAME "empFILE.txt"
using namespace std;
#include"Worker.h"
////管理类：
//与用户进行沟通
//对职工增删查改操作
//与文件的读写交互

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单函数
	void Show_Menu();

	//退出管理系统函数
	void ExitSystem();

	//增加职工
	void Add_Emp();

	//保存文件
	void save();

	//获取记录的职工人数函数
	int get_EmpNum();

	//初始化数组函数
	void init_Emp();
	 
	//显示职工
	void Show_Emp();
	
	//删除职工
	void Del_Emp();

	//判断职工是否存在，便于删除、查找和修改职工信息
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();

	//记录职工人数
	int m_EmpNum;

	//记录不同职工类的二级指针数组
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;
};
