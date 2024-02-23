#pragma once
//类模板文件
#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		//cout << "有参构造函数" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造函数" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝操作
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "operator=调用函数" << endl;
		//先判断，原来堆区是否有数据，如果有要先释放,例如一个arr[5]=arr1[100];先把arr本身清空，再把arr1赋值进去
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝操作
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T& val)
	{
		//先判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			cout << "数组容量已满，无法插入" << endl;
			return;
		}
		else
		{
			//数组末尾插入数据
			this->pAddress[this->m_Size] = val;
			//更新数组大小
			this->m_Size++;
		}
	}
	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删
		if (this->m_Size == 0)
		{
			cout << "数组中没有元素，删除失败" << endl;
			return;
		}
		this->m_Size--;
	}
	//用户通过下标方式来访问数组中元素
	//重载中括号(引用是为了做左值)arr[0]=100;
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
	~MyArray()
	{
		//cout << "析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}

	}

private:

	T* pAddress;//指针指向堆区开辟的真实的数组
	int m_Capacity;//数组容量
	int m_Size;//数组大小
};