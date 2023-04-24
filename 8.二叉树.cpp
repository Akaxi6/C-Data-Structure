# include<iostream.h>
struct Btnode//结点定义
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
		cout<<"输入左子结点："<<endl;
		creat(q,1,end);
		cout<<"输入右子结点："<<endl;
		creat(q,2,end);
	}
	return 0;
}
Btnode *creat_Binary_Tree(int end)
 {
	Btnode *p, *BT; 
	int  x;
	cout<<"输入根结点"<<endl;
	cin>>x;
	if (x==end) return 0;
	p=new Btnode;
    p->d=x;p->lchild=NULL;p->rchild=NULL;
    BT=p;
	cout<<"输入左结点："<<endl;
    creat(BT,1,end);
	cout<<"输入右结点："<<endl;
	creat(BT,2,end);
	return BT;
}

//前序遍历
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
//中序遍历
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
//后序遍历
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
	cout<<"请输入二叉树各结点值，建立二叉树，以（-1）结束！"<<endl;
	ROOT=creat_Binary_Tree(-1);

//cout<<"请输入要插入的左节点:"<<creat(BT,1,-1);

	cout<<"前序遍历："<<endl;
	pretrav_Binary_Tree(ROOT);
	cout<<endl;
	cout<<"中序遍历："<<endl;
	intrav_Binary_Tree(ROOT);
	cout<<endl;
	cout<<"后序遍历："<<endl;
	postrav_Binary_Tree(ROOT);
	cout<<endl;
}
