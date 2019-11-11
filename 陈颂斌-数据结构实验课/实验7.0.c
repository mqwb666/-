#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree(){
	char ch;
	BiTree T;	
	do{
		scanf("%c",&ch);
	}while(ch=='\n');			//while循环防止ch接收到换行符
	 
	if(ch=='#') 				//判断是否为空，若是，返回空 
	{
		return NULL;
	}
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode ));		//申请结点空间 
		T->data=ch;									//结点赋值 
		printf("请输入%c的左孩子：",ch); 
		T->lchild=CreateBiTree();					//递归创建左孩子 
		printf("请输入%c的右孩子：",ch); 
		T->rchild=CreateBiTree();					//递归创建右孩子 
	}
	return T;					//返回指针 
	 
}

int NOchild(BiTNode *T){
	int cnt=0; 					 
	if(T==NULL) return 0; 		//判断是否为空，若是，返回0 
	
	if(T->lchild==NULL&&T->rchild==NULL){		//判断左孩子和右孩子是否都为空 
		printf("%c",T->data);					
		cnt++;									//叶子结点加一 
	}
	cnt+=NOchild(T->lchild);	//递归判断左孩子叶子结点 
	cnt+=NOchild(T->rchild);	//递归判断右孩子叶子结点 
	return cnt;					//返回叶子结点数 

}

int	Depth(BiTNode *T){
	int n,m;
	if(T==NULL) return 0;
	else
	{
		m=Depth(T->lchild);		//递归判断左孩子深度
		n=Depth(T->rchild);		//递归判断右孩子深度
		
		if(m>n) return m+1;		//判断左右孩子深度大小，返回大的 
		else return n+1;
	}
	
} 

void PreOrderTraverse(BiTNode *T){

	if(T)		//判断是否为空 
	{
		printf("%c",T->data);			//输出结点值 
		PreOrderTraverse(T->lchild);	//递归遍历输出左孩子 
		PreOrderTraverse(T->rchild);	//递归遍历输出右孩子
	}
}

int main(){
	BiTree T;
	int cnt;
	
	printf("请输入一个字符：");
	T=CreateBiTree();				//创建二叉树，并接收指针 
	
	printf("\n按照先序输出这棵二叉树：");
	PreOrderTraverse(T);			//传指针T，先序输出二叉树
	
	printf("\n输出这棵二叉树的叶子结点：");
	cnt=NOchild(T);					//传针T，计算二叉树的叶子结点 ，并返回 
	printf("\n这棵二叉树的叶子结点个数为：%d",cnt);
		
	cnt=Depth(T);					//传针T，计算二叉树的深度 ，并返回 
	printf("\n这棵二叉树的深度是：%d",cnt);
}
