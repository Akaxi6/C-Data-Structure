//ʵ��2 ��ͷ������
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>

struct LNode
{
	int data;
	struct LNode *next;
};

void display(LNode *first);	//��ʾ���нڵ��Ԫ��
LNode *creat();		//����һ����number���ڵ�ĵ����������ص�һ���ڵ�ָ��
int found(LNode *first, int x);	//����ָ��Ԫ��x��λ�ã�����λ��
void delet(LNode *first, int x);	//ɾ��Ԫ��x���ڽڵ�
void delet_all(LNode *first);	//�ͷ����нڵ�
void insert(LNode **ph, int n);	//�ڵ�i���ڵ�֮�����Ԫ��x

void display(LNode *first)	//��ʾ���нڵ��Ԫ��
{
	if(first == NULL)
		cout<<"����Ϊ�գ�"<<endl;
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

LNode *creat()	//����һ����number���ڵ�ĵ����������ص�һ���ڵ�ָ��
{
	LNode *first, *p, *s;
	int i, number;
	cout<<"����ڵ����:";
	cin>>number;
	if(number < 1)
	{
		cout<<"����δ������"<<endl;
		return NULL;
	}
	else
	{
		cout<<number<<"���ڵ�����: ";
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

int found(LNode *first, int x)	//����ָ��Ԫ��x��λ�ã�����λ��
{
	LNode *p;
	int i = 1;
	p = first;
	if(first = NULL)
		return 0;	//����Ϊ��
	while(p != NULL)
	{
		if(p->data == x)
			return i;
		p = p->next;
		i++;
	}
	return -1;
}

void delet(LNode **ph, int x)	//ɾ��Ԫ��x���ڽڵ�
{
	LNode *p, *q;
	p = *ph;
	q = p;
	if(p == NULL)
		cout<<"����Ϊ�գ�ɾ��ʧ�ܣ�"<<endl;
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
			cout<<"ɾ���ɹ���"<<endl;
		}
		else
		{
			if(p == NULL)
				cout<<"δ�ҵ�ָ��Ԫ�أ�ɾ��ʧ�ܣ�"<<endl;
			else
			{
				q->next = p->next;
				delete p;
				cout<<"ɾ���ɹ���"<<endl;
			}
		}
	}

}

void delet_all(LNode *first)	//�ͷ����нڵ�
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

void insert(LNode **ph, int n)	//�ڵ�i���ڵ�֮�����Ԫ��x
{
	LNode *p, *s;
	int i, x;
	p = *ph;
	if(p == NULL)
	{
		cout<<"����Ϊ�գ����ڵ�һ��λ�ò������ݣ�"<<endl;
		cout<<"����Ԫ�أ�";
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
			cout<<"����Ԫ�أ�";
			cin>>x;
			s = new LNode;
			s->data = x;
			s->next = p;
			*ph = s;
			cout<<"����ɹ���"<<endl;
		}	
		else
		{
			for(i = 1; i < n && p->next != NULL; i++)
				p = p->next;
			if(i < n)
				cout<<"ָ��λ�ó�������Χ������ʧ��"<<endl;
			else
			{
				cout<<"����Ԫ�أ�";
				cin>>x;
				s = new LNode;
				s->data = x;
				s->next = p->next;
				p->next = s;
				cout<<"����ɹ���"<<endl;
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
		cout<<"===����ѡ��1-���� 2-���� 3-ɾ�� 4-��ʾ 0-�˳�==="<<endl<<"choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:	//����
			cout<<"����λ�ã�";
			cin>>i;
			insert(&first,i);
			break;
		case 2:	//����
			cout<<"��Ҫ���ҵ�Ԫ�أ�";
			cin>>x;
			i = found(first,x);
			if(i == 0)
				cout<<"����Ϊ�գ�δ�ҵ�ָ��Ԫ�أ�"<<endl;
			else if(i == -1)
				cout<<"δ�ҵ�ָ��Ԫ�أ�"<<endl;
			else
				cout<<"���ҳɹ���"<<endl<<"Ԫ��"<<x<<"�ı��Ϊ��"<<i<<endl;
			break;
		case 3:	//ɾ��
			cout<<"��Ҫɾ����Ԫ��:";
			cin>>x;
			delet(&first,x);
			display(first);
			break;
		case 4:
			display(first);
			break;
		case 0:
			delet_all(first);	//�ͷ����нڵ�
			exit(0);
		}
	}
}