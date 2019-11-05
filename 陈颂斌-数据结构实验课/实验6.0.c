#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree(BiTree T){
	char ch;
	BiTNode t;
	do{
		scanf("%c",&ch);
	}while(ch=='\n');
		if(ch=='#') 
	{
		return NULL;
	}
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode ));
		T->data=ch;
		T->lchild=CreateBiTree(T->lchild);
		T->rchild=CreateBiTree(T->rchild);
	}
	return T;
	 
}

void PreOrderTraverse(BiTNode *T){

	if(T)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTNode *T){

	if(T)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTNode *T){

	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
}

int main(){
	BiTree T;
	printf("请输入二叉树的先序扩展序列：");
	T=CreateBiTree(T);
	printf("先序遍历二叉树：");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树：");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树：");
	PostOrderTraverse(T);
	}
