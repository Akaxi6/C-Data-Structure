# include<iostream.h>
struct Btnode//��㶨��
 {	   
    int d; 
    Btnode *lchild, *rchild;
};
creat(Btnode *p, int k, int end)
 {
	Btnode *q; 
	q=new Btnode;
    int  x;   
	cin>>x;
    if (x!=end)
	{
		q->d=x;q->lchild=NULL;q->rchild=NULL;
		if(k==1) p->lchild=q;
		if(k==2) p->rchild=q;
		cout<<"�������ӽ�㣺"<<endl;
		creat(q,1,end);
		cout<<"�������ӽ�㣺"<<endl;
		creat(q,2,end);
	}
	return 0;
}
Btnode *creat_Binary_Tree(int end)
 {
	Btnode *p, *BT; 
	int  x;
	cout<<"��������"<<endl;
	cin>>x;
	if (x==end) return 0;
	p=new Btnode;
    p->d=x;p->lchild=NULL;p->rchild=NULL;
    BT=p;
	cout<<"�������㣺"<<endl;
    creat(BT,1,end);
	cout<<"�����ҽ�㣺"<<endl;
	creat(BT,2,end);
	return BT;
}

//ǰ�����
void pretrav_Binary_Tree(Btnode *BT)
 {
	Btnode *p; 
	p=BT;
	if (p!=NULL)
	{
		cout<<p->d<<" ";
		pretrav_Binary_Tree(p->lchild);
		pretrav_Binary_Tree(p->rchild);
	}
	return;
}
//�������
void intrav_Binary_Tree(Btnode *BT)
 {
	Btnode *p; 
	p=BT;
	if (p!=NULL)
	{
		intrav_Binary_Tree(p->lchild);
		cout<<p->d<<" ";
		intrav_Binary_Tree(p->rchild);
	}
	return;
}
//�������
void postrav_Binary_Tree(Btnode *BT)
 {
	Btnode *p; 
	p=BT;
	if (p!=NULL)
	{
		postrav_Binary_Tree(p->lchild);
		postrav_Binary_Tree(p->rchild);
		cout<<p->d<<" ";
	}
	return;
}
void main()
{
	Btnode *ROOT;
	cout<<"����������������ֵ���������������ԣ�-1��������"<<endl;
	ROOT=creat_Binary_Tree(-1);

//cout<<"������Ҫ�������ڵ�:"<<creat(BT,1,-1);

	cout<<"ǰ�������"<<endl;
	pretrav_Binary_Tree(ROOT);
	cout<<endl;
	cout<<"���������"<<endl;
	intrav_Binary_Tree(ROOT);
	cout<<endl;
	cout<<"���������"<<endl;
	postrav_Binary_Tree(ROOT);
	cout<<endl;
}
