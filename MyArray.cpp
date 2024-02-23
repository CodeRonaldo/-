 #define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;
void PrintIntArray(MyArray<int> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test01()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	//arr1.Pop_Back();
	PrintIntArray(arr1);
	MyArray<int>arr2(arr1);
	cout << arr1.getSize() << endl;
	cout << arr1.getCapacity() << endl;
	arr2.Pop_Back();
	PrintIntArray(arr2);
	cout << arr2.getSize() << endl;
	cout << arr2.getCapacity() << endl;
}
//�����Զ�����������
class Person
{
public:
	Person() {};//Ĭ�Ϲ��캯��һ��Ҫд����ʹ�ǿ�ʵ�֣�������Ϊ��.hpp�ļ���new����Person������õ��޲ι��죬����д���вι��죬��˱����������Ĭ���޲ι��죬�����д�ͻᱨ��
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
void PrintPersonArray(MyArray<Person>&arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i].m_Name << endl;
		cout << arr[i].m_Age << endl;
	}
}
void test02()
{
	MyArray<Person>arr(10);
	Person p1("���", 999);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("����", 19);
	Person p5("������", 25);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	PrintPersonArray(arr);
	cout << "����:" << arr.getCapacity() << endl;
	cout << "��С:" << arr.getSize() << endl;
}

int main()
{
	test02();
	system("pause");
	return 0;
}