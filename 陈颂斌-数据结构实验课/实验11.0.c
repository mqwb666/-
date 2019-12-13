#include <stdio.h>
#include <stdlib.h>
#define  MAXINT  32767

typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;



void Select(HuffmanTree HT,int n,int *s1,int *s2){
	int i,m1,m2;
	m1=m2=MAXINT;
	for(i=0;i<n;i++){
		if(HT[i].weight<m1&&HT[i].parent==0){
			m2=m1;
			*s2=*s1;
			m1=HT[i].weight;
			*s1=i;
		}
		else if(HT[i].weight<m2&&HT[i].parent==0){
			m2=HT[i].weight;
			*s2=i;
		}
	}
	
}

void CreateHuffmanTree(HuffmanTree HT,int n){
	int i,s1,s2;
	for(i=n;i<2*n-1;i++){
		Select(HT,i,&s1,&s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
	}
}

char code[20];
int cnt;

void initCode(){
	int i;
	for(i=0;i<20;i++){
		code[i]='\0';
	}
	cnt = 0;
}

int Code(HuffmanTree HT,int i){
	if(HT[i].parent==0)
		return ;
	Code(HT,HT[i].parent);
	if(HT[HT[i].parent].lchild==i)
		return code[cnt++]='0';
	if(HT[HT[i].parent].rchild==i)
		return code[cnt++]='1';
}

int main(){
	int i,n,m;
	HuffmanTree HT;
	printf("输入节点的个数：\n");
	scanf("%d",&n);
	m=2*n-1;
	HT=(HuffmanTree )malloc(sizeof(HTNode)*m);
	for(i=0;i<m;i++){
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=0;i<n;i++){
		printf("输入第%d个叶子结点的权值：\n",i);
		scanf("%d",&HT[i].weight);
	}
	
	CreateHuffmanTree(HT,n);
	
	for(i=0;i<n;i++){
		initCode();
		Code(HT,i);
		puts(code);
	}		
}

