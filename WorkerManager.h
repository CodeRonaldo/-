#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������
#include<fstream>
#define FILENAME "empFILE.txt"
using namespace std;
#include"Worker.h"
////�����ࣺ
//���û����й�ͨ
//��ְ����ɾ��Ĳ���
//���ļ��Ķ�д����

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�����
	void Show_Menu();

	//�˳�����ϵͳ����
	void ExitSystem();

	//����ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//��ȡ��¼��ְ����������
	int get_EmpNum();

	//��ʼ�����麯��
	void init_Emp();
	 
	//��ʾְ��
	void Show_Emp();
	
	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�����ɾ�������Һ��޸�ְ����Ϣ
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();

	//��¼ְ������
	int m_EmpNum;

	//��¼��ְͬ����Ķ���ָ������
	Worker** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};
