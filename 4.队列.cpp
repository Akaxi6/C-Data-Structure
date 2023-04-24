#include<stdio.h>
#include<iostream.h>
#include<string>
#define QUEUE_MAX_NUM 100 
//定义结构体
typedef struct{
    int queue[QUEUE_MAX_NUM];
    int front;
    int rear;
}Queue_Type;

//结构体变量定义
Queue_Type myQueue;//声明变量



//初始化函数
void InitQueue(Queue_Type *p)
{
       p->front = 0;
       p->rear  = 0;
}

//入队操作函数
void InQueue (Queue_Type *p, int m, int x)
{
	if((p->rear+1)%m == p->front)
		printf(" overflow!\n ");
	else{
	    p->rear = (p->rear +1)%m;
	    p->queue[p->rear] = x;
	}
}

//出队函数
int OutQueue (Queue_Type *p, int m)
{
	if(p->rear == p->front)
		printf(" empty!\n ");
	else
	{
	    p->front=(p->front+1)%m;
	}
           return p->queue[p->front];
}


//显示数据
void dispalyQueue(Queue_Type * p)
{
	int j;
	cout<<"队中数据为：";
	if(p->rear == p->front)
	{
		cout<<"空";
	}
	else
	{
		for (j=p->front;j<p->rear;j++)
		{
			cout<<p->queue[j+1];
		}
	}
		cout<<'\n';
}
void  main(void )
{  
	InitQueue (&myQueue);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';

	InQueue (&myQueue, 100, 6);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 5);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 4);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 3);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 2);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 1);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';

	dispalyQueue(&myQueue);

	cout<<"当前出队元素为："<<OutQueue(&myQueue,100)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	cout<<"当前出队元素为："<<OutQueue(&myQueue,100)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	dispalyQueue(&myQueue);
}
