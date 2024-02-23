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
		//利用尾插法向数组中插入数据
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
//测试自定义数据类型
class Person
{
public:
	Person() {};//默认构造函数一定要写，即使是空实现，这是因为在.hpp文件中new出的Person对象调用的无参构造，由于写了有参构造，因此编译器不会给默认无参构造，如果不写就会报错
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
	Person p1("悟空", 999);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("赵云", 19);
	Person p5("安琪拉", 25);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	PrintPersonArray(arr);
	cout << "容量:" << arr.getCapacity() << endl;
	cout << "大小:" << arr.getSize() << endl;
}

int main()
{
	test02();
	system("pause");
	return 0;
}