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


//初始化函数
void InitList (Linear_List_Type *p)
{
    p->len = 0;
}
//插入操作函数，在第i个位置插入学生信息
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
		p->s[k].num = p->s[k -1].num;//学号
	    strcpy(p->s[k].name,p->s[k -1].name);//名字
	}
	int b;
	char input_name[20];
	cout<<"输入要插入的学生学号:";cin>>b;p->s[i-1].num = b;
    cout<<"输入要插入的学生姓名:";cin>>input_name;
	strcpy(p->s[i-1].name,input_name);
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
		printf("This element is not in the list!\n "); return;
	}
	for(k = i; k < p->len; k++)
	{
		p->s[k-1].num = p->s[k ].num;//学号
	    strcpy(p->s[k-1].name,p->s[k ].name);//名字
	}
	p->len= p->len -1;
	return;
}
//顺序表定位,找到学号
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

//显示数据
void dispalyList(Linear_List_Type * p)
{
	int j;
	cout<<"顺序表数据为："<<endl;
	for (j=0;j<p->len;j++)
	{
	cout<<"学号："<<p->s[j].num<<";";
	cout<<"姓名："<<p->s[j].name<<endl;
	}
	cout<<'\n';
}
void  main(void )
{  
	Linear_List_Type   myList;
	InitList (&myList);
	cout<<"当前顺序表长度为："<<myList.len<<'\n';
    dispalyList(&myList);

	int loc_num;
	cout<<"请输入要插入学生信息在表中位置：";
    cin>>loc_num;
	cout<<endl;
    InsertList (&myList, 100, loc_num);
	dispalyList(&myList);
    cout<<"当前顺序表长度为："<<myList.len<<'\n';

    cout<<"请输入要插入学生信息在表中位置："<<'\n';
    cin>>loc_num;

	InsertList (&myList, 100, loc_num);
	dispalyList(&myList);
    cout<<"当前顺序表长度为："<<myList.len<<'\n';
    
	cout<<"请输入要查找学生的学号：";
	int find_num;
	cin>>find_num;
	cout<<endl;
	int location_i;
    location_i=LocateList(&myList,find_num);
	if (location_i==-1)
		cout<<"数据不存在！"<<endl;
	else
		cout<<"数据位置在："<<location_i<<endl;

	cout<<"请输入要删除学生信息在表中位置：";
	int delete_num;
    cin>>delete_num;
	cout<<endl;
	DeleteList(&myList,delete_num);
	dispalyList(&myList);
}
