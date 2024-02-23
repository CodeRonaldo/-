#pragma once
//��ģ���ļ�
#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		//cout << "�вι��캯��" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "�������캯��" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//�������
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "operator=���ú���" << endl;
		//���жϣ�ԭ�������Ƿ������ݣ������Ҫ���ͷ�,����һ��arr[5]=arr1[100];�Ȱ�arr������գ��ٰ�arr1��ֵ��ȥ
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//�������
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//β�巨
	void Push_Back(const T& val)
	{
		//���ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			cout << "���������������޷�����" << endl;
			return;
		}
		else
		{
			//����ĩβ��������
			this->pAddress[this->m_Size] = val;
			//���������С
			this->m_Size++;
		}
	}
	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ
		if (this->m_Size == 0)
		{
			cout << "������û��Ԫ�أ�ɾ��ʧ��" << endl;
			return;
		}
		this->m_Size--;
	}
	//�û�ͨ���±귽ʽ������������Ԫ��
	//����������(������Ϊ������ֵ)arr[0]=100;
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int getSize()
	{
		return this->m_Size;
	}
	~MyArray()
	{
		//cout << "������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}

	}

private:

	T* pAddress;//ָ��ָ��������ٵ���ʵ������
	int m_Capacity;//��������
	int m_Size;//�����С
};