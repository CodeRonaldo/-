#pragma once
#include"Worker.h"
//��ͨԱ����
class Employee :public Worker
{
public:
	//���캯������Id��name
	Employee(int Id, string name, int dId);
	
	//��ȡְ��������Ϣ����
	virtual void ShowInfo();
	
	//��ȡְ�����ڲ������Ʊ�ź���
	virtual string GetDepId();
	
};
