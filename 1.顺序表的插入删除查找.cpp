#include<stdio.h>
#include<iostream.h>
#include<string>

typedef struct
{
  int list[100];
  int len; 
} Linear_List_Type;//定义


//初始化函数
void InitList (Linear_List_Type *p)
{
    p->len = 0;
}
//插入操作函数
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
//删除函数
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
//顺序表定位
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

//显示数据
void dispalyList(Linear_List_Type * p)
{
	int j;
	cout<<"顺序表数据为：";
	for (j=0;j<p->len;j++)
	{
	cout<<p->list[j];
	}
	cout<<'\n';
}
void  main(void )
{  
	Linear_List_Type   myList;//线性表变量声明
	InitList (&myList);
	cout<<"当前顺序表长度为："<<myList.len<<'\n';
    dispalyList(&myList);

    InsertList (&myList, 100, 9, 6);

	dispalyList(&myList);
    cout<<"当前顺序表长度为："<<myList.len<<'\n';
	InsertList (&myList, 100, 9, 7);
	dispalyList(&myList);
    cout<<"当前顺序表长度为："<<myList.len<<'\n';
	InsertList (&myList, 100, 1, 5);
	dispalyList(&myList);
    cout<<"当前顺序表长度为："<<myList.len<<'\n';
	InsertList (&myList, 100, 2, 8);
	dispalyList(&myList);
    cout<<"当前顺序表长度为："<<myList.len<<'\n';
    
	int location_i;
    location_i=LocateList(&myList,16);
	cout<<"数据位置在："<<location_i<<endl;

DeleteList(&myList,3);
dispalyList(&myList);
    //cout<<"当前顺序表长度为："<<myList.len<<'\n';
//
//	InsertList (&myList, 100, 5, 5);
//	cout<<"当前顺序表长度为："<<myList.len<<'\n';

//    DeleteList(&myList,10);
//	LocateList(&myList,6);
//	dispalyList(&myList);


}
