#include "stdio.h"
#define N 100

int m=10;

void fun1(int a[])
{
	int i;
	printf("当前元素为：\n");
	for(i=0;i<m;i++)
	{
		printf("\t%d",a[i]);	
	}
	printf("\n");
} 

void fun2(int a[])
{
	int i;
	printf("请输入要查找的第i个元素：");
	scanf("%d",&i);
	printf("第i个是元素是：%d\n",a[i-1]);
}

void fun3(int a[])
{
	int i,n;
	printf("请输入要查找元素：");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==m)
		printf("没有找到%d这个元素\n",n);
	else
		printf("找到%d这个元素，第%d个\n",n,i+1);
} 

void fun4(int a[])
{
	int i,j,e;
	printf("请输入要插入的元素");
	scanf("%d",&e);
	printf("插入的位置");
	scanf("%d",&i);
	for(j=m-1;j>=i-1;j--)
	{
		a[j+1]=a[j];
	}
	a[j]=e;
	m++;
	fun1(a);
}

void fun5(int a[])
{
	int i,j,e;
	printf("请输入要删除的第i个元素：");
	scanf("%d",&i);
	if(i>m)
	{
		printf("第%d个元素不存在\n",i);
	}
	else
	{
		for(j=i-1;j<m;j++)
		{
			a[j]=a[j+1];
		}
		a[j]=0;
		m--;
	}
	fun1(a);
}

int main()
{
	int a[N]={11,22,33,44,55,66,77,88,99,100};
	fun1(a);
	fun2(a);
	fun3(a);
	fun4(a);
	fun5(a);
	return 0;
}
