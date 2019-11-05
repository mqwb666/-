#include "stdio.h"
#define N 100

int m=10;

void fun1(int a[])
{
	int i;
	printf("\t当前元素有%d个；分别为：",m);
	for(i=0;i<m;i++)
	{
		printf(" %d",a[i]);	
	}
	printf("\n");
} 

void fun2(int a[])
{
	int i;
	system("cls");
	printf("\n\n\t请输入要查找的第i个元素[1,%d]：",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t第%d个位置不存在\n",i);
	}
	else
	{
		printf("\t第i个是元素是：%d\n\t",a[i-1]);
	}
	system("pause");
}

void fun3(int a[])
{
	int i,n;
	system("cls");
	printf("\n\n\t请输入要查找元素：");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==m)
		printf("\t没有找到%d这个元素\n\t",n);
	else
		printf("\t找到%d这个元素，第%d个\n\t",n,i+1);
	system("pause");
} 

void fun4(int a[])
{
	int i,j,e;
	system("cls");
	printf("\n");
	fun1(a);
	printf("\n\t请输入要插入的元素（还可以插入%d个)：",N-m);
	scanf("%d",&e);
	printf("\t插入的位置[1,%d]：",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t第%d个位置不存在\n\t",i);
	}
	else
	{
		for(j=m-1;j>=i-1;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=e;
		m++;
		printf("\t插入成功\n\t",i);		
	} 
	system("pause");
}

void fun5(int a[])
{
	int i,j,e;
	system("cls");
	printf("\n");
	fun1(a);
	printf("\n\t请输入要删除的第i个元素[1,%d]：",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t第%d个位置不存在\n\t",i);
	}
	else
	{
		for(j=i-1;j<m;j++)
		{
			a[j]=a[j+1];
		}
		a[j]=0;
		m--;
		printf("\t删除成功\n\t",i);		
	}
	system("pause");
}

int zcd(int a[])
{
	int i;
	printf("\n\n");
	printf("\t\t*******************************\n\n");
	printf("\t\t*  1.查找i号元素   2.查找元素  *\n\n");
	printf("\t\t*  3.添加元素      4.删除元素  *\n\n");
	printf("\t\t*  0.退出                      *\n\n");
	printf("\t\t********************************\n\n");
	fun1(a);
	printf("\n\t请输入[1~4]:[ ]\b\b"); 
	scanf("%d",&i);
	return i;
}
int main()
{
	int a[N]={11,22,33,44,55,66,77,88,99,100},i=1;
	while(i)
	{
		system("cls");
		switch(zcd(a))
		{
			case 1:fun2(a);break;
			case 2:fun3(a);break;
			case 3:fun4(a);break;
			case 4:fun5(a);break;
			case 0:i=0;
			default:break; 
		}
	}
	
	return 0;
}
