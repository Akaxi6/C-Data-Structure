//实验2 无头结点程序
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>

struct LNode
{
	int data;
	struct LNode *next;
};

void display(LNode *first);	//显示所有节点的元素
LNode *creat();		//建立一个有number个节点的单向链表，返回第一个节点指针
int found(LNode *first, int x);	//查找指定元素x的位置，返回位置
void delet(LNode *first, int x);	//删除元素x所在节点
void delet_all(LNode *first);	//释放所有节点
void insert(LNode **ph, int n);	//在第i个节点之后插入元素x

void display(LNode *first)	//显示所有节点的元素
{
	if(first == NULL)
		cout<<"链表为空！"<<endl;
	else
	{
		cout<<"first->";
		while(first != NULL)
		{
			cout<<first->data<<"->";
			first = first->next;
		}
		cout<<"end"<<endl;
	}
}

LNode *creat()	//建立一个有number个节点的单向链表，返回第一个节点指针
{
	LNode *first, *p, *s;
	int i, number;
	cout<<"输入节点个数:";
	cin>>number;
	if(number < 1)
	{
		cout<<"链表未建立！"<<endl;
		return NULL;
	}
	else
	{
		cout<<number<<"个节点数据: ";
		first = new LNode;
		p = first;
		p->next = NULL;
		cin>>p->data;
		for(i = 2; i <= number; i++)
		{
			s = new LNode;
			cin>>s->data;
			s->next = p->next;
			p->next = s;
			p = p->next;
		}
		return first;
	}
}

int found(LNode *first, int x)	//查找指定元素x的位置，返回位置
{
	LNode *p;
	int i = 1;
	p = first;
	if(first = NULL)
		return 0;	//链表为空
	while(p != NULL)
	{
		if(p->data == x)
			return i;
		p = p->next;
		i++;
	}
	return -1;
}

void delet(LNode **ph, int x)	//删除元素x所在节点
{
	LNode *p, *q;
	p = *ph;
	q = p;
	if(p == NULL)
		cout<<"链表为空，删除失败！"<<endl;
	else
	{
		while(p != NULL && p->data != x)
		{
			q = p;
			p = p->next;
		}
		if(q == p)
		{
			*ph = q->next;
			delete q;
			cout<<"删除成功！"<<endl;
		}
		else
		{
			if(p == NULL)
				cout<<"未找到指定元素，删除失败！"<<endl;
			else
			{
				q->next = p->next;
				delete p;
				cout<<"删除成功！"<<endl;
			}
		}
	}

}

void delet_all(LNode *first)	//释放所有节点
{
	LNode *p;
	p = first;
	while(p != NULL)
	{
		p = first->next;
		delete first;
		first = p;
	}
	delete first;
}

void insert(LNode **ph, int n)	//在第i个节点之后插入元素x
{
	LNode *p, *s;
	int i, x;
	p = *ph;
	if(p == NULL)
	{
		cout<<"链表为空，将在第一个位置插入数据！"<<endl;
		cout<<"插入元素：";
		cin>>x;
		s = new LNode;
		s->data = x;
		s->next = p;
		*ph = s;
	}
	else
	{
		if(n == 0)
		{
			cout<<"插入元素：";
			cin>>x;
			s = new LNode;
			s->data = x;
			s->next = p;
			*ph = s;
			cout<<"插入成功！"<<endl;
		}	
		else
		{
			for(i = 1; i < n && p->next != NULL; i++)
				p = p->next;
			if(i < n)
				cout<<"指定位置超出链表范围，插入失败"<<endl;
			else
			{
				cout<<"插入元素：";
				cin>>x;
				s = new LNode;
				s->data = x;
				s->next = p->next;
				p->next = s;
				cout<<"插入成功！"<<endl;
			}
		}
	}
}

void main()
{
	LNode *first;
	int i, x, choice;
	first = creat();
	while(1)
	{
		cout<<"===功能选择：1-插入 2-查找 3-删除 4-显示 0-退出==="<<endl<<"choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:	//插入
			cout<<"插入位置：";
			cin>>i;
			insert(&first,i);
			break;
		case 2:	//查找
			cout<<"需要查找的元素：";
			cin>>x;
			i = found(first,x);
			if(i == 0)
				cout<<"链表为空，未找到指定元素！"<<endl;
			else if(i == -1)
				cout<<"未找到指定元素！"<<endl;
			else
				cout<<"查找成功！"<<endl<<"元素"<<x<<"的编号为："<<i<<endl;
			break;
		case 3:	//删除
			cout<<"需要删除的元素:";
			cin>>x;
			delet(&first,x);
			display(first);
			break;
		case 4:
			display(first);
			break;
		case 0:
			delet_all(first);	//释放所有节点
			exit(0);
		}
	}
}