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



//��ʼ������
void InitQueue(Queue_Type *p)
{
       p->front = QUEUE_MAX_NUM;
       p->rear  = QUEUE_MAX_NUM;
       p->s = 0;
}

//��Ӳ�������
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


//���Ӻ���
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

//��ʾ����
void dispalyQueue(Queue_Type * p)
{
	int j,k;
	cout<<"��������Ϊ��";

	if (p->s == 0)
	{
		cout<<"��";
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

	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';

	InQueue (&myQueue, QUEUE_MAX_NUM, 6);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.front<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 5);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 4);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 3);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 2);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, QUEUE_MAX_NUM, 1);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';

	dispalyQueue(&myQueue);

	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,4)<<'\n';

	InQueue (&myQueue, QUEUE_MAX_NUM, 9);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';

	dispalyQueue(&myQueue);
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
    cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,QUEUE_MAX_NUM)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	dispalyQueue(&myQueue);
}
