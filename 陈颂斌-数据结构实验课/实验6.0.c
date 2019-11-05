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
	printf("�������������������չ���У�");
	T=CreateBiTree(T);
	printf("���������������");
	PreOrderTraverse(T);
	printf("\n���������������");
	InOrderTraverse(T);
	printf("\n���������������");
	PostOrderTraverse(T);
	}
