#include<iostream>
using namespace std;
struct node//����һ�����
{
	int data;
	node* next;
};

struct node* creatLinkList();//��������ʼ��һ������
void OutPut_LinkList(node*header);//��ӡһ����������0��ʼ��Ҳ���Ǵ�ͷ������һ����㿪ʼ��
struct node* Insert_LinkList(node* header, int oldval, int newval);//�������в���һ��Ԫ�أ���㣩
struct node* Clear_LinkList(node* header);//�������������Ԫ�أ�ֻ����һ��ͷ���
struct node* Delete_LinkList(node* header,int oldval);//ɾ��������ĳһ��ָ��Ԫ�أ���㣩
int main()
{
	int oldval, newval;
	node* LinkList1 = creatLinkList();
	//LinkList1=Insert_LinkList(LinkList1, 2,  5);
	//Clear_LinkList(LinkList1);
	LinkList1=Delete_LinkList(LinkList1,7);
	 OutPut_LinkList(LinkList1);

	system("pause");
	return 0;
}
struct node* creatLinkList()
{
	node* header = new node;
	header->next = NULL;
	header->data = -1;
	int val = 0;
	node* pRear = header;//����β��ָ�뷽�����Ӹ������
	while (1)
	{
		cout << "�����뵱ǰ����ֵ�� ";
		cin >> val;
		if (val != -1)
		{
			node* newnode = new node;
			newnode->data = val;
			newnode->next = NULL;
			pRear->next = newnode;//�ı�β��ָ��ָ��
			pRear = newnode;//�����µ�β��ָ��λ��
			pRear->next = NULL;
		}
		else
		{
			break;
		}
	}
	return header;
}
void OutPut_LinkList(node* header)
{
	if (header == NULL)
		cout << "��ǰΪһ��������" << endl;
	else
	{
		node* pCurrent = header->next;//���ø���ָ������������
		while (pCurrent != NULL)
		{
			cout << pCurrent->data << " ";
			pCurrent = pCurrent->next;
		}
	}
}
struct node* Insert_LinkList(node* header, int oldval, int newval)
{
	if (header == NULL)
		cout << "��ǰΪһ���������޷�����" << endl;
	else 
	{//������������ָ����ȷ�����������ǰ��λ�ã������������ڴ����ǲ������ģ��ʲ���ֱ��++���������õ�ǰ��λ�ã�
		node* pCurrent = header->next;
		node* pPrev = header;
		while (pCurrent->next != NULL)
		{
			if (pCurrent->data != oldval)
			{
				pCurrent = pCurrent->next;
				pPrev = pPrev->next;
			}
		}
		if (pCurrent->data!=oldval)
			cout << "û���ҵ��ý��" << endl;
		else
		{
			node* newnode = new node{ newval,NULL };
			pPrev->next = newnode;
			newnode->next = pCurrent;
		}

	}
	return header;
}
struct node* Clear_LinkList(node* header)
{
	if (header == NULL)
		cout << "��ǰΪһ���������޷�����" << endl;
	else
	{//����һ������ָ�����������������ͷŸ����
		node* pCurrent = header->next;
		while (pCurrent != NULL)
		{
			//���ͷŸý��ʱ��Ӧ������һ��ָ�뱣����һ�����ĵ�ַ
			node* pNext = pCurrent->next;
			delete pCurrent;
			pCurrent = pNext;
		}
		//ѭ��֮��ǵ��ٳ�ʼ��һ��ͷָ��ָ��
		header->next = NULL;
	}
	return header;
}
struct node* Delete_LinkList(node* header,int oldval)
{
	if (header == NULL)
		cout << "��ǰΪһ���������޷�����" << endl;
	else
	{//������������ָ���ҵ�oldvalue�ĺ�����ǰһ�����
		node* pCurrent = header->next;
		node* pPrev = header;
		while (pCurrent->next != NULL)
		{
			if (pCurrent->data == oldval)
				break;
			else
			{
				pCurrent = pCurrent->next;
				pPrev = pPrev->next;
			}
		}
		pPrev->next = pCurrent->next;
		delete pCurrent;
	}
	return header;
}