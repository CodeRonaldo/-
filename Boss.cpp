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
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��ţ�" << this->m_DepId
		<< "\tְ��ְλ��" << this->GetDepId()
		<< "\tְ��ְ�񣺹���˾��������" << endl;
}
string Boss::GetDepId()
{
	return string("�ϰ�");
}