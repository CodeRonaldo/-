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
	cout << "ְ����ţ�" << this->m_ID
		 << "\tְ��������" << this->m_Name
		 << "\t��λ��ţ�" << this->m_DepId
		 <<"\tְ��ְλ��"<<this->GetDepId()
		 << "\tְ��ְ����ɾ�����������" << endl;
}
string Employee:: GetDepId()
{
	return string("Ա��");
}