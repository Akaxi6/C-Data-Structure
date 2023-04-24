#include <iostream.h>
#include <malloc.h>

struct node
{ 
    int d;
    struct node *next;
};

//判断是否为空
int LinkedListStatus(node *head)
{
    if(head==NULL)
        return 1;
    else
		return 0;
}

//插入链表, 在包含元素x的结点前插入新元素b
node *InsertList(node *head, int x, int b) 
{
     node  *p, *q; //申请新结点

     p=new node; 
	 
     p->d=b;      //置新结点的数据域
     if (head==NULL)  //原链表为空
	 { 		 
		 p->next=NULL;
		 head=p; 
		 return head;
	 }

     if (head->d==x)  //在第一个结点前插入
	 { 
		 p->next=head;  
		 head=p; 
		 return head;
	 }
     q=head;
     while ((q->next!=NULL)&&(((q->next)->d)!=x))
	 {
		 q=q->next;
	 }//寻找包含元素x的前一个结点q
     p->next=q->next; q->next=p; //新结点p插入到结点q之后
	 return head;
}

//删除链表，删除包含元素x的结点元素
node *delete_LList(node *head, int x) 
{
	node *p, *q;
  if (head==NULL) 
  {
	  cout<<"链表为空，无法删除！"<<endl;
	  return head; //链表为空，无删除的元素
  }
  if ((head->d)==x)  //删除第一个结点
  { 
	  p=head->next; 
	  delete head; 
	  head=p; 
	  return head;
  }
  q=head;
  while ((q->next!=NULL)&&(((q->next)->d)!=x))
  {
	  q=q->next;  //寻找包含元素x的前一个结点q
  }
  if (q->next==NULL) 
  {
	  cout<<"链表中无此元素！"<<endl;
	  return head; //链表中无删除的元素
  }
  p=q->next; q->next=p->next;  //删除q的下一个结点p
  delete  p;  //释放结点p的存储空间
  return head;
}


//扫描输出链表元素
void displayList(node *head)
{
	node *p;
	
	cout<<"链表数据为:";
	if (head==NULL)
	{
		cout<<"空！";
	}
    p=head;
	while(p!=NULL)
	{
		cout<<p->d;
		p=p->next;
	}
	cout<<endl;
}

node *sfun (node *h)

{
node *p, *q, *w ;
if (h==NULL)
return h;
else
p=h;  q=p->next;  w=q->next;  p->next=NULL;
while (q->next!=NULL)

{ q->next=p;  p=q;  q=w;  w=q->next;}
q->next=p;  h=q; 
return h;

}


int main()
{

    node *head;

	head=NULL;//头指针为空
	cout<<"head指针的地址为："<<head<<endl;

    cout<<"链表是否为空（1为空，0为非空）："<<LinkedListStatus(head)<<endl;
	displayList(head);

	//插入数据
    head=InsertList(head, 0, 3);displayList(head);
	cout<<"head指针的地址为："<<head<<endl;
	head=InsertList(head, 0, 6);displayList(head);
	head=InsertList(head, 3, 7); displayList(head);
    
    cout<<"链表是否为空（1为空，0为非空）："<<LinkedListStatus(head)<<endl;
	//删除数据
	//head=delete_LList(head, 7);	displayList(head);
//	head=delete_LList(head, 3);displayList(head);
//	head=delete_LList(head, 9);displayList(head);
	head=sfun(head);
	displayList(head);
    return 0;
}
