#include<stdio.h>
#include<iostream.h>
#include<string>
#define STACK_MAX_NUM 100 

typedef struct Stack_Type
{
    int stack[STACK_MAX_NUM];
    int top;
};

Stack_Type myStack;//�������������д洢�ռ�


//��ʼ������
  void InitStack (Stack_Type *p)
{
	  p->top = 0;
}

//��ջ��������
void Push (Stack_Type *p ,int m, int x)
{
	if (p->top == m)
	{
		printf(" overflow !\n ");
		return;
	}
	p->top = p->top + 1;
	p->stack[p->top - 1] = x;
	return;
}

//��ջ����
 int Pop (Stack_Type *p)
 {
	int value;//�м���������ڼ�¼��ջ��Ԫ��
	if (p->top == 0){
	    printf(" underflow!\n ");
	}
        else{
	    value = p->stack[p->top - 1];
	    p->top = p->top - 1;
	    return value;
        }
   }

//��ȡջ��Ԫ��
int Top (Stack_Type *p)
{
	int value;
	if (p->top == 0){
	    printf(" underflow!\n ");
	}
        else{
	    value = p->stack[p->top - 1];
	    return value;
        }
   }
//�ж�ջ�Ƿ�Ϊ��
 int StackStatus (Stack_Type *p ,int m)
 {
        if (p->top == m)
               return (-1);            //ջ��
        if (p->top == 0)
               return (0);             //ջ��
        return (1)  ;                   //ջ״̬����
   }


//��ʾ����
void dispalyStack(Stack_Type * p)
{
	int j;
	cout<<"ջ������Ϊ��";
	for (j=0;j<p->top;j++)
	{
	cout<<p->stack[j];
	}
	cout<<'\n';
}
void  main(void )
{  
	InitStack (&myStack);

	cout<<"��ǰջ�ĳ���Ϊ��"<<myStack.top<<'\n';

	Push (&myStack,100, 6);
	cout<<"��ǰջ�ĳ���Ϊ��"<<myStack.top<<'\n';
	Push (&myStack,100, 5);
	cout<<"��ǰջ�ĳ���Ϊ��"<<myStack.top<<'\n';
	Push (&myStack,100, 4);
	cout<<"��ǰջ�ĳ���Ϊ��"<<myStack.top<<'\n';
	Push (&myStack,100, 3);
	cout<<"��ǰջ�ĳ���Ϊ��"<<myStack.top<<'\n';
Pop(&myStack);
dispalyStack(&myStack);
//    Push (&myStack,100, 2);
//	cout<<"��ǰջ�ĳ���Ϊ��"<<myStack.top<<'\n';

	int Top_stck;
	Top_stck=Top(&myStack);
	cout<<"ջ��Ԫ��Ϊ��"<<Top_stck<<'\n';
	dispalyStack(&myStack);

    Pop(&myStack);
	dispalyStack(&myStack);


}
