#pragma once
#include"Worker.h"
//������
class Manager :public Worker
{
public:
	//���캯������Id��name
	Manager(int Id, string name, int dId);

	//��ȡְ��������Ϣ����
	virtual void ShowInfo();

	//��ȡְ�����ڲ������Ʊ�ź���
	virtual string GetDepId();


};