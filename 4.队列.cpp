#include<stdio.h>
#include<iostream.h>
#include<string>
#define QUEUE_MAX_NUM 100 
//����ṹ��
typedef struct{
    int queue[QUEUE_MAX_NUM];
    int front;
    int rear;
}Queue_Type;

//�ṹ���������
Queue_Type myQueue;//��������



//��ʼ������
void InitQueue(Queue_Type *p)
{
       p->front = 0;
       p->rear  = 0;
}

//��Ӳ�������
void InQueue (Queue_Type *p, int m, int x)
{
	if((p->rear+1)%m == p->front)
		printf(" overflow!\n ");
	else{
	    p->rear = (p->rear +1)%m;
	    p->queue[p->rear] = x;
	}
}

//���Ӻ���
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


//��ʾ����
void dispalyQueue(Queue_Type * p)
{
	int j;
	cout<<"��������Ϊ��";
	if(p->rear == p->front)
	{
		cout<<"��";
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
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';

	InQueue (&myQueue, 100, 6);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 5);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 4);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 3);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 2);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';
	InQueue (&myQueue, 100, 1);
	cout<<"��ǰ��βλ��Ϊ��"<<myQueue.rear<<'\n';

	dispalyQueue(&myQueue);

	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,100)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	cout<<"��ǰ����Ԫ��Ϊ��"<<OutQueue(&myQueue,100)<<'\n';
	cout<<"��ǰ����λ��Ϊ��"<<myQueue.front<<'\n';
	dispalyQueue(&myQueue);
}
