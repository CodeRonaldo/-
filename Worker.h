#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//����ְ����
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��λ����
	virtual string GetDepId() = 0;

	int m_ID;//ְ�����
	string m_Name;//ְ������
	int m_DepId;//ְ�����ڲ������Ʊ��
};