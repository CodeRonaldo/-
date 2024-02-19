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
	//1���ļ������ڵ����
	if (!ifs.is_open())
	{
		//cout << "�ļ�������!" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArray = NULL;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ���ǩΪ��
		ifs.close();
		return;
	}
	//2���ļ����ڣ���û�м�¼�����ļ���
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof()Ϊһ�����������Ϊ��������ļ�βΪ��
	{
		//cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArray = NULL;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ���ǩΪ��
		ifs.close();
		return;
	}
	//3���ļ�����,�������ݶ�����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;//���Դ���
	this->m_EmpNum = num;

	//����ְ��������������ռ�
	m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();
	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ�����ţ�" << this->m_EmpArray[i]->m_ID
			<< "\t������" << this->m_EmpArray[i]->m_Name
			<< "\t��λ���ţ�" << this->m_EmpArray[i]->m_DepId << endl;
	}*/
}
void WorkerManager::Show_Menu()//չʾ�˵�����
{
	cout << "*******************************************" << endl;
	cout << "***********��ӭʹ��ְ������ϵͳ************" << endl;
	cout << "************0.�˳�����ϵͳ*****************" << endl;
	cout << "************1.����ְ����Ϣ*****************" << endl;
	cout << "************2.��ʾְ����Ϣ*****************" << endl;
	cout << "************3.ɾ����ְְ��*****************" << endl;
	cout << "************4.�޸�ְ����Ϣ*****************" << endl;
	cout << "************5.����ְ����Ϣ*****************" << endl;
	cout << "************6.���ձ������*****************" << endl;
	cout << "************7.��������ĵ�*****************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;

}
//�˳�ϵͳ����
void WorkerManager::ExitSystem()
{
	cout << "�˳��ɹ�����ӭ�´�ʹ��" <<endl;
	system("pause");
	exit(0);//�˳���ִ�г���ĺ����������return��ֻ���˳���ǰ������������������δ�˳�������ѭ������
}
//����ְ������
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
	   //�����µĿռ��С
		int newSize = addNum + m_EmpNum;
		
		//�������ٿռ䣬���ø�����治ְͬ����
		Worker** newSpace = new Worker * [newSize];

		//ÿ�ν�ԭְ�����Ƶ��³��ȵ������У��Դﵽ����Ŀ��
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			//��ʾ������ְ����Ϣ
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;
			int index = this->IsExist(id);
			//�ж�ְ������Ƿ���ڣ��������ظ���
			if (index == -1)
			{
				cout << "�������" << i + 1 << "����ְ��������" << endl;
				cin >> name;
				cout << "��ѡ���ְ���ĸ�λ��" << endl;
				cout << "1����ְͨԱ" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dSelect;
				//����ָ�븨����������
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1://��ְͨ��
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					cout << "��λ���������������������" << endl;
					break;
				}
				newSpace[i + m_EmpNum] = worker;
			}
			else
			{
				cout << "ְ������Ѵ��ڣ�����������" << endl;
				i--;
				continue;
			}
		}
			//�ͷ�ԭ�пռ�
			delete[]m_EmpArray;
			//�����¿ռ�ָ��
			m_EmpArray = newSpace;
			//����ְ������
			m_EmpNum = newSize;
			//�����ļ��Ƿ�Ϊ��
			m_FileIsEmpty = false;
			//��ʾ��ӳɹ�
			cout << "�ɹ����" << addNum << "����ְ��!" << endl;
			//�������ݵ��ļ���
			this->save();//�ŵ�forѭ�����棡����ϸ��
	    
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}
//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//ofs << "ְ�����:" << "\tְ������:" << "\tְ����λ���Ʊ��:" << endl;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID<<" "
			<< this->m_EmpArray[i]->m_Name <<" "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs << "��ע��ְ����λ�����1������ְͨ����2������3�����ϰ壩" << endl;
	ofs.close();
}
//��ȡ��¼��ְ����������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)//���ж�ȡ����˼
	{
		num++;
	}
	ifs.close();
	return num;
}

//��ʼ�����麯��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;//�����±꣬���ڱ��������ʼ����

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)//��ְͨ��
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//����
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)//�ϰ�
		{
			worker = new Boss(id, name, did);
		}
		
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
	this->m_FileIsEmpty = false;
}
//��ʾְ������
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
//�ж�ְ���Ƿ���ڵĺ���
int WorkerManager:: IsExist(int id)
{
	//����ְ������ж�ְ���Ƿ���ڣ������ڣ�����ְ���������е����⣻�������ڣ�����-1��
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
//ɾ��ְ������
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�������ɾ��ְ��
		cout << "��������Ҫɾ����ְ����ְ�����:" << endl;
		int id = 0;
		cin >> id;
	
		//���жϸ�ְ���Ƿ����
		int index = this->IsExist(id);
		if (index != -1)
		{
			//��ʱindex��Ϊ��Ҫɾ��ְ���������е�λ��
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();//ɾ�����µ��������´����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�޸�ְ������
void WorkerManager::Mod_Emp()
{
	//����ְ����Ŷ�ְ����Ϣ�����޸ĺͱ���
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ����ְ����ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		//�ж�ְ���Ƿ����
		if (ret != -1)
		{
			//�ҵ���ְ��
			delete this->m_EmpArray[ret];
			this->m_EmpArray[ret] = NULL;
			//����ɾ�������ܸı��λ���ʱ��������ְ���෢���ı䣬����ֱ�Ӹ��ǾͲ�̫�Ͻ�
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ����ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "��ѡ���¸�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1://��ְͨ��
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2://����
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3://�ϰ�
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				cout << "��λ�����������,����������" << endl;
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			
			cout << "�޸ĳɹ�" << endl;
			//�����ļ�
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְ������
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//��ְ����Ų���
			int id = 0;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret= this->IsExist(id);

			if (ret != -1)
			{
				//�ҵ����ˣ����������Ϣ
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			//��������������
			string name;
			cout << "��������ҵ�����:" << endl;
			cin >> name;

			int counter = 0;//�������飬ͳ�Ƹ�������������ֹ�������
			int index = 0;//���û���������������¼�����и�ְ��Ԫ���±�
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
				cout << "����ʧ�ܣ����޴���" << endl;
			}
			else if (counter == 1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[index]->ShowInfo();
			}
			else if (counter > 1)
			{
				//����������ʾ�û�����ְ��id����
				cout << "����" << counter << "������ְ��,���������ְ��ְ�����:" << endl;
				int m_id = 0;
				cin >> m_id;
				int findNum = this->IsExist(m_id);
				if (findNum != -1)
				{
					if (this->m_EmpArray[findNum]->m_Name == name)
					{
						cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
						this->m_EmpArray[findNum]->ShowInfo();
					}
					else
					{
						cout << "ְ������������󣬲��޴���" << endl;
					}
				}
				else
				{
					cout << "����ʧ�ܣ�ְ������������󣬲��޴���" << endl;
				}
			}
		}
		else
		{
			cout << "���ҷ�ʽ������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ѡ����������ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ����Ž�������" << endl;
		cout << "2����ְ����Ž��н���" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����
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
			//����
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
			cout << "����ѡ��ʽ��������������" << endl;
			return;
		}
		cout << "����ɹ����������Ϊ��" << endl;
		//�����ļ�
		this->save();
		//��ʾ��ְ��
		this->Show_Emp();
		
	}
	system("pause");
	system("cls");
}
//����ļ�
void WorkerManager::Clean_File()
{
	cout << "��ȷ���Ƿ�����ļ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//ios::trunc ����ļ����ڣ���ɾ�������´������ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//�Ƚ������ڲ�ά����ÿһ�������ͷŸɾ������ͷ����鱾��
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
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
	
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		//�Ƚ������ڲ�ά����ÿһ�������ͷŸɾ������ͷ����鱾��
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
