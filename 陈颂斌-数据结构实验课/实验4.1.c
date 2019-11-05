#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
	int *base;
	int *top;
	int stackack;
}SqStack;

void InitStack(SqStack *S){
	S->base = (int *)malloc(MAXSIZE);
	if(!S->base) exit(0);
	S->top=S->base;
	S->stackack=MAXSIZE;	
}

SqStack Push(SqStack S,int e){
	if(S.top-S.base==S.stackack){
		printf("栈满");
		exit(0); 
	}
	*(++S.top)=e;
	return S;
} 

SqStack GetTop(SqStack S){
	for(;S.top!=S.base;)
	{
		if(*S.top>10)
			printf("%c",*S.top+55);
		else
			printf("%d",*S.top);
		S.top--;
	}
	return S; 
}

int main()
{
	int e,i;
	SqStack S;
	InitStack(&S);
	printf("请输入数据n（十进制）：\n");
	scanf("%d",&e);
	printf("请输入要转换的进制p（小于36进制即可）：\n");
	scanf("%d",&i);
	for(;e>0;e/=i)
	{
		S=Push(S,e%i);
	}
	printf("转换后的%d进制为：\n",i);
	GetTop(S);
	printf("\n");
}
