#include <stdio.h>
#include <stdlib.h> 

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void TraverseList(LinkList L);				
void CreatList(LinkList L,int n);			
int LocateElem(LinkList L,int e);
void ListDelete(LinkList L,int i);
void ListInsert(LinkList L,int i,int e); 

int main()
{
	int e,i;
	int n;
	LinkList L,m;
	L=(LNode *)malloc(sizeof(LNode));  
	L->next=NULL;
	printf("请输入元素个数");
	scanf("%d",&n);
	CreatList(L,n);
	TraverseList(L);
	
	printf("请输入要查找的元素\n");
	scanf("%d",&e);
	i=LocateElem(L,e);
	if(i==0)
		printf("未找到！\n");
	else
		printf("位置为%d\n",i);
		
	printf("请输入要插入的位置\n");
	scanf("%d",&i);
	printf("请输入要插入的元素\n");
	scanf("%d",&e);
	ListInsert(L,i,e);
	TraverseList(L);

	printf("请输入要删除的位置\n");
	scanf("%d",&i);
	ListDelete(L,i);
	TraverseList(L);
}

void ListDelete(LinkList L,int i)
{
	LinkList q,p=L;
	int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;j++;
	}
	if(!(p->next)||(j>i-1)) 
	{
		printf("删除位置错误！");
		return ;
	}
	q=p->next;
	p->next=q->next;
	free(q);
}

void ListInsert(LinkList L,int i,int e) 
{
	LinkList s,p=L;
	int j=0;
	while(p&&(j<i-1))
	{
		p=p->next;j++;
	}
	if(!p||(j>i-1)) 
	{
		printf("插入位置错误！");
		return ;
	}
	s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
}

int LocateElem(LinkList L,int e)
{
	int i=1;
	LinkList p;
	p=L->next;
	while(p&&p->data!=e)
	{
		p=p->next;
		i++;
	}
	if(p) return i;
	else return 0;
}


void TraverseList(LinkList L)
{
	LinkList p;
	//p=(LNode *)malloc(sizeof(LNode));
	for(p=L->next;p!=NULL;p=p->next)
	{
		printf("%d-> ",p->data);	
	}
	printf("\n");	
}
	
	
	
void CreatList(LinkList L,int n)
{
	int i;
	LinkList r,p;
	r=L;
	printf("请输入各元素"); 
	for(i=0;i<n;i++)
	{
		p=(LNode *)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=NULL;r->next=p;
		r=p;
	}
}	
	



