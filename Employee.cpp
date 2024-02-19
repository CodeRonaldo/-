 #define  _CRT_SECURE_NO_WARNINGS 1
#include"Employee.h"
Employee:: Employee(int Id, string name, int dId)
{
	this->m_ID = Id;
	this->m_Name = name;
	this->m_DepId = dId;
}
void Employee:: ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		 << "\t职工姓名：" << this->m_Name
		 << "\t岗位编号：" << this->m_DepId
		 <<"\t职工职位："<<this->GetDepId()
		 << "\t职工职务：完成经理交给的任务" << endl;
}
string Employee:: GetDepId()
{
	return string("员工");
}