#include<stdio.h>
#include<iostream.h>
#include<string>

typedef struct
{
  int list[100];
  int len; 
} Linear_List_Type;//����


//��ʼ������
void InitList (Linear_List_Type *p)
{
    p->len = 0;
}
//�����������
void InsertList (Linear_List_Type * p, int m, int i, int b)
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
		p->list[k] = p->list[k -1];
	}
	    p->list[i-1] = b;
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
		printf("This element is not in the list!\n "); 
	}
	for(k = i; k < p->len; k++)
	{
		p->list[k-1] = p->list[k];
	}
	p->len= p->len -1;
	return;
}
//˳���λ
int LocateList (Linear_List_Type * p ,int x)
{
    int i = 0;
    while((i<p->len) && (p->list[i] !=x))
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
	cout<<"˳�������Ϊ��";
	for (j=0;j<p->len;j++)
	{
	cout<<p->list[j];
	}
	cout<<'\n';
}
void  main(void )
{  
	Linear_List_Type   myList;//���Ա��������
	InitList (&myList);
	cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
    dispalyList(&myList);

    InsertList (&myList, 100, 9, 6);

	dispalyList(&myList);
    cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
	InsertList (&myList, 100, 9, 7);
	dispalyList(&myList);
    cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
	InsertList (&myList, 100, 1, 5);
	dispalyList(&myList);
    cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
	InsertList (&myList, 100, 2, 8);
	dispalyList(&myList);
    cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
    
	int location_i;
    location_i=LocateList(&myList,16);
	cout<<"����λ���ڣ�"<<location_i<<endl;

DeleteList(&myList,3);
dispalyList(&myList);
    //cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';
//
//	InsertList (&myList, 100, 5, 5);
//	cout<<"��ǰ˳�����Ϊ��"<<myList.len<<'\n';

//    DeleteList(&myList,10);
//	LocateList(&myList,6);
//	dispalyList(&myList);


}
