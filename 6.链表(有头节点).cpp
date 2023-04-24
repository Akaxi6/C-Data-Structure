#include <iostream.h>
#include <malloc.h>

struct node
{ 
    int d;
    struct node *next;
};

//�ж��Ƿ�Ϊ��
int LinkedListStatus(node *head)
{
    if(head==NULL)
        return 1;
    else
		return 0;
}

//��������, �ڰ���Ԫ��x�Ľ��ǰ������Ԫ��b
node *InsertList(node *head, int x, int b) 
{
     node  *p, *q; //�����½��

     p=new node; 
	 
     p->d=b;      //���½���������
     if (head==NULL)  //ԭ����Ϊ��
	 { 		 
		 p->next=NULL;
		 head=p; 
		 return head;
	 }

     if (head->d==x)  //�ڵ�һ�����ǰ����
	 { 
		 p->next=head;  
		 head=p; 
		 return head;
	 }
     q=head;
     while ((q->next!=NULL)&&(((q->next)->d)!=x))
	 {
		 q=q->next;
	 }//Ѱ�Ұ���Ԫ��x��ǰһ�����q
     p->next=q->next; q->next=p; //�½��p���뵽���q֮��
	 return head;
}

//ɾ������ɾ������Ԫ��x�Ľ��Ԫ��
node *delete_LList(node *head, int x) 
{
	node *p, *q;
  if (head==NULL) 
  {
	  cout<<"����Ϊ�գ��޷�ɾ����"<<endl;
	  return head; //����Ϊ�գ���ɾ����Ԫ��
  }
  if ((head->d)==x)  //ɾ����һ�����
  { 
	  p=head->next; 
	  delete head; 
	  head=p; 
	  return head;
  }
  q=head;
  while ((q->next!=NULL)&&(((q->next)->d)!=x))
  {
	  q=q->next;  //Ѱ�Ұ���Ԫ��x��ǰһ�����q
  }
  if (q->next==NULL) 
  {
	  cout<<"�������޴�Ԫ�أ�"<<endl;
	  return head; //��������ɾ����Ԫ��
  }
  p=q->next; q->next=p->next;  //ɾ��q����һ�����p
  delete  p;  //�ͷŽ��p�Ĵ洢�ռ�
  return head;
}


//ɨ���������Ԫ��
void displayList(node *head)
{
	node *p;
	
	cout<<"��������Ϊ:";
	if (head==NULL)
	{
		cout<<"�գ�";
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

	head=NULL;//ͷָ��Ϊ��
	cout<<"headָ��ĵ�ַΪ��"<<head<<endl;

    cout<<"�����Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ�ǿգ���"<<LinkedListStatus(head)<<endl;
	displayList(head);

	//��������
    head=InsertList(head, 0, 3);displayList(head);
	cout<<"headָ��ĵ�ַΪ��"<<head<<endl;
	head=InsertList(head, 0, 6);displayList(head);
	head=InsertList(head, 3, 7); displayList(head);
    
    cout<<"�����Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ�ǿգ���"<<LinkedListStatus(head)<<endl;
	//ɾ������
	//head=delete_LList(head, 7);	displayList(head);
//	head=delete_LList(head, 3);displayList(head);
//	head=delete_LList(head, 9);displayList(head);
	head=sfun(head);
	displayList(head);
    return 0;
}
