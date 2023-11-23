#include<iostream>
using namespace std;
struct node//创建一个结点
{
	int data;
	node* next;
};

struct node* creatLinkList();//创建并初始化一个链表
void OutPut_LinkList(node*header);//打印一个链表（不从0开始，也就是从头结点的下一个结点开始）
struct node* Insert_LinkList(node* header, int oldval, int newval);//在链表中插入一个元素（结点）
struct node* Clear_LinkList(node* header);//清空链表中所有元素，只保留一个头结点
struct node* Delete_LinkList(node* header,int oldval);//删除链表中某一个指定元素（结点）
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
	node* pRear = header;//创建尾部指针方便连接各个结点
	while (1)
	{
		cout << "请输入当前结点的值： ";
		cin >> val;
		if (val != -1)
		{
			node* newnode = new node;
			newnode->data = val;
			newnode->next = NULL;
			pRear->next = newnode;//改变尾部指针指向
			pRear = newnode;//更新新的尾部指针位置
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
		cout << "当前为一个空链表" << endl;
	else
	{
		node* pCurrent = header->next;//利用辅助指针来遍历链表
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
		cout << "当前为一个空链表，无法操作" << endl;
	else 
	{//利用两个辅助指针来确定插入链表的前后位置（由于链表在内存中是不连续的，故不能直接++、——来得到前后位置）
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
			cout << "没有找到该结点" << endl;
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
		cout << "当前为一个空链表，无法操作" << endl;
	else
	{//利用一个辅助指针来遍历链表，依次释放各结点
		node* pCurrent = header->next;
		while (pCurrent != NULL)
		{
			//在释放该结点时，应该先用一个指针保留下一个结点的地址
			node* pNext = pCurrent->next;
			delete pCurrent;
			pCurrent = pNext;
		}
		//循环之后记得再初始化一遍头指针指向
		header->next = NULL;
	}
	return header;
}
struct node* Delete_LinkList(node* header,int oldval)
{
	if (header == NULL)
		cout << "当前为一个空链表，无法操作" << endl;
	else
	{//利用两个辅助指针找到oldvalue的和它的前一个结点
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