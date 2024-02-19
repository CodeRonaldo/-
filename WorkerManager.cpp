 #define  _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1、文件不存在的情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在!" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArray = NULL;//初始化数组
		this->m_FileIsEmpty = true;//初始化文件标签为空
		ifs.close();
		return;
	}
	//2、文件存在，但没有记录（空文件）
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof()为一个函数，如果为真则代表文件尾为空
	{
		//cout << "文件为空!" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArray = NULL;//初始化数组
		this->m_FileIsEmpty = true;//初始化文件标签为空
		ifs.close();
		return;
	}
	//3、文件存在,并且数据都存在
	int num = this->get_EmpNum();
	//cout << "职工个数为：" << num << endl;//测试代码
	this->m_EmpNum = num;

	//根据职工人数开辟数组空间
	m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();
	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工代号：" << this->m_EmpArray[i]->m_ID
			<< "\t姓名：" << this->m_EmpArray[i]->m_Name
			<< "\t岗位代号：" << this->m_EmpArray[i]->m_DepId << endl;
	}*/
}
void WorkerManager::Show_Menu()//展示菜单函数
{
	cout << "*******************************************" << endl;
	cout << "***********欢迎使用职工管理系统************" << endl;
	cout << "************0.退出管理系统*****************" << endl;
	cout << "************1.增加职工信息*****************" << endl;
	cout << "************2.显示职工信息*****************" << endl;
	cout << "************3.删除离职职工*****************" << endl;
	cout << "************4.修改职工信息*****************" << endl;
	cout << "************5.查找职工信息*****************" << endl;
	cout << "************6.按照编号排序*****************" << endl;
	cout << "************7.清空所有文档*****************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;

}
//退出系统函数
void WorkerManager::ExitSystem()
{
	cout << "退出成功，欢迎下次使用" <<endl;
	system("pause");
	exit(0);//退出所执行程序的函数，如果用return，只能退出当前函数，但是主函数并未退出，仍在循环输入
}
//增加职工函数
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工人数：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
	   //计算新的空间大小
		int newSize = addNum + m_EmpNum;
		
		//堆区开辟空间，利用该数组存不同职工类
		Worker** newSpace = new Worker * [newSize];

		//每次将原职工复制到新长度的数组中，以达到增加目的
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			//提示输入新职工信息
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;
			int index = this->IsExist(id);
			//判断职工编号是否存在（不允许重复）
			if (index == -1)
			{
				cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
				cin >> name;
				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职员" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;
				//创建指针辅助存入数组
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1://普通职工
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					cout << "岗位编号输入有误，请重新输入" << endl;
					break;
				}
				newSpace[i + m_EmpNum] = worker;
			}
			else
			{
				cout << "职工编号已存在，请重新输入" << endl;
				i--;
				continue;
			}
		}
			//释放原有空间
			delete[]m_EmpArray;
			//更改新空间指向
			m_EmpArray = newSpace;
			//更新职工人数
			m_EmpNum = newSize;
			//更改文件是否为空
			m_FileIsEmpty = false;
			//提示添加成功
			cout << "成功添加" << addNum << "名新职工!" << endl;
			//保存数据到文件中
			this->save();//放到for循环外面！！！细节
	    
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}
//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//ofs << "职工编号:" << "\t职工姓名:" << "\t职工岗位名称编号:" << endl;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID<<" "
			<< this->m_EmpArray[i]->m_Name <<" "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs << "（注：职工岗位编号中1代表普通职工，2代表经理，3代表老板）" << endl;
	ofs.close();
}
//获取记录的职工人数函数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)//逐行读取的意思
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化数组函数
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;//数组下标，便于遍历数组初始化用

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)//普通职工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//经理
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)//老板
		{
			worker = new Boss(id, name, did);
		}
		
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
	this->m_FileIsEmpty = false;
}
//显示职工函数
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();

		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在的函数
int WorkerManager:: IsExist(int id)
{
	//按照职工编号判断职工是否存在，若存在，返回职工在数组中的问题；若不存在，返回-1；
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}
//删除职工函数
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号来删除职工
		cout << "请输入您要删除的职工的职工编号:" << endl;
		int id = 0;
		cin >> id;
	
		//先判断该职工是否存在
		int index = this->IsExist(id);
		if (index != -1)
		{
			//此时index即为需要删除职工在数组中的位置
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();//删除后新的数组重新存入文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
//修改职工函数
void WorkerManager::Mod_Emp()
{
	//按照职工编号对职工信息进行修改和保存
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的职工编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		//判断职工是否存在
		if (ret != -1)
		{
			//找到该职工
			delete this->m_EmpArray[ret];
			this->m_EmpArray[ret] = NULL;
			//若不删除，可能改变岗位编号时，所属的职工类发生改变，这样直接覆盖就不太严谨
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工编号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请选择新岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1://普通职工
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2://经理
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3://老板
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				cout << "岗位编号输入有误,请重新输入" << endl;
				break;
			}
			//更改数据到数组中
			this->m_EmpArray[ret] = worker;
			
			cout << "修改成功" << endl;
			//保存文件
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职工函数
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按职工编号查找
			int id = 0;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret= this->IsExist(id);

			if (ret != -1)
			{
				//找到此人，输出他的信息
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名来查找
			string name;
			cout << "请输入查找的姓名:" << endl;
			cin >> name;

			int counter = 0;//遍历数组，统计该名称人数，防止重名情况
			int index = 0;//针对没有重名的情况，记录数组中该职工元素下标
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name ==name)
				{
					counter++;
					index = i;
				}
			}
			if (counter == 0)
			{
				cout << "查找失败，查无此人" << endl;
			}
			else if (counter == 1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[index]->ShowInfo();
			}
			else if (counter > 1)
			{
				//有重名，提示用户输入职工id查找
				cout << "发现" << counter << "名重名职工,请输入查找职工职工编号:" << endl;
				int m_id = 0;
				cin >> m_id;
				int findNum = this->IsExist(m_id);
				if (findNum != -1)
				{
					if (this->m_EmpArray[findNum]->m_Name == name)
					{
						cout << "查找成功，该职工信息如下：" << endl;
						this->m_EmpArray[findNum]->ShowInfo();
					}
					else
					{
						cout << "职工编号输入有误，查无此人" << endl;
					}
				}
				else
				{
					cout << "查找失败，职工编号输入有误，查无此人" << endl;
				}
			}
		}
		else
		{
			cout << "查找方式输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}
//利用选择排序，排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工编号进行升序" << endl;
		cout << "2、按职工编号进行降序" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//升序
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int min = i;
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[min]->m_ID > this->m_EmpArray[j]->m_ID)
						min = j;
				}
				
				int temp= this->m_EmpArray[i]->m_ID;
				this->m_EmpArray[i]->m_ID = this->m_EmpArray[min]->m_ID;
				this->m_EmpArray[min]->m_ID = temp;
			}
		}
		else if (select == 2)
		{
			//降序
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int max = i;
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[max]->m_ID < this->m_EmpArray[j]->m_ID)
						max = j;
				}

				int temp = this->m_EmpArray[i]->m_ID;
				this->m_EmpArray[i]->m_ID = this->m_EmpArray[max]->m_ID;
				this->m_EmpArray[max]->m_ID = temp;
			}
		}
		else
		{
			cout << "排序选择方式有误，请重新输入" << endl;
			return;
		}
		cout << "排序成功，排序后结果为：" << endl;
		//保存文件
		this->save();
		//显示新职工
		this->Show_Emp();
		
	}
	system("pause");
	system("cls");
}
//清空文件
void WorkerManager::Clean_File()
{
	cout << "请确认是否清空文件" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//ios::trunc 如果文件存在，先删除后重新创建空文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//先将数组内部维护的每一个对象释放干净后再释放数组本身
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i])
					delete this->m_EmpArray[i];
			}
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
	
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		//先将数组内部维护的每一个对象释放干净后再释放数组本身
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i])
				delete this->m_EmpArray[i];
		}
		this->m_EmpNum = 0;
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
	}
}
