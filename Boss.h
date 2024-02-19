#pragma once
#include"Worker.h"
class Boss :public Worker
{
public:
	//构造函数，传Id和name
	Boss(int Id, string name, int dId);

	//获取职工个人信息函数
	virtual void ShowInfo();

	//获取职工所在部门名称编号函数
	virtual string GetDepId();

};
