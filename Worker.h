#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//抽象职工类
class Worker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string GetDepId() = 0;

	int m_ID;//职工编号
	string m_Name;//职工姓名
	int m_DepId;//职工所在部门名称编号
};