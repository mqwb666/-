#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct
{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

int DeQueue(LinkQueue *Q)
{
	Queueptr p;
	int e;
	if(Q->front==Q->rear) return -1;
	p=Q->front->next;
	e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p) Q->rear=Q->front;
	free(p);
	return e;
}

LinkQueue EnQueue(LinkQueue Q,int e)
{
	Queueptr p;
	p=(QNode *)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return Q;
}

int main()
{
	int i,j,e;
	LinkQueue Q;
	Queueptr p;
	Q.front=Q.rear=(QNode *)malloc(sizeof(QNode));
	Q.front->next=NULL;
	
	while(1)
	{
		printf("1:排队 2:就诊 3:查看排队 4:停止排队\n请选择："); 
		scanf("%d",&i);
		switch(i)
		{
			case 1:	while(1)
					{
						printf("请输入病历号：");
						scanf("%d",&e);
						for(p=Q.front->next;p!=NULL;p=p->next)
						{
							if(p->data==e) break;
						}
						if(p!=NULL)
						{
							printf("输入病历号重复，重新输入\n");
							continue;
						}
						else if(e<=0) break;
						Q=EnQueue(Q,e);
					}
					break;
						
			case 2: j=DeQueue(&Q);
					if(j==-1)
						printf("暂无病人\n");
					else
						printf("第%d号病人就诊\n",j);
					break;
			case 3: printf("目前所有的病历号：");
					for(p=Q.front->next;p!=NULL;p=p->next)
					{
						printf("% d",p->data);
					}
					printf("\n");
					break;
			case 4: exit(0);
		}
	}
	
	for(p=Q.front->next;p!=NULL;p=p->next)
	{
		printf("%d",p->data);
	}
	
}

