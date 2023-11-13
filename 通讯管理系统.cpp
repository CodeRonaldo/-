//1、打印一个界面，用封装函数显示
//2、在main中调用该函数
#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//地址
	string m_Addr;
};
//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存联系人的数组
	struct Person personArray[MAX];
	//通讯录中当前联系人个数
	int m_Size;
};
//1、添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满，如果已满，则不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别为： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{//如果输入的是1或2，可以退出循环，因为输入的是正确值
		 //如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;//若用system（pause）则从此退出函数而不仅是退出循环
			}
			else 
			{ 
				cout << "输入有误，请重新输入" << endl; 
			}
		}
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		while (true)
		{
			//如果输入的在0和120之间则可以退出循环，因为输入的是正确的值
			//反之，输入有误，重新输入
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;

		cout << "恭喜添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//2、显示所有联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录里人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人的信息
	if (abs->m_Size == 0)
	{
		cout << "当前的记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " <<( abs->personArray[i].m_Sex==1 ? "男":"女")<< "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "地址： " << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");
}
//检查联系人是否存在，如果存在，返回联系人所在数组中的具体位置（下标），不存在，返回-1
//参数一通讯录，参数二对比姓名
int isExist(Addressbooks *abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
    }
	return -1;//如果都没找到返回-1
}
//3、删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//ret==-1未查到
	//ret！=1-查到
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//查找到此人，进行删除：删除一个人，将该人后面的数据向前移动，并让通讯录中记录的人数减一
		for (int i = ret; i < abs->m_Size; i++)
		{   //数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4、查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定联系人是否在通讯录中
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "地址： " << abs->personArray[ret].m_Addr << "\t";
		cout << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5、修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别为： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{//如果输入的是1或2，可以退出循环，因为输入的是正确值
		 //如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;//若用system（pause）则从此退出函数而不仅是退出循环
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		while (true)
		{
			//如果输入的在0和120之间则可以退出循环，因为输入的是正确的值
			//反之，输入有误，重新输入
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6、清空通讯录
void cleanPerson(Addressbooks* abs)
{
	int a = 0;
	cout << "请确认是否清空所有联系人，是则输出1，否则输出2： " << endl;
	cin >> a;
	if (a == 1)
	{
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、推出通讯录 *****" << endl;
	cout << "*************************" << endl;
}
int main()
{
	//创建一个通讯录的结构体变量
	Addressbooks abs;
	//初始化通讯录中人员个数
	abs.m_Size = 0;
	int select = 0;//创建用户选择输入的变量
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//利用地址传递可修饰实参
			break; //1、添加联系人
		case 2:
			showPerson(&abs);
			break; // 2、显示联系人
		case 3:
			deletePerson(&abs);
		break; //3、删除联系人
		case 4:
			findPerson(&abs);
			break; //4、查找联系人
		case 5:
			modifyPerson(&abs);
			break; //5、修改联系人
		case 6:
			cleanPerson(&abs);
			break; //6、清空联系人
		case 0:
			cout << "欢迎下次继续使用" << endl;
			system("pause");
			return 0;
			break; //0、推出通讯录
		default:
			break;
		}
	}
	system("pause");
	return 0;
}