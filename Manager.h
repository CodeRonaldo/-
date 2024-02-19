#pragma once
#include"Worker.h"
//经理类
class Manager :public Worker
{
public:
	//构造函数，传Id和name
	Manager(int Id, string name, int dId);

	//获取职工个人信息函数
	virtual void ShowInfo();

	//获取职工所在部门名称编号函数
	virtual string GetDepId();


};