#include "stdio.h"
#define N 100

int m=10;

void fun1(int a[])
{
	int i;
	printf("��ǰԪ��Ϊ��\n");
	for(i=0;i<m;i++)
	{
		printf("\t%d",a[i]);	
	}
	printf("\n");
} 

void fun2(int a[])
{
	int i;
	printf("������Ҫ���ҵĵ�i��Ԫ�أ�");
	scanf("%d",&i);
	printf("��i����Ԫ���ǣ�%d\n",a[i-1]);
}

void fun3(int a[])
{
	int i,n;
	printf("������Ҫ����Ԫ�أ�");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==m)
		printf("û���ҵ�%d���Ԫ��\n",n);
	else
		printf("�ҵ�%d���Ԫ�أ���%d��\n",n,i+1);
} 

void fun4(int a[])
{
	int i,j,e;
	printf("������Ҫ�����Ԫ��");
	scanf("%d",&e);
	printf("�����λ��");
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
	printf("������Ҫɾ���ĵ�i��Ԫ�أ�");
	scanf("%d",&i);
	if(i>m)
	{
		printf("��%d��Ԫ�ز�����\n",i);
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
