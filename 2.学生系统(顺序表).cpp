#include<stdio.h>
#include<iostream.h>
#include<string>
typedef struct
{
  int num;
  char name[20]; 
} student;

typedef struct
{
  student s[100];
  int len; 
} Linear_List_Type;


//��ʼ������
void InitList (Linear_List_Type *p)
{
    p->len = 0;
}
//��������������ڵ�i��λ�ò���ѧ����Ϣ
void InsertList (Linear_List_Type * p, int m, int i)
{
	int k;
	if(p->len == m)
	{
	    printf(" overflow!\n ");
                return;
	}

	if(i > p->len)
	{
		i = p->len + 1;
	}
	else if( i < 1)
		i = 1;

	for(k = p->len; k >= i; k--)
	{
		p->s[k].num = p->s[k -1].num;//ѧ��
	    strcpy(p->s[k].name,p->s[k -1].name);//����
	}
	int b;
	char input_name[20];
	cout<<"����Ҫ�����ѧ��ѧ��:";cin>>b;p->s[i-1].num = b;
    cout<<"����Ҫ�����ѧ������:";cin>>input_name;
	strcpy(p->s[i-1].name,input_name);
	    p->len += 1; 
}
//ɾ������
void DeleteList (Linear_List_Type * p, int i)
{
	int k;
	if(p->len == 0)
	{
                printf(" underflow !\n "); 
                return;
	}
	if((i < 1) || (i > p->len))
	{
		printf("This element is not in the list!\n "); return;
	}
	for(k = i; k < p->len; k++)
	{
		p->s[k-1].num = p->s[k ].num;//ѧ��
	    strcpy(p->s[k-1].name,p->s[k ].name);//����
	}
	p->len= p->len -1;
	return;
}
//˳���λ,�ҵ�ѧ��
int LocateList (Linear_List_Type * p ,int x)
{
    int i = 0;
    while((i<p->len) && (p->s[i].num !=x))
        i++;
    if(i<p->len)
        return (i+1);
    else
        return (-1);
}

//��ʾ����
void dispalyList(Linear_List_Type * p)
{
	int j;
	cout<<"˳�������Ϊ��"<<endl;
	for (j=0;j<p->len;j++)
	{
	cout<<"ѧ�ţ�"<<p->s[j].num<<";";
	cout<<"������"<<p->s[j].name<<endl;
	}
	cout<<'\n';
}
void  main(void )
{  
	Linear_List_Type   myList;
	InitList (&myList);
	cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
    dispalyList(&myList);

	int loc_num;
	cout<<"������Ҫ����ѧ����Ϣ�ڱ���λ�ã�";
    cin>>loc_num;
	cout<<endl;
    InsertList (&myList, 100, loc_num);
	dispalyList(&myList);
    cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';

    cout<<"������Ҫ����ѧ����Ϣ�ڱ���λ�ã�"<<'\n';
    cin>>loc_num;

	InsertList (&myList, 100, loc_num);
	dispalyList(&myList);
    cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
    
	cout<<"������Ҫ����ѧ����ѧ�ţ�";
	int find_num;
	cin>>find_num;
	cout<<endl;
	int location_i;
    location_i=LocateList(&myList,find_num);
	if (location_i==-1)
		cout<<"���ݲ����ڣ�"<<endl;
	else
		cout<<"����λ���ڣ�"<<location_i<<endl;

	cout<<"������Ҫɾ��ѧ����Ϣ�ڱ���λ�ã�";
	int delete_num;
    cin>>delete_num;
	cout<<endl;
	DeleteList(&myList,delete_num);
	dispalyList(&myList);
}
