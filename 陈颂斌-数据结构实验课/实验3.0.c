#include <stdio.h>
#include <stdlib.h> 

typedef struct LNode
{
	int a;
	struct LNode *next;
}LNode,*LinkList;

int m;

void fun1(LinkList L)
{
	LinkList r,p;
	int i;
	p=L->next;
	printf("\t当前元素有%d个；分别为：",m);
	for(p;p!=NULL;p=p->next)
	{
		printf(" %d",p->a);	
	}
	printf("\n");
} 

void fun2(LinkList L)
{
	int i,n=0;
	LinkList p;
	p=L->next;
	system("cls");
	printf("\n\n\t请输入要查找的第i个元素[1,%d]：",m);
	scanf("%d",&i);
	if(i>m||i<1)
	{
		printf("\t第%d个位置不存在\n",i);
	}
	else
	{
		for(p;p!=NULL;p=p->next)
		{
			n++;
			if(i==n)
			{
				break;		
			}
		}
		printf("\t第i个是元素是：%d\n\t",p->a);
	}
	system("pause");
}

void fun3(LinkList L)
{
	int n,i=0;
	LinkList p;
	p=L->next;
	system("cls");
	printf("\n\n\t请输入要查找元素：");
	scanf("%d",&n);
	for(p;p!=NULL;p=p->next)
	{
		i++;
		if(p->a==n)
		{
			break;		
		}
	}
	if(p==NULL)
		printf("\t没有找到%d这个元素\n\t",n);
	else
		printf("\t找到%d这个元素，第%d个\n\t",p->a,i);
	system("pause");
} 

void fun4(LinkList L)
{
	int i,j,e;
	LinkList p,s;
	system("cls");
	printf("\n");
	fun1(L);
	printf("\n\t请输入要插入的元素");
	scanf("%d",&e);
	printf("\t插入的位置[1,%d]：",m+1);
	scanf("%d",&i);
	if(i>m+1||i<1)
	{
		printf("\t第%d个位置不存在\n\t",i);
	}
	else
	{
		for(j=0,p=L;j<i-1;p=p->next,j++);
		if(p!=NULL)
		{
			s=(LNode *)malloc(sizeof(LNode));
			s->a=e;
			s->next=p->next;
			p->next=s;		
			printf("\t插入成功\n\t",i);	
			m++;	
		}		
	} 
	system("pause");
}

void fun5(LinkList L)
{
	int i,j,e;
	LinkList p,s;
	system("cls");
	printf("\n");
	fun1(L);
	printf("\n\t请输入要删除的第i个元素[1,%d]：",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t第%d个位置不存在\n\t",i);
	}
	else
	{
		for(j=0,p=L;j<i-1;p=p->next,j++);
		
		if(p!=NULL)
		{
			s=p->next;
			p->next=s->next;
			free(s);		
			m--;
			printf("\t删除成功\n\t",i);		
		}
	}
	system("pause");
}

void fun6(LinkList L)
{
	int i,j;
	LinkList r,p;
	system("cls");
	printf("\n");
	printf("\n\t请输入要创建的元素个数：");
	scanf("%d",&m);

	printf("\n\t请输入要创建的元素：");
	
	L->next=NULL;
	r=L;
	for(i=0;i<m;i++)
	{
		p=(LNode *)malloc(sizeof(LNode));
		scanf("%d",&p->a);
		p->next=NULL;
		r->next=p;
		r=p;
	}	
	printf("\t创建成功\n\t",i);		
	system("pause");
}

int zcd(LinkList L)
{
	int i;
	printf("\n\n");
	printf("\t\t*******************************\n\n");
	printf("\t\t*  1.查找i号元素   2.查找元素  *\n\n");
	printf("\t\t*  3.添加元素      4.删除元素  *\n\n");
	printf("\t\t*  5.创建输入元素  0.退出      *\n\n");
	printf("\t\t********************************\n\n");
	fun1(L);
	printf("\n\t请输入[1~4]:[ ]\b\b"); 
	scanf("%d",&i);
	return i;
}

int main()
{
	int i=1;
	LinkList L,p,m;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	while(i)
	{
		system("cls");
		switch(zcd(L))
		{
			case 1:fun2(L);break;
			case 2:fun3(L);break;
			case 3:fun4(L);break;
			case 4:fun5(L);break;
			case 5:fun6(L);break;
			case 0:i=0;
			default:break; 
		}
	}
	
	return 0;
}
