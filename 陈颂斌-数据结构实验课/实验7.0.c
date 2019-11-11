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
	}while(ch=='\n');			//whileѭ����ֹch���յ����з�
	 
	if(ch=='#') 				//�ж��Ƿ�Ϊ�գ����ǣ����ؿ� 
	{
		return NULL;
	}
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode ));		//������ռ� 
		T->data=ch;									//��㸳ֵ 
		printf("������%c�����ӣ�",ch); 
		T->lchild=CreateBiTree();					//�ݹ鴴������ 
		printf("������%c���Һ��ӣ�",ch); 
		T->rchild=CreateBiTree();					//�ݹ鴴���Һ��� 
	}
	return T;					//����ָ�� 
	 
}

int NOchild(BiTNode *T){
	int cnt=0; 					 
	if(T==NULL) return 0; 		//�ж��Ƿ�Ϊ�գ����ǣ�����0 
	
	if(T->lchild==NULL&&T->rchild==NULL){		//�ж����Ӻ��Һ����Ƿ�Ϊ�� 
		printf("%c",T->data);					
		cnt++;									//Ҷ�ӽ���һ 
	}
	cnt+=NOchild(T->lchild);	//�ݹ��ж�����Ҷ�ӽ�� 
	cnt+=NOchild(T->rchild);	//�ݹ��ж��Һ���Ҷ�ӽ�� 
	return cnt;					//����Ҷ�ӽ���� 

}

int	Depth(BiTNode *T){
	int n,m;
	if(T==NULL) return 0;
	else
	{
		m=Depth(T->lchild);		//�ݹ��ж��������
		n=Depth(T->rchild);		//�ݹ��ж��Һ������
		
		if(m>n) return m+1;		//�ж����Һ�����ȴ�С�����ش�� 
		else return n+1;
	}
	
} 

void PreOrderTraverse(BiTNode *T){

	if(T)		//�ж��Ƿ�Ϊ�� 
	{
		printf("%c",T->data);			//������ֵ 
		PreOrderTraverse(T->lchild);	//�ݹ����������� 
		PreOrderTraverse(T->rchild);	//�ݹ��������Һ���
	}
}

int main(){
	BiTree T;
	int cnt;
	
	printf("������һ���ַ���");
	T=CreateBiTree();				//������������������ָ�� 
	
	printf("\n�������������ö�������");
	PreOrderTraverse(T);			//��ָ��T���������������
	
	printf("\n�����ö�������Ҷ�ӽ�㣺");
	cnt=NOchild(T);					//����T�������������Ҷ�ӽ�� �������� 
	printf("\n��ö�������Ҷ�ӽ�����Ϊ��%d",cnt);
		
	cnt=Depth(T);					//����T���������������� �������� 
	printf("\n��ö�����������ǣ�%d",cnt);
}
