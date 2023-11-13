//1����ӡһ�����棬�÷�װ������ʾ
//2����main�е��øú���
#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//��ַ
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б�����ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��ϵ�˸���
	int m_Size;
};
//1�������ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ���������������������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�Ϊ�� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{//����������1��2�������˳�ѭ������Ϊ���������ȷֵ
		 //�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;//����system��pause����Ӵ��˳��������������˳�ѭ��
			}
			else 
			{ 
				cout << "������������������" << endl; 
			}
		}
		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		while (true)
		{
			//����������0��120֮��������˳�ѭ������Ϊ���������ȷ��ֵ
			//��֮������������������
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ϲ��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//2����ʾ������ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ�˵���Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " <<( abs->personArray[i].m_Sex==1 ? "��":"Ů")<< "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ�� " << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}
	system("pause");//�����������
	system("cls");
}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã��±꣩�������ڣ�����-1
//����һͨѶ¼���������Ա�����
int isExist(Addressbooks *abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
    }
	return -1;//�����û�ҵ�����-1
}
//3��ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret==-1δ�鵽
	//ret��=1-�鵽
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//���ҵ����ˣ�����ɾ����ɾ��һ���ˣ������˺����������ǰ�ƶ�������ͨѶ¼�м�¼��������һ
		for (int i = ret; i < abs->m_Size; i++)
		{   //����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4������ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ����ϵ���Ƿ���ͨѶ¼��
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ�� " << abs->personArray[ret].m_Addr << "\t";
		cout << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�������� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�Ϊ�� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{//����������1��2�������˳�ѭ������Ϊ���������ȷֵ
		 //�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;//����system��pause����Ӵ��˳��������������˳�ѭ��
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		while (true)
		{
			//����������0��120֮��������˳�ѭ������Ϊ���������ȷ��ֵ
			//��֮������������������
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6�����ͨѶ¼
void cleanPerson(Addressbooks* abs)
{
	int a = 0;
	cout << "��ȷ���Ƿ����������ϵ�ˣ��������1���������2�� " << endl;
	cin >> a;
	if (a == 1)
	{
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���Ƴ�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}
int main()
{
	//����һ��ͨѶ¼�Ľṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼����Ա����
	abs.m_Size = 0;
	int select = 0;//�����û�ѡ������ı���
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//���õ�ַ���ݿ�����ʵ��
			break; //1�������ϵ��
		case 2:
			showPerson(&abs);
			break; // 2����ʾ��ϵ��
		case 3:
			deletePerson(&abs);
		break; //3��ɾ����ϵ��
		case 4:
			findPerson(&abs);
			break; //4��������ϵ��
		case 5:
			modifyPerson(&abs);
			break; //5���޸���ϵ��
		case 6:
			cleanPerson(&abs);
			break; //6�������ϵ��
		case 0:
			cout << "��ӭ�´μ���ʹ��" << endl;
			system("pause");
			return 0;
			break; //0���Ƴ�ͨѶ¼
		default:
			break;
		}
	}
	system("pause");
	return 0;
}