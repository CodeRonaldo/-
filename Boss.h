#pragma once
#include"Worker.h"
class Boss :public Worker
{
public:
	//���캯������Id��name
	Boss(int Id, string name, int dId);

	//��ȡְ��������Ϣ����
	virtual void ShowInfo();

	//��ȡְ�����ڲ������Ʊ�ź���
	virtual string GetDepId();

};
