 #define  _CRT_SECURE_NO_WARNINGS 1
#include"Boss.h"
Boss::Boss(int Id, string name, int dId)
{
	this->m_ID = Id;
	this->m_Name = name;
	this->m_DepId = dId;
}
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位编号：" << this->m_DepId
		<< "\t职工职位：" << this->GetDepId()
		<< "\t职工职务：管理公司所有事务" << endl;
}
string Boss::GetDepId()
{
	return string("老板");
}