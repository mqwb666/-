#include "stdio.h"
#define N 100

int m=10;

void fun1(int a[])
{
	int i;
	printf("\t��ǰԪ����%d�����ֱ�Ϊ��",m);
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
	printf("\n\n\t������Ҫ���ҵĵ�i��Ԫ��[1,%d]��",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t��%d��λ�ò�����\n",i);
	}
	else
	{
		printf("\t��i����Ԫ���ǣ�%d\n\t",a[i-1]);
	}
	system("pause");
}

void fun3(int a[])
{
	int i,n;
	system("cls");
	printf("\n\n\t������Ҫ����Ԫ�أ�");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==m)
		printf("\tû���ҵ�%d���Ԫ��\n\t",n);
	else
		printf("\t�ҵ�%d���Ԫ�أ���%d��\n\t",n,i+1);
	system("pause");
} 

void fun4(int a[])
{
	int i,j,e;
	system("cls");
	printf("\n");
	fun1(a);
	printf("\n\t������Ҫ�����Ԫ�أ������Բ���%d��)��",N-m);
	scanf("%d",&e);
	printf("\t�����λ��[1,%d]��",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t��%d��λ�ò�����\n\t",i);
	}
	else
	{
		for(j=m-1;j>=i-1;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=e;
		m++;
		printf("\t����ɹ�\n\t",i);		
	} 
	system("pause");
}

void fun5(int a[])
{
	int i,j,e;
	system("cls");
	printf("\n");
	fun1(a);
	printf("\n\t������Ҫɾ���ĵ�i��Ԫ��[1,%d]��",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("\t��%d��λ�ò�����\n\t",i);
	}
	else
	{
		for(j=i-1;j<m;j++)
		{
			a[j]=a[j+1];
		}
		a[j]=0;
		m--;
		printf("\tɾ���ɹ�\n\t",i);		
	}
	system("pause");
}

int zcd(int a[])
{
	int i;
	printf("\n\n");
	printf("\t\t*******************************\n\n");
	printf("\t\t*  1.����i��Ԫ��   2.����Ԫ��  *\n\n");
	printf("\t\t*  3.���Ԫ��      4.ɾ��Ԫ��  *\n\n");
	printf("\t\t*  0.�˳�                      *\n\n");
	printf("\t\t********************************\n\n");
	fun1(a);
	printf("\n\t������[1~4]:[ ]\b\b"); 
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
