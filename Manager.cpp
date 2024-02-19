 #define  _CRT_SECURE_NO_WARNINGS 1
#include"Manager.h"
Manager::Manager(int Id, string name, int dId)
{
	this->m_ID = Id;
	this->m_Name = name;
	this->m_DepId = dId;
}
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位编号：" << this->m_DepId
		<< "\t职工职位：" << this->GetDepId()
		<< "\t职工职务：完成老板交给的任务，并下发任务给员工" << endl;
}
string Manager::GetDepId()
{
	return string("经理");
}