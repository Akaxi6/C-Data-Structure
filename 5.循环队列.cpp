#include<stdio.h>
#include<iostream.h>
#include<string>
#define QUEUE_MAX_NUM 100 
typedef struct
{
    int queue[QUEUE_MAX_NUM];
    int front;
    int rear;
    int s;
}Queue_Type;

Queue_Type myQueue;



//初始化函数
void InitQueue(Queue_Type *p)
{
       p->front = QUEUE_MAX_NUM;
       p->rear  = QUEUE_MAX_NUM;
       p->s = 0;
}

//入队操作函数
void InQueue (Queue_Type *p, int m, int x)
{
	if((p->s == 1) &&(p->rear == p->front))
		printf(" overflow!\n ");
	else
	{
	    p->rear += 1;
	    if(p->rear == m+1) 
		{
			p->rear = 1;
		}
		p->queue[p->rear - 1] = x;
		p->s = 1;
	}
}


//出队函数
int OutQueue (Queue_Type *p,int m)
{
        int y;
        if(p->s == 0)
	    printf(" underflow!\n ");
        else
		{
	    p->front  = p->front%m+1;
	    y = p->queue[p->front -1];
	    if(p->front == p->rear)
		p->s= 0;
	    return y;
        }
}

//显示数据
void dispalyQueue(Queue_Type * p)
{
	int j,k;
	cout<<"队中数据为：";

	if (p->s == 0)
	{
		cout<<"空";
	}
    
	else
	{
		j=p->front;
		do 
		{
			j=j+1;
			if (j==QUEUE_MAX_NUM+1) j=1;
			cout<<p->queue[j-1];
		}while(j!=p->rear);

	}
		cout<<'\n';
}
void  main(void )
{  
	InitQueue (&myQueue);
	//dispalyQueue(&myQueue);

	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';

	InQueue (&myQueue, QUEUE_MAX_NUM, 6);
	cout<<"当前队尾位置为："<<myQueue.front<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 5);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 4);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 3);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 2);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 1);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';

	dispalyQueue(&myQueue);

	cout<<"当前出队元素为："<<OutQueue(&myQueue,4)<<'\n';

	InQueue (&myQueue, QUEUE_MAX_NUM, 9);
	cout<<"当前队尾位置为："<<myQueue.rear<<'\n';

	dispalyQueue(&myQueue);
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
    cout<<"当前出队元素为："<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	cout<<"当前出队元素为："<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	cout<<"当前出队元素为："<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	cout<<"当前出队元素为："<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	cout<<"当前出队元素为："<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	cout<<"当前出队元素为："<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"当前队首位置为："<<myQueue.front<<'\n';
	dispalyQueue(&myQueue);
}
