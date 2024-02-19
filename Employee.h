#pragma once
#include"Worker.h"
//普通员工类
class Employee :public Worker
{
public:
	//构造函数，传Id和name
	Employee(int Id, string name, int dId);
	
	//获取职工个人信息函数
	virtual void ShowInfo();
	
	//获取职工所在部门名称编号函数
	virtual string GetDepId();
	
};
