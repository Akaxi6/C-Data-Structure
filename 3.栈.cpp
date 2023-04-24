#include<stdio.h>
#include<iostream.h>
#include<string>
#define STACK_MAX_NUM 100 

typedef struct Stack_Type
{
    int stack[STACK_MAX_NUM];
    int top;
};

Stack_Type myStack;//声明变量，才有存储空间


//初始化函数
  void InitStack (Stack_Type *p)
{
	  p->top = 0;
}

//入栈操作函数
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

//出栈函数
 int Pop (Stack_Type *p)
 {
	int value;//中间变量，用于记录出栈的元素
	if (p->top == 0){
	    printf(" underflow!\n ");
	}
        else{
	    value = p->stack[p->top - 1];
	    p->top = p->top - 1;
	    return value;
        }
   }

//读取栈顶元素
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
//判断栈是否为空
 int StackStatus (Stack_Type *p ,int m)
 {
        if (p->top == m)
               return (-1);            //栈满
        if (p->top == 0)
               return (0);             //栈空
        return (1)  ;                   //栈状态正常
   }


//显示数据
void dispalyStack(Stack_Type * p)
{
	int j;
	cout<<"栈中数据为：";
	for (j=0;j<p->top;j++)
	{
	cout<<p->stack[j];
	}
	cout<<'\n';
}
void  main(void )
{  
	InitStack (&myStack);

	cout<<"当前栈的长度为："<<myStack.top<<'\n';

	Push (&myStack,100, 6);
	cout<<"当前栈的长度为："<<myStack.top<<'\n';
	Push (&myStack,100, 5);
	cout<<"当前栈的长度为："<<myStack.top<<'\n';
	Push (&myStack,100, 4);
	cout<<"当前栈的长度为："<<myStack.top<<'\n';
	Push (&myStack,100, 3);
	cout<<"当前栈的长度为："<<myStack.top<<'\n';
Pop(&myStack);
dispalyStack(&myStack);
//    Push (&myStack,100, 2);
//	cout<<"当前栈的长度为："<<myStack.top<<'\n';

	int Top_stck;
	Top_stck=Top(&myStack);
	cout<<"栈顶元素为："<<Top_stck<<'\n';
	dispalyStack(&myStack);

    Pop(&myStack);
	dispalyStack(&myStack);


}
